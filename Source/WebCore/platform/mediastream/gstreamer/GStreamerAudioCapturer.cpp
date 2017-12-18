/*
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "GStreamerAudioCapturer.h"
#include <gst/app/gstappsink.h>
#include "GStreamerUtilities.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
namespace WebCore {

GRefPtr<GstDeviceMonitor> GStreamerAudioCapturer::s_deviceMonitor = nullptr;
GStreamerAudioCapturer::GStreamerAudioCapturer(const String& deviceID)
    : m_deviceID(deviceID)
{
}

void GStreamerAudioCapturer::start() {
    if (!s_deviceMonitor) {
        initializeGStreamer ();

        s_deviceMonitor = gst_device_monitor_new ();

        gst_device_monitor_add_filter (s_deviceMonitor.get(), "Audio/Source", NULL);
    }

    GList *devices = gst_device_monitor_get_devices (s_deviceMonitor.get());
    for (GList *tmp = devices; tmp; tmp = tmp->next) {
        GstDevice * device = GST_DEVICE (tmp->data);

        String display_name = String::fromUTF8(gst_device_get_display_name (device));
        // HACK- libwebrtc adds 'default: ' before the default device
        // name.
        String default_name = String("default: ");
        default_name.append(display_name);

        if (m_deviceID == display_name || m_deviceID == default_name) {
            m_device = (GstDevice*) gst_object_ref (device);
            break;
        }
    }

    if (m_device) {
        m_pipeline = gst_element_factory_make ("pipeline", NULL);
        GRefPtr<GstElement> source = gst_device_create_element (m_device.get(), NULL);
        GRefPtr<GstElement> converter = gst_parse_bin_from_description ("audioconvert ! audioresample",
            TRUE, NULL); // FIXME Handle errors.
        m_sink = gst_element_factory_make ("appsink", NULL);
        gst_app_sink_set_emit_signals(GST_APP_SINK (m_sink.get()), TRUE);

        gst_bin_add_many (GST_BIN (m_pipeline.get()), source.get(), converter.get(),
            m_sink.get(), NULL);
        gst_element_link_many (source.get(), converter.get(), m_sink.get(), NULL);
    }

    g_list_free_full (devices, gst_object_unref);
}

void GStreamerAudioCapturer::play() {
    g_assert(m_pipeline.get());

    String res = gst_element_state_change_return_get_name (
        gst_element_set_state (m_pipeline.get(), GST_STATE_PLAYING));
}

void GStreamerAudioCapturer::stop() {
    g_assert(m_pipeline.get());

    gst_element_set_state (m_pipeline.get(), GST_STATE_NULL);
}

} // namespace WebCore


#endif //ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
