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
#include "GStreamerVideoCapturer.h"

#include "GStreamerUtilities.h"

#include <gst/app/gstappsink.h>

namespace WebCore {

GStreamerVideoCapturer::GStreamerVideoCapturer(GStreamerCaptureDevice device)
    : GStreamerCapturer(device, adoptGRef(gst_caps_new_empty_simple("video/x-raw")))
{
}

GStreamerVideoCapturer::GStreamerVideoCapturer(const gchar* sourceFactory)
    : GStreamerCapturer(sourceFactory, adoptGRef(gst_caps_new_empty_simple("video/x-raw")))
{
}

void GStreamerVideoCapturer::setupPipeline()
{
    m_pipeline = makeElement("pipeline");

    GStreamerCapturer::setupPipeline();

    GstElement* source = createSource();
    GstElement* converter = gst_parse_bin_from_description("videoscale ! videoconvert ! videorate",
        TRUE, nullptr); // FIXME Handle errors.

    // Gonna pass our new ref to the pipeline.
    m_capsfilter = makeElement("capsfilter");
    m_tee = makeElement("tee");
    m_sink = makeElement("appsink");

    gst_app_sink_set_emit_signals(GST_APP_SINK(m_sink.get()), TRUE);

    gst_bin_add_many(GST_BIN(m_pipeline.get()), source, converter,
        m_capsfilter.get(), m_tee.get(), nullptr);
    gst_element_link_many(source, converter, m_capsfilter.get(), m_tee.get(), nullptr);
    g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    addSink(m_sink.get());
}

GstVideoInfo GStreamerVideoCapturer::getBestFormat()
{
    GstCaps* caps = gst_caps_fixate(gst_device_get_caps(m_device.get()));
    GstVideoInfo info;
    gst_video_info_from_caps(&info, caps);
    gst_caps_unref(caps);

    return info;
}

bool GStreamerVideoCapturer::setSize(int width, int height)
{
    if (!width || !height)
        return false;

    GstCaps* caps = gst_caps_copy(m_caps.get());
    gst_caps_set_simple(caps, "width", G_TYPE_INT, width, "height",
        G_TYPE_INT, height, nullptr);
    m_caps = adoptGRef(caps);

    if (!m_capsfilter)
        return false;

    g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    return true;
}

bool GStreamerVideoCapturer::setFrameRate(double frameRate)
{
    int numerator, denominator;

    gst_util_double_to_fraction(frameRate, &numerator, &denominator);

    if (numerator < -G_MAXINT) {
        GST_INFO_OBJECT(m_pipeline.get(), "Framerate %f not allowed",
            frameRate);
        return false;
    }

    if (!numerator) {
        GST_ERROR_OBJECT(m_pipeline.get(), "Do not force variable frameRate");
        return false;
    }

    auto caps = gst_caps_copy(m_caps.get());
    gst_caps_set_simple(caps, "framerate",
        GST_TYPE_FRACTION, numerator, denominator, nullptr);
    m_caps = adoptGRef(caps);

    if (!m_capsfilter)
        return false;

    g_object_set(m_capsfilter.get(), "caps", m_caps.get(), nullptr);

    return true;
}

} // namespace WebCore
#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
