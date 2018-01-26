
enable_language(ASM)

if (NOT LIBWEBRTC_INPUT_DIR)
    set(LIBWEBRTC_INPUT_DIR ${CMAKE_SOURCE_DIR}/Source/ThirdParty/libwebrtc/Source)
endif ()
if (NOT LIBWEBRTC_OUTPUT_DIR)
    set(LIBWEBRTC_OUTPUT_DIR ${CMAKE_BINARY_DIR})
endif ()

add_definitions(-Wno-undef -Wno-unused-function -Wno-implicit-fallthrough -Wno-format-truncation -Wno-return-type -Wno-suggest-attribute=format -Wno-int-in-bool-context -Wno-extra -Wno-memset-elt-size -Wno-sign-compare)

# find_library(XCB_LIBRARY xcb)
find_library(JPEG_LIBRARY jpeg)
# find_library(X11-XCB_LIBRARY X11-xcb)
find_library(VPX_LIBRARY vpx)
find_library(EVENT_LIBRARY event)
find_library(RT_LIBRARY rt)
# find_library(XTST_LIBRARY Xtst)
# find_library(XCURSOR_LIBRARY Xcursor)
find_library(DL_LIBRARY dl)
# find_library(XEXT_LIBRARY Xext)
# find_library(XRENDER_LIBRARY Xrender)
# find_library(XI_LIBRARY Xi)
# find_library(X11_LIBRARY X11)
# find_library(XCOMPOSITE_LIBRARY Xcomposite)
find_library(M_LIBRARY m)
# find_library(XFIXES_LIBRARY Xfixes)

# Start of target WebrtcModulesMedia_FileMedia_File
set(WebrtcModulesMedia_FileMedia_File_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/media_file/media_file_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/media_file/media_file_utility.cc)
add_library(WebrtcModulesMedia_FileMedia_File STATIC ${WebrtcModulesMedia_FileMedia_File_SOURCES})
target_compile_options(WebrtcModulesMedia_FileMedia_File PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesMedia_FileMedia_File PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesMedia_FileMedia_File PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesMedia_FileMedia_File PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesMedia_FileMedia_File PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/media_file)
set_target_properties(WebrtcModulesMedia_FileMedia_File PROPERTIES OUTPUT_NAME media_file)
target_link_libraries(WebrtcModulesMedia_FileMedia_File WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesMedia_FileMedia_File WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesMedia_FileMedia_File WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesMedia_FileMedia_File WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesMedia_FileMedia_File Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesMedia_FileMedia_File WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesMedia_FileMedia_File PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesMedia_FileMedia_File ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesMedia_FileMedia_File PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesMedia_FileMedia_File ${RT_LIBRARY})
# End of target WebrtcModulesMedia_FileMedia_File

# Start of target WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal
set(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/builtin_audio_decoder_factory_internal.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal STATIC ${WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PROPERTIES OUTPUT_NAME builtin_audio_decoder_factory_internal)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingG722)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingIlbc)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingPcm16B)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingRed)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_CodingWebrtc_Opus)
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${XEXT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal ${M_LIBRARY})
# End of target WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal

# Start of target WebrtcP2PRtc_P2P
set(WebrtcP2PRtc_P2P_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/asyncstuntcpsocket.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/basicpacketsocketfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/dtlstransportchannel.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/jseptransport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/p2pconstants.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/p2ptransportchannel.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/packetlossestimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/port.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/portallocator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/pseudotcp.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/relayport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/session.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/sessiondescription.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/stun.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/stunport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/stunrequest.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/tcpport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/transportcontroller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/transportdescription.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/transportdescriptionfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/turnport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/udptransport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/client/basicportallocator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/client/socketmonitor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/relayserver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/stunserver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/base/turnserver.cc)
add_library(WebrtcP2PRtc_P2P STATIC ${WebrtcP2PRtc_P2P_SOURCES})
target_compile_options(WebrtcP2PRtc_P2P PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcP2PRtc_P2P PRIVATE FEATURE_ENABLE_VOICEMAIL FEATURE_ENABLE_PSTN USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX FEATURE_ENABLE_VOICEMAIL)
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcP2PRtc_P2P PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcP2PRtc_P2P PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/p2p)
set_target_properties(WebrtcP2PRtc_P2P PROPERTIES OUTPUT_NAME rtc_p2p)
target_link_libraries(WebrtcP2PRtc_P2P WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcP2PRtc_P2P WebrtcBaseRtc_Base)
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcP2PRtc_P2P ${DL_LIBRARY})
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcP2PRtc_P2P ${RT_LIBRARY})
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PRtc_P2P ${XEXT_LIBRARY})
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PRtc_P2P ${X11_LIBRARY})
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PRtc_P2P ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcP2PRtc_P2P PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PRtc_P2P ${XRENDER_LIBRARY})
# End of target WebrtcP2PRtc_P2P

# Start of target WebrtcCallRtp_Receiver
set(WebrtcCallRtp_Receiver_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/call/rtp_demuxer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/call/rtx_receive_stream.cc)
add_library(WebrtcCallRtp_Receiver OBJECT ${WebrtcCallRtp_Receiver_SOURCES})
target_compile_options(WebrtcCallRtp_Receiver PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCallRtp_Receiver PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcCallRtp_Receiver PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCallRtp_Receiver PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcCallRtp_Receiver WebrtcBaseRtc_Base_Approved WebrtcModulesRtp_RtcpRtp_Rtcp)
# End of target WebrtcCallRtp_Receiver

# Start of target WebrtcSystem_WrappersSystem_Wrappers
set(WebrtcSystem_WrappersSystem_Wrappers_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/aligned_malloc.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/clock.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/cpu_features.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/cpu_info.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/event.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/event_timer_posix.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/file_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/rtp_to_ntp_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/rw_lock.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/rw_lock_posix.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/sleep.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/timestamp_extrapolator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/trace_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/trace_posix.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/atomic32_non_darwin_unix.cc)
add_library(WebrtcSystem_WrappersSystem_Wrappers STATIC ${WebrtcSystem_WrappersSystem_Wrappers_SOURCES})
target_compile_options(WebrtcSystem_WrappersSystem_Wrappers PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcSystem_WrappersSystem_Wrappers PRIVATE WEBRTC_THREAD_RR USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcSystem_WrappersSystem_Wrappers PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcSystem_WrappersSystem_Wrappers PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcSystem_WrappersSystem_Wrappers PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/system_wrappers)
set_target_properties(WebrtcSystem_WrappersSystem_Wrappers PROPERTIES OUTPUT_NAME system_wrappers)
target_link_libraries(WebrtcSystem_WrappersSystem_Wrappers WebrtcWebrtc_Common)
target_link_libraries(WebrtcSystem_WrappersSystem_Wrappers WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcSystem_WrappersSystem_Wrappers WebrtcSystem_WrappersCpu_Features_Linux)
target_include_directories(WebrtcSystem_WrappersSystem_Wrappers PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcSystem_WrappersSystem_Wrappers ${RT_LIBRARY})
# End of target WebrtcSystem_WrappersSystem_Wrappers

# Start of target WebrtcApiLibjingle_Peerconnection_Api
set(WebrtcApiLibjingle_Peerconnection_Api_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/mediaconstraintsinterface.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/mediastreaminterface.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/mediatypes.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/rtcerror.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/statstypes.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiLibjingle_Peerconnection_Api STATIC ${WebrtcApiLibjingle_Peerconnection_Api_SOURCES})
target_compile_options(WebrtcApiLibjingle_Peerconnection_Api PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiLibjingle_Peerconnection_Api PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiLibjingle_Peerconnection_Api PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcApiLibjingle_Peerconnection_Api PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/api)
set_target_properties(WebrtcApiLibjingle_Peerconnection_Api PROPERTIES OUTPUT_NAME jingle_peerconnection_api)
target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api WebrtcBaseRtc_Base)
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${DL_LIBRARY})
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${RT_LIBRARY})
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${XEXT_LIBRARY})
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${X11_LIBRARY})
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcApiLibjingle_Peerconnection_Api PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcApiLibjingle_Peerconnection_Api ${XRENDER_LIBRARY})
# End of target WebrtcApiLibjingle_Peerconnection_Api

# Start of target WebrtcSystem_WrappersField_Trial_Default
set(WebrtcSystem_WrappersField_Trial_Default_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/field_trial_default.cc)
add_library(WebrtcSystem_WrappersField_Trial_Default STATIC ${WebrtcSystem_WrappersField_Trial_Default_SOURCES})
target_compile_options(WebrtcSystem_WrappersField_Trial_Default PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcSystem_WrappersField_Trial_Default PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcSystem_WrappersField_Trial_Default PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcSystem_WrappersField_Trial_Default PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcSystem_WrappersField_Trial_Default PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/system_wrappers)
set_target_properties(WebrtcSystem_WrappersField_Trial_Default PROPERTIES OUTPUT_NAME field_trial_default)
# End of target WebrtcSystem_WrappersField_Trial_Default

# Start of target WebrtcModulesAudio_MixerAudio_Frame_Manipulator
set(WebrtcModulesAudio_MixerAudio_Frame_Manipulator_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_mixer/audio_frame_manipulator.cc)
add_library(WebrtcModulesAudio_MixerAudio_Frame_Manipulator STATIC ${WebrtcModulesAudio_MixerAudio_Frame_Manipulator_SOURCES})
target_compile_options(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_mixer)
set_target_properties(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PROPERTIES OUTPUT_NAME audio_frame_manipulator)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_MixerAudio_Frame_Manipulator PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_MixerAudio_Frame_Manipulator ${RT_LIBRARY})
# End of target WebrtcModulesAudio_MixerAudio_Frame_Manipulator

