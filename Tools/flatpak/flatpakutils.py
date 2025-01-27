# Copyright (C) 2017 Igalia S.L.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
# Boston, MA 02110-1301, USA.
import argparse
try:
    import configparser
except ImportError:
    import ConfigParser as configparser
import errno
import json
import os
import shlex
import shutil
import subprocess
import sys
import tempfile
import re

try:
    import yaml
except ImportError:
    sys.stderr.write("PyYaml not found, please install it before continuing\n")
    sys.exit(1)

try:
    from urllib.parse import urlparse  # pylint: disable=E0611
except ImportError:
    from urlparse import urlparse

try:
    from urllib.request import urlretrieve  # pylint: disable=E0611
except ImportError:
    from urllib import urlretrieve

FLATPAK_REQ = [
    ("flatpak", "0.10.0"),
    ("flatpak-builder", "0.10.0"),
]

scriptdir = os.path.abspath(os.path.dirname(__file__))


class Colors:
    HEADER = "\033[95m"
    OKBLUE = "\033[94m"
    OKGREEN = "\033[92m"
    WARNING = "\033[93m"
    FAIL = "\033[91m"
    ENDC = "\033[0m"


class Console:

    quiet = False

    @classmethod
    def message(cls, str_format, *args):
        if cls.quiet:
            return

        if args:
            print(str_format % args)
        else:
            print(str_format)

        # Flush so that messages are printed at the right time
        # as we use many subprocesses.
        sys.stdout.flush()


def remove_extension_points(array):
    result_args = []
    for arg in array:
        if(not arg.startswith('--extension')):
            result_args.append(arg)
    return result_args


def remove_comments(string):
    pattern = r"(\".*?\"|\'.*?\')|(/\*.*?\*/|//[^\r\n]*$)"
    # first group captures quoted strings (double or single)
    # second group captures comments (//single-line or /* multi-line */)
    regex = re.compile(pattern, re.MULTILINE | re.DOTALL)

    def _replacer(match):
        # if the 2nd group (capturing comments) is not None,
        # it means we have captured a non-quoted (real) comment string.
        if match.group(2) is not None:
            return ""  # so we will return empty to remove the comment
        else:  # otherwise, we will return the 1st group
            return match.group(1)  # captured quoted-string
    return regex.sub(_replacer, string)


def load_manifest(manifest_path, port_name=None, command=None):
    is_yaml = manifest_path.endswith('.yaml')
    with open(manifest_path, "r") as mr:
        contents = mr.read()

        contents = contents % {"COMMAND": command, "PORTNAME": port_name}
        if is_yaml:
            manifest = yaml.load(contents)
        else:
            contents = remove_comments(contents)
            manifest = json.loads(contents)

    return manifest


def expand_manifest(manifest_path, outfile, port_name, source_root, command):
    """Creates the manifest file."""
    try:
        os.remove(outfile)
    except OSError:
        pass

    manifest = load_manifest(manifest_path, port_name, command)
    if not manifest:
        return False

    if "sdk-hash" in manifest:
        del manifest["sdk-hash"]
    if "runtime-hash" in manifest:
        del manifest["runtime-hash"]
    i = 0
    all_modules = []

    overriden_modules = []
    if "WEBKIT_EXTRA_MODULESETS" in os.environ:
        overriden_modules = load_manifest(os.environ["WEBKIT_EXTRA_MODULESETS"])
        if not overriden_modules:
            overriden_modules = []
    for modules in manifest["modules"]:
        submanifest_path = None
        if type(modules) is str:
            submanifest_path = os.path.join(os.path.dirname(manifest_path), modules)
            modules = load_manifest(submanifest_path, port_name, command)

        if not isinstance(modules, list):
            modules = [modules]

        for module in modules:
            for overriden_module in overriden_modules:
                if module['name'] == overriden_module['name']:
                    module = overriden_module
                    overriden_modules.remove(module)
                    break

            all_modules.append(module)

    # And add overriden modules right before the webkit port build def.
    for overriden_module in overriden_modules:
        all_modules.insert(-1, overriden_module)

    manifest["modules"] = all_modules
    for module in manifest["modules"]:
        submanifest_path = None
        if module["sources"][0]["type"] == "git":
            if port_name == module["name"]:
                repo = "file://" + source_root
                module["sources"][0]["url"] = repo

        for source in module["sources"]:
            if source["type"] == "patch" or source["type"] == "file":
                if(submanifest_path is not None):
                    source["path"] = os.path.join(os.path.dirname(submanifest_path), source["path"])
                else:
                    source["path"] = os.path.join(os.path.dirname(manifest_path), source["path"])
        i += 1

    with open(outfile, "w") as of:
        of.write(json.dumps(manifest, indent=4))

    return True


