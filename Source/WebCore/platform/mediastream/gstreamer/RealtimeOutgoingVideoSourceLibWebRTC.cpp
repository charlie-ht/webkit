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

#include "RealtimeOutgoingVideoSourceLibWebRTC.h"

#if USE(LIBWEBRTC) && USE(GSTREAMER)

#include "MediaSampleGStreamer.h"
#include <webrtc/api/video/i420_buffer.h>
#include <webrtc/rtc_base/callback.h>
#include <webrtc/common_video/include/video_frame_buffer.h>
#include <webrtc/common_video/libyuv/include/webrtc_libyuv.h>

namespace libyuv {
extern "C" {
typedef enum RotationMode {
  kRotate0 = 0,      // No rotation.
  kRotate90 = 90,    // Rotate 90 degrees clockwise.
  kRotate180 = 180,  // Rotate 180 degrees.
  kRotate270 = 270,  // Rotate 270 degrees clockwise.

  // Deprecated.
  kRotateNone = 0,
  kRotateClockwise = 90,
  kRotateCounterClockwise = 270,
} RotationModeEnum;

int ConvertToI420(const uint8_t* src_frame,
                  size_t src_size,
                  uint8_t* dst_y,
                  int dst_stride_y,
                  uint8_t* dst_u,
                  int dst_stride_u,
                  uint8_t* dst_v,
                  int dst_stride_v,
                  int crop_x,
                  int crop_y,
                  int src_width,
                  int src_height,
                  int crop_width,
                  int crop_height,
                  RotationMode rotation,
                  uint32_t format);
}
}

namespace WebCore {

Ref<RealtimeOutgoingVideoSource> RealtimeOutgoingVideoSource::create(Ref<MediaStreamTrackPrivate>&& videoSource)
{
    return RealtimeOutgoingVideoSourceLibWebRTC::create(WTFMove(videoSource));
}

Ref<RealtimeOutgoingVideoSourceLibWebRTC> RealtimeOutgoingVideoSourceLibWebRTC::create(Ref<MediaStreamTrackPrivate>&& videoSource)
{
    return adoptRef(*new RealtimeOutgoingVideoSourceLibWebRTC(WTFMove(videoSource)));
}

RealtimeOutgoingVideoSourceLibWebRTC::RealtimeOutgoingVideoSourceLibWebRTC(Ref<MediaStreamTrackPrivate>&& videoSource)
    : RealtimeOutgoingVideoSource(WTFMove(videoSource))
{
}

#if 0
template <GstVideoFrame* F>
static inline rtc::Callback0<void> UnmapGstFrameWhenDone(GstVideoFrame* frame)
{
    return gst_video_frame_unmap(frame);
}
#endif

static inline int ConvertToI420(webrtc::VideoType src_video_type,
                  const uint8_t* src_frame,
                  int crop_x,
                  int crop_y,
                  int src_width,
                  int src_height,
                  size_t sample_size,
                  libyuv::RotationMode rotation,
                  webrtc::I420Buffer* dst_buffer) {
  int dst_width = dst_buffer->width();
  int dst_height = dst_buffer->height();
  // LibYuv expects pre-rotation values for dst.
  // Stride values should correspond to the destination values.
  if (rotation == libyuv::kRotate90 || rotation == libyuv::kRotate270) {
    std::swap(dst_width, dst_height);
  }
  return libyuv::ConvertToI420(
      src_frame, sample_size,
      dst_buffer->MutableDataY(), dst_buffer->StrideY(),
      dst_buffer->MutableDataU(), dst_buffer->StrideU(),
      dst_buffer->MutableDataV(), dst_buffer->StrideV(),
      crop_x, crop_y,
      src_width, src_height,
      dst_width, dst_height,
      rotation,
      webrtc::ConvertVideoType(src_video_type));
}

void RealtimeOutgoingVideoSourceLibWebRTC::sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample& sample)
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

    // FIXME - ASSERT(sample.platformSample().type == PlatformSample::LibWebRTCMediaSample);
    auto& mediaSample = static_cast<MediaSampleGStreamer&>(sample);
    rtc::scoped_refptr<webrtc::VideoFrameBuffer> framebuf(
        GStreamerVideoFrame::Create(gst_sample_ref(mediaSample.platformSample().sample.gstSample))
    );

    sendFrame(WTFMove(framebuf));
}

} // namespace WebCore

#endif // USE(LIBWEBRTC)
