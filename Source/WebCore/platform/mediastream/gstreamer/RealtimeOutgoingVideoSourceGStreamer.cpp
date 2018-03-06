/*
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted, provided that the following conditions
 * are required to be met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. AND ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "RealtimeOutgoingVideoSourceGStreamer.h"

#if USE(LIBWEBRTC) && USE(GSTREAMER)

#include "MediaSampleGStreamer.h"
#include "GStreamerUtils.h"
#include <webrtc/api/video/i420_buffer.h>
#include <webrtc/base/callback.h>
#include <webrtc/common_video/include/video_frame_buffer.h>
#include <webrtc/common_video/libyuv/include/webrtc_libyuv.h>

namespace WebCore {

Ref<RealtimeOutgoingVideoSource> RealtimeOutgoingVideoSource::create(Ref<MediaStreamTrackPrivate>&& videoSource)
{
    return RealtimeOutgoingVideoSourceGStreamer::create(WTFMove(videoSource));
}

Ref<RealtimeOutgoingVideoSourceGStreamer> RealtimeOutgoingVideoSourceGStreamer::create(Ref<MediaStreamTrackPrivate>&& videoSource)
{
    return adoptRef(*new RealtimeOutgoingVideoSourceGStreamer(WTFMove(videoSource)));
}

RealtimeOutgoingVideoSourceGStreamer::RealtimeOutgoingVideoSourceGStreamer(Ref<MediaStreamTrackPrivate>&& videoSource)
    : RealtimeOutgoingVideoSource(WTFMove(videoSource))
{
}

template <GstVideoFrame* F>
static inline rtc::Callback0<void> UnmapGstFrameWhenDone(GstVideoFrame* frame)
{
    return gst_video_frame_unmap(frame);
}

void RealtimeOutgoingVideoSourceGStreamer::sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample& sample)
{
    if (!m_sinks.size())
        return;

    if (m_muted || !m_enabled)
        return;

    switch (sample.videoRotation()) {
    case MediaSample::VideoRotation::None:
        m_currentRotation = webrtc::kVideoRotation_0;
        break;
    case MediaSample::VideoRotation::UpsideDown:
        m_currentRotation = webrtc::kVideoRotation_180;
        break;
    case MediaSample::VideoRotation::Right:
        m_currentRotation = webrtc::kVideoRotation_90;
        break;
    case MediaSample::VideoRotation::Left:
        m_currentRotation = webrtc::kVideoRotation_270;
        break;
    }

    // FIXME - ASSERT(sample.platformSample().type == PlatformSample::GStreamerMediaSample);
    auto& mediaSample = static_cast<MediaSampleGStreamer&>(sample);
    rtc::scoped_refptr<webrtc::VideoFrameBuffer> framebuf(
        GStreamer::VideoFrame::Create(gst_sample_ref(mediaSample.platformSample().sample.gstSample))
    );

    sendFrame(WTFMove(framebuf));
}

} // namespace WebCore

#endif // USE(LIBWEBRTC)