# Start of target WebrtcVoice_EngineFile_Player
set(WebrtcVoice_EngineFile_Player_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/file_player.cc)
add_library(WebrtcVoice_EngineFile_Player STATIC ${WebrtcVoice_EngineFile_Player_SOURCES})
target_compile_options(WebrtcVoice_EngineFile_Player PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVoice_EngineFile_Player PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVoice_EngineFile_Player PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVoice_EngineFile_Player PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/voice_engine)
set_target_properties(WebrtcVoice_EngineFile_Player PROPERTIES OUTPUT_NAME file_player)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcWebrtc_Common)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcVoice_EngineFile_Player Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcModulesMedia_FileMedia_File)
target_link_libraries(WebrtcVoice_EngineFile_Player WebrtcVoice_EngineAudio_Coder)
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Player ${RT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Player ${JPEG_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Player ${DL_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Player ${XEXT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Player ${X11_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Player ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Player ${XRENDER_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Player ${EVENT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Player PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Player ${M_LIBRARY})
# End of target WebrtcVoice_EngineFile_Player


# Start of target WebrtcModulesAudio_CodingIsac_Fix
set(WebrtcModulesAudio_CodingIsac_Fix_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/audio_decoder_isacfix.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/audio_encoder_isacfix.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_C>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_Common>)
add_library(WebrtcModulesAudio_CodingIsac_Fix STATIC ${WebrtcModulesAudio_CodingIsac_Fix_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac_Fix PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac_Fix PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac_Fix PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/include/)
set_target_properties(WebrtcModulesAudio_CodingIsac_Fix PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingIsac_Fix PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingIsac_Fix PROPERTIES OUTPUT_NAME isac_fix)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix WebrtcModulesAudio_CodingIsac_Common)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_CodingIsac_Fix PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIsac_Fix ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingIsac_Fix

# Start of target WebrtcModulesAudio_ProcessingAudio_Processing_C
set(WebrtcModulesAudio_ProcessingAudio_Processing_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/legacy/analog_agc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/legacy/digital_agc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/ns/noise_suppression.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/ns/ns_core.c)
add_library(WebrtcModulesAudio_ProcessingAudio_Processing_C OBJECT ${WebrtcModulesAudio_ProcessingAudio_Processing_C_SOURCES})
target_compile_options(WebrtcModulesAudio_ProcessingAudio_Processing_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_ProcessingAudio_Processing_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_ProcessingAudio_Processing_C WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved WebrtcCommon_AudioCommon_Audio WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcModulesAudio_ProcessingAudio_Processing_C

# Start of target WebrtcModulesAudio_ProcessingAec_Dump_Interface
set(WebrtcModulesAudio_ProcessingAec_Dump_Interface_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/include/aec_dump.cc)
add_library(WebrtcModulesAudio_ProcessingAec_Dump_Interface OBJECT ${WebrtcModulesAudio_ProcessingAec_Dump_Interface_SOURCES})
target_compile_options(WebrtcModulesAudio_ProcessingAec_Dump_Interface PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_ProcessingAec_Dump_Interface PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_ProcessingAec_Dump_Interface PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_ProcessingAec_Dump_Interface PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_ProcessingAec_Dump_Interface WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_ProcessingAec_Dump_Interface

# Start of target WebrtcVoice_EngineFile_Recorder
set(WebrtcVoice_EngineFile_Recorder_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/file_recorder.cc)
add_library(WebrtcVoice_EngineFile_Recorder STATIC ${WebrtcVoice_EngineFile_Recorder_SOURCES})
target_compile_options(WebrtcVoice_EngineFile_Recorder PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVoice_EngineFile_Recorder PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVoice_EngineFile_Recorder PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVoice_EngineFile_Recorder PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/voice_engine)
set_target_properties(WebrtcVoice_EngineFile_Recorder PROPERTIES OUTPUT_NAME file_recorder)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcWebrtc_Common)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcVoice_EngineFile_Recorder Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcModulesMedia_FileMedia_File)
target_link_libraries(WebrtcVoice_EngineFile_Recorder WebrtcVoice_EngineAudio_Coder)
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Recorder ${RT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Recorder ${JPEG_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Recorder ${DL_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Recorder ${XEXT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Recorder ${X11_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Recorder ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineFile_Recorder ${XRENDER_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Recorder ${EVENT_LIBRARY})
target_include_directories(WebrtcVoice_EngineFile_Recorder PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineFile_Recorder ${M_LIBRARY})
# End of target WebrtcVoice_EngineFile_Recorder

# Start of target WebrtcModulesAudio_CodingIlbc_C
set(WebrtcModulesAudio_CodingIlbc_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/abs_quant.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/abs_quant_loop.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/augmented_cb_corr.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/bw_expand.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_construct.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_augmentation.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_mem_energy_calc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_search.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_search_core.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/cb_update_best_index.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/chebyshev.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/comp_corr.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/constants.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/create_augmented_vec.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/decode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/decode_residual.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/decoder_interpolate_lsf.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/do_plc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/energy_inverse.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/enh_upsample.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/enhancer.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/enhancer_interface.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/filtered_cb_vecs.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/frame_classify.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/gain_dequant.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/gain_quant.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/get_cd_vec.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/get_lsp_poly.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/get_sync_seq.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/hp_input.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/hp_output.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/ilbc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/index_conv_dec.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/index_conv_enc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/init_decode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/init_encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/interpolate.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/interpolate_samples.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lpc_encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsf_check.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_dec.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsf_interpolate_to_poly_enc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_lsp.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsf_to_poly.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/lsp_to_lsf.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/my_corr.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/nearest_neighbor.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/pack_bits.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsf.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/poly_to_lsp.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/refiner.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/simple_interpolate_lsf.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/simple_lpc_analysis.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_dequant.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/simple_lsf_quant.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/smooth.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/smooth_out_data.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/sort_sq.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/split_vq.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/state_construct.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/state_search.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/swap_bytes.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/unpack_bits.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/vq3.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/vq4.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/window32_w32.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/xcorr_coef.c)
add_library(WebrtcModulesAudio_CodingIlbc_C OBJECT ${WebrtcModulesAudio_CodingIlbc_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIlbc_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIlbc_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIlbc_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingIlbc_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingIlbc_C WebrtcWebrtc_Common WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcBaseRtc_Base_Approved WebrtcCommon_AudioCommon_Audio)
# End of target WebrtcModulesAudio_CodingIlbc_C

# Start of target WebrtcAudioAudio
set(WebrtcAudioAudio_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/audio/audio_receive_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/audio/audio_send_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/audio/audio_state.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/audio/audio_transport_proxy.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcCallCall_Interfaces>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcAudioAudio STATIC ${WebrtcAudioAudio_SOURCES})
target_compile_options(WebrtcAudioAudio PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcAudioAudio PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcAudioAudio PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcAudioAudio PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcAudioAudio PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/audio)
set_target_properties(WebrtcAudioAudio PROPERTIES OUTPUT_NAME audio)
target_link_libraries(WebrtcAudioAudio WebrtcWebrtc_Common)
target_link_libraries(WebrtcAudioAudio WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcAudioAudio Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcAudioAudio WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcAudioAudio WebrtcApiCall_Api)
target_link_libraries(WebrtcAudioAudio WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory)
target_link_libraries(WebrtcAudioAudio WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcAudioAudio WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcAudioAudio Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcAudioAudio WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcAudioAudio WebrtcBaseRtc_Base)
target_link_libraries(WebrtcAudioAudio WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcAudioAudio WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcAudioAudio WebrtcModulesAudio_DeviceAudio_Device)
target_link_libraries(WebrtcAudioAudio WebrtcModulesAudio_ProcessingAudio_Processing)
target_link_libraries(WebrtcAudioAudio WebrtcModulesBitrate_ControllerBitrate_Controller)
target_link_libraries(WebrtcAudioAudio WebrtcModulesCongestion_ControllerCongestion_Controller)
target_link_libraries(WebrtcAudioAudio WebrtcModulesPacingPacing)
target_link_libraries(WebrtcAudioAudio WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_link_libraries(WebrtcAudioAudio WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcAudioAudio WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcAudioAudio WebrtcVoice_EngineVoice_Engine)
target_include_directories(WebrtcAudioAudio PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcAudioAudio ${JPEG_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcAudioAudio ${RT_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcAudioAudio ${DL_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcAudioAudio ${XEXT_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcAudioAudio ${X11_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcAudioAudio ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcAudioAudio ${XRENDER_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcAudioAudio ${EVENT_LIBRARY})
target_include_directories(WebrtcAudioAudio PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcAudioAudio ${M_LIBRARY})
# End of target WebrtcAudioAudio

# Start of target WebrtcModulesAudio_CodingG722
set(WebrtcModulesAudio_CodingG722_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/audio_decoder_g722.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/audio_encoder_g722.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingG722_C>)
add_library(WebrtcModulesAudio_CodingG722 STATIC ${WebrtcModulesAudio_CodingG722_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingG722 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingG722 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingG722 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingG722 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingG722 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingG722 PROPERTIES OUTPUT_NAME g722)
target_link_libraries(WebrtcModulesAudio_CodingG722 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingG722 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingG722 WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame)
# End of target WebrtcModulesAudio_CodingG722

# Start of target WebrtcModulesAudio_CodingAudio_Network_Adaptor
set(WebrtcModulesAudio_CodingAudio_Network_Adaptor_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/audio_network_adaptor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/audio_network_adaptor_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/bitrate_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/channel_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/controller_manager.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/debug_dump_writer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/dtx_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/event_log_writer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/fec_controller_plr_based.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/fec_controller_rplr_based.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/audio_network_adaptor/frame_length_controller.cc)
add_library(WebrtcModulesAudio_CodingAudio_Network_Adaptor STATIC ${WebrtcModulesAudio_CodingAudio_Network_Adaptor_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingAudio_Network_Adaptor PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingAudio_Network_Adaptor PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingAudio_Network_Adaptor PROPERTIES OUTPUT_NAME audio_network_adaptor)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Network_Adaptor PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Network_Adaptor ${EVENT_LIBRARY})
# End of target WebrtcModulesAudio_CodingAudio_Network_Adaptor

# Start of target WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2
# set(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/differ_vector_sse2.cc)
# add_library(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 STATIC ${WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2_SOURCES})
# target_compile_options(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PRIVATE  "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
# target_compile_definitions(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/desktop_capture)
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2 PROPERTIES OUTPUT_NAME desktop_capture_differ_sse2)
# End of target WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2

# Start of target WebrtcModulesAudio_CodingWebrtc_Opus
set(WebrtcModulesAudio_CodingWebrtc_Opus_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/opus/audio_decoder_opus.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/opus/audio_encoder_opus.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingWebrtc_Opus_C>)
add_library(WebrtcModulesAudio_CodingWebrtc_Opus STATIC ${WebrtcModulesAudio_CodingWebrtc_Opus_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED WEBRTC_OPUS_VARIABLE_COMPLEXITY=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingWebrtc_Opus PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingWebrtc_Opus PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingWebrtc_Opus PROPERTIES OUTPUT_NAME webrtc_opus)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus Third_PartyOpusOpus)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcBaseRtc_Numerics)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcModulesAudio_CodingAudio_Network_Adaptor)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus Third_PartyOpusOpus)
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingWebrtc_Opus ${EVENT_LIBRARY})
# End of target WebrtcModulesAudio_CodingWebrtc_Opus

# Start of target WebrtcPcRtc_Pc_Base
set(WebrtcPcRtc_Pc_Base_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/audiomonitor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/bundlefilter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/channel.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/channelmanager.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/currentspeakermonitor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/externalhmac.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/mediamonitor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/mediasession.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/rtcpmuxfilter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/rtptransport.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/srtpfilter.cc
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcPcRtc_Pc_Base STATIC ${WebrtcPcRtc_Pc_Base_SOURCES})
target_compile_options(WebrtcPcRtc_Pc_Base PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>")
target_compile_definitions(WebrtcPcRtc_Pc_Base PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX HAVE_SCTP WEBRTC_BUILD_LIBEVENT FEATURE_ENABLE_VOICEMAIL PACKAGE_STRING="libsrtp2 2.0.0-pre" PACKAGE_VERSION="2.0.0-pre" HAVE_CONFIG_H OPENSSL HAVE_STDLIB_H HAVE_STRING_H HAVE_STDINT_H HAVE_INTTYPES_H HAVE_INT16_T HAVE_INT32_T HAVE_INT8_T HAVE_UINT16_T HAVE_UINT32_T HAVE_UINT64_T HAVE_UINT8_T HAVE_ARPA_INET_H HAVE_NETINET_IN_H HAVE_SYS_TYPES_H HAVE_UNISTD_H)
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/config/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcPcRtc_Pc_Base PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcPcRtc_Pc_Base PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/pc)
set_target_properties(WebrtcPcRtc_Pc_Base PROPERTIES OUTPUT_NAME rtc_pc_base)
target_link_libraries(WebrtcPcRtc_Pc_Base Third_PartyLibsrtpLibsrtp)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcWebrtc_Common)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcApiCall_Api)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcBaseRtc_Base)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcMediaRtc_Data)
target_link_libraries(WebrtcPcRtc_Pc_Base Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcP2PLibstunprober)
target_link_libraries(WebrtcPcRtc_Pc_Base WebrtcP2PRtc_P2P)
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcPcRtc_Pc_Base ${JPEG_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcPcRtc_Pc_Base ${RT_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcPcRtc_Pc_Base ${DL_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcPcRtc_Pc_Base ${XEXT_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcPcRtc_Pc_Base ${X11_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcPcRtc_Pc_Base ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcPcRtc_Pc_Base ${XRENDER_LIBRARY})
target_include_directories(WebrtcPcRtc_Pc_Base PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcPcRtc_Pc_Base ${EVENT_LIBRARY})
# End of target WebrtcPcRtc_Pc_Base

# Start of target WebrtcCommon_AudioCommon_Audio
set(WebrtcCommon_AudioCommon_Audio_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/audio_converter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/audio_ring_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/audio_util.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/blocker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/channel_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/fir_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/lapped_transform.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/real_fourier.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/real_fourier_ooura.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/push_resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/push_sinc_resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/sinc_resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/smoothing_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/sparse_fir_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/vad.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/wav_file.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/wav_header.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/window_generator.cc
    $<TARGET_OBJECTS:WebrtcCommon_AudioCommon_Audio_C>
    $<TARGET_OBJECTS:WebrtcCommon_AudioCommon_Audio_Cc>)
add_library(WebrtcCommon_AudioCommon_Audio STATIC ${WebrtcCommon_AudioCommon_Audio_SOURCES})
target_compile_options(WebrtcCommon_AudioCommon_Audio PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCommon_AudioCommon_Audio PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcCommon_AudioCommon_Audio PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCommon_AudioCommon_Audio PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcCommon_AudioCommon_Audio PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/common_audio)
set_target_properties(WebrtcCommon_AudioCommon_Audio PROPERTIES OUTPUT_NAME common_audio)
target_link_libraries(WebrtcCommon_AudioCommon_Audio WebrtcWebrtc_Common)
target_link_libraries(WebrtcCommon_AudioCommon_Audio WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcCommon_AudioCommon_Audio WebrtcSystem_WrappersSystem_Wrappers)
# target_link_libraries(WebrtcCommon_AudioCommon_Audio WebrtcCommon_AudioCommon_Audio_Sse2)
target_include_directories(WebrtcCommon_AudioCommon_Audio PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_AudioCommon_Audio ${RT_LIBRARY})
# End of target WebrtcCommon_AudioCommon_Audio

# Start of target WebrtcModulesAudio_CodingWebrtc_Opus_C
set(WebrtcModulesAudio_CodingWebrtc_Opus_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/opus/opus_interface.c)
add_library(WebrtcModulesAudio_CodingWebrtc_Opus_C OBJECT ${WebrtcModulesAudio_CodingWebrtc_Opus_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingWebrtc_Opus_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingWebrtc_Opus_C PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingWebrtc_Opus_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingWebrtc_Opus_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingWebrtc_Opus_C Third_PartyOpusOpus WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_CodingWebrtc_Opus_C

# Start of target WebrtcModulesAudio_MixerAudio_Mixer
add_custom_target(WebrtcModulesAudio_MixerAudio_Mixer)
add_dependencies(WebrtcModulesAudio_MixerAudio_Mixer WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcModulesAudio_MixerAudio_Mixer_Impl)
# End of target WebrtcModulesAudio_MixerAudio_Mixer

# Start of target WebrtcModulesDesktop_CapturePrimitives
set(WebrtcModulesDesktop_CapturePrimitives_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_frame.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_geometry.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_region.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/shared_desktop_frame.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/shared_memory.cc)
add_library(WebrtcModulesDesktop_CapturePrimitives STATIC ${WebrtcModulesDesktop_CapturePrimitives_SOURCES})
target_compile_options(WebrtcModulesDesktop_CapturePrimitives PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesDesktop_CapturePrimitives PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesDesktop_CapturePrimitives PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesDesktop_CapturePrimitives PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/desktop_capture)
set_target_properties(WebrtcModulesDesktop_CapturePrimitives PROPERTIES OUTPUT_NAME primitives)
target_link_libraries(WebrtcModulesDesktop_CapturePrimitives WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesDesktop_CapturePrimitives WebrtcBaseRtc_Base)
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${DL_LIBRARY})
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${RT_LIBRARY})
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${X11_LIBRARY})
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesDesktop_CapturePrimitives PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesDesktop_CapturePrimitives ${XRENDER_LIBRARY})
# End of target WebrtcModulesDesktop_CapturePrimitives

# Start of target WebrtcSystem_WrappersSystem_Wrappers_Default
add_custom_target(WebrtcSystem_WrappersSystem_Wrappers_Default)
add_dependencies(WebrtcSystem_WrappersSystem_Wrappers_Default WebrtcSystem_WrappersField_Trial_Default WebrtcSystem_WrappersMetrics_Default WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcSystem_WrappersSystem_Wrappers_Default

# Start of target WebrtcApiVideo_Frame_Api
set(WebrtcApiVideo_Frame_Api_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/video/i420_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/video/video_frame.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/video/video_frame_buffer.cc)
add_library(WebrtcApiVideo_Frame_Api OBJECT ${WebrtcApiVideo_Frame_Api_SOURCES})
target_compile_options(WebrtcApiVideo_Frame_Api PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiVideo_Frame_Api PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiVideo_Frame_Api PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/)
set_target_properties(WebrtcApiVideo_Frame_Api PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcApiVideo_Frame_Api Third_PartyLibyuvLibyuv WebrtcBaseRtc_Base_Approved WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcApiVideo_Frame_Api

# Start of target WebrtcBaseRtc_Base_Approved
set(WebrtcBaseRtc_Base_Approved_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/base64.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/bitbuffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/bufferqueue.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/bytebuffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/checks.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/copyonwritebuffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/criticalsection.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/event.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/event_tracer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/file.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/flags.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/location.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/optional.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/pathutils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/platform_file.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/platform_thread.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/race_checker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/random.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/rate_limiter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/rate_statistics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/ratetracker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/string_to_number.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/stringencode.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/stringutils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/thread_checker_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/timestampaligner.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/timeutils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/file_posix.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/logging.cc)
add_library(WebrtcBaseRtc_Base_Approved STATIC ${WebrtcBaseRtc_Base_Approved_SOURCES})
target_compile_options(WebrtcBaseRtc_Base_Approved PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseRtc_Base_Approved PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcBaseRtc_Base_Approved PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseRtc_Base_Approved PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcBaseRtc_Base_Approved PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseRtc_Base_Approved PROPERTIES OUTPUT_NAME rtc_base_approved)
target_link_libraries(WebrtcBaseRtc_Base_Approved WebrtcWebrtc_Common)
# End of target WebrtcBaseRtc_Base_Approved

# Start of target WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory
set(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec_dump/null_aec_dump_factory.cc)
add_library(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory OBJECT ${WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory_SOURCES})
target_compile_options(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory WebrtcModulesAudio_ProcessingAec_Dump_Interface WebrtcModulesAudio_ProcessingAec_DumpAec_Dump)
# End of target WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory

# Start of target WebrtcWebrtc_Common
set(WebrtcWebrtc_Common_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_types.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/config.cc)
add_library(WebrtcWebrtc_Common STATIC ${WebrtcWebrtc_Common_SOURCES})
target_compile_options(WebrtcWebrtc_Common PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcWebrtc_Common PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcWebrtc_Common PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcWebrtc_Common PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcWebrtc_Common PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc)
set_target_properties(WebrtcWebrtc_Common PROPERTIES OUTPUT_NAME webrtc_common)
# End of target WebrtcWebrtc_Common

# Start of target WebrtcLoggingRtc_Event_Log_Impl
set(WebrtcLoggingRtc_Event_Log_Impl_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/logging/rtc_event_log/rtc_event_log.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/logging/rtc_event_log/rtc_event_log_factory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/logging/rtc_event_log/rtc_event_log_helper_thread.cc)
add_library(WebrtcLoggingRtc_Event_Log_Impl STATIC ${WebrtcLoggingRtc_Event_Log_Impl_SOURCES})
target_compile_options(WebrtcLoggingRtc_Event_Log_Impl PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcLoggingRtc_Event_Log_Impl PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcLoggingRtc_Event_Log_Impl PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcLoggingRtc_Event_Log_Impl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/logging)
set_target_properties(WebrtcLoggingRtc_Event_Log_Impl PROPERTIES OUTPUT_NAME rtc_event_log_impl)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcWebrtc_Common)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcModulesAudio_CodingAudio_Network_Adaptor)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${JPEG_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${RT_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${DL_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${XEXT_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${X11_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${XRENDER_LIBRARY})
target_include_directories(WebrtcLoggingRtc_Event_Log_Impl PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcLoggingRtc_Event_Log_Impl ${EVENT_LIBRARY})
# End of target WebrtcLoggingRtc_Event_Log_Impl

# Start of target WebrtcVideo_Stream_Api
add_custom_target(WebrtcVideo_Stream_Api)
add_dependencies(WebrtcVideo_Stream_Api WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved WebrtcCommon_VideoCommon_Video)
# End of target WebrtcVideo_Stream_Api

# Start of target WebrtcCallCall_Interfaces
set(WebrtcCallCall_Interfaces_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/call/audio_send_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/call/syncable.cc)
add_library(WebrtcCallCall_Interfaces OBJECT ${WebrtcCallCall_Interfaces_SOURCES})
target_compile_options(WebrtcCallCall_Interfaces PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCallCall_Interfaces PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcCallCall_Interfaces PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCallCall_Interfaces PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcCallCall_Interfaces WebrtcVideo_Stream_Api WebrtcWebrtc_Common WebrtcApiLibjingle_Peerconnection_Api WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcBaseRtc_Base WebrtcBaseRtc_Base_Approved)
# End of target WebrtcCallCall_Interfaces


# Start of target WebrtcModulesVideo_ProcessingVideo_Processing
set(WebrtcModulesVideo_ProcessingVideo_Processing_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/util/denoiser_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/util/denoiser_filter_c.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/util/noise_estimation.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/util/skin_detection.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/video_denoiser.cc)
add_library(WebrtcModulesVideo_ProcessingVideo_Processing STATIC ${WebrtcModulesVideo_ProcessingVideo_Processing_SOURCES})
target_compile_options(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_processing)
set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing PROPERTIES OUTPUT_NAME video_processing)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcSystem_WrappersSystem_Wrappers)
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing WebrtcModulesVideo_ProcessingVideo_Processing_Sse2)
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_ProcessingVideo_Processing

# Start of target WebrtcModulesAudio_CodingG711_C
set(WebrtcModulesAudio_CodingG711_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/g711.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/g711_interface.c)
add_library(WebrtcModulesAudio_CodingG711_C OBJECT ${WebrtcModulesAudio_CodingG711_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingG711_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingG711_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingG711_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingG711_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingG711_C WebrtcWebrtc_Common)
# End of target WebrtcModulesAudio_CodingG711_C

# Start of target WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl
set(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/linux/device_info_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/linux/video_capture_linux.cc)
add_library(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl STATIC ${WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl_SOURCES})
target_compile_options(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_capture)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PROPERTIES OUTPUT_NAME video_capture_internal_impl)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcModulesVideo_CaptureVideo_Capture_Module)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl

# Start of target WebrtcModulesAudio_CodingIsac_C
set(WebrtcModulesAudio_CodingIsac_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines_hist.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/arith_routines_logist.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/bandwidth_estimator.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/crc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/decode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/decode_bwe.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/encode_lpc_swb.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/entropy_coding.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/fft.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/filter_functions.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/filterbank_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/filterbanks.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/intialize.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/isac.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lattice.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_analysis.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_gain_swb_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb12_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_shape_swb16_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/lpc_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_estimator.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_filter.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_gain_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/pitch_lag_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/spectrum_ar_model_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/transform.c)
add_library(WebrtcModulesAudio_CodingIsac_C STATIC ${WebrtcModulesAudio_CodingIsac_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingIsac_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingIsac_C PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingIsac_C PROPERTIES OUTPUT_NAME isac_c)
target_link_libraries(WebrtcModulesAudio_CodingIsac_C WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingIsac_C WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingIsac_C WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingIsac_C WebrtcModulesAudio_CodingIsac_Common)
target_include_directories(WebrtcModulesAudio_CodingIsac_C PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIsac_C ${M_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingIsac_C PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIsac_C ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingIsac_C

# Start of target WebrtcVoice_EngineAudio_Level
set(WebrtcVoice_EngineAudio_Level_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/audio_level.cc)
add_library(WebrtcVoice_EngineAudio_Level STATIC ${WebrtcVoice_EngineAudio_Level_SOURCES})
target_compile_options(WebrtcVoice_EngineAudio_Level PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVoice_EngineAudio_Level PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcVoice_EngineAudio_Level PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVoice_EngineAudio_Level PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVoice_EngineAudio_Level PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/voice_engine)
set_target_properties(WebrtcVoice_EngineAudio_Level PROPERTIES OUTPUT_NAME audio_level)
target_link_libraries(WebrtcVoice_EngineAudio_Level WebrtcWebrtc_Common)
target_link_libraries(WebrtcVoice_EngineAudio_Level WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVoice_EngineAudio_Level WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcVoice_EngineAudio_Level Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineAudio_Level WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcVoice_EngineAudio_Level PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Level ${RT_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Level PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Level ${JPEG_LIBRARY})
# End of target WebrtcVoice_EngineAudio_Level

# Start of target WebrtcModulesAudio_CodingG711
set(WebrtcModulesAudio_CodingG711_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/audio_decoder_pcm.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/audio_encoder_pcm.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingG711_C>)
add_library(WebrtcModulesAudio_CodingG711 STATIC ${WebrtcModulesAudio_CodingG711_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingG711 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingG711 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingG711 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingG711 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingG711 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingG711 PROPERTIES OUTPUT_NAME g711)
target_link_libraries(WebrtcModulesAudio_CodingG711 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingG711 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingG711 WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame)
# End of target WebrtcModulesAudio_CodingG711

# Start of target Third_PartyGflagsGflags
set(Third_PartyGflagsGflags_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/src/src/gflags.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/src/src/gflags_completions.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/src/src/gflags_reporting.cc)
add_library(Third_PartyGflagsGflags OBJECT ${Third_PartyGflagsGflags_SOURCES})
target_compile_options(Third_PartyGflagsGflags PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "-UHAVE_CONFIG_H")
target_compile_definitions(Third_PartyGflagsGflags PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 GFLAGS_DLL_DECL= GFLAGS_DLL_DECLARE_FLAG= GFLAGS_DLL_DEFINE_FLAG=)
target_include_directories(Third_PartyGflagsGflags PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/gen/posix/include/gflags/ ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/src/src/ ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/gen/posix/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/gflags/gen/posix/include/private/)
set_target_properties(Third_PartyGflagsGflags PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
# End of target Third_PartyGflagsGflags

# Start of target WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory
set(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/builtin_audio_decoder_factory.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory STATIC ${WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory_SOURCES})
target_compile_options(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/api/audio_codecs)
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PROPERTIES OUTPUT_NAME builtin_audio_decoder_factory)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal)
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${RT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${JPEG_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${DL_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${XEXT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${X11_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${XRENDER_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${EVENT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory ${M_LIBRARY})
# End of target WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory

# Start of target WebrtcToolsReference_Less_Video_Analysis_Lib
set(WebrtcToolsReference_Less_Video_Analysis_Lib_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/frame_analyzer/reference_less_video_analysis_lib.cc)
add_library(WebrtcToolsReference_Less_Video_Analysis_Lib STATIC ${WebrtcToolsReference_Less_Video_Analysis_Lib_SOURCES})
target_compile_options(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcToolsReference_Less_Video_Analysis_Lib PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcToolsReference_Less_Video_Analysis_Lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/tools)
set_target_properties(WebrtcToolsReference_Less_Video_Analysis_Lib PROPERTIES OUTPUT_NAME reference_less_video_analysis_lib)
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib WebrtcToolsVideo_Quality_Analysis)
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${JPEG_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${RT_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${DL_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${XEXT_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${X11_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${XRENDER_LIBRARY})
target_include_directories(WebrtcToolsReference_Less_Video_Analysis_Lib PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsReference_Less_Video_Analysis_Lib ${EVENT_LIBRARY})
# End of target WebrtcToolsReference_Less_Video_Analysis_Lib

# Start of target WebrtcModulesAudio_MixerAudio_Mixer_Impl
set(WebrtcModulesAudio_MixerAudio_Mixer_Impl_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_mixer/audio_mixer_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_mixer/default_output_rate_calculator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_mixer/frame_combiner.cc)
add_library(WebrtcModulesAudio_MixerAudio_Mixer_Impl STATIC ${WebrtcModulesAudio_MixerAudio_Mixer_Impl_SOURCES})
target_compile_options(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_MixerAudio_Mixer_Impl PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_MixerAudio_Mixer_Impl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_mixer)
set_target_properties(WebrtcModulesAudio_MixerAudio_Mixer_Impl PROPERTIES OUTPUT_NAME audio_mixer_impl)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcModulesAudio_MixerAudio_Frame_Manipulator)
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcModulesAudio_ProcessingAudio_Processing)
target_include_directories(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_MixerAudio_Mixer_Impl PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_MixerAudio_Mixer_Impl ${M_LIBRARY})
# End of target WebrtcModulesAudio_MixerAudio_Mixer_Impl

# Start of target WebrtcModulesAudio_CodingPcm16B_C
set(WebrtcModulesAudio_CodingPcm16B_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/pcm16b.c)
add_library(WebrtcModulesAudio_CodingPcm16B_C OBJECT ${WebrtcModulesAudio_CodingPcm16B_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingPcm16B_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingPcm16B_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingPcm16B_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingPcm16B_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingPcm16B_C WebrtcWebrtc_Common)
# End of target WebrtcModulesAudio_CodingPcm16B_C

# Start of target WebrtcMediaRtc_Audio_Video
set(WebrtcMediaRtc_Audio_Video_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/adm_helpers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/apm_helpers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/internaldecoderfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/internalencoderfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/payload_type_mapper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/simulcast.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/videodecodersoftwarefallbackwrapper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/videoencodersoftwarefallbackwrapper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/webrtcmediaengine.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/webrtcvideocapturer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/webrtcvideocapturerfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/webrtcvideoengine.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/engine/webrtcvoiceengine.cc
    $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAec_DumpNull_Aec_Dump_Factory>
    $<TARGET_OBJECTS:WebrtcApiVideo_Frame_Api>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>
    $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAec_Dump_Interface>)
add_library(WebrtcMediaRtc_Audio_Video STATIC ${WebrtcMediaRtc_Audio_Video_SOURCES})
target_compile_options(WebrtcMediaRtc_Audio_Video PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "-Wno-deprecated-declarations" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcMediaRtc_Audio_Video PRIVATE WEBRTC_INTELLIGIBILITY_ENHANCER=0 WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX HAVE_WEBRTC_VIDEO HAVE_WEBRTC_VOICE WEBRTC_BUILD_LIBEVENT FEATURE_ENABLE_VOICEMAIL HAVE_SCTP)
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcMediaRtc_Audio_Video PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcMediaRtc_Audio_Video PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/media)
set_target_properties(WebrtcMediaRtc_Audio_Video PROPERTIES OUTPUT_NAME rtc_audio_video)
target_link_libraries(WebrtcMediaRtc_Audio_Video Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcWebrtc_Common)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcApiCall_Api)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcMediaRtc_Audio_Video Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcBaseRtc_Base)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcCallCall)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcP2PLibstunprober)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesAudio_CodingRent_A_Codec)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesAudio_DeviceAudio_Device)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesAudio_MixerAudio_Mixer_Impl)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesAudio_ProcessingAudio_Processing)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcMediaRtc_Audio_Video Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CaptureVideo_Capture_Module)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CodingVideo_Coding)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CodingWebrtc_H264)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CodingWebrtc_Vp8)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcModulesVideo_CodingWebrtc_Vp9)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcPcRtc_Pc_Base)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcVideoVideo)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcVoice_EngineVoice_Engine)
target_link_libraries(WebrtcMediaRtc_Audio_Video WebrtcSystem_WrappersMetrics_Default)
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${JPEG_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${RT_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${DL_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Audio_Video ${XEXT_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Audio_Video ${X11_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Audio_Video ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${XRENDER_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${EVENT_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${M_LIBRARY})
target_include_directories(WebrtcMediaRtc_Audio_Video PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Audio_Video ${VPX_LIBRARY})
# End of target WebrtcMediaRtc_Audio_Video

# Start of target WebrtcSystem_WrappersCpu_Features_Linux
set(WebrtcSystem_WrappersCpu_Features_Linux_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/cpu_features_linux.c)
add_library(WebrtcSystem_WrappersCpu_Features_Linux STATIC ${WebrtcSystem_WrappersCpu_Features_Linux_SOURCES})
target_compile_options(WebrtcSystem_WrappersCpu_Features_Linux PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcSystem_WrappersCpu_Features_Linux PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcSystem_WrappersCpu_Features_Linux PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcSystem_WrappersCpu_Features_Linux PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcSystem_WrappersCpu_Features_Linux PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/system_wrappers)
set_target_properties(WebrtcSystem_WrappersCpu_Features_Linux PROPERTIES OUTPUT_NAME cpu_features_linux)
target_link_libraries(WebrtcSystem_WrappersCpu_Features_Linux WebrtcWebrtc_Common)
# End of target WebrtcSystem_WrappersCpu_Features_Linux

# Start of target WebrtcModulesVideo_CodingWebrtc_Vp8
set(WebrtcModulesVideo_CodingWebrtc_Vp8_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp8/default_temporal_layers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp8/screenshare_layers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp8/simulcast_encoder_adapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp8/simulcast_rate_allocator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp8/vp8_impl.cc)
add_library(WebrtcModulesVideo_CodingWebrtc_Vp8 STATIC ${WebrtcModulesVideo_CodingWebrtc_Vp8_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H" "-DWEBRTC_ARCH_ARM")
target_compile_definitions(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp8 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp8 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp8 PROPERTIES OUTPUT_NAME webrtc_vp8)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcBaseSequenced_Task_Checker)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcModulesVideo_CodingVideo_Coding_Utility)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${VPX_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${M_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp8 PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp8 ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CodingWebrtc_Vp8

# Start of target WebrtcModulesVideo_CodingWebrtc_Vp9
set(WebrtcModulesVideo_CodingWebrtc_Vp9_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp9/screenshare_layers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp9/vp9_frame_buffer_pool.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/vp9/vp9_impl.cc)
add_library(WebrtcModulesVideo_CodingWebrtc_Vp9 STATIC ${WebrtcModulesVideo_CodingWebrtc_Vp9_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp9 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp9 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_Vp9 PROPERTIES OUTPUT_NAME webrtc_vp9)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcModulesVideo_CodingVideo_Coding_Utility)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${VPX_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${M_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_Vp9 PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_Vp9 ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CodingWebrtc_Vp9

# Start of target WebrtcModulesAudio_CodingIsac_Fix_C
set(WebrtcModulesAudio_CodingIsac_Fix_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines_hist.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/arith_routines_logist.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/bandwidth_estimator.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/decode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/decode_bwe.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/decode_plc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/entropy_coding.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbank_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/filterbanks.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/filters.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/initialize.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/isacfix.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/lattice_c.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_masking_model.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/lpc_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_estimator.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_estimator_c.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_filter_c.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_gain_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/pitch_lag_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/spectrum_ar_model_tables.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/transform.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/transform_tables.c)
add_library(WebrtcModulesAudio_CodingIsac_Fix_C OBJECT ${WebrtcModulesAudio_CodingIsac_Fix_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac_Fix_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac_Fix_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac_Fix_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/include/)
set_target_properties(WebrtcModulesAudio_CodingIsac_Fix_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingIsac_Fix_C WebrtcWebrtc_Common WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcBaseRtc_Base_Approved WebrtcCommon_AudioCommon_Audio WebrtcModulesAudio_CodingIsac_Common WebrtcModulesAudio_CodingIsac_Fix_Common WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcModulesAudio_CodingIsac_Fix_C

# Start of target WebrtcP2PLibstunprober
set(WebrtcP2PLibstunprober_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/p2p/stunprober/stunprober.cc)
add_library(WebrtcP2PLibstunprober STATIC ${WebrtcP2PLibstunprober_SOURCES})
target_compile_options(WebrtcP2PLibstunprober PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcP2PLibstunprober PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX FEATURE_ENABLE_VOICEMAIL)
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcP2PLibstunprober PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcP2PLibstunprober PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/p2p)
set_target_properties(WebrtcP2PLibstunprober PROPERTIES OUTPUT_NAME stunprober)
target_link_libraries(WebrtcP2PLibstunprober WebrtcWebrtc_Common)
target_link_libraries(WebrtcP2PLibstunprober WebrtcBaseRtc_Base)
target_link_libraries(WebrtcP2PLibstunprober WebrtcP2PRtc_P2P)
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcP2PLibstunprober ${DL_LIBRARY})
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcP2PLibstunprober ${RT_LIBRARY})
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PLibstunprober ${XEXT_LIBRARY})
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PLibstunprober ${X11_LIBRARY})
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcP2PLibstunprober ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcP2PLibstunprober PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcP2PLibstunprober ${XRENDER_LIBRARY})
# End of target WebrtcP2PLibstunprober

# Start of target WebrtcBaseRtc_Task_Queue
set(WebrtcBaseRtc_Task_Queue_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/task_queue_libevent.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/task_queue_posix.cc)
add_library(WebrtcBaseRtc_Task_Queue STATIC ${WebrtcBaseRtc_Task_Queue_SOURCES})
target_compile_options(WebrtcBaseRtc_Task_Queue PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseRtc_Task_Queue PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_BUILD_LIBEVENT WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcBaseRtc_Task_Queue PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseRtc_Task_Queue PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcBaseRtc_Task_Queue PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseRtc_Task_Queue PROPERTIES OUTPUT_NAME rtc_task_queue)
target_link_libraries(WebrtcBaseRtc_Task_Queue WebrtcBaseRtc_Base_Approved)
target_include_directories(WebrtcBaseRtc_Task_Queue PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcBaseRtc_Task_Queue ${EVENT_LIBRARY})
# End of target WebrtcBaseRtc_Task_Queue

# Start of target WebrtcModulesAudio_CodingIsac_Common
set(WebrtcModulesAudio_CodingIsac_Common_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/locked_bandwidth_info.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingIsac_Common STATIC ${WebrtcModulesAudio_CodingIsac_Common_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac_Common PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac_Common PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac_Common PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingIsac_Common PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingIsac_Common PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingIsac_Common PROPERTIES OUTPUT_NAME isac_common)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Common WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingIsac_Common WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_CodingIsac_Common


# Start of target WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory
set(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/builtin_audio_encoder_factory.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory STATIC ${WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory_SOURCES})
target_compile_options(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/api/audio_codecs)
set_target_properties(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PROPERTIES OUTPUT_NAME builtin_audio_encoder_factory)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal)
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${RT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${JPEG_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${DL_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${XEXT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${X11_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${XRENDER_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${EVENT_LIBRARY})
target_include_directories(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory ${M_LIBRARY})
# End of target WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory

# Start of target Third_PartyLibvpxLibvpx_Shim
add_custom_target(Third_PartyLibvpxLibvpx_Shim)
add_dependencies(Third_PartyLibvpxLibvpx_Shim Third_PartyLibvpxGen_Libvpx_Shim)
# End of target Third_PartyLibvpxLibvpx_Shim

# Start of target WebrtcBaseBase
add_custom_target(WebrtcBaseBase)
add_dependencies(WebrtcBaseBase WebrtcBaseRtc_Base WebrtcBaseRtc_Base_Approved WebrtcBaseRtc_Task_Queue WebrtcBaseSequenced_Task_Checker WebrtcBaseWeak_Ptr)
# End of target WebrtcBaseBase

# Start of target WebrtcVoice_EngineVoice_Engine
set(WebrtcVoice_EngineVoice_Engine_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/channel.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/channel_manager.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/channel_proxy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/output_mixer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/shared_data.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/statistics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/transmit_mixer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/transport_feedback_packet_loss_tracker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/utility.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voe_base_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voe_codec_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voe_file_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voe_network_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voe_rtp_rtcp_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/voice_engine_impl.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcVoice_EngineVoice_Engine STATIC ${WebrtcVoice_EngineVoice_Engine_SOURCES})
target_compile_options(WebrtcVoice_EngineVoice_Engine PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVoice_EngineVoice_Engine PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_conference_mixer/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVoice_EngineVoice_Engine PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVoice_EngineVoice_Engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/voice_engine)
set_target_properties(WebrtcVoice_EngineVoice_Engine PROPERTIES OUTPUT_NAME voice_engine)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcWebrtc_Common)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVoice_EngineVoice_Engine Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcApiCall_Api)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcVoice_EngineVoice_Engine Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_CodingAudio_Coding)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_CodingAudio_Format_Conversion)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_CodingRent_A_Codec)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_DeviceAudio_Device)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_ProcessingAudio_Processing)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesBitrate_ControllerBitrate_Controller)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesMedia_FileMedia_File)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesPacingPacing)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcVoice_EngineAudio_Level)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcVoice_EngineFile_Player)
target_link_libraries(WebrtcVoice_EngineVoice_Engine WebrtcVoice_EngineFile_Recorder)
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${RT_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${JPEG_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${DL_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineVoice_Engine ${XEXT_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineVoice_Engine ${X11_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineVoice_Engine ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${XRENDER_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${EVENT_LIBRARY})
target_include_directories(WebrtcVoice_EngineVoice_Engine PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineVoice_Engine ${M_LIBRARY})
# End of target WebrtcVoice_EngineVoice_Engine

# Start of target Third_PartyBoringsslBoringssl_Asm
# set(Third_PartyBoringsslBoringssl_Asm_SOURCES
    # ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/chacha/chacha-x86_64.S
    #  ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-arm/crypto/aes/aesv8-armx32.S
    #  ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-arm/crypto/aes/aes-armv4.S
    #  ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/fipsmodule/aes/asm/aes-armv4.S
    #  ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/chacha/asm/chacha-armv4.S

    #  ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/
    # ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/poly1305/poly1305_arm_asm.S
# )

# set(Third_PartyBoringsslBoringssl_Asm_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/chacha/chacha-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/cipher_extra/aes128gcmsiv-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/cipher_extra/chacha20_poly1305_x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/aes-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/aesni-gcm-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/aesni-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/bsaes-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/ghash-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/md5-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/p256-x86_64-asm.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/rdrand-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/rsaz-avx2.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/sha1-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/sha256-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/sha512-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/vpaes-x86_64.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/x86_64-mont.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/linux-x86_64/crypto/fipsmodule/x86_64-mont5.S
#     ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/curve25519/asm/x25519-asm-x86_64.S)

# add_library(Third_PartyBoringsslBoringssl_Asm OBJECT ${Third_PartyBoringsslBoringssl_Asm_SOURCES})
# target_compile_options(Third_PartyBoringsslBoringssl_Asm PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "-UHAVE_CONFIG_H")
# target_compile_definitions(Third_PartyBoringsslBoringssl_Asm PRIVATE BORINGSSL_CLANG_SUPPORTS_DOT_ARCH USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1)
# target_include_directories(Third_PartyBoringsslBoringssl_Asm PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/)
# set_target_properties(Third_PartyBoringsslBoringssl_Asm PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# End of target Third_PartyBoringsslBoringssl_Asm

# Start of target WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory
add_custom_target(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory)
add_dependencies(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory)
# End of target WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory


# Start of target WebrtcModulesModules
add_custom_target(WebrtcModulesModules)
add_dependencies(WebrtcModulesModules WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer
    WebrtcModulesAudio_DeviceAudio_Device
    WebrtcModulesAudio_MixerAudio_Mixer WebrtcModulesAudio_ProcessingAudio_Processing WebrtcModulesBitrate_ControllerBitrate_Controller WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesMedia_FileMedia_File WebrtcModulesPacingPacing WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcModulesUtilityUtility WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_ProcessingVideo_Processing)
# End of target WebrtcModulesModules

# Start of target WebrtcPcCreate_Pc_Factory
set(WebrtcPcCreate_Pc_Factory_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/createpeerconnectionfactory.cc)
add_library(WebrtcPcCreate_Pc_Factory OBJECT ${WebrtcPcCreate_Pc_Factory_SOURCES})
target_compile_options(WebrtcPcCreate_Pc_Factory PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcPcCreate_Pc_Factory PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_WEBRTC_VIDEO HAVE_WEBRTC_VOICE)
target_include_directories(WebrtcPcCreate_Pc_Factory PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcPcCreate_Pc_Factory PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcPcCreate_Pc_Factory WebrtcApiLibjingle_Peerconnection_Api WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory WebrtcBaseRtc_Base WebrtcBaseRtc_Base_Approved WebrtcCallCall WebrtcCallCall_Interfaces WebrtcLoggingRtc_Event_Log_Api WebrtcMediaRtc_Audio_Video
    WebrtcModulesAudio_DeviceAudio_Device
    )
# End of target WebrtcPcCreate_Pc_Factory

# Start of target WebrtcModulesAudio_ProcessingAudio_Processing
set(WebrtcModulesAudio_ProcessingAudio_Processing_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec/aec_core.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec/aec_resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec/echo_cancellation.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/adaptive_fir_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/aec3_common.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/aec3_fft.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/aec_state.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/block_framer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/block_processor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/block_processor_metrics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/cascaded_biquad_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/comfort_noise_generator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/decimator_by_4.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/downsampled_render_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/echo_canceller3.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/echo_path_delay_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/echo_path_variability.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/echo_remover.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/echo_remover_metrics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/erl_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/erle_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/frame_blocker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/main_filter_update_gain.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/matched_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/matched_filter_lag_aggregator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/output_selector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/render_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/render_delay_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/render_delay_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/render_delay_controller_metrics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/render_signal_analyzer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/residual_echo_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/shadow_filter_update_gain.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/subtractor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/suppression_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec3/suppression_gain.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aecm/aecm_core.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aecm/echo_control_mobile.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/agc.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/agc_manager_direct.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/loudness_histogram.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc/utility.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc2/digital_gain_applier.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/agc2/gain_controller2.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/audio_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/audio_processing_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/beamformer/array_util.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/beamformer/covariance_matrix_generator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/beamformer/nonlinear_beamformer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_cancellation_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_control_mobile_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_detector/circular_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_detector/mean_variance_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_detector/moving_max.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/echo_detector/normalized_covariance_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/gain_control_for_experimental_agc.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/gain_control_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/include/audio_processing.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/include/config.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/biquad_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/down_sampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/gain_applier.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/gain_selector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/level_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/noise_level_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/noise_spectrum_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/peak_level_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/saturating_gain_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_controller/signal_classifier.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/level_estimator_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/logging/apm_data_dumper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/low_cut_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/noise_suppression_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/residual_echo_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/rms_level.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/splitting_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/three_band_filter_bank.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/transient/moving_moments.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/transient/transient_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/transient/transient_suppressor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/transient/wpd_node.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/transient/wpd_tree.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/typing_detection.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/utility/block_mean_calculator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/utility/delay_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/utility/delay_estimator_wrapper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/utility/ooura_fft.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/gmm.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/pitch_based_vad.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/pitch_internal.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/pole_zero_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/standalone_vad.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/vad_audio_proc.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/vad_circular_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/vad/voice_activity_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/voice_detection_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aecm/aecm_core_c.cc
    $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAec_Dump_Interface>
    $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAudio_Processing_C>)
add_library(WebrtcModulesAudio_ProcessingAudio_Processing STATIC ${WebrtcModulesAudio_ProcessingAudio_Processing_SOURCES})
target_compile_options(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE WEBRTC_APM_DEBUG_DUMP=0 WEBRTC_INTELLIGIBILITY_ENHANCER=0 WEBRTC_NS_FLOAT USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_processing)
set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing PROPERTIES OUTPUT_NAME audio_processing)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcCommon_AudioCommon_Audio)
# target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing WebrtcModulesAudio_ProcessingAudio_Processing_Sse2)
target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_ProcessingAudio_Processing ${M_LIBRARY})
# End of target WebrtcModulesAudio_ProcessingAudio_Processing

# Start of target WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer
set(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_conference_mixer/source/audio_conference_mixer_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_conference_mixer/source/audio_frame_manipulator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_conference_mixer/source/time_scheduler.cc)
add_library(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer STATIC ${WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer_SOURCES})
target_compile_options(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_conference_mixer/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_conference_mixer)
set_target_properties(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PROPERTIES OUTPUT_NAME audio_conference_mixer)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer WebrtcModulesAudio_ProcessingAudio_Processing)
target_include_directories(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer ${M_LIBRARY})
# End of target WebrtcModulesAudio_Conference_MixerAudio_Conference_Mixer

# Start of target WebrtcModulesRtp_RtcpRtp_Rtcp
set(WebrtcModulesRtp_RtcpRtp_Rtcp_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/dtmf_queue.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/flexfec_header_reader_writer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/flexfec_receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/flexfec_sender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/forward_error_correction_internal.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/packet_loss_stats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/playout_delay_oracle.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/receive_statistics_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/remote_ntp_time_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_nack_stats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/app.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/bye.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/common_header.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/compound_packet.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/dlrr.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/extended_jitter_report.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/extended_reports.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/fir.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/nack.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/pli.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/psfb.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/rapid_resync_request.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/receiver_report.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/remb.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/report_block.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/rrtr.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/rtpfb.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/sdes.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/sender_report.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/target_bitrate.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/tmmb_item.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/tmmbn.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/tmmbr.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/transport_feedback.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_packet/voip_metric.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtcp_sender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_format.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_format_h264.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_format_video_generic.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_format_vp8.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_format_vp9.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_header_extension_map.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_header_extensions.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_header_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_packet.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_packet_history.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_payload_registry.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_receiver_audio.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_receiver_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_receiver_strategy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_receiver_video.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_rtcp_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_sender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_sender_audio.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_sender_video.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/rtp_utility.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/time_util.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/tmmbr_help.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/ulpfec_generator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/ulpfec_header_reader_writer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/rtp_rtcp/source/ulpfec_receiver_impl.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesRtp_RtcpRtp_Rtcp STATIC ${WebrtcModulesRtp_RtcpRtp_Rtcp_SOURCES})
target_compile_options(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H" "-DWEBRTC_ARCH_ARM")
target_compile_definitions(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE BWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesRtp_RtcpRtp_Rtcp PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesRtp_RtcpRtp_Rtcp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/rtp_rtcp)
set_target_properties(WebrtcModulesRtp_RtcpRtp_Rtcp PROPERTIES OUTPUT_NAME rtp_rtcp)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcBaseSequenced_Task_Checker)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcModulesAudio_CodingAudio_Format_Conversion)
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${RT_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${DL_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${X11_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesRtp_RtcpRtp_Rtcp PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRtp_RtcpRtp_Rtcp ${EVENT_LIBRARY})
# End of target WebrtcModulesRtp_RtcpRtp_Rtcp

# Start of target WebrtcModulesVideo_CodingWebrtc_H264
set(WebrtcModulesVideo_CodingWebrtc_H264_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/h264/h264.cc
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcModulesVideo_CodingWebrtc_H264 STATIC ${WebrtcModulesVideo_CodingWebrtc_H264_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_H264 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingWebrtc_H264 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_H264 PROPERTIES OUTPUT_NAME webrtc_h264)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcBaseRtc_Base)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcP2PLibstunprober)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcModulesVideo_CodingVideo_Coding_Utility)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_H264 PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_H264 ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CodingWebrtc_H264


# Start of target WebrtcBaseRtc_Numerics
set(WebrtcBaseRtc_Numerics_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/numerics/exp_filter.cc)
add_library(WebrtcBaseRtc_Numerics STATIC ${WebrtcBaseRtc_Numerics_SOURCES})
target_compile_options(WebrtcBaseRtc_Numerics PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseRtc_Numerics PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcBaseRtc_Numerics PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseRtc_Numerics PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcBaseRtc_Numerics PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseRtc_Numerics PROPERTIES OUTPUT_NAME rtc_numerics)
target_link_libraries(WebrtcBaseRtc_Numerics WebrtcBaseRtc_Base_Approved)
# End of target WebrtcBaseRtc_Numerics

# Start of target WebrtcCommon_AudioCommon_Audio_C
set(WebrtcCommon_AudioCommon_Audio_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/fft4g.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/ring_buffer.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/auto_corr_to_refl_coef.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/auto_correlation.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/copy_set_operations.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/cross_correlation.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/division_operations.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/downsample_fast.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/energy.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/filter_ar.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/filter_ma_fast_q12.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/get_hanning_window.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/get_scaling_square.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/ilbc_specific_functions.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/levinson_durbin.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/lpc_to_refl_coef.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/min_max_operations.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/randomization_functions.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/real_fft.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/refl_coef_to_lpc.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/resample.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/resample_48khz.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/resample_by_2.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/resample_by_2_internal.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/resample_fractional.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/spl_init.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/spl_inl.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/spl_sqrt.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/splitting_filter.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/sqrt_of_one_minus_x_squared.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/vector_scaling_operations.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/vad_core.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/vad_filterbank.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/vad_gmm.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/vad_sp.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/webrtc_vad.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/complex_fft.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/complex_bit_reverse.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/filter_ar_fast_q12.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/spl_sqrt_floor.c)
add_library(WebrtcCommon_AudioCommon_Audio_C OBJECT ${WebrtcCommon_AudioCommon_Audio_C_SOURCES})
target_compile_options(WebrtcCommon_AudioCommon_Audio_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCommon_AudioCommon_Audio_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcCommon_AudioCommon_Audio_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCommon_AudioCommon_Audio_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcCommon_AudioCommon_Audio_C WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved WebrtcCommon_AudioCommon_Audio_Cc WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcCommon_AudioCommon_Audio_C

# Start of target WebrtcCommon_AudioCommon_Audio_Cc
set(WebrtcCommon_AudioCommon_Audio_Cc_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/dot_product_with_scale.cc)
add_library(WebrtcCommon_AudioCommon_Audio_Cc OBJECT ${WebrtcCommon_AudioCommon_Audio_Cc_SOURCES})
target_compile_options(WebrtcCommon_AudioCommon_Audio_Cc PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCommon_AudioCommon_Audio_Cc PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcCommon_AudioCommon_Audio_Cc PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCommon_AudioCommon_Audio_Cc PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcCommon_AudioCommon_Audio_Cc WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved WebrtcSystem_WrappersSystem_Wrappers)
# End of target WebrtcCommon_AudioCommon_Audio_Cc

# Start of target WebrtcApiAudio_CodecsG722Audio_Decoder_G722
set(WebrtcApiAudio_CodecsG722Audio_Decoder_G722_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/g722/audio_decoder_g722.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 STATIC ${WebrtcApiAudio_CodecsG722Audio_Decoder_G722_SOURCES})
target_compile_options(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/api/audio_codecs/g722)
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 PROPERTIES OUTPUT_NAME audio_decoder_g722)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Decoder_G722 WebrtcModulesAudio_CodingG722)
# End of target WebrtcApiAudio_CodecsG722Audio_Decoder_G722

# Start of target WebrtcModulesAudio_CodingNeteq
set(WebrtcModulesAudio_CodingNeteq_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/accelerate.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/audio_decoder_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/audio_multi_vector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/audio_vector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/background_noise.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/buffer_level_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/comfort_noise.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/cross_correlation.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/decision_logic.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/decision_logic_fax.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/decision_logic_normal.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/decoder_database.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/delay_manager.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/delay_peak_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/dsp_helper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/dtmf_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/dtmf_tone_generator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/expand.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/merge.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/nack_tracker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/neteq.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/neteq_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/normal.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/packet.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/packet_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/post_decode_vad.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/preemptive_expand.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/random_vector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/red_payload_splitter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/rtcp.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/statistics_calculator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/sync_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/tick_timer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/time_stretch.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/timestamp_scaler.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingNeteq_Decoder_Enum>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingNeteq STATIC ${WebrtcModulesAudio_CodingNeteq_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingNeteq PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingNeteq PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingNeteq PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingNeteq PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingNeteq PROPERTIES OUTPUT_NAME neteq)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingNeteq Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_CodingNeteq Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingG722)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingIlbc)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingIsac_Fix)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingPcm16B)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingWebrtc_Opus)
target_link_libraries(WebrtcModulesAudio_CodingNeteq WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingNeteq ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingNeteq ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingNeteq ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingNeteq PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingNeteq ${M_LIBRARY})
# End of target WebrtcModulesAudio_CodingNeteq

# Start of target WebrtcModulesAudio_DeviceAudio_Device
set(WebrtcModulesAudio_DeviceAudio_Device_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/audio_device_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/audio_device_generic.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/audio_device_dummy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/file_audio_device.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/fine_audio_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/audio_device_data_observer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/audio_device_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/alsasymboltable_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/audio_device_alsa_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/audio_mixer_manager_alsa_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/latebindingsymboltable_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/audio_device_pulse_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/audio_mixer_manager_pulse_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/pulseaudiosymboltable_linux.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/file_audio_device_factory.cc)
add_library(WebrtcModulesAudio_DeviceAudio_Device STATIC ${WebrtcModulesAudio_DeviceAudio_Device_SOURCES})
target_compile_options(WebrtcModulesAudio_DeviceAudio_Device PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_DeviceAudio_Device PRIVATE
    LINUX_ALSA
    LINUX_PULSE
    USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1
    # USE_X11=1
    FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/dummy/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_device/linux/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_DeviceAudio_Device PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_DeviceAudio_Device PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_device)
set_target_properties(WebrtcModulesAudio_DeviceAudio_Device PROPERTIES OUTPUT_NAME audio_device)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_DeviceAudio_Device PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_DeviceAudio_Device ${EVENT_LIBRARY})
# End of target WebrtcModulesAudio_DeviceAudio_Device

# Start of target WebrtcModulesAudio_CodingPcm16B
set(WebrtcModulesAudio_CodingPcm16B_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/audio_decoder_pcm16b.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/audio_encoder_pcm16b.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingPcm16B_C>)
add_library(WebrtcModulesAudio_CodingPcm16B STATIC ${WebrtcModulesAudio_CodingPcm16B_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingPcm16B PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingPcm16B PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingPcm16B PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingPcm16B PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingPcm16B PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingPcm16B PROPERTIES OUTPUT_NAME pcm16b)
target_link_libraries(WebrtcModulesAudio_CodingPcm16B WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingPcm16B WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingPcm16B WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingPcm16B WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame)
# End of target WebrtcModulesAudio_CodingPcm16B

# Start of target WebrtcModulesVideo_ProcessingVideo_Processing_Sse2
# set(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_processing/util/denoiser_filter_sse2.cc)
# add_library(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 STATIC ${WebrtcModulesVideo_ProcessingVideo_Processing_Sse2_SOURCES})
# target_compile_options(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PRIVATE  "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
# target_compile_definitions(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
# target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
# set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_processing)
# set_target_properties(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PROPERTIES OUTPUT_NAME video_processing_sse2)
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 WebrtcBaseRtc_Base_Approved)
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 WebrtcWebrtc_Common)
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 Third_PartyLibyuvLibyuv_Internal)
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 WebrtcSystem_WrappersSystem_Wrappers)
# target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PRIVATE ${JPEG_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 ${JPEG_LIBRARY})
# target_include_directories(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 PRIVATE ${RT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_ProcessingVideo_Processing_Sse2 ${RT_LIBRARY})
# End of target WebrtcModulesVideo_ProcessingVideo_Processing_Sse2

