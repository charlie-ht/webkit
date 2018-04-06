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

#pragma once

#include "config.h"
#include <gst/gst.h>
#include <gst/video/video.h>

#include "GRefPtrGStreamer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/common_video/include/video_frame_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/common_video/include/video_frame_buffer.h"

#include "LibWebRTCMacros.h"
#include <webrtc/common_video/include/i420_buffer_pool.h>

#if USE(LIBWEBRTC) && USE(GSTREAMER)

#include "LibWebRTCMacros.h"

namespace WebCore {
namespace GStreamer {

GstSample * SampleFromVideoFrame(const webrtc::VideoFrame& frame);
webrtc::VideoFrame *VideoFrameFromBuffer(GstSample *sample, webrtc::VideoRotation rotation);
void connectSimpleBusMessageCallback(GstElement *pipeline);

class VideoFrame : public webrtc::VideoFrameBuffer {
public:
    VideoFrame(GstSample * sample, GstVideoInfo info)
        : m_sample(adoptGRef(sample))
        , m_info(info) {
    }

    static VideoFrame * Create(GstSample * sample) {
        GstVideoInfo info;

        g_assert (gst_video_info_from_caps (&info, gst_sample_get_caps (sample)));

        return new VideoFrame (sample, info);
    }

    GstSample *GetSample();
    rtc::scoped_refptr<webrtc::I420BufferInterface> ToI420() final;

    // Reference count; implementation copied from rtc::RefCountedObject.
    // FIXME- Should we rely on GStreamer Buffer refcounting here?!
    void AddRef() const override {
        rtc::AtomicOps::Increment(&ref_count_);
    }

    rtc::RefCountReleaseStatus Release() const {
        int count = rtc::AtomicOps::Decrement(&ref_count_);
        if (!count) {
            delete this;

            return rtc::RefCountReleaseStatus::kDroppedLastRef;
        }

        return rtc::RefCountReleaseStatus::kOtherRefsRemained;
    }

    int width() const override { return GST_VIDEO_INFO_WIDTH (&m_info); }
    int height() const override { return GST_VIDEO_INFO_HEIGHT (&m_info); }

private:
    webrtc::VideoFrameBuffer::Type type() const override;
    mutable volatile int ref_count_ = 0;
    GRefPtr<GstSample> m_sample;
    GstVideoInfo m_info;
    webrtc::I420BufferPool m_bufferPool;
};


} // GStreamer
} // WebCore

#endif

