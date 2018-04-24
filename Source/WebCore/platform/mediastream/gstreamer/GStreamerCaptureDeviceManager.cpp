/*
 *  Copyright (C) 2017 Igalia S.L. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "config.h"

#if ENABLE(MEDIA_STREAM) && USE(GSTREAMER)
#include "GStreamerCaptureDeviceManager.h"

#include "GStreamerCommon.h"
#include <wtf/glib/GUniquePtr.h>

namespace WebCore {

GStreamerAudioCaptureDeviceManager& GStreamerAudioCaptureDeviceManager::singleton()
{
    static NeverDestroyed<GStreamerAudioCaptureDeviceManager> manager;
    return manager;
}

GStreamerVideoCaptureDeviceManager& GStreamerVideoCaptureDeviceManager::singleton()
{
    static NeverDestroyed<GStreamerVideoCaptureDeviceManager> manager;
    return manager;
}

GStreamerDisplayCaptureDeviceManager& GStreamerDisplayCaptureDeviceManager::singleton()
{
    static NeverDestroyed<GStreamerDisplayCaptureDeviceManager> manager;
    return manager;
}

std::optional<GStreamerCaptureDevice> GStreamerCaptureDeviceManager::gstreamerDeviceWithUID(const String& deviceID)
{
    initializeGStreamer();
    if (m_gstreamerDevices.isEmpty())
        refreshCaptureDevices();

    for (auto& device : m_gstreamerDevices) {
        if (device.persistentId() == deviceID)
            return device;
    }
    return std::nullopt;
}

Vector<CaptureDevice>& GStreamerCaptureDeviceManager::captureDevices()
{
    initializeGStreamer();
    if (m_devices.isEmpty())
        refreshCaptureDevices();

    return m_devices;
}

void GStreamerCaptureDeviceManager::deviceAdded(GstDevice* device)
{
    GstStructure* properties = gst_device_get_properties(device);
    const gchar* klass = gst_structure_get_string(properties, "device.class");

    if (klass && !g_strcmp0(klass, "monitor")) {
        gst_structure_free(properties);
        return;
    }
    gst_structure_free(properties);

    CaptureDevice::DeviceType type = deviceType();
    GUniquePtr<gchar> deviceClassChar(gst_device_get_device_class(device));
    String deviceClass(String(deviceClassChar.get()));
    if (type == CaptureDevice::DeviceType::Microphone && !deviceClass.startsWith("Audio"))
        return;
    if (type == CaptureDevice::DeviceType::Camera && !deviceClass.startsWith("Video"))
        return;

    // FIXME: This isn't really a UID but should be good enough (libwebrtc itself does that
    // at least for pulseaudio devices.)
    GUniquePtr<gchar> deviceName(gst_device_get_display_name(device));
    String identifier = String::fromUTF8(deviceName.get());

    auto gstCaptureDevice = GStreamerCaptureDevice(device, identifier, type, identifier);
    gstCaptureDevice.setEnabled(true);
    m_gstreamerDevices.append(WTFMove(gstCaptureDevice));
    auto captureDevice = CaptureDevice(identifier, type, identifier);
    captureDevice.setEnabled(true);
    m_devices.append(WTFMove(captureDevice));
}

void GStreamerCaptureDeviceManager::refreshCaptureDevices()
{
    if (!m_deviceMonitor) {
        m_deviceMonitor = adoptGRef(gst_device_monitor_new());

        CaptureDevice::DeviceType type = deviceType();
        if (type == CaptureDevice::DeviceType::Camera) {
            GRefPtr<GstCaps> caps = adoptGRef(gst_caps_new_empty_simple("video/x-raw"));
            gst_device_monitor_add_filter(m_deviceMonitor.get(), "Video/Source", caps.get());
            GRefPtr<GstCaps> compressedCaps = adoptGRef(gst_caps_new_empty_simple("video/x-h264"));
            gst_device_monitor_add_filter(m_deviceMonitor.get(), "Video/Source", compressedCaps.get());
        } else if (type == CaptureDevice::DeviceType::Microphone) {
            GRefPtr<GstCaps> caps = adoptGRef(gst_caps_new_empty_simple("audio/x-raw"));
            gst_device_monitor_add_filter(m_deviceMonitor.get(), "Audio/Source", caps.get());
        }

        // TODO: Monitor for added/removed messages on the bus.
    }

    if (!gst_device_monitor_start(m_deviceMonitor.get())) {
        GST_WARNING_OBJECT(m_deviceMonitor.get(), "Could not start device monitor");
        m_deviceMonitor = nullptr;

        return;
    }

    GList* devices = gst_device_monitor_get_devices(m_deviceMonitor.get());
    while (devices) {
        GRefPtr<GstDevice> device = adoptGRef(GST_DEVICE_CAST(devices->data));
        deviceAdded(device.get());
        devices = g_list_delete_link(devices, devices);
    }

    gst_device_monitor_stop(m_deviceMonitor.get());
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(GSTREAMER)