class FlatpakObject:

    def __init__(self, user):
        self.user = user

    def flatpak(self, command, *args, **kwargs):
        show_output = kwargs.pop("show_output", False)
        comment = kwargs.pop("commend", None)
        if comment:
            Console.message(comment)

        command = ["flatpak", command]
        if self.user:
            res = subprocess.check_output(command + ["--help"]).decode("utf-8")
            if "--user" in res:
                command.append("--user")
        command.extend(args)

        if not show_output:
            return subprocess.check_output(command).decode("utf-8")

        return subprocess.check_call(command)


class FlatpakPackages(FlatpakObject):

    def __init__(self, repos, user=True):
        FlatpakObject.__init__(self, user=user)

        self.repos = repos

        self.runtimes = self.__detect_runtimes()
        self.apps = self.__detect_apps()
        self.packages = self.runtimes + self.apps

    def __detect_packages(self, *args):
        packs = []
        package_defs = [rd
                        for rd in self.flatpak("list", "-d", "--all", *args).split("\n")
                        if rd]
        for package_def in package_defs:
            splited_packaged_def = package_def.split()
            name, arch, branch = splited_packaged_def[0].split("/")

            # If installed from a file, the package is in no repo
            repo_name = splited_packaged_def[1]
            repo = self.repos.repos.get(repo_name)

            packs.append(FlatpakPackage(name, branch, repo, arch))

        return packs

    def __detect_runtimes(self):
        return self.__detect_packages("--runtime")

    def __detect_apps(self):
        return self.__detect_packages()

    def __iter__(self):
        for package in self.packages:
            yield package


class FlatpakRepos(FlatpakObject):

    def __init__(self, user=True):
        FlatpakObject.__init__(self, user=user)
        self.repos = {}
        self.update()

    def update(self):
        self.repos = {}
        remotes = [row
                   for row in self.flatpak("remote-list", "-d").split("\n")
                   if row]
        for repo in remotes:
            for components in [repo.split(" "), repo.split("\t")]:
                if len(components) == 1:
                    components = repo.split("\t")
                name = components[0]
                desc = ""
                url = None
                for elem in components[1:]:
                    if not elem:
                        continue
                    parsed_url = urlparse(elem)
                    if parsed_url.scheme:
                        url = elem
                        break

                    if desc:
                        desc += " "
                    desc += elem

                if url:
                    break

            if not url:
                Console.message("No valid URI found for: %s", repo)
                continue

            self.repos[name] = FlatpakRepo(name, url, desc, repos=self)

        self.packages = FlatpakPackages(self)

    def add(self, repo, override=True):
        same_name = None
        for name, tmprepo in self.repos.items():
            if repo.url == tmprepo.url:
                return tmprepo
            elif repo.name == name:
                same_name = tmprepo

        if same_name:
            if override:
                self.flatpak("remote-modify", repo.name, "--url=" + repo.url,
                             comment="Setting repo %s URL from %s to %s"
                             % (repo.name, same_name.url, repo.url))
                same_name.url = repo.url

                return same_name
            else:
                return None
        else:
            self.flatpak("remote-add", repo.name, "--from", repo.repo_file.name,
                         "--if-not-exists",
                         comment="Adding repo %s" % repo.name)

        repo.repos = self
        return repo


class FlatpakRepo(FlatpakObject):

    def __init__(self, name, desc=None, url=None,
                 repo_file=None, user=True, repos=None):
        FlatpakObject.__init__(self, user=user)

        self.name = name
        self.url = url
        self.desc = desc
        self.repo_file_name = repo_file
        self._repo_file = None
        self.repos = repos
        assert name
        if repo_file and not url:
            repo = configparser.ConfigParser()
            repo.read(self.repo_file.name)
            self.url = repo["Flatpak Repo"]["Url"]
        else:
            assert url

    @property
    def repo_file(self):
        if self._repo_file:
            return self._repo_file

        assert self.repo_file_name
        self._repo_file = tempfile.NamedTemporaryFile(mode="w")
        urlretrieve(self.repo_file_name, self._repo_file.name)

        return self._repo_file