# Start of target WebrtcModulesAudio_CodingCng
set(WebrtcModulesAudio_CodingCng_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/audio_encoder_cng.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/webrtc_cng.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingCng STATIC ${WebrtcModulesAudio_CodingCng_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingCng PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingCng PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingCng PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingCng PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingCng PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingCng PROPERTIES OUTPUT_NAME cng)
target_link_libraries(WebrtcModulesAudio_CodingCng WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingCng WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingCng WebrtcCommon_AudioCommon_Audio)
target_include_directories(WebrtcModulesAudio_CodingCng PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingCng ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingCng

# Start of target Third_PartyOpusOpus
set(Third_PartyOpusOpus_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/bands.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/celt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/celt_decoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/celt_encoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/celt_lpc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/cwrs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/entcode.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/entdec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/entenc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/kiss_fft.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/laplace.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/mathops.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/mdct.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/modes.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/pitch.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/quant_bands.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/rate.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/vq.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/A2NLSF.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/CNG.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/HP_variable_cutoff.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/LPC_analysis_filter.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/LPC_inv_pred_gain.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/LP_variable_cutoff.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF2A.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_VQ.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_VQ_weights_laroia.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_decode.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_del_dec_quant.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_encode.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_stabilize.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NLSF_unpack.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NSQ.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/NSQ_del_dec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/PLC.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/VAD.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/VQ_WMat_EC.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/ana_filt_bank_1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/biquad_alt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/bwexpander.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/bwexpander_32.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/check_control_input.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/code_signs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/control_SNR.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/control_audio_bandwidth.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/control_codec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/debug.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/dec_API.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_core.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_frame.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_indices.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_parameters.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_pitch.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decode_pulses.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/decoder_set_fs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/enc_API.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/encode_indices.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/encode_pulses.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/gain_quant.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/init_decoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/init_encoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/inner_prod_aligned.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/interpolate.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/lin2log.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/log2lin.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/pitch_est_tables.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/process_NLSFs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/quant_LTP_gains.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_down2.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_down2_3.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_private_AR2.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_private_IIR_FIR.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_private_down_FIR.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_private_up2_HQ.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/resampler_rom.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/shell_coder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/sigm_Q15.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/sort.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_LR_to_MS.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_MS_to_LR.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_decode_pred.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_encode_pred.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_find_predictor.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/stereo_quant_pred.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/sum_sqr_shift.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/table_LSF_cos.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_LTP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_NLSF_CB_NB_MB.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_NLSF_CB_WB.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_gain.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_other.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_pitch_lag.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/tables_pulses_per_block.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/analysis.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/mlp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/mlp_data.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus_decoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus_encoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus_multistream.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus_multistream_decoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/opus_multistream_encoder.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/src/repacketizer.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/LPC_analysis_filter_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/LPC_inv_pred_gain_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/LTP_analysis_filter_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/LTP_scale_ctrl_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/apply_sine_window_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/autocorrelation_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/burg_modified_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/bwexpander_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/corrMatrix_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/encode_frame_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/energy_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/find_LPC_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/find_LTP_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/find_pitch_lags_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/find_pred_coefs_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/inner_product_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/k2a_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/levinsondurbin_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/noise_shape_analysis_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/pitch_analysis_core_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/prefilter_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/process_gains_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/regularize_correlations_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/residual_energy_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/scale_copy_vector_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/scale_vector_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/schur_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/solve_LS_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/sort_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/warped_autocorrelation_FLP.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/wrappers_FLP.c)
add_library(Third_PartyOpusOpus STATIC ${Third_PartyOpusOpus_SOURCES})
target_compile_options(Third_PartyOpusOpus PRIVATE "-Wno-#pragma-messages" "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "-UHAVE_CONFIG_H")
target_compile_definitions(Third_PartyOpusOpus PRIVATE OPUS_BUILD OPUS_EXPORT= HAVE_LRINT HAVE_LRINTF VAR_ARRAYS USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1)
target_include_directories(Third_PartyOpusOpus PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/celt/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/silk/float/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(Third_PartyOpusOpus PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
set_target_properties(Third_PartyOpusOpus PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/third_party/opus)
set_target_properties(Third_PartyOpusOpus PROPERTIES OUTPUT_NAME opus)
# End of target Third_PartyOpusOpus


# Start of target WebrtcModulesVideo_CodingVideo_Coding_Utility
set(WebrtcModulesVideo_CodingVideo_Coding_Utility_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/default_video_bitrate_allocator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/frame_dropper.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/ivf_file_writer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/moving_average.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/quality_scaler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/vp8_header_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/utility/vp9_uncompressed_header_parser.cc)
add_library(WebrtcModulesVideo_CodingVideo_Coding_Utility STATIC ${WebrtcModulesVideo_CodingVideo_Coding_Utility_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding_Utility PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding_Utility PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding_Utility PROPERTIES OUTPUT_NAME video_coding_utility)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcBaseRtc_Numerics)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcBaseSequenced_Task_Checker)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcModulesRtp_RtcpRtp_Rtcp)
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding_Utility PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding_Utility ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CodingVideo_Coding_Utility


# Start of target Third_PartyJsoncppJsoncpp
set(Third_PartyJsoncppJsoncpp_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/overrides/src/lib_json/json_reader.cpp
    ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/overrides/src/lib_json/json_value.cpp
    ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/source/src/lib_json/json_writer.cpp)
add_library(Third_PartyJsoncppJsoncpp OBJECT ${Third_PartyJsoncppJsoncpp_SOURCES})
target_compile_options(Third_PartyJsoncppJsoncpp PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "-UHAVE_CONFIG_H")
target_compile_definitions(Third_PartyJsoncppJsoncpp PRIVATE JSON_USE_EXCEPTION=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1)
target_include_directories(Third_PartyJsoncppJsoncpp PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/overrides/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/source/src/lib_json/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/source/include/)
set_target_properties(Third_PartyJsoncppJsoncpp PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# End of target Third_PartyJsoncppJsoncpp


# Start of target WebrtcModulesAudio_CodingIsac_Fix_Common
set(WebrtcModulesAudio_CodingIsac_Fix_Common_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/source/fft.c)
add_library(WebrtcModulesAudio_CodingIsac_Fix_Common OBJECT ${WebrtcModulesAudio_CodingIsac_Fix_Common_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac_Fix_Common PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac_Fix_Common PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac_Fix_Common PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingIsac_Fix_Common PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# End of target WebrtcModulesAudio_CodingIsac_Fix_Common



# Start of target WebrtcApiAudio_CodecsG722Audio_Encoder_G722
set(WebrtcApiAudio_CodecsG722Audio_Encoder_G722_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/g722/audio_encoder_g722.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 STATIC ${WebrtcApiAudio_CodecsG722Audio_Encoder_G722_SOURCES})
target_compile_options(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/api/audio_codecs/g722)
set_target_properties(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 PROPERTIES OUTPUT_NAME audio_encoder_g722)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiAudio_CodecsG722Audio_Encoder_G722 WebrtcModulesAudio_CodingG722)
# End of target WebrtcApiAudio_CodecsG722Audio_Encoder_G722

# Start of target Third_PartyLibyuvLibyuv_Internal
set(Third_PartyLibyuvLibyuv_Internal_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/compare.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/compare_common.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/compare_gcc.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_argb.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_from.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_from_argb.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_jpeg.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_to_argb.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/convert_to_i420.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/cpu_id.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/mjpeg_decoder.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/mjpeg_validate.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/planar_functions.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_neon.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_neon64.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_any.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_argb.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_common.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_dspr2.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/rotate_gcc.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_neon.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_neon64.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_any.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_common.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_dspr2.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/row_gcc.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_neon.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_any.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_argb.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_common.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_dspr2.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/scale_gcc.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/source/video_common.cc)
add_library(Third_PartyLibyuvLibyuv_Internal STATIC ${Third_PartyLibyuvLibyuv_Internal_SOURCES})
target_compile_options(Third_PartyLibyuvLibyuv_Internal PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "-UHAVE_CONFIG_H")
target_compile_definitions(Third_PartyLibyuvLibyuv_Internal PRIVATE HAVE_JPEG USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1)
target_include_directories(Third_PartyLibyuvLibyuv_Internal PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(Third_PartyLibyuvLibyuv_Internal PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(Third_PartyLibyuvLibyuv_Internal PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/third_party/libyuv)
set_target_properties(Third_PartyLibyuvLibyuv_Internal PROPERTIES OUTPUT_NAME yuv_internal)
# End of target Third_PartyLibyuvLibyuv_Internal

# Start of target WebrtcModulesAudio_CodingAudio_Coding
set(WebrtcModulesAudio_CodingAudio_Coding_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/acm_receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/acm_resampler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/audio_coding_module.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/call_statistics.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/codec_manager.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingAudio_Coding STATIC ${WebrtcModulesAudio_CodingAudio_Coding_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingAudio_Coding PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingAudio_Coding PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingAudio_Coding PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingAudio_Coding PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingAudio_Coding PROPERTIES OUTPUT_NAME audio_coding)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingG722)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingIlbc)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingNeteq)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingPcm16B)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingRed)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingRent_A_Codec)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding WebrtcModulesAudio_CodingWebrtc_Opus)
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingAudio_Coding PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingAudio_Coding ${M_LIBRARY})
# End of target WebrtcModulesAudio_CodingAudio_Coding

