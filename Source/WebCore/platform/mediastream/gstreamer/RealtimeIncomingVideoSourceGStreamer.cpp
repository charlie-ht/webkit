/*
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer
 *    in the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#if USE(LIBWEBRTC) && USE(GSTREAMER)

#include "RealtimeIncomingVideoSourceGStreamer.h"
#include "Logging.h"
#include "GStreamerMediaSample.h"
#include <gst/video/video.h>

namespace WebCore {

Ref<RealtimeIncomingVideoSource> RealtimeIncomingVideoSource::create(rtc::scoped_refptr<webrtc::VideoTrackInterface>&& videoTrack, String&& trackId)
{
    auto source = RealtimeIncomingVideoSourceGStreamer::create(WTFMove(videoTrack), WTFMove(trackId));
    source->start();
    return WTFMove(source);
}

Ref<RealtimeIncomingVideoSourceGStreamer> RealtimeIncomingVideoSourceGStreamer::create(rtc::scoped_refptr<webrtc::VideoTrackInterface>&& videoTrack, String&& trackId)
{
    return adoptRef(*new RealtimeIncomingVideoSourceGStreamer(WTFMove(videoTrack), WTFMove(trackId)));
}

RealtimeIncomingVideoSourceGStreamer::RealtimeIncomingVideoSourceGStreamer(rtc::scoped_refptr<webrtc::VideoTrackInterface>&& videoTrack, String&& videoTrackId)
    : RealtimeIncomingVideoSource(WTFMove(videoTrack), WTFMove(videoTrackId))
{
    gst_video_info_init (&m_info);
}

void RealtimeIncomingVideoSourceGStreamer::OnFrame(const webrtc::VideoFrame& frame)
{

    if (!isProducingData())
        return;

    GstVideoInfo info;
    gst_video_info_set_format (&info, GST_VIDEO_FORMAT_I420, frame.width(),
        frame.height());

    if (!gst_video_info_is_equal (&info, &m_info)) {
        m_info = info;
        m_caps = gst_video_info_to_caps (&m_info);
    }

    auto webrtcbuffer = frame.video_frame_buffer().get();
    GstBuffer *buffer = gst_buffer_new();

    // GstBuffer *buffer = gst_buffer_new_wrapped((gpointer) webrtcbuffer->DataY(), m_info.size);

    // FIXME - Check lifetime of those buffers.
    const uint8_t *comps[3] = {webrtcbuffer->DataY(), webrtcbuffer->DataU(), webrtcbuffer->DataV()};

    for (gint i = 0; i < 3; i++) {
        gsize compsize = GST_VIDEO_INFO_COMP_STRIDE (&m_info, i) *
            GST_VIDEO_INFO_COMP_HEIGHT (&m_info, i); 

        GstMemory * comp = gst_memory_new_wrapped(GST_MEMORY_FLAG_PHYSICALLY_CONTIGUOUS,
            (gpointer) comps[i], compsize, 0, compsize, webrtcbuffer, nullptr);
        gst_buffer_append_memory (buffer, comp);
    }

    auto sample = gst_sample_new (buffer, m_caps.get(), NULL, NULL);
    callOnMainThread([protectedThis = makeRef(*this), sample] {
        protectedThis->processNewSample(sample);
    });
}

void RealtimeIncomingVideoSourceGStreamer::processNewSample(GstSample *sample)
{
    // FIXME - handle setting changes!
    // m_buffer = sample;
    // if (width != m_currentSettings.width() || height != m_currentSettings.height()) {
    //     m_currentSettings.setWidth(width);
    //     m_currentSettings.setHeight(height);
    //     settingsDidChange();
    // }

    videoSampleAvailable(GStreamerMediaSample::create(sample, WebCore::FloatSize(), String()));
}

} // namespace WebCore

#endif // USE(LIBWEBRTC)