class FlatpakPackage(FlatpakObject):
    """A flatpak app."""

    def __init__(self, name, branch, repo, arch, user=True, hash=None):
        FlatpakObject.__init__(self, user=user)

        self.name = name
        self.branch = str(branch)
        self.repo = repo
        self.arch = arch
        self.hash = hash

    def __str__(self):
        return "%s/%s/%s %s" % (self.name, self.arch, self.branch, self.repo.name)

    def is_installed(self, branch):
        if not self.repo:
            # Bundle installed from file
            return True

        self.repo.repos.update()
        for package in self.repo.repos.packages:
            if package.name == self.name and \
                    package.branch == branch and \
                    package.arch == self.arch:
                return True

        return False

    def install(self):
        if not self.repo:
            return False

        self.flatpak("install", self.repo.name, self.name, "--reinstall",
                     self.branch, show_output=True,
                     comment="Installing from " + self.repo.name + " " +
                             self.name + " " + self.arch + " " + self.branch)

    def update(self):
        if not self.is_installed(self.branch):
            return self.install()

        extra_args = []
        comment = "Updating %s" % self.name
        if self.hash:
            extra_args = ["--commit", self.hash]
            comment += " to %s" % self.hash

        self.flatpak("update", self.name, self.branch, show_output=True,
                    *extra_args, comment=comment)


class FlatpakModule(FlatpakObject):

    def __init__(self, flatpak_app, manifest_path, module_name,
                 debug):
        self.flatpak_app = flatpak_app

        manifest = load_manifest(manifest_path)
        if not manifest:
            exit(1)

        for module in manifest["modules"]:
            if module["name"] == module_name:
                break
        self.source_path = module["sources"][0]["url"]
        assert urlparse(self.source_path).scheme == "file"
        self.source_path = urlparse(self.source_path).path
        self.build_system = module.get("buildsystem", "autotools")
        self.config_options = module.get("config-opts", [])
        self.make_args = module.get("make-args", [])
        self.make_install_args = module.get("make-install-args", [])
        self.use_builddir = module.get("builddir", "false")
        # Only one command
        self.build_command, = module.get("build-commands", [])
        self.debug = debug

    def install_file(self, **kwargs):
        return "echo \"install %(src)s %(dest)s\"\ninstall -D %(src)s %(dest)s\npatchelf --remove-rpath %(dest)s 2>&1 |grep -v \"not an ELF\" || true\n" % (kwargs)

    def run(self, builddir):
        command = shlex.split(self.build_command)
        if self.debug:
            command.append('--debug')
        else:
            command.append('--release')

        self.flatpak_app.run_in_sandbox(*command, cwd=self.source_path)


