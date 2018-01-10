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

GStreamerAudioCapturer::GStreamerAudioCapturer(GStreamerCaptureDevice device)
    : GStreamerCapturer(device, adoptGRef(gst_caps_new_empty_simple("audio/x-raw")))
{
    m_caps = adoptGRef(gst_caps_new_empty_simple("audio/x-raw"));
}

void GStreamerAudioCapturer::setupPipeline() {
    m_pipeline = gst_element_factory_make ("pipeline", "AudioCapturer");


    GRefPtr<GstElement> source = m_device.gstSourceElement();
    GRefPtr<GstElement> converter = gst_parse_bin_from_description ("audioconvert ! audioresample",
        TRUE, NULL); // FIXME Handle errors.
    GRefPtr<GstElement> m_capsfilter = gst_element_factory_make ("capsfilter", nullptr);
    m_sink = gst_element_factory_make ("appsink", NULL);

    gst_app_sink_set_emit_signals(GST_APP_SINK (m_sink.get()), TRUE);
    g_object_set (m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    gst_bin_add_many (GST_BIN (m_pipeline.get()), source.get(), converter.get(),
        m_capsfilter.get(), m_sink.get(), NULL);
    gst_element_link_many (source.get(), converter.get(), m_capsfilter.get(), m_sink.get(), NULL);

    GStreamerCapturer::setupPipeline();
}

bool GStreamerAudioCapturer::setSampleRate(int sampleRate)
{
    m_caps = adoptGRef(gst_caps_new_simple("audio/x-raw", "rate",
        G_TYPE_INT, sampleRate, nullptr));

    if (m_capsfilter.get())
        g_object_set (m_capsfilter.get(), "caps", m_caps.get(), nullptr);
}
} // namespace WebCore
#endif //ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
