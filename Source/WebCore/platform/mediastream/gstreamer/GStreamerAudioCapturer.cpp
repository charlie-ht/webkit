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

#include "LibWebRTCAudioFormat.h"

#include <gst/app/gstappsink.h>

namespace WebCore {

GStreamerAudioCapturer::GStreamerAudioCapturer(GStreamerCaptureDevice device)
    : GStreamerCapturer(device, adoptGRef(gst_caps_new_simple("audio/x-raw", "rate", G_TYPE_INT, LibWebRTCAudioFormat::sampleRate, nullptr)))
{
}

GStreamerAudioCapturer::GStreamerAudioCapturer()
    : GStreamerCapturer("audiotestsrc", adoptGRef(gst_caps_new_simple("audio/x-raw", "rate", G_TYPE_INT, LibWebRTCAudioFormat::sampleRate, nullptr)))
{
}

GstElement* GStreamerAudioCapturer::createConverter()
{
    // FIXME Handle errors.
    return gst_parse_bin_from_description("audioconvert ! audioresample", TRUE, nullptr);
}

bool GStreamerAudioCapturer::setSampleRate(int sampleRate)
{

    if (sampleRate > 0) {
        GST_INFO_OBJECT(m_pipeline.get(), "Setting SampleRate %d", sampleRate);
        m_caps = adoptGRef(gst_caps_new_simple("audio/x-raw", "rate", G_TYPE_INT, sampleRate, nullptr));
    } else {
        GST_INFO_OBJECT(m_pipeline.get(), "Not forcing sample rate");
        m_caps = adoptGRef(gst_caps_new_empty_simple("audio/x-raw"));
    }

    if (!m_capsfilter.get())
        return false;

    g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    return true;
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