class WebkitFlatpak:

    @staticmethod
    def load_from_args(args=None):
        self = WebkitFlatpak()

        parser = argparse.ArgumentParser(prog="webkit-flatpak")
        general = parser.add_argument_group("General")
        general.add_argument("--debug",
                            help="Compile with Debug configuration, also installs Sdk debug symboles.",
                            action="store_true")
        general.add_argument("--release", help="Compile with Release configuration.", action="store_true")
        general.add_argument('--platform', action='store', help='Platform to use (e.g., "mac-lion")'),
        general.add_argument('--gtk', action='store_const', dest='platform', const='gtk',
                             help='Alias for --platform=gtk')
        general.add_argument('--wpe', action='store_const', dest='platform', const='wpe',
                            help=('Alias for --platform=wpe'))
        general.add_argument("-nf", "--no-flatpak-update", dest="no_flatpak_update",
                            action="store_true",
                            help="Do not update flaptak runtime/sdk")
        general.add_argument("-u", "--update", dest="update",
                            action="store_true",
                            help="Update the runtime/sdk/app and rebuild the development environment if needed")
        general.add_argument("-b", "--build-webkit", dest="build_webkit_args",
                            nargs=argparse.REMAINDER,
                            help="Force rebuilding the app.")
        general.add_argument("-ba", "--build-all", dest="build_all",
                            action="store_true",
                            help="Force rebuilding the app and its dependencies.")
        general.add_argument("-q", "--quiet", dest="quiet",
                            action="store_true",
                            help="Do not print anything")
        general.add_argument("-t", "--tests", dest="run_tests",
                            nargs=argparse.REMAINDER,
                            help="Run LayoutTests")
        general.add_argument("-c", "--command",
                            nargs=argparse.REMAINDER,
                            help="The command to run in the sandbox",
                            dest="user_command")
        general.add_argument("args",
                            nargs=argparse.REMAINDER,
                            help="Arguments passed when starting %s" % self.name)
        general.add_argument("--name", dest="name",
                            help="The name of the component to develop",
                            default=self.name)
        general.add_argument('--avalaible', action='store_true', dest="check_avalaible", help='Check if required dependencies are avalaible.'),

        debugoptions = parser.add_argument_group("Debugging")
        debugoptions.add_argument("--gdb", nargs="?", help="Activate gdb, passing extra args to it if wanted.")
        debugoptions.add_argument("-m", "--coredumpctl-matches", default="", help='Arguments to pass to gdb.')

        buildoptions = parser.add_argument_group("Extra build arguments")
        buildoptions.add_argument("--makeargs", help="Optional Makefile flags")
        buildoptions.add_argument("--cmakeargs",
                                help="One or more optional CMake flags (e.g. --cmakeargs=\"-DFOO=bar -DCMAKE_PREFIX_PATH=/usr/local\")")

        general.add_argument("--clean", dest="clean", action="store_true",
            help="Clean previous builds and restart from scratch")

        parser.parse_args(args=args, namespace=self)
        self.clean_args()

        return self

    def __init__(self):
        self.sdk_repo = None
        self.runtime = None
        self.locale = None
        self.sdk = None
        self.sdk_debug = None
        self.app = None

        self.quiet = False
        self.packs = []
        self.update = False
        self.args = []
        self.finish_args = None

        self.no_flatpak_update = False
        self.debug = False
        self.clean = False
        self.run_tests = None
        self.source_root = os.path.normpath(os.path.abspath(os.path.join(scriptdir, '../../')))
        # Where the source folder is mounted inside the sandbox.
        self.sandbox_source_root = "/app/webkit"

        self.build_webkit_args = None
        self.build_all = False

        self.sdk_branch = None
        self.platform = "GTK"
        self.build_type = "Release"
        self.manifest_path = None
        self.name = None
        self.build_name = None
        self.flatpak_root_path = None
        self.cache_path = None
        self.app_module = None
        self.flatpak_default_args = []
        self.check_avalaible = False

        # Default application to run in the sandbox
        self.command = None
        self.user_command = []

        # debug options
        self.gdb = None
        self.coredumpctl_matches = ""

        # Extra build options
        self.cmakeargs = ""
        self.makeargs = ""

    def check_flatpak(self):
        for app, required_version in FLATPAK_REQ:
            try:
                output = subprocess.check_output([app, "--version"])
            except subprocess.CalledProcessError:
                Console.message("\n%sYou need to install %s >= %s"
                                " to be able to use the '%s' script.\n\n"
                                "You can find some informations about"
                                " how to install it for your distribution at:\n"
                                "    * http://flatpak.org/%s\n", Colors.FAIL,
                                app, required_version, sys.argv[0], Colors.ENDC)
                exit(1)

            def comparable_version(version):
                return tuple(map(int, (version.split("."))))

            version = output.decode("utf-8").split(" ")[1].strip("\n")
            if comparable_version(version) < comparable_version(required_version):
                Console.message("\n%s%s %s required but %s found."
                                " Please update and try again%s\n", Colors.FAIL,
                                app, version, version, Colors.ENDC)
                exit(1)

    def clean_args(self):
        self.platform = self.platform.upper()
        self.build_type = "Debug" if self.debug else "Release"
        if self.gdb is None and '--gdb' in sys.argv:
            self.gdb = ""

        self.command = "%s %s %s" % (os.path.join(self.sandbox_source_root,
            "Tools/Scripts/run-minibrowser"),
            "--" + self.platform.lower(),
            " --debug" if self.debug else " --release")

        self.name = "org.webkit.%s" % self.platform
        self.manifest_path = os.path.abspath(os.path.join(scriptdir, '../flatpak/org.webkit.WebKit.yaml'))
        self.build_name = self.name + "-generated"

        build_root = os.path.join(self.source_root, 'WebKitBuild')
        self.flatpak_build_path = os.path.join(build_root, self.platform, "FlatpakTree" + self.build_type)
        self.cache_path = os.path.join(build_root, "FlatpakCache")
        self.build_path = os.path.join(build_root, self.platform, self.build_type)
        try:
            os.makedirs(self.build_path)
        except OSError as e:
            if e.errno != errno.EEXIST:
                raise e

        Console.quiet = self.quiet
        self.check_flatpak()

        repos = FlatpakRepos()
        self.sdk_repo = repos.add(
            FlatpakRepo("flathub",
                        url="https://dl.flathub.org/repo/",
                        repo_file="https://dl.flathub.org/repo/flathub.flatpakrepo"))

        manifest = load_manifest(self.manifest_path)
        if not manifest:
            exit(1)

        self.sdk_branch = manifest["runtime-version"]
        self.finish_args = manifest.get("finish-args", [])
        self.finish_args = remove_extension_points(self.finish_args)
        self.runtime = FlatpakPackage("org.gnome.Platform", self.sdk_branch,
                                      self.sdk_repo, "x86_64",
                                      hash=manifest.get("runtime-hash"))
        self.locale = FlatpakPackage("org.gnome.Platform.Locale",
                                     self.sdk_branch, self.sdk_repo, "x86_64")
        self.sdk = FlatpakPackage("org.gnome.Sdk", self.sdk_branch,
                                  self.sdk_repo, "x86_64",
                                  hash=manifest.get("sdk-hash"))
        self.packs = [self.runtime, self.locale, self.sdk]

        if self.debug:
            self.sdk_debug = FlatpakPackage("org.gnome.Sdk.Debug", self.sdk_branch,
                                      self.sdk_repo, "x86_64")
            self.packs.append(self.sdk_debug)
        self.manifest_generated_path = os.path.join(self.cache_path,
                                                    self.build_name + ".json")

    def run_in_sandbox(self, *args, **kwargs):
        cwd = kwargs.pop("cwd", None)
        remove_devices = kwargs.pop("remove_devices", False)

        if not isinstance(args, list):
            args = list(args)
        if args:
            command = os.path.normpath(os.path.abspath(args[0]))
            # Take into account the fact that the webkit source dir is remounted inside the sandbox.
            args[0] = command.replace(self.source_root, self.sandbox_source_root)
        sandbox_build_path = os.path.join(self.sandbox_source_root, "WebKitBuild", self.build_type)
        with tempfile.NamedTemporaryFile(mode="w") as tmpscript:
            flatpak_command = ["flatpak", "build", "--die-with-parent",
                "--bind-mount=%s=%s" % (tempfile.gettempdir(), tempfile.gettempdir()),
                "--bind-mount=%s=%s" % (self.sandbox_source_root, self.source_root),
                # We mount WebKitBuild/PORTNAME/BuildType to /app/webkit/WebKitBuild/BuildType
                # so we can build WPE and GTK in a same source tree.
                "--bind-mount=%s=%s" % (sandbox_build_path, self.build_path)]

            forwarded = {
                "WEBKIT_TOP_LEVEL": "/app/",
                "TEST_RUNNER_INJECTED_BUNDLE_FILENAME": "/app/webkit/lib/libTestRunnerInjectedBundle.so",
            }

            for envvar, value in os.environ.items():
                if envvar.split("_")[0] in ("GST", "GTK", "G") or \
                        envvar in ["WAYLAND_DISPLAY", "DISPLAY", "LANG"]:
                    forwarded[envvar] = value

            for envvar, value in forwarded.items():
                flatpak_command.append("--env=%s=%s" % (envvar, value))

            finish_args = self.finish_args
            if remove_devices:
                finish_args.remove("--device=all")

            flatpak_command += finish_args + [self.flatpak_build_path]

            shell_string = ""
            if args:
                if cwd:
                    shell_string = 'cd "%s" && "%s"' % (cwd, '" "'.join(args))
                else:
                    shell_string = '"%s"' % ('" "'.join(args))
            else:
                shell_string = self.command
                if self.args:
                    shell_string += ' "%s"' % '" "'.join(self.args)

            tmpscript.write(shell_string)
            tmpscript.flush()

            Console.message('Running in sandbox: "%s" %s\n' % ('" "'.join(flatpak_command), shell_string))
            flatpak_command.extend(['sh', tmpscript.name])

            try:
                subprocess.check_call(flatpak_command)
            except subprocess.CalledProcessError as e:
                sys.stderr.write(str(e) + "\n")
                exit(e.returncode)

    def run(self):
        if self.check_avalaible:
            return
        if self.clean:
            if os.path.exists(self.flatpak_build_path):
                shutil.rmtree(self.flatpak_build_path)
            if os.path.exists(self.build_path):
                shutil.rmtree(self.build_path)

        if self.update:
            Console.message("Updating Flatpak environment for %s (%s)" % (
                self.platform, self.build_type))
            if not self.no_flatpak_update:
                self.update_all()

        self.setup_dev_env()

    def has_environment(self):
        return os.path.exists(os.path.join(self.build_path, self.flatpak_build_path))

    def setup_dev_env(self):
        if not os.path.exists(os.path.join(self.build_path, "bin", "MiniBrowser")) \
                or not os.path.exists(os.path.join(self.build_path, self.flatpak_build_path)) \
                or self.update or self.build_all:
            self.install_all()
            Console.message("Building %s and dependencies in %s",
                            self.name, self.flatpak_build_path)

            # Create environment dirs if necessary
            try:
                os.makedirs(os.path.dirname(self.manifest_generated_path))
            except OSError as e:
                if e.errno != errno.EEXIST:
                    raise e
            if not expand_manifest(self.manifest_path, self.manifest_generated_path,
                                   self.name, self.sandbox_source_root, self.command):
                exit(1)

            builder_args = ["flatpak-builder", "--disable-rofiles-fuse", "--state-dir",
                            self.cache_path, "--ccache", self.flatpak_build_path, "--force-clean",
                            self.manifest_generated_path]
            builder_args.append("--build-only")
            builder_args.append("--stop-at=%s" % self.name)
            subprocess.check_call(builder_args)

            self.build_webkit_args = []

        if self.build_webkit_args is None:
            if not expand_manifest(self.manifest_path, self.manifest_generated_path,
                                   self.name, self.sandbox_source_root, self.command):
                exit(1)
            self.app_module = FlatpakModule(self, self.manifest_generated_path, self.name,
                self.debug)
            self.app_module.run(self.cache_path)
        else:
            Console.message("Using %s prefix in %s", self.name, self.flatpak_build_path)

        if self.run_tests is not None:
            test_launcher = [os.path.join(self.sandbox_source_root, 'Tools/Scripts/run-webkit-tests'),
                "--debug" if self.debug  else "--release", '--' + self.platform.lower()] + self.run_tests
            self.run_in_sandbox(*test_launcher, remove_devices=True)
        elif self.gdb is not None:
            self.run_gdb()
        elif self.user_command:
            self.run_in_sandbox(*self.user_command)
        elif not self.update:
            self.run_in_sandbox()

    def install_all(self):
        for package in self.packs:
            if not package.is_installed(self.sdk_branch):
                package.install()

    def run_gdb(self):
        try:
            subprocess.check_output(['which', 'coredumpctl'])
        except subprocess.CalledProcessError as e:
            sys.stderr.write("'coredumpctl' not present on the system, can't run. (%s)\n" % e)
            sys.exit(1)

        # We need access to the host from the sandbox to run.
        with tempfile.NamedTemporaryFile() as coredump:
            with tempfile.NamedTemporaryFile() as stderr:
                subprocess.check_call(["coredumpctl", "dump"] + shlex.split(self.coredumpctl_matches),
                                      stdout=coredump, stderr=stderr)

                with open(stderr.name, 'r') as stderrf:
                    stderr = stderrf.read()
                executable, = re.findall(".*Executable: (.*)", stderr)
                if not executable.startswith("/newroot"):
                    sys.stderr.write("Executable %s doesn't seem to be a flatpaked application.\n" % executable)

                executable = executable.replace("/newroot", "")
                args = ["gdb", executable, coredump.name] + shlex.split(self.gdb)

                self.run_in_sandbox(*args)

    def update_all(self):
        for m in [self.runtime, self.sdk, self.sdk_debug]:
            if m:
                m.update()


def is_sandboxed():
    return os.path.exists("/usr/manifest.json")


def run_in_sandbox_if_available(args):
    if is_sandboxed():
        return None

    flatpak_runner = WebkitFlatpak.load_from_args(args)
    if not flatpak_runner.has_environment():
        return None

    sys.exit(flatpak_runner.run_in_sandbox(*args, remove_devices=args[0].endswith('run-webkit-tests')))
