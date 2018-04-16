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

#include "config.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
#include "GStreamerAudioCapturer.h"

#include "GStreamerUtilities.h"
#include "LibWebRTCAudioFormat.h"

#include <gst/app/gstappsink.h>

namespace WebCore {

GStreamerAudioCapturer::GStreamerAudioCapturer(GStreamerCaptureDevice device)
    : GStreamerCapturer(device, gst_caps_new_empty_simple("audio/x-raw"))
{
    m_caps = adoptGRef(gst_caps_new_simple("audio/x-raw", "rate",
        G_TYPE_INT, LibWebRTCAudioFormat::sampleRate, nullptr));
}

GStreamerAudioCapturer::GStreamerAudioCapturer()
    : GStreamerCapturer("audiotestsrc", gst_caps_new_empty_simple("audio/x-raw"))
{
    m_caps = adoptGRef(gst_caps_new_simple("audio/x-raw", "rate",
        G_TYPE_INT, LibWebRTCAudioFormat::sampleRate, nullptr));
}

void GStreamerAudioCapturer::setupPipeline()
{
    auto name = g_strdup_printf("AudioCapturer_%p", this);
    m_pipeline = makeElement("pipeline");
    g_free(name);

    GRefPtr<GstElement> source = createSource();
    GRefPtr<GstElement> converter = gst_parse_bin_from_description("audioconvert ! audioresample",
        TRUE, nullptr); // FIXME Handle errors.
    m_capsfilter = makeElement("capsfilter");
    m_tee = makeElement("tee");
    m_sink = makeElement("appsink");

    gst_app_sink_set_emit_signals(GST_APP_SINK(m_sink.get()), TRUE);
    g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    gst_bin_add_many(GST_BIN(m_pipeline.get()), source.get(), converter.get(),
        m_capsfilter.get(), m_tee.get(), nullptr);
    gst_element_link_many(source.get(), converter.get(), m_capsfilter.get(), m_tee.get(), NULL);
    addSink(m_sink.get());

    GStreamerCapturer::setupPipeline();
}

bool GStreamerAudioCapturer::setSampleRate(int sampleRate)
{
    GST_INFO_OBJECT(m_pipeline.get(), "Setting SampleRate %d", sampleRate);

    m_caps = adoptGRef(gst_caps_new_simple("audio/x-raw", "rate",
        G_TYPE_INT, sampleRate, nullptr));

    if (m_capsfilter.get()) {
        g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

        return true;
    }

    return false;
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