# Start of target WebrtcLoggingRtc_Event_Log_Api
add_custom_target(WebrtcLoggingRtc_Event_Log_Api)
add_dependencies(WebrtcLoggingRtc_Event_Log_Api WebrtcVideo_Stream_Api WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved)
# End of target WebrtcLoggingRtc_Event_Log_Api

# Start of target WebrtcModulesPacingPacing
set(WebrtcModulesPacingPacing_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/pacing/alr_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/pacing/bitrate_prober.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/pacing/paced_sender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/pacing/packet_router.cc)
add_library(WebrtcModulesPacingPacing STATIC ${WebrtcModulesPacingPacing_SOURCES})
target_compile_options(WebrtcModulesPacingPacing PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesPacingPacing PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesPacingPacing PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesPacingPacing PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/pacing)
set_target_properties(WebrtcModulesPacingPacing PROPERTIES OUTPUT_NAME pacing)
target_link_libraries(WebrtcModulesPacingPacing WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesPacingPacing WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesPacingPacing WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesPacingPacing Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesPacingPacing WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesPacingPacing WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_link_libraries(WebrtcModulesPacingPacing WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcModulesPacingPacing WebrtcModulesUtilityUtility)
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesPacingPacing ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesPacingPacing ${RT_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesPacingPacing ${DL_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesPacingPacing ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesPacingPacing ${X11_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesPacingPacing ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesPacingPacing ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesPacingPacing PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesPacingPacing ${EVENT_LIBRARY})
# End of target WebrtcModulesPacingPacing

# Start of target WebrtcModulesCongestion_ControllerCongestion_Controller
set(WebrtcModulesCongestion_ControllerCongestion_Controller_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/acknowledge_bitrate_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/congestion_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/delay_based_bwe.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/median_slope_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/probe_bitrate_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/probe_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/receive_side_congestion_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/send_side_congestion_controller.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/transport_feedback_adapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/congestion_controller/trendline_estimator.cc)
add_library(WebrtcModulesCongestion_ControllerCongestion_Controller STATIC ${WebrtcModulesCongestion_ControllerCongestion_Controller_SOURCES})
target_compile_options(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE BWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesCongestion_ControllerCongestion_Controller PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesCongestion_ControllerCongestion_Controller PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/congestion_controller)
set_target_properties(WebrtcModulesCongestion_ControllerCongestion_Controller PROPERTIES OUTPUT_NAME congestion_controller)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcBaseRtc_Base)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcBaseRtc_Numerics)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesBitrate_ControllerBitrate_Controller)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesPacingPacing)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${RT_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${DL_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${X11_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesCongestion_ControllerCongestion_Controller PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesCongestion_ControllerCongestion_Controller ${EVENT_LIBRARY})
# End of target WebrtcModulesCongestion_ControllerCongestion_Controller

# Start of target WebrtcModulesAudio_CodingAudio_Encoder_Interface
add_custom_target(WebrtcModulesAudio_CodingAudio_Encoder_Interface)
add_dependencies(WebrtcModulesAudio_CodingAudio_Encoder_Interface WebrtcApiAudio_CodecsAudio_Codecs_Api)
# End of target WebrtcModulesAudio_CodingAudio_Encoder_Interface

# Start of target WebrtcBaseSequenced_Task_Checker
set(WebrtcBaseSequenced_Task_Checker_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/sequenced_task_checker_impl.cc)
add_library(WebrtcBaseSequenced_Task_Checker STATIC ${WebrtcBaseSequenced_Task_Checker_SOURCES})
target_compile_options(WebrtcBaseSequenced_Task_Checker PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseSequenced_Task_Checker PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcBaseSequenced_Task_Checker PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseSequenced_Task_Checker PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcBaseSequenced_Task_Checker PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseSequenced_Task_Checker PROPERTIES OUTPUT_NAME sequenced_task_checker)
target_link_libraries(WebrtcBaseSequenced_Task_Checker WebrtcBaseRtc_Task_Queue)
target_include_directories(WebrtcBaseSequenced_Task_Checker PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcBaseSequenced_Task_Checker ${EVENT_LIBRARY})
# End of target WebrtcBaseSequenced_Task_Checker

# Start of target WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator
set(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/aimd_rate_control.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/bwe_defines.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/inter_arrival.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/overuse_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/overuse_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_abs_send_time.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/remote_bitrate_estimator_single_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/remote_estimator_proxy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/remote_bitrate_estimator/send_time_history.cc)
add_library(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator STATIC ${WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator_SOURCES})
target_compile_options(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE BWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/remote_bitrate_estimator)
set_target_properties(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PROPERTIES OUTPUT_NAME remote_bitrate_estimator)
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcBaseRtc_Base)
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${DL_LIBRARY})
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${RT_LIBRARY})
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${X11_LIBRARY})
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator ${XRENDER_LIBRARY})
# End of target WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator

