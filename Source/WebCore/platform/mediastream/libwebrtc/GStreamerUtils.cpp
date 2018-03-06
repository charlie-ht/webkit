/*
 * Copyright (C) 2018 Igalia S.L. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#if USE(LIBWEBRTC) && USE(GSTREAMER)

#include <gst/gst.h>

#include "GStreamerUtils.h"
#include "GRefPtrGStreamer.h"

#include <wtf/glib/RunLoopSourcePriority.h>

namespace WebCore {
namespace GStreamer {

GstSample * SampleFromVideoFrame(const webrtc::VideoFrame& frame)
{
    if (frame.video_frame_buffer()->type() == webrtc::VideoFrameBuffer::Type::kNative) {
        auto framebuffer = static_cast<GStreamer::VideoFrame*>(frame.video_frame_buffer().get());
        auto gstsample = framebuffer->GetSample();
        GST_INFO ("Reusing native GStreamer buffer! %p", gstsample);
        return gstsample;
    }

    auto webrtcbuffer = frame.video_frame_buffer().get();
    auto buffer = gst_buffer_new();
    // FIXME - Check lifetime of those buffers.
    const uint8_t* comps[3] = {
        webrtcbuffer->DataY(),
        webrtcbuffer->DataU(),
        webrtcbuffer->DataV()
    };

    GstVideoInfo info;
    gst_video_info_set_format(&info, GST_VIDEO_FORMAT_I420, frame.width(),
        frame.height());
    for (gint i = 0; i < 3; i++) {
        gsize compsize = GST_VIDEO_INFO_COMP_STRIDE(&info, i) * GST_VIDEO_INFO_COMP_HEIGHT(&info, i);

        GstMemory* comp = gst_memory_new_wrapped(GST_MEMORY_FLAG_PHYSICALLY_CONTIGUOUS,
            (gpointer)comps[i], compsize, 0, compsize, webrtcbuffer, nullptr);
        gst_buffer_append_memory(buffer, comp);
    }

    auto caps = gst_video_info_to_caps (&info);
    auto sample = gst_sample_new (buffer, caps, nullptr, nullptr);
    gst_caps_unref (caps);
    return sample;
}

webrtc::VideoFrame *VideoFrameFromBuffer(GstSample *sample, webrtc::VideoRotation rotation)
{
    rtc::scoped_refptr<webrtc::VideoFrameBuffer> framebuf( VideoFrame::Create(sample));

    auto buffer = gst_sample_get_buffer (sample);
    auto frame = new webrtc::VideoFrame(framebuf,
        GST_BUFFER_DTS (buffer),
        GST_BUFFER_PTS (buffer),
        rotation);
    return frame;
}

static void simpleBusMessageCallback(GstBus*, GstMessage* message, GstBin* pipeline)
{
    switch (GST_MESSAGE_TYPE(message)) {
    case GST_MESSAGE_ERROR:
        GST_ERROR_OBJECT (pipeline, "Got message: %" GST_PTR_FORMAT, message);

        gchar* dump_name;
        dump_name = g_strdup_printf("%s_error", GST_OBJECT_NAME(pipeline));
        GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(pipeline, GST_DEBUG_GRAPH_SHOW_ALL,
            dump_name);
        g_free (dump_name);
        break;
    case GST_MESSAGE_STATE_CHANGED:
        if (GST_MESSAGE_SRC(message) == GST_OBJECT(pipeline)) {
            GstState oldstate, newstate, pending;
            gchar* dump_name;

            gst_message_parse_state_changed(message, &oldstate, &newstate,
                &pending);

            GST_INFO_OBJECT(pipeline, "State changed (old: %s, new: %s, pending: %s)",
                gst_element_state_get_name(oldstate),
                gst_element_state_get_name(newstate),
                gst_element_state_get_name(pending));

            dump_name = g_strdup_printf("%s_%s_%s",
                GST_OBJECT_NAME(pipeline),
                gst_element_state_get_name(oldstate),
                gst_element_state_get_name(newstate));

            GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN(pipeline),
                GST_DEBUG_GRAPH_SHOW_ALL, dump_name);

            g_free(dump_name);
        }
        break;
    default:
        break;
    }
}

void connectSimpleBusMessageCallback(GstElement *pipeline)
{
    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(pipeline)));
    gst_bus_add_signal_watch_full(bus.get(), RunLoopSourcePriority::RunLoopDispatcher);
    g_signal_connect(bus.get(), "message", G_CALLBACK(simpleBusMessageCallback),
        pipeline);
}

void* VideoFrame::native_handle() const {
    GST_ERROR ("Returning native handle");
    return (void*) m_sample.get();
}

GstSample *VideoFrame::GetSample() {
    return gst_sample_ref (m_sample.get());
}

rtc::scoped_refptr<webrtc::I420BufferInterface> VideoFrame::ToI420() {
    GstVideoInfo info;
    GstVideoFrame frame;

    g_assert (gst_video_info_from_caps (&info, gst_sample_get_caps (m_sample.get())));
    auto pixelFormatType = GST_VIDEO_INFO_FORMAT(&info);

    GstBuffer* buf = gst_sample_get_buffer(m_sample.get());
    gst_video_frame_map(&frame, &info, buf, GST_MAP_READ);

    auto newBuffer = m_bufferPool.CreateBuffer(GST_VIDEO_FRAME_WIDTH(&frame),
        GST_VIDEO_FRAME_HEIGHT(&frame));
    ASSERT(newBuffer);
    if (!newBuffer) {
        gst_video_frame_unmap(&frame);
        GST_INFO("RealtimeOutgoingVideoSourceGStreamer::videoSampleAvailable unable to allocate buffer for conversion to YUV");
        return nullptr;
    }

    webrtc::VideoType sformat;
    switch (pixelFormatType) {
    case GST_VIDEO_FORMAT_BGRA:
    case GST_VIDEO_FORMAT_BGRx:
        sformat = webrtc::VideoType::kBGRA;
        break;
    case GST_VIDEO_FORMAT_ARGB:
    case GST_VIDEO_FORMAT_xRGB:
        sformat = webrtc::VideoType::kARGB;
        break;
    case GST_VIDEO_FORMAT_I420:
        sformat = webrtc::VideoType::kI420;
        break;
    case GST_VIDEO_FORMAT_YUY2:
        sformat = webrtc::VideoType::kYUY2;
        break;
    default:
        g_assert_not_reached();
    }
    webrtc::ConvertToI420(sformat, (const uint8_t*)frame.data[0], 0, 0, GST_VIDEO_INFO_WIDTH (&info),
        GST_VIDEO_INFO_HEIGHT (&info), 0, webrtc::kVideoRotation_0, newBuffer);
    gst_video_frame_unmap(&frame);

    return newBuffer;
}
}
}

#endif