# Start of target WebrtcP2PP2P
add_custom_target(WebrtcP2PP2P)
add_dependencies(WebrtcP2PP2P WebrtcP2PLibstunprober WebrtcP2PRtc_P2P)
# End of target WebrtcP2PP2P

# Start of target WebrtcToolsCommand_Line_Parser
set(WebrtcToolsCommand_Line_Parser_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/simple_command_line_parser.cc)
add_library(WebrtcToolsCommand_Line_Parser STATIC ${WebrtcToolsCommand_Line_Parser_SOURCES})
target_compile_options(WebrtcToolsCommand_Line_Parser PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcToolsCommand_Line_Parser PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcToolsCommand_Line_Parser PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcToolsCommand_Line_Parser PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcToolsCommand_Line_Parser PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/tools)
set_target_properties(WebrtcToolsCommand_Line_Parser PROPERTIES OUTPUT_NAME command_line_parser)
target_link_libraries(WebrtcToolsCommand_Line_Parser WebrtcBaseRtc_Base_Approved)
# End of target WebrtcToolsCommand_Line_Parser


# Start of target WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame
set(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/legacy_encoded_audio_frame.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame STATIC ${WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame PROPERTIES OUTPUT_NAME legacy_encoded_audio_frame)
target_link_libraries(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame



# Start of target WebrtcModulesAudio_CodingNeteq_Decoder_Enum
set(WebrtcModulesAudio_CodingNeteq_Decoder_Enum_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/neteq/neteq_decoder_enum.cc)
add_library(WebrtcModulesAudio_CodingNeteq_Decoder_Enum OBJECT ${WebrtcModulesAudio_CodingNeteq_Decoder_Enum_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingNeteq_Decoder_Enum PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingNeteq_Decoder_Enum PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingNeteq_Decoder_Enum PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingNeteq_Decoder_Enum PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingNeteq_Decoder_Enum WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_CodingNeteq_Decoder_Enum

# Start of target Third_PartyUsrsctpUsrsctp
set(Third_PartyUsrsctpUsrsctp_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_asconf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_auth.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_bsd_addr.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_callout.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_cc_functions.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_crc32.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_indata.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_input.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_output.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_pcb.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_peeloff.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_sha1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_ss_functions.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_sysctl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_timer.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_userspace.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctp_usrreq.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/sctputil.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet6/sctp6_usrreq.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/user_environment.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/user_mbuf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/user_recv_thread.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/user_socket.c)
add_library(Third_PartyUsrsctpUsrsctp STATIC ${Third_PartyUsrsctpUsrsctp_SOURCES})
target_compile_options(Third_PartyUsrsctpUsrsctp PRIVATE "-UINET" "-UINET6" "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-local-typedefs" "-Wno-discarded-qualifiers" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "-UHAVE_CONFIG_H")
target_compile_definitions(Third_PartyUsrsctpUsrsctp PRIVATE SCTP_PROCESS_LEVEL_LOCKS SCTP_SIMPLE_ALLOCATOR SCTP_USE_OPENSSL_SHA1 __Userspace__ __Userspace_os_Linux _GNU_SOURCE NON_WINDOWS_DEFINE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1)
target_include_directories(Third_PartyUsrsctpUsrsctp PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/ ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/)
set_target_properties(Third_PartyUsrsctpUsrsctp PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
set_target_properties(Third_PartyUsrsctpUsrsctp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/third_party/usrsctp)
set_target_properties(Third_PartyUsrsctpUsrsctp PROPERTIES OUTPUT_NAME usrsctp)
target_link_libraries(Third_PartyUsrsctpUsrsctp Third_PartyBoringsslBoringssl)
# End of target Third_PartyUsrsctpUsrsctp


# Start of target WebrtcModulesVideo_CodingWebrtc_I420
set(WebrtcModulesVideo_CodingWebrtc_I420_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codecs/i420/i420.cc)
add_library(WebrtcModulesVideo_CodingWebrtc_I420 STATIC ${WebrtcModulesVideo_CodingWebrtc_I420_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_I420 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingWebrtc_I420 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingWebrtc_I420 PROPERTIES OUTPUT_NAME webrtc_i420)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingWebrtc_I420 PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingWebrtc_I420 ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CodingWebrtc_I420

# Start of target WebrtcCallCall
set(WebrtcCallCall_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/call/bitrate_allocator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/call/call.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/call/callfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/call/flexfec_receive_stream_impl.cc
    $<TARGET_OBJECTS:WebrtcCallCall_Interfaces>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcCallRtp_Receiver>
    $<TARGET_OBJECTS:WebrtcCallRtp_Sender>)
add_library(WebrtcCallCall STATIC ${WebrtcCallCall_SOURCES})
target_compile_options(WebrtcCallCall PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCallCall PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcCallCall PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCallCall PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcCallCall PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/call)
set_target_properties(WebrtcCallCall PROPERTIES OUTPUT_NAME call)
target_link_libraries(WebrtcCallCall WebrtcWebrtc_Common)
target_link_libraries(WebrtcCallCall WebrtcApiCall_Api)
target_link_libraries(WebrtcCallCall WebrtcAudioAudio)
target_link_libraries(WebrtcCallCall WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcCallCall WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcCallCall WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcCallCall Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcCallCall WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcCallCall WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcCallCall WebrtcBaseRtc_Base)
target_link_libraries(WebrtcCallCall WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcCallCall WebrtcModulesCongestion_ControllerCongestion_Controller)
target_link_libraries(WebrtcCallCall WebrtcLoggingRtc_Event_Log_Impl)
target_link_libraries(WebrtcCallCall WebrtcModulesBitrate_ControllerBitrate_Controller)
target_link_libraries(WebrtcCallCall WebrtcModulesPacingPacing)
target_link_libraries(WebrtcCallCall WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcCallCall WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcCallCall WebrtcVideoVideo)
target_include_directories(WebrtcCallCall PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${JPEG_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${RT_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${DL_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcCallCall ${XEXT_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcCallCall ${X11_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcCallCall ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${XRENDER_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${EVENT_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${M_LIBRARY})
target_include_directories(WebrtcCallCall PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcCallCall ${VPX_LIBRARY})
# End of target WebrtcCallCall


# Start of target WebrtcModulesVideo_CaptureVideo_Capture
set(WebrtcModulesVideo_CaptureVideo_Capture_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/external/device_info_external.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/external/video_capture_external.cc)
add_library(WebrtcModulesVideo_CaptureVideo_Capture STATIC ${WebrtcModulesVideo_CaptureVideo_Capture_SOURCES})
target_compile_options(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_capture)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture PROPERTIES OUTPUT_NAME video_capture)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture WebrtcModulesVideo_CaptureVideo_Capture_Module)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CaptureVideo_Capture

# Start of target WebrtcBaseRtc_Base
set(WebrtcBaseRtc_Base_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asyncinvoker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asyncpacketsocket.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asyncresolverinterface.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asyncsocket.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asynctcpsocket.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/asyncudpsocket.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/crc32.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/cryptstring.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/filerotatingstream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/fileutils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/helpers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/httpbase.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/httpcommon.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/ipaddress.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/messagedigest.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/messagehandler.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/messagequeue.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/nethelpers.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/network.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/networkmonitor.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/nullsocketserver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/openssladapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/openssldigest.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/opensslidentity.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/opensslstreamadapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/physicalsocketserver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/proxyinfo.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/ratelimiter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/rtccertificate.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/rtccertificategenerator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/signalthread.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/sigslot.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/socketadapters.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/socketaddress.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/socketaddresspair.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/socketstream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/ssladapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/sslfingerprint.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/sslidentity.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/sslstreamadapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/thread.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/logsinks.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/optionsfile.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/transformadapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/ifaddrs_converter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/base/unixfilesystem.cc)
add_library(WebrtcBaseRtc_Base STATIC ${WebrtcBaseRtc_Base_SOURCES})
target_compile_options(WebrtcBaseRtc_Base PRIVATE "-Wno-uninitialized" "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseRtc_Base PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/)
set_target_properties(WebrtcBaseRtc_Base PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
set_target_properties(WebrtcBaseRtc_Base PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseRtc_Base PROPERTIES OUTPUT_NAME rtc_base)
target_link_libraries(WebrtcBaseRtc_Base Third_PartyBoringsslBoringssl)
target_link_libraries(WebrtcBaseRtc_Base WebrtcWebrtc_Common)
target_link_libraries(WebrtcBaseRtc_Base WebrtcBaseRtc_Base_Approved)
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcBaseRtc_Base ${DL_LIBRARY})
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcBaseRtc_Base ${RT_LIBRARY})
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcBaseRtc_Base ${XEXT_LIBRARY})
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcBaseRtc_Base ${X11_LIBRARY})
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcBaseRtc_Base ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcBaseRtc_Base PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcBaseRtc_Base ${XRENDER_LIBRARY})
# End of target WebrtcBaseRtc_Base

# Start of target WebrtcModulesAudio_ProcessingAec_DumpAec_Dump
add_custom_target(WebrtcModulesAudio_ProcessingAec_DumpAec_Dump)
add_dependencies(WebrtcModulesAudio_ProcessingAec_DumpAec_Dump WebrtcBaseRtc_Base_Approved WebrtcModulesAudio_ProcessingAec_Dump_Interface)
# End of target WebrtcModulesAudio_ProcessingAec_DumpAec_Dump

# Start of target WebrtcModulesAudio_CodingRed
set(WebrtcModulesAudio_CodingRed_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/audio_encoder_copy_red.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingRed STATIC ${WebrtcModulesAudio_CodingRed_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingRed PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingRed PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingRed PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingRed PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingRed PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingRed PROPERTIES OUTPUT_NAME red)
target_link_libraries(WebrtcModulesAudio_CodingRed WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingRed WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingRed WebrtcCommon_AudioCommon_Audio)
target_include_directories(WebrtcModulesAudio_CodingRed PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRed ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingRed

# Start of target WebrtcModulesUtilityUtility
set(WebrtcModulesUtilityUtility_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/utility/source/process_thread_impl.cc)
add_library(WebrtcModulesUtilityUtility STATIC ${WebrtcModulesUtilityUtility_SOURCES})
target_compile_options(WebrtcModulesUtilityUtility PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesUtilityUtility PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesUtilityUtility PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesUtilityUtility PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesUtilityUtility PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/utility)
set_target_properties(WebrtcModulesUtilityUtility PROPERTIES OUTPUT_NAME utility)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcAudioUtilityAudio_Frame_Operations)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesUtilityUtility Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesUtilityUtility WebrtcModulesMedia_FileMedia_File)
target_include_directories(WebrtcModulesUtilityUtility PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesUtilityUtility ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesUtilityUtility PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesUtilityUtility ${RT_LIBRARY})
target_include_directories(WebrtcModulesUtilityUtility PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesUtilityUtility ${EVENT_LIBRARY})
# End of target WebrtcModulesUtilityUtility


# Start of target WebrtcMediaRtc_Data
set(WebrtcMediaRtc_Data_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/media/sctp/sctptransport.cc
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcMediaRtc_Data STATIC ${WebrtcMediaRtc_Data_SOURCES})
target_compile_options(WebrtcMediaRtc_Data PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "-Wno-deprecated-declarations" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcMediaRtc_Data PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX FEATURE_ENABLE_VOICEMAIL)
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/netinet/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/third_party/usrsctp/usrsctplib/usrsctplib/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcMediaRtc_Data PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcMediaRtc_Data PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/media)
set_target_properties(WebrtcMediaRtc_Data PROPERTIES OUTPUT_NAME rtc_data)
target_link_libraries(WebrtcMediaRtc_Data Third_PartyUsrsctpUsrsctp)
target_link_libraries(WebrtcMediaRtc_Data WebrtcWebrtc_Common)
target_link_libraries(WebrtcMediaRtc_Data WebrtcApiCall_Api)
target_link_libraries(WebrtcMediaRtc_Data WebrtcBaseRtc_Base)
target_link_libraries(WebrtcMediaRtc_Data WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcMediaRtc_Data Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcMediaRtc_Data WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcMediaRtc_Data WebrtcP2PLibstunprober)
target_link_libraries(WebrtcMediaRtc_Data WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcMediaRtc_Data WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcMediaRtc_Data WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Data ${JPEG_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Data ${DL_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Data ${RT_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Data ${XEXT_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Data ${X11_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcMediaRtc_Data ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcMediaRtc_Data PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcMediaRtc_Data ${XRENDER_LIBRARY})
# End of target WebrtcMediaRtc_Data




# Start of target WebrtcModulesBitrate_ControllerBitrate_Controller
set(WebrtcModulesBitrate_ControllerBitrate_Controller_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/bitrate_controller/bitrate_controller_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/bitrate_controller/send_side_bandwidth_estimation.cc)
add_library(WebrtcModulesBitrate_ControllerBitrate_Controller STATIC ${WebrtcModulesBitrate_ControllerBitrate_Controller_SOURCES})
target_compile_options(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE BWE_TEST_LOGGING_COMPILE_TIME_ENABLE=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesBitrate_ControllerBitrate_Controller PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesBitrate_ControllerBitrate_Controller PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/bitrate_controller)
set_target_properties(WebrtcModulesBitrate_ControllerBitrate_Controller PROPERTIES OUTPUT_NAME bitrate_controller)
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${RT_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${DL_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${X11_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesBitrate_ControllerBitrate_Controller PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesBitrate_ControllerBitrate_Controller ${EVENT_LIBRARY})
# End of target WebrtcModulesBitrate_ControllerBitrate_Controller

# Start of target WebrtcModulesAudio_CodingIlbc
set(WebrtcModulesAudio_CodingIlbc_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/audio_decoder_ilbc.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/audio_encoder_ilbc.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIlbc_C>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingIlbc STATIC ${WebrtcModulesAudio_CodingIlbc_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIlbc PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIlbc PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIlbc PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/signal_processing/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/vad/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingIlbc PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingIlbc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingIlbc PROPERTIES OUTPUT_NAME ilbc)
target_link_libraries(WebrtcModulesAudio_CodingIlbc WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingIlbc WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingIlbc WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingIlbc WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame)
target_include_directories(WebrtcModulesAudio_CodingIlbc PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIlbc ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingIlbc

# Start of target WebrtcToolsRtp_Analyzer
list(APPEND WebrtcToolsRtp_Analyzer ${LIBWEBRTC_OUTPUT_DIR}/misc.py ${LIBWEBRTC_OUTPUT_DIR}/pb_parse.py ${LIBWEBRTC_OUTPUT_DIR}/rtp_analyzer.py ${LIBWEBRTC_OUTPUT_DIR}/rtp_analyzer.sh)
file(COPY ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/py_event_log_analyzer/misc.py DESTINATION ${LIBWEBRTC_OUTPUT_DIR}/misc.py)
file(COPY ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/py_event_log_analyzer/pb_parse.py DESTINATION ${LIBWEBRTC_OUTPUT_DIR}/pb_parse.py)
file(COPY ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/py_event_log_analyzer/rtp_analyzer.py DESTINATION ${LIBWEBRTC_OUTPUT_DIR}/rtp_analyzer.py)
file(COPY ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/py_event_log_analyzer/rtp_analyzer.sh DESTINATION ${LIBWEBRTC_OUTPUT_DIR}/rtp_analyzer.sh)
add_custom_target(WebrtcToolsRtp_Analyzer
    COMMAND echo "Generating copy targetWebrtcToolsRtp_Analyzer"
    VERBATIM)
# End of target WebrtcToolsRtp_Analyzer

# Start of target WebrtcVideoVideo
set(WebrtcVideoVideo_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/video/call_stats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/encoder_rtcp_feedback.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/overuse_frame_detector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/payload_router.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/quality_threshold.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/receive_statistics_proxy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/report_block_stats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/rtp_streams_synchronizer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/rtp_video_stream_receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/send_delay_stats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/send_statistics_proxy.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/stats_counter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/stream_synchronization.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/transport_adapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/video_receive_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/video_send_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/video_stream_decoder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/video/vie_encoder.cc
    $<TARGET_OBJECTS:WebrtcCallCall_Interfaces>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcVideoVideo STATIC ${WebrtcVideoVideo_SOURCES})
target_compile_options(WebrtcVideoVideo PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVideoVideo PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcVideoVideo PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVideoVideo PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVideoVideo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/video)
set_target_properties(WebrtcVideoVideo PROPERTIES OUTPUT_NAME video)
target_link_libraries(WebrtcVideoVideo WebrtcWebrtc_Common)
target_link_libraries(WebrtcVideoVideo WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVideoVideo WebrtcBaseRtc_Numerics)
target_link_libraries(WebrtcVideoVideo WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcVideoVideo WebrtcBaseSequenced_Task_Checker)
target_link_libraries(WebrtcVideoVideo WebrtcBaseWeak_Ptr)
target_link_libraries(WebrtcVideoVideo WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVideoVideo WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcVideoVideo WebrtcBaseRtc_Base)
target_link_libraries(WebrtcVideoVideo WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcVideoVideo WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcVideoVideo WebrtcP2PLibstunprober)
target_link_libraries(WebrtcVideoVideo WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcVideoVideo WebrtcModulesBitrate_ControllerBitrate_Controller)
target_link_libraries(WebrtcVideoVideo WebrtcModulesCongestion_ControllerCongestion_Controller)
target_link_libraries(WebrtcVideoVideo WebrtcModulesPacingPacing)
target_link_libraries(WebrtcVideoVideo WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator)
target_link_libraries(WebrtcVideoVideo WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcVideoVideo WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcVideoVideo WebrtcModulesVideo_CodingVideo_Coding)
target_link_libraries(WebrtcVideoVideo WebrtcModulesVideo_CodingVideo_Coding_Utility)
target_link_libraries(WebrtcVideoVideo WebrtcModulesVideo_CodingWebrtc_Vp8)
target_link_libraries(WebrtcVideoVideo WebrtcModulesVideo_ProcessingVideo_Processing)
target_link_libraries(WebrtcVideoVideo WebrtcVoice_EngineVoice_Engine)
target_include_directories(WebrtcVideoVideo PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${JPEG_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${RT_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${DL_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcVideoVideo ${XEXT_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcVideoVideo ${X11_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcVideoVideo ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${XRENDER_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${EVENT_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${VPX_LIBRARY})
target_include_directories(WebrtcVideoVideo PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcVideoVideo ${M_LIBRARY})
# End of target WebrtcVideoVideo

# Start of target WebrtcModulesAudio_ProcessingAudio_Processing_Sse2
# set(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/aec/aec_core_sse2.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_processing/utility/ooura_fft_sse2.cc)
# add_library(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 STATIC ${WebrtcModulesAudio_ProcessingAudio_Processing_Sse2_SOURCES})
# target_compile_options(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PRIVATE  "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
# target_compile_definitions(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PRIVATE WEBRTC_APM_DEBUG_DUMP=0 USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
# target_include_directories(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
# set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_processing)
# set_target_properties(WebrtcModulesAudio_ProcessingAudio_Processing_Sse2 PROPERTIES OUTPUT_NAME audio_processing_sse2)
# End of target WebrtcModulesAudio_ProcessingAudio_Processing_Sse2

# Start of target BaseThird_PartyLibeventGen_Libevent_Shim
add_custom_command(OUTPUT ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/event.h
    COMMAND python ${LIBWEBRTC_INPUT_DIR}/tools/generate_shim_headers/generate_shim_headers.py --generate --headers-root /home/alex/checkout/libwebrtc/src/base/third_party/libevent --output-directory /home/alex/checkout/libwebrtc/src/out/gen/shim_headers/libevent_shim event.h
    VERBATIM)
add_custom_target(BaseThird_PartyLibeventGen_Libevent_Shim DEPENDS  ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/event.h)
# End of target BaseThird_PartyLibeventGen_Libevent_Shim

# Start of target WebrtcMediaRtc_Media_Base
set(WebrtcMediaRtc_Media_Base_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/adaptedvideotracksource.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/codec.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/h264_profile_level_id.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/mediaconstants.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/mediaengine.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/rtpdataengine.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/rtputils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/streamparams.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/turnutils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/videoadapter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/videobroadcaster.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/videocapturer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/videocommon.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/media/base/videosourcebase.cc)
add_library(WebrtcMediaRtc_Media_Base OBJECT ${WebrtcMediaRtc_Media_Base_SOURCES})
target_compile_options(WebrtcMediaRtc_Media_Base PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcMediaRtc_Media_Base PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX FEATURE_ENABLE_VOICEMAIL)
target_include_directories(WebrtcMediaRtc_Media_Base PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/)
set_target_properties(WebrtcMediaRtc_Media_Base PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcMediaRtc_Media_Base Third_PartyLibyuvLibyuv WebrtcWebrtc_Common WebrtcApiLibjingle_Peerconnection_Api WebrtcBaseRtc_Base WebrtcBaseRtc_Base_Approved WebrtcP2PP2P)
# End of target WebrtcMediaRtc_Media_Base



# Start of target WebrtcModulesAudio_CodingG722_C
set(WebrtcModulesAudio_CodingG722_C_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/g722_decode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/g722_encode.c
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/g722_interface.c)
add_library(WebrtcModulesAudio_CodingG722_C OBJECT ${WebrtcModulesAudio_CodingG722_C_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingG722_C PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingG722_C PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingG722_C PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingG722_C PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcModulesAudio_CodingG722_C WebrtcWebrtc_Common)
# End of target WebrtcModulesAudio_CodingG722_C

# Start of target WebrtcModulesVideo_CaptureVideo_Capture_Module
set(WebrtcModulesVideo_CaptureVideo_Capture_Module_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/device_info_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/video_capture_factory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_capture/video_capture_impl.cc)
add_library(WebrtcModulesVideo_CaptureVideo_Capture_Module STATIC ${WebrtcModulesVideo_CaptureVideo_Capture_Module_SOURCES})
target_compile_options(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Module PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Module PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_capture)
set_target_properties(WebrtcModulesVideo_CaptureVideo_Capture_Module PROPERTIES OUTPUT_NAME video_capture_module)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl)
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CaptureVideo_Capture_Module PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CaptureVideo_Capture_Module ${EVENT_LIBRARY})
# End of target WebrtcModulesVideo_CaptureVideo_Capture_Module

# Start of target WebrtcModulesAudio_CodingIsac
set(WebrtcModulesAudio_CodingIsac_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/audio_decoder_isac.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/source/audio_encoder_isac.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingIsac STATIC ${WebrtcModulesAudio_CodingIsac_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingIsac PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingIsac PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingIsac PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/)
set_target_properties(WebrtcModulesAudio_CodingIsac PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingIsac PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingIsac PROPERTIES OUTPUT_NAME isac)
target_link_libraries(WebrtcModulesAudio_CodingIsac WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingIsac WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingIsac WebrtcModulesAudio_CodingIsac_C)
target_link_libraries(WebrtcModulesAudio_CodingIsac WebrtcModulesAudio_CodingIsac_Common)
target_include_directories(WebrtcModulesAudio_CodingIsac PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIsac ${M_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingIsac PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingIsac ${RT_LIBRARY})
# End of target WebrtcModulesAudio_CodingIsac

# Start of target Third_PartyLibvpxGen_Libvpx_Shim
add_custom_command(OUTPUT ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8cx.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8dx.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec_impl_bottom.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec_impl_top.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_decoder.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_encoder.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_frame_buffer.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_image.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_integer.h
    COMMAND python ${LIBWEBRTC_INPUT_DIR}/tools/generate_shim_headers/generate_shim_headers.py --generate --headers-root /home/alex/checkout/libwebrtc/src/third_party/libvpx/source/libvpx --output-directory /home/alex/checkout/libwebrtc/src/out/gen/shim_headers/libvpx_shim vpx/vp8.h vpx/vp8cx.h vpx/vp8dx.h vpx/vpx_codec.h vpx/vpx_codec_impl_bottom.h vpx/vpx_codec_impl_top.h vpx/vpx_decoder.h vpx/vpx_encoder.h vpx/vpx_frame_buffer.h vpx/vpx_image.h vpx/vpx_integer.h
    VERBATIM)
add_custom_target(Third_PartyLibvpxGen_Libvpx_Shim DEPENDS  ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8cx.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vp8dx.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec_impl_bottom.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_codec_impl_top.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_decoder.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_encoder.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_frame_buffer.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_image.h ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/vpx_integer.h)
# End of target Third_PartyLibvpxGen_Libvpx_Shim

# Start of target WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory
add_custom_target(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory)
add_dependencies(WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory)
# End of target WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory




# Start of target WebrtcVoice_EngineAudio_Coder
set(WebrtcVoice_EngineAudio_Coder_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/voice_engine/coder.cc)
add_library(WebrtcVoice_EngineAudio_Coder STATIC ${WebrtcVoice_EngineAudio_Coder_SOURCES})
target_compile_options(WebrtcVoice_EngineAudio_Coder PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcVoice_EngineAudio_Coder PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcVoice_EngineAudio_Coder PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcVoice_EngineAudio_Coder PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/voice_engine)
set_target_properties(WebrtcVoice_EngineAudio_Coder PROPERTIES OUTPUT_NAME audio_coder)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcWebrtc_Common)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory)
target_link_libraries(WebrtcVoice_EngineAudio_Coder Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcModulesAudio_CodingAudio_Coding)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcModulesAudio_CodingAudio_Format_Conversion)
target_link_libraries(WebrtcVoice_EngineAudio_Coder WebrtcModulesAudio_CodingRent_A_Codec)
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${RT_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${JPEG_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${DL_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineAudio_Coder ${XEXT_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineAudio_Coder ${X11_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcVoice_EngineAudio_Coder ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${XRENDER_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${EVENT_LIBRARY})
target_include_directories(WebrtcVoice_EngineAudio_Coder PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcVoice_EngineAudio_Coder ${M_LIBRARY})
# End of target WebrtcVoice_EngineAudio_Coder

# Start of target WebrtcToolsFrame_Editing_Lib
set(WebrtcToolsFrame_Editing_Lib_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/frame_editing/frame_editing_lib.cc)
add_library(WebrtcToolsFrame_Editing_Lib STATIC ${WebrtcToolsFrame_Editing_Lib_SOURCES})
target_compile_options(WebrtcToolsFrame_Editing_Lib PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcToolsFrame_Editing_Lib PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcToolsFrame_Editing_Lib PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcToolsFrame_Editing_Lib PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/tools)
set_target_properties(WebrtcToolsFrame_Editing_Lib PROPERTIES OUTPUT_NAME frame_editing_lib)
target_link_libraries(WebrtcToolsFrame_Editing_Lib WebrtcWebrtc_Common)
target_link_libraries(WebrtcToolsFrame_Editing_Lib WebrtcCommon_VideoCommon_Video)
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcToolsFrame_Editing_Lib ${JPEG_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsFrame_Editing_Lib ${RT_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcToolsFrame_Editing_Lib ${DL_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsFrame_Editing_Lib ${XEXT_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${X11_INCLUDE_DIR})

target_link_libraries(WebrtcToolsFrame_Editing_Lib ${X11_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsFrame_Editing_Lib ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcToolsFrame_Editing_Lib ${XRENDER_LIBRARY})
target_include_directories(WebrtcToolsFrame_Editing_Lib PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsFrame_Editing_Lib ${EVENT_LIBRARY})
# End of target WebrtcToolsFrame_Editing_Lib

# Start of target WebrtcToolsVideo_Quality_Analysis
set(WebrtcToolsVideo_Quality_Analysis_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/tools/frame_analyzer/video_quality_analysis.cc)
add_library(WebrtcToolsVideo_Quality_Analysis STATIC ${WebrtcToolsVideo_Quality_Analysis_SOURCES})
target_compile_options(WebrtcToolsVideo_Quality_Analysis PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcToolsVideo_Quality_Analysis PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcToolsVideo_Quality_Analysis PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcToolsVideo_Quality_Analysis PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/tools)
set_target_properties(WebrtcToolsVideo_Quality_Analysis PROPERTIES OUTPUT_NAME video_quality_analysis)
target_link_libraries(WebrtcToolsVideo_Quality_Analysis WebrtcCommon_VideoCommon_Video)
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${JPEG_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${RT_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${DL_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${XEXT_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${X11_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${XRENDER_LIBRARY})
target_include_directories(WebrtcToolsVideo_Quality_Analysis PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcToolsVideo_Quality_Analysis ${EVENT_LIBRARY})
# End of target WebrtcToolsVideo_Quality_Analysis

# Start of target WebrtcWebrtc
add_custom_target(WebrtcWebrtc)
add_dependencies(WebrtcWebrtc WebrtcWebrtc_Common WebrtcApiLibjingle_Peerconnection_Api WebrtcAudioAudio WebrtcBaseBase WebrtcCallCall WebrtcCommon_AudioCommon_Audio WebrtcCommon_VideoCommon_Video WebrtcModulesModules WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcP2PP2P WebrtcStatsRtc_Stats WebrtcSystem_WrappersSystem_Wrappers_Default WebrtcVideoVideo WebrtcVoice_EngineVoice_Engine)
# End of target WebrtcWebrtc

# Start of target Third_PartyLibsrtpLibsrtp
set(Third_PartyLibsrtpLibsrtp_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/cipher/aes_gcm_ossl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/cipher/aes_icm_ossl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/cipher/cipher.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/cipher/null_cipher.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/hash/auth.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/hash/hmac_ossl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/hash/null_auth.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/kernel/alloc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/kernel/crypto_kernel.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/kernel/err.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/kernel/key.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/math/datatypes.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/math/stat.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/replay/rdb.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/replay/rdbx.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/srtp/ekt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/srtp/srtp.c)
add_library(Third_PartyLibsrtpLibsrtp STATIC ${Third_PartyLibsrtpLibsrtp_SOURCES})
target_compile_options(Third_PartyLibsrtpLibsrtp PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>")
target_compile_definitions(Third_PartyLibsrtpLibsrtp PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 PACKAGE_STRING="libsrtp2 2.0.0-pre" PACKAGE_VERSION="2.0.0-pre" HAVE_CONFIG_H OPENSSL HAVE_STDLIB_H HAVE_STRING_H HAVE_STDINT_H HAVE_INTTYPES_H HAVE_INT16_T HAVE_INT32_T HAVE_INT8_T HAVE_UINT16_T HAVE_UINT32_T HAVE_UINT64_T HAVE_UINT8_T HAVE_ARPA_INET_H HAVE_NETINET_IN_H HAVE_SYS_TYPES_H HAVE_UNISTD_H)
target_include_directories(Third_PartyLibsrtpLibsrtp PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/config/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/ ${LIBWEBRTC_INPUT_DIR}/third_party/libsrtp/crypto/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(Third_PartyLibsrtpLibsrtp PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
set_target_properties(Third_PartyLibsrtpLibsrtp PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/third_party/libsrtp)
set_target_properties(Third_PartyLibsrtpLibsrtp PROPERTIES OUTPUT_NAME srtp)
target_link_libraries(Third_PartyLibsrtpLibsrtp Third_PartyBoringsslBoringssl)
# End of target Third_PartyLibsrtpLibsrtp

# Start of target WebrtcModulesVideo_CodingVideo_Coding
set(WebrtcModulesVideo_CodingVideo_Coding_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codec_database.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/codec_timer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/decoding_state.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/encoded_frame.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/frame_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/frame_buffer2.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/frame_object.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/generic_decoder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/generic_encoder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/h264_sprop_parameter_sets.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/h264_sps_pps_tracker.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/histogram.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/inter_frame_delay.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/jitter_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/jitter_estimator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/media_opt_util.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/media_optimization.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/nack_module.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/packet.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/packet_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/protection_bitrate_calculator.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/qp_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/rtp_frame_reference_finder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/rtt_filter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/session_info.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/timestamp_map.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/timing.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/video_codec_initializer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/video_coding_impl.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/video_receiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/video_coding/video_sender.cc)
add_library(WebrtcModulesVideo_CodingVideo_Coding STATIC ${WebrtcModulesVideo_CodingVideo_Coding_SOURCES})
target_compile_options(WebrtcModulesVideo_CodingVideo_Coding PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesVideo_CodingVideo_Coding PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libvpx_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/video_coding)
set_target_properties(WebrtcModulesVideo_CodingVideo_Coding PROPERTIES OUTPUT_NAME video_coding)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcBaseRtc_Base)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcBaseRtc_Numerics)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcBaseSequenced_Task_Checker)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesRtp_RtcpRtp_Rtcp)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesUtilityUtility)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_CodingVideo_Coding_Utility)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_CodingWebrtc_H264)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_CodingWebrtc_I420)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_CodingWebrtc_Vp8)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcModulesVideo_CodingWebrtc_Vp9)
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${RT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${DL_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${X11_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${VPX_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${VPX_LIBRARY})
target_include_directories(WebrtcModulesVideo_CodingVideo_Coding PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesVideo_CodingVideo_Coding ${M_LIBRARY})
# End of target WebrtcModulesVideo_CodingVideo_Coding

# Start of target BaseThird_PartyLibeventLibevent_Shim
add_custom_target(BaseThird_PartyLibeventLibevent_Shim)
add_dependencies(BaseThird_PartyLibeventLibevent_Shim BaseThird_PartyLibeventGen_Libevent_Shim)
# End of target BaseThird_PartyLibeventLibevent_Shim

# Start of target WebrtcModulesAudio_CodingRent_A_Codec
set(WebrtcModulesAudio_CodingRent_A_Codec_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/acm_codec_database.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/acm2/rent_a_codec.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_C>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_Common>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingNeteq_Decoder_Enum>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingRent_A_Codec STATIC ${WebrtcModulesAudio_CodingRent_A_Codec_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/fix/include/)
set_target_properties(WebrtcModulesAudio_CodingRent_A_Codec PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingRent_A_Codec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingRent_A_Codec PROPERTIES OUTPUT_NAME rent_a_codec)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingG722)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingIlbc)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcCommon_AudioCommon_Audio)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingIsac_Common)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingPcm16B)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingRed)
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesAudio_CodingWebrtc_Opus)
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${XRENDER_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingRent_A_Codec PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingRent_A_Codec ${M_LIBRARY})
# End of target WebrtcModulesAudio_CodingRent_A_Codec

# Start of target WebrtcApiAudio_CodecsAudio_Codecs_Api
set(WebrtcApiAudio_CodecsAudio_Codecs_Api_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/audio_decoder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/audio_encoder.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/api/audio_codecs/audio_format.cc)
add_library(WebrtcApiAudio_CodecsAudio_Codecs_Api OBJECT ${WebrtcApiAudio_CodecsAudio_Codecs_Api_SOURCES})
target_compile_options(WebrtcApiAudio_CodecsAudio_Codecs_Api PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiAudio_CodecsAudio_Codecs_Api PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiAudio_CodecsAudio_Codecs_Api PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiAudio_CodecsAudio_Codecs_Api PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcApiAudio_CodecsAudio_Codecs_Api WebrtcWebrtc_Common WebrtcBaseRtc_Base_Approved)
# End of target WebrtcApiAudio_CodecsAudio_Codecs_Api

# Start of target WebrtcModulesDesktop_CaptureDesktop_Capture
# set(WebrtcModulesDesktop_CaptureDesktop_Capture_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/blank_detector_desktop_capturer_wrapper.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/cropped_desktop_frame.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/cropping_window_capturer.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_and_cursor_composer.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_capture_options.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_capturer.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_capturer_differ_wrapper.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/desktop_frame_rotation.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/differ_block.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/fallback_desktop_capturer_wrapper.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/mouse_cursor.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/resolution_change_detector.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/rgba_color.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/screen_capturer_helper.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/mouse_cursor_monitor_x11.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/screen_capturer_x11.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/window_capturer_x11.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/x11/shared_x_display.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/x11/x_error_trap.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/desktop_capture/x11/x_server_pixel_buffer.cc)
# add_library(WebrtcModulesDesktop_CaptureDesktop_Capture STATIC ${WebrtcModulesDesktop_CaptureDesktop_Capture_SOURCES})
# target_compile_options(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
# target_compile_definitions(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/)
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/desktop_capture)
# set_target_properties(WebrtcModulesDesktop_CaptureDesktop_Capture PROPERTIES OUTPUT_NAME desktop_capture)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture Third_PartyLibyuvLibyuv_Internal)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture WebrtcWebrtc_Common)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture WebrtcBaseRtc_Base)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture WebrtcModulesDesktop_CapturePrimitives)
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture WebrtcSystem_WrappersSystem_Wrappers)
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${X11_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${X11_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${X11-XCB_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XCB_LIBRARYX11-XCB_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XCB_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XCB_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XCOMPOSITE_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XCURSOR_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XCURSOR_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XDAMAGE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XDAMAGE_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XEXT_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XEXT_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XFIXES_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XFIXES_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XI_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XI_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XRENDER_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XRENDER_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${XTST_INCLUDE_DIR})
# # target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${XTST_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${DL_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${DL_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${RT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${RT_LIBRARY})
# target_include_directories(WebrtcModulesDesktop_CaptureDesktop_Capture PRIVATE ${JPEG_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesDesktop_CaptureDesktop_Capture ${JPEG_LIBRARY})
# End of target WebrtcModulesDesktop_CaptureDesktop_Capture


# Start of target WebrtcSystem_WrappersMetrics_Default
set(WebrtcSystem_WrappersMetrics_Default_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/system_wrappers/source/metrics_default.cc)
add_library(WebrtcSystem_WrappersMetrics_Default STATIC ${WebrtcSystem_WrappersMetrics_Default_SOURCES})
target_compile_options(WebrtcSystem_WrappersMetrics_Default PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcSystem_WrappersMetrics_Default PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcSystem_WrappersMetrics_Default PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcSystem_WrappersMetrics_Default PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcSystem_WrappersMetrics_Default PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/system_wrappers)
set_target_properties(WebrtcSystem_WrappersMetrics_Default PROPERTIES OUTPUT_NAME metrics_default)
target_link_libraries(WebrtcSystem_WrappersMetrics_Default WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcSystem_WrappersMetrics_Default WebrtcWebrtc_Common)
# End of target WebrtcSystem_WrappersMetrics_Default


# Start of target WebrtcCommon_VideoCommon_Video
set(WebrtcCommon_VideoCommon_Video_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/bitrate_adjuster.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/h264/h264_bitstream_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/h264/h264_common.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/h264/pps_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/h264/sps_parser.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/h264/sps_vui_rewriter.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/i420_buffer_pool.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/incoming_video_stream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/webrtc_libyuv.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/video_frame.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/video_frame_buffer.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/video_render_frames.cc
    $<TARGET_OBJECTS:WebrtcApiVideo_Frame_Api>
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcCommon_VideoCommon_Video STATIC ${WebrtcCommon_VideoCommon_Video_SOURCES})
target_compile_options(WebrtcCommon_VideoCommon_Video PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCommon_VideoCommon_Video PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/libyuv/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/common_video/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/interface/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCommon_VideoCommon_Video PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcCommon_VideoCommon_Video PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/common_video)
set_target_properties(WebrtcCommon_VideoCommon_Video PROPERTIES OUTPUT_NAME common_video)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcWebrtc_Common)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcBaseRtc_Task_Queue)
target_link_libraries(WebrtcCommon_VideoCommon_Video Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcWebrtc_Common)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcP2PLibstunprober)
target_link_libraries(WebrtcCommon_VideoCommon_Video WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcCommon_VideoCommon_Video Third_PartyLibyuvLibyuv_Internal)
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_VideoCommon_Video ${JPEG_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_VideoCommon_Video ${RT_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_VideoCommon_Video ${DL_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcCommon_VideoCommon_Video ${XEXT_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_VideoCommon_Video ${X11_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcCommon_VideoCommon_Video ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcCommon_VideoCommon_Video ${XRENDER_LIBRARY})
target_include_directories(WebrtcCommon_VideoCommon_Video PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcCommon_VideoCommon_Video ${EVENT_LIBRARY})
# End of target WebrtcCommon_VideoCommon_Video

# Start of target WebrtcModulesAudio_CodingAudio_Format_Conversion
set(WebrtcModulesAudio_CodingAudio_Format_Conversion_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/audio_format_conversion.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingAudio_Format_Conversion STATIC ${WebrtcModulesAudio_CodingAudio_Format_Conversion_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingAudio_Format_Conversion PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingAudio_Format_Conversion PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcModulesAudio_CodingAudio_Format_Conversion PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingAudio_Format_Conversion PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingAudio_Format_Conversion PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingAudio_Format_Conversion PROPERTIES OUTPUT_NAME audio_format_conversion)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Format_Conversion WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingAudio_Format_Conversion WebrtcBaseRtc_Base_Approved)
# End of target WebrtcModulesAudio_CodingAudio_Format_Conversion

# Start of target WebrtcBaseRtc_Json
set(WebrtcBaseRtc_Json_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/json.cc)
add_library(WebrtcBaseRtc_Json OBJECT ${WebrtcBaseRtc_Json_SOURCES})
target_compile_options(WebrtcBaseRtc_Json PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseRtc_Json PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcBaseRtc_Json PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/source/include/ ${LIBWEBRTC_INPUT_DIR}/third_party/jsoncpp/overrides/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseRtc_Json PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcBaseRtc_Json Third_PartyJsoncppJsoncpp)
# End of target WebrtcBaseRtc_Json

# Start of target WebrtcAudioUtilityAudio_Frame_Operations
set(WebrtcAudioUtilityAudio_Frame_Operations_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/audio/utility/audio_frame_operations.cc)
add_library(WebrtcAudioUtilityAudio_Frame_Operations STATIC ${WebrtcAudioUtilityAudio_Frame_Operations_SOURCES})
target_compile_options(WebrtcAudioUtilityAudio_Frame_Operations PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcAudioUtilityAudio_Frame_Operations PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcAudioUtilityAudio_Frame_Operations PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcAudioUtilityAudio_Frame_Operations PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcAudioUtilityAudio_Frame_Operations PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/audio/utility)
set_target_properties(WebrtcAudioUtilityAudio_Frame_Operations PROPERTIES OUTPUT_NAME audio_frame_operations)
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations WebrtcWebrtc_Common)
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations WebrtcModulesAudio_CodingAudio_Format_Conversion)
target_include_directories(WebrtcAudioUtilityAudio_Frame_Operations PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations ${JPEG_LIBRARY})
target_include_directories(WebrtcAudioUtilityAudio_Frame_Operations PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcAudioUtilityAudio_Frame_Operations ${RT_LIBRARY})
# End of target WebrtcAudioUtilityAudio_Frame_Operations

# Start of target Third_PartyLibyuvLibyuv
add_custom_target(Third_PartyLibyuvLibyuv)
add_dependencies(Third_PartyLibyuvLibyuv Third_PartyLibyuvLibyuv_Internal)
# End of target Third_PartyLibyuvLibyuv

# Start of target WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal
set(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/builtin_audio_encoder_factory_internal.cc
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal STATIC ${WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal_SOURCES})
target_compile_options(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE WEBRTC_CODEC_ILBC WEBRTC_CODEC_OPUS WEBRTC_OPUS_SUPPORT_120MS_PTIME=0 WEBRTC_CODEC_ISAC WEBRTC_CODEC_G722 WEBRTC_CODEC_RED USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_PTHREAD)
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g711/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/red/ ${LIBWEBRTC_INPUT_DIR}/third_party/opus/src/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/isac/main/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/g722/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/pcm16b/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/cng/include/ ${LIBWEBRTC_INPUT_DIR}/webrtc/modules/audio_coding/codecs/ilbc/include/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/modules/audio_coding)
set_target_properties(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PROPERTIES OUTPUT_NAME builtin_audio_encoder_factory_internal)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcWebrtc_Common)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingCng)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingG711)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingG722)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingIlbc)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingIsac)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingPcm16B)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingRed)
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcModulesAudio_CodingWebrtc_Opus)
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${RT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${JPEG_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${DL_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${XEXT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${X11_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${XRENDER_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${EVENT_LIBRARY})
target_include_directories(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal PRIVATE ${M_INCLUDE_DIR})
target_link_libraries(WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal ${M_LIBRARY})
# End of target WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal

# Start of target WebrtcCallRtp_Sender
set(WebrtcCallRtp_Sender_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/call/rtp_transport_controller_send.cc)
add_library(WebrtcCallRtp_Sender OBJECT ${WebrtcCallRtp_Sender_SOURCES})
target_compile_options(WebrtcCallRtp_Sender PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcCallRtp_Sender PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcCallRtp_Sender PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcCallRtp_Sender PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
add_dependencies(WebrtcCallRtp_Sender WebrtcBaseRtc_Base_Approved WebrtcModulesCongestion_ControllerCongestion_Controller)
# End of target WebrtcCallRtp_Sender

# Start of target Third_PartyBoringsslBoringssl
set(Third_PartyBoringsslBoringssl_SOURCES ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/err_data.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_bitstr.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_bool.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_d2i_fp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_dup.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_enum.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_gentm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_i2d_fp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_int.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_mbstr.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_object.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_octet.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_print.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_strnid.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_time.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_type.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_utctm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/a_utf8.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/asn1_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/asn1_par.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/asn_pack.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/f_enum.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/f_int.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/f_string.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_dec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_enc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_fre.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_new.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_typ.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/tasn_utl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/asn1/time_support.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/base64/base64.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/bio.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/bio_mem.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/connect.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/fd.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/file.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/hexdump.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/pair.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/printf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/socket.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bio/socket_helper.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bn_extra/bn_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bn_extra/convert.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/buf/buf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bytestring/asn1_compat.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bytestring/ber.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bytestring/cbb.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/bytestring/cbs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/chacha/chacha.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/cipher_extra.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/derive_key.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_aesctrhmac.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_aesgcmsiv.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_chacha20poly1305.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_null.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_rc2.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_rc4.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_ssl3.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/e_tls.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cipher_extra/tls_cbc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cmac/cmac.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/conf/conf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cpu-aarch64-linux.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cpu-arm-linux.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cpu-arm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cpu-intel.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/cpu-ppc64le.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/crypto.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/curve25519/curve25519.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/curve25519/spake25519.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/curve25519/x25519-x86_64.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dh/check.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dh/dh.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dh/dh_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dh/params.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/digest_extra/digest_extra.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dsa/dsa.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/dsa/dsa_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/ec_extra/ec_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/ecdh/ecdh.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/ecdsa_extra/ecdsa_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/engine/engine.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/err/err.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/digestsign.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/evp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/evp_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/evp_ctx.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_dsa_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_ec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_ec_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_ed25519.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_ed25519_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_rsa.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/p_rsa_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/pbkdf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/print.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/scrypt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/evp/sign.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/ex_data.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/fipsmodule/bcm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/fipsmodule/is_fips.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/hkdf/hkdf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/lhash/lhash.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/mem.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/obj/obj.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/obj/obj_xref.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_all.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_info.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_oth.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_pk8.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_pkey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pem/pem_xaux.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pkcs7/pkcs7.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pkcs7/pkcs7_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pkcs8/p5_pbev2.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pkcs8/pkcs8.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pkcs8/pkcs8_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/poly1305/poly1305.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/poly1305/poly1305_arm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/poly1305/poly1305_vec.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/pool/pool.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rand_extra/deterministic.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rand_extra/forkunsafe.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rand_extra/fuchsia.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rand_extra/rand_extra.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rand_extra/windows.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rc4/rc4.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/refcount_c11.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/refcount_lock.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/rsa_extra/rsa_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/stack/stack.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/thread.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/thread_none.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/thread_pthread.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/thread_win.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/a_digest.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/a_sign.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/a_strex.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/a_verify.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/algorithm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/asn1_gen.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/by_dir.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/by_file.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/i2d_pr.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/rsa_pss.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/t_crl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/t_req.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/t_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/t_x509a.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_att.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_cmp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_d2.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_def.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_ext.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_lu.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_obj.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_r2x.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_req.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_set.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_trs.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_txt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_v3.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_vfy.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509_vpm.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509cset.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509name.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509rset.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x509spki.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_algor.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_all.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_attrib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_crl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_exten.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_info.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_name.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_pkey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_pubkey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_req.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_sig.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_spki.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_val.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509/x_x509a.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_cache.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_data.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_map.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_node.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/pcy_tree.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_akey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_akeya.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_alt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_bcons.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_bitst.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_conf.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_cpols.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_crld.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_enum.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_extku.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_genn.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_ia5.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_info.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_int.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_ncons.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_pci.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_pcia.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_pcons.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_pku.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_pmaps.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_prn.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_purp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_skey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_sxnet.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/crypto/x509v3/v3_utl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/bio_ssl.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/custom_extensions.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/d1_both.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/d1_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/d1_pkt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/d1_srtp.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/dtls_method.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/dtls_record.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/handshake_client.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/handshake_server.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/s3_both.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/s3_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/s3_pkt.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_aead_ctx.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_asn1.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_buffer.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_cert.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_cipher.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_ecdh.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_file.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_privkey.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_privkey_cc.cc
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_session.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_stat.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_transcript.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/ssl_x509.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/t1_enc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/t1_lib.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls13_both.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls13_client.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls13_enc.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls13_server.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls_method.c
    ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/ssl/tls_record.c
    # $<TARGET_OBJECTS:Third_PartyBoringsslBoringssl_Asm>
)
add_library(Third_PartyBoringsslBoringssl STATIC ${Third_PartyBoringsslBoringssl_SOURCES})
target_compile_options(Third_PartyBoringsslBoringssl PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "$<$<COMPILE_LANGUAGE:C>:-std=c99>" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "-UHAVE_CONFIG_H" "-DOPENSSL_NO_ASM=1")
target_compile_definitions(Third_PartyBoringsslBoringssl PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 BORINGSSL_IMPLEMENTATION BORINGSSL_NO_STATIC_INITIALIZER OPENSSL_SMALL _XOPEN_SOURCE=700)
target_include_directories(Third_PartyBoringsslBoringssl PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/boringssl/src/include/)
set_target_properties(Third_PartyBoringsslBoringssl PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Wl,--gdb-index")
set_target_properties(Third_PartyBoringsslBoringssl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/)
set_target_properties(Third_PartyBoringsslBoringssl PROPERTIES OUTPUT_NAME boringssl)
# End of target Third_PartyBoringsslBoringssl

# Start of target WebrtcApiCall_Api
set(WebrtcApiCall_Api_SOURCES $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>)
add_library(WebrtcApiCall_Api STATIC ${WebrtcApiCall_Api_SOURCES})
target_compile_options(WebrtcApiCall_Api PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcApiCall_Api PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcApiCall_Api PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcApiCall_Api PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
target_link_libraries(WebrtcApiCall_Api WebrtcWebrtc_Common)
target_link_libraries(WebrtcApiCall_Api WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcApiCall_Api Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcApiCall_Api WebrtcSystem_WrappersSystem_Wrappers)
target_include_directories(WebrtcApiCall_Api PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcApiCall_Api ${JPEG_LIBRARY})
target_include_directories(WebrtcApiCall_Api PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcApiCall_Api ${RT_LIBRARY})
# End of target WebrtcApiCall_Api

# Start of target WebrtcBaseWeak_Ptr
set(WebrtcBaseWeak_Ptr_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/base/weak_ptr.cc)
add_library(WebrtcBaseWeak_Ptr STATIC ${WebrtcBaseWeak_Ptr_SOURCES})
target_compile_options(WebrtcBaseWeak_Ptr PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcBaseWeak_Ptr PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT)
target_include_directories(WebrtcBaseWeak_Ptr PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcBaseWeak_Ptr PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcBaseWeak_Ptr PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/base)
set_target_properties(WebrtcBaseWeak_Ptr PROPERTIES OUTPUT_NAME weak_ptr)
target_link_libraries(WebrtcBaseWeak_Ptr WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcBaseWeak_Ptr WebrtcBaseSequenced_Task_Checker)
target_include_directories(WebrtcBaseWeak_Ptr PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcBaseWeak_Ptr ${EVENT_LIBRARY})
# End of target WebrtcBaseWeak_Ptr

# Start of target WebrtcStatsRtc_Stats
set(WebrtcStatsRtc_Stats_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/stats/rtcstats.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/stats/rtcstats_objects.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/stats/rtcstatsreport.cc)
add_library(WebrtcStatsRtc_Stats STATIC ${WebrtcStatsRtc_Stats_SOURCES})
target_compile_options(WebrtcStatsRtc_Stats PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcStatsRtc_Stats PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
target_include_directories(WebrtcStatsRtc_Stats PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
set_target_properties(WebrtcStatsRtc_Stats PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcStatsRtc_Stats PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/stats)
set_target_properties(WebrtcStatsRtc_Stats PROPERTIES OUTPUT_NAME rtc_stats)
target_link_libraries(WebrtcStatsRtc_Stats WebrtcBaseRtc_Base_Approved)
# End of target WebrtcStatsRtc_Stats

# Start of target WebrtcPcPeerconnection
set(WebrtcPcPeerconnection_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/audiotrack.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/datachannel.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/dtmfsender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/iceserverparsing.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/jsepicecandidate.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/jsepsessiondescription.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/localaudiosource.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/mediastream.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/mediastreamobserver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/peerconnection.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/peerconnectionfactory.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/remoteaudiosource.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/rtcstatscollector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/rtpreceiver.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/rtpsender.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/sctputils.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/statscollector.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/trackmediainfomap.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/videocapturertracksource.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/videotrack.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/videotracksource.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/webrtcsdp.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/webrtcsession.cc
    ${LIBWEBRTC_INPUT_DIR}/webrtc/pc/webrtcsessiondescriptionfactory.cc
    $<TARGET_OBJECTS:WebrtcCallCall_Interfaces>
    $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api>
    $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base>)
add_library(WebrtcPcPeerconnection STATIC ${WebrtcPcPeerconnection_SOURCES})
target_compile_options(WebrtcPcPeerconnection PRIVATE "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
target_compile_definitions(WebrtcPcPeerconnection PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX WEBRTC_BUILD_LIBEVENT HAVE_SCTP FEATURE_ENABLE_VOICEMAIL)
target_include_directories(WebrtcPcPeerconnection PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libjpeg_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/shim_headers/libevent_shim/ ${LIBWEBRTC_OUTPUT_DIR}/gen/ ${LIBWEBRTC_INPUT_DIR}/third_party/libyuv/include/)
set_target_properties(WebrtcPcPeerconnection PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
set_target_properties(WebrtcPcPeerconnection PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/pc)
set_target_properties(WebrtcPcPeerconnection PROPERTIES OUTPUT_NAME peerconnection)
target_link_libraries(WebrtcPcPeerconnection WebrtcApiCall_Api)
target_link_libraries(WebrtcPcPeerconnection WebrtcApiLibjingle_Peerconnection_Api)
target_link_libraries(WebrtcPcPeerconnection Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcPcPeerconnection WebrtcSystem_WrappersSystem_Wrappers)
target_link_libraries(WebrtcPcPeerconnection WebrtcBaseRtc_Base_Approved)
target_link_libraries(WebrtcPcPeerconnection WebrtcCommon_VideoCommon_Video)
target_link_libraries(WebrtcPcPeerconnection WebrtcMediaRtc_Data)
target_link_libraries(WebrtcPcPeerconnection Third_PartyLibyuvLibyuv_Internal)
target_link_libraries(WebrtcPcPeerconnection WebrtcWebrtc_Common)
target_link_libraries(WebrtcPcPeerconnection WebrtcBaseRtc_Base)
target_link_libraries(WebrtcPcPeerconnection WebrtcP2PLibstunprober)
target_link_libraries(WebrtcPcPeerconnection WebrtcP2PRtc_P2P)
target_link_libraries(WebrtcPcPeerconnection WebrtcPcRtc_Pc_Base)
target_link_libraries(WebrtcPcPeerconnection WebrtcStatsRtc_Stats)
target_include_directories(WebrtcPcPeerconnection PRIVATE ${DL_INCLUDE_DIR})
target_link_libraries(WebrtcPcPeerconnection ${DL_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${RT_INCLUDE_DIR})
target_link_libraries(WebrtcPcPeerconnection ${RT_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${XEXT_INCLUDE_DIR})
# target_link_libraries(WebrtcPcPeerconnection ${XEXT_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(WebrtcPcPeerconnection ${X11_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${XCOMPOSITE_INCLUDE_DIR})
# target_link_libraries(WebrtcPcPeerconnection ${XCOMPOSITE_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${XRENDER_INCLUDE_DIR})
# target_link_libraries(WebrtcPcPeerconnection ${XRENDER_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${JPEG_INCLUDE_DIR})
target_link_libraries(WebrtcPcPeerconnection ${JPEG_LIBRARY})
target_include_directories(WebrtcPcPeerconnection PRIVATE ${EVENT_INCLUDE_DIR})
target_link_libraries(WebrtcPcPeerconnection ${EVENT_LIBRARY})
# End of target WebrtcPcPeerconnection

# Start of target WebrtcCommon_AudioCommon_Audio_Sse2
# set(WebrtcCommon_AudioCommon_Audio_Sse2_SOURCES ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/fir_filter_sse.cc
#     ${LIBWEBRTC_INPUT_DIR}/webrtc/common_audio/resampler/sinc_resampler_sse.cc)
# add_library(WebrtcCommon_AudioCommon_Audio_Sse2 STATIC ${WebrtcCommon_AudioCommon_Audio_Sse2_SOURCES})
# target_compile_options(WebrtcCommon_AudioCommon_Audio_Sse2 PRIVATE  "-fno-strict-aliasing" "--param=ssp-buffer-size=4" "-fstack-protector" "-Wno-builtin-macro-redefined" "-D__DATE__=" "-D__TIME__=" "-D__TIMESTAMP__=" "-funwind-tables" "-fPIC" "-pipe" "-B../third_party/binutils/Linux_x64/Release/bin" "-pthread"  "-march=armv7" "-Wno-unused-local-typedefs" "-Wno-missing-field-initializers" "-Wno-unused-parameter" "-O0" "-fno-omit-frame-pointer" "-g2" "-gsplit-dwarf" "-fvisibility=hidden" "-Wno-unused-parameter" "-Wno-missing-field-initializers" "-Wno-strict-overflow" "$<$<COMPILE_LANGUAGE:CXX>:-std=gnu++11>" "$<$<COMPILE_LANGUAGE:CXX>:-Wno-narrowing>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>" "$<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>" "$<$<COMPILE_LANGUAGE:CXX>:-fvisibility-inlines-hidden>" "$<$<COMPILE_LANGUAGE:CXX>:-Wnon-virtual-dtor>" "$<$<COMPILE_LANGUAGE:CXX>:-Woverloaded-virtual>" "-UHAVE_CONFIG_H")
# target_compile_definitions(WebrtcCommon_AudioCommon_Audio_Sse2 PRIVATE USE_UDEV USE_AURA=1 USE_PANGO=1 USE_CAIRO=1 USE_GLIB=1 USE_NSS_CERTS=1 USE_X11=1 FULL_SAFE_BROWSING SAFE_BROWSING_CSD SAFE_BROWSING_DB_LOCAL CHROMIUM_BUILD FIELDTRIAL_TESTING_ENABLED _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE _LARGEFILE64_SOURCE __STDC_CONSTANT_MACROS __STDC_FORMAT_MACROS _DEBUG DYNAMIC_ANNOTATIONS_ENABLED=1 WTF_USE_DYNAMIC_ANNOTATIONS=1 WEBRTC_INCLUDE_INTERNAL_AUDIO_DEVICE EXPAT_RELATIVE_PATH HAVE_SCTP WEBRTC_POSIX WEBRTC_LINUX)
# target_include_directories(WebrtcCommon_AudioCommon_Audio_Sse2 PRIVATE ${LIBWEBRTC_INPUT_DIR}/ ${LIBWEBRTC_OUTPUT_DIR}/gen/)
# set_target_properties(WebrtcCommon_AudioCommon_Audio_Sse2 PROPERTIES LINK_FLAGS "-Wl,--fatal-warnings -fPIC -Wl,-z,noexecstack -Wl,-z,now -Wl,-z,relro -Wl,-z,defs -Wl,--no-as-needed -lpthread -Wl,--as-needed -fuse-ld=gold -B../third_party/binutils/Linux_x64/Release/bin -Wl,--icf=all - -Werror -Wl,--gdb-index")
# set_target_properties(WebrtcCommon_AudioCommon_Audio_Sse2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${LIBWEBRTC_OUTPUT_DIR}/obj/webrtc/common_audio)
# set_target_properties(WebrtcCommon_AudioCommon_Audio_Sse2 PROPERTIES OUTPUT_NAME common_audio_sse2)
# target_link_libraries(WebrtcCommon_AudioCommon_Audio_Sse2 WebrtcWebrtc_Common)
# target_link_libraries(WebrtcCommon_AudioCommon_Audio_Sse2 WebrtcBaseRtc_Base_Approved)
# target_link_libraries(WebrtcCommon_AudioCommon_Audio_Sse2 WebrtcSystem_WrappersSystem_Wrappers)
# target_include_directories(WebrtcCommon_AudioCommon_Audio_Sse2 PRIVATE ${RT_INCLUDE_DIR})
# target_link_libraries(WebrtcCommon_AudioCommon_Audio_Sse2 ${RT_LIBRARY})
# End of target WebrtcCommon_AudioCommon_Audio_Sse2

# Start of target LIBWEBRTC
add_library(webrtc STATIC $<TARGET_OBJECTS:WebrtcBaseRtc_Json> $<TARGET_OBJECTS:WebrtcCallRtp_Receiver> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingG711_C> $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAec_Dump_Interface> $<TARGET_OBJECTS:WebrtcCallCall_Interfaces>
    # $<TARGET_OBJECTS:Third_PartyBoringsslBoringssl_Asm>
    $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_C> $<TARGET_OBJECTS:WebrtcCommon_AudioCommon_Audio_C> $<TARGET_OBJECTS:WebrtcPcCreate_Pc_Factory> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingNeteq_Decoder_Enum> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIlbc_C> $<TARGET_OBJECTS:WebrtcCallRtp_Sender> $<TARGET_OBJECTS:WebrtcApiAudio_CodecsAudio_Codecs_Api> $<TARGET_OBJECTS:Third_PartyGflagsGflags> $<TARGET_OBJECTS:WebrtcCommon_AudioCommon_Audio_Cc> $<TARGET_OBJECTS:WebrtcMediaRtc_Media_Base> $<TARGET_OBJECTS:WebrtcModulesAudio_ProcessingAudio_Processing_C> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingIsac_Fix_Common> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingPcm16B_C> $<TARGET_OBJECTS:WebrtcApiVideo_Frame_Api> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingWebrtc_Opus_C> $<TARGET_OBJECTS:WebrtcModulesAudio_CodingG722_C> $<TARGET_OBJECTS:Third_PartyJsoncppJsoncpp>)
target_link_libraries(webrtc
    # WebrtcCommon_AudioCommon_Audio_Sse2
    WebrtcBaseRtc_Base WebrtcModulesAudio_CodingLegacy_Encoded_Audio_Frame WebrtcModulesAudio_MixerAudio_Frame_Manipulator WebrtcModulesAudio_CodingAudio_Network_Adaptor WebrtcModulesBitrate_ControllerBitrate_Controller WebrtcCommon_VideoCommon_Video WebrtcCallCall WebrtcModulesUtilityUtility WebrtcPcPeerconnection WebrtcToolsVideo_Quality_Analysis WebrtcP2PLibstunprober WebrtcModulesVideo_CodingWebrtc_I420 WebrtcModulesVideo_ProcessingVideo_Processing WebrtcModulesVideo_CodingWebrtc_Vp9 WebrtcModulesVideo_CodingWebrtc_Vp8 WebrtcBaseRtc_Numerics
    WebrtcModulesAudio_DeviceAudio_Device
    WebrtcVoice_EngineAudio_Coder WebrtcModulesAudio_CodingBuiltin_Audio_Encoder_Factory_Internal WebrtcSystem_WrappersSystem_Wrappers
    # WebrtcModulesDesktop_CaptureDesktop_Capture_Differ_Sse2
    Third_PartyLibsrtpLibsrtp WebrtcToolsCommand_Line_Parser WebrtcModulesAudio_CodingG722 WebrtcModulesMedia_FileMedia_File WebrtcSystem_WrappersCpu_Features_Linux WebrtcModulesAudio_CodingNeteq WebrtcModulesAudio_CodingIsac WebrtcModulesAudio_CodingPcm16B WebrtcWebrtc_Common WebrtcModulesAudio_CodingCng WebrtcModulesAudio_CodingAudio_Format_Conversion WebrtcModulesVideo_CodingWebrtc_H264 WebrtcModulesAudio_CodingWebrtc_Opus WebrtcBaseSequenced_Task_Checker WebrtcModulesPacingPacing Third_PartyBoringsslBoringssl WebrtcAudioAudio WebrtcVoice_EngineAudio_Level WebrtcModulesAudio_CodingIlbc WebrtcPcRtc_Pc_Base WebrtcApiAudio_CodecsG722Audio_Decoder_G722 WebrtcModulesAudio_MixerAudio_Mixer_Impl WebrtcVideoVideo Third_PartyUsrsctpUsrsctp WebrtcModulesAudio_CodingIsac_C WebrtcAudioUtilityAudio_Frame_Operations WebrtcModulesAudio_CodingIsac_Common WebrtcApiLibjingle_Peerconnection_Api WebrtcModulesAudio_CodingRent_A_Codec WebrtcModulesVideo_CaptureVideo_Capture_Internal_Impl WebrtcCommon_AudioCommon_Audio WebrtcVoice_EngineVoice_Engine WebrtcModulesAudio_CodingRed WebrtcModulesAudio_CodingIsac_Fix
    # WebrtcModulesDesktop_CaptureDesktop_Capture
    WebrtcVoice_EngineFile_Recorder WebrtcToolsReference_Less_Video_Analysis_Lib WebrtcModulesVideo_CaptureVideo_Capture_Module WebrtcBaseRtc_Base_Approved WebrtcModulesDesktop_CapturePrimitives WebrtcSystem_WrappersField_Trial_Default WebrtcApiAudio_CodecsG722Audio_Encoder_G722 WebrtcModulesCongestion_ControllerCongestion_Controller WebrtcLoggingRtc_Event_Log_Impl WebrtcApiAudio_CodecsBuiltin_Audio_Decoder_Factory WebrtcMediaRtc_Data Third_PartyOpusOpus WebrtcSystem_WrappersMetrics_Default WebrtcToolsFrame_Editing_Lib WebrtcModulesVideo_CodingVideo_Coding WebrtcP2PRtc_P2P WebrtcModulesAudio_CodingBuiltin_Audio_Decoder_Factory_Internal WebrtcModulesAudio_ProcessingAudio_Processing WebrtcApiAudio_CodecsBuiltin_Audio_Encoder_Factory WebrtcBaseRtc_Task_Queue WebrtcModulesAudio_CodingG711 WebrtcModulesVideo_CaptureVideo_Capture WebrtcModulesRtp_RtcpRtp_Rtcp WebrtcStatsRtc_Stats Third_PartyLibyuvLibyuv_Internal WebrtcModulesRemote_Bitrate_EstimatorRemote_Bitrate_Estimator WebrtcModulesAudio_CodingAudio_Coding
    # WebrtcModulesAudio_ProcessingAudio_Processing_Sse2
    WebrtcBaseWeak_Ptr WebrtcModulesVideo_CodingVideo_Coding_Utility WebrtcVoice_EngineFile_Player WebrtcMediaRtc_Audio_Video)
# End of target LIBWEBRTC
