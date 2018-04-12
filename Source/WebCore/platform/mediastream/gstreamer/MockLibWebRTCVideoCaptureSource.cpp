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
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
 */

#include "config.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)

#include <gst/app/gstappsrc.h>

#include "MediaSampleGStreamer.h"
#include "MockRealtimeVideoSource.h"
#include "MockLibWebRTCVideoCaptureSource.h"

namespace WebCore {

class MockLibwebrtcRealtimeVideoSource : public MockRealtimeVideoSource {
public:
    MockLibwebrtcRealtimeVideoSource(const String& deviceID, const String& name)
        : MockRealtimeVideoSource(deviceID, name) {}
    void updateSampleBuffer() {
        int fps_n, fps_d;
        auto imageBuffer = this->imageBuffer();

        if (!imageBuffer)
            return;

        gst_util_double_to_fraction(frameRate(), &fps_n, &fps_d);
        auto data = imageBuffer->toBGRAData();
        auto size = data.size();
        GST_ERROR ("Framerate is %f", frameRate());
        auto image_size = imageBuffer->internalSize();
        auto gstsample = gst_sample_new (gst_buffer_new_wrapped((guint8*) data.releaseBuffer().get(),
            size), adoptGRef(gst_caps_new_simple ("video/x-raw",
                "format", G_TYPE_STRING, "BGRA",
                "width", G_TYPE_INT, image_size.width(),
                "height", G_TYPE_INT, image_size.height(),
                "framerate", GST_TYPE_FRACTION, fps_n, fps_d,
                nullptr)).get(),
            nullptr, nullptr);

        auto sample = MediaSampleGStreamer::create(WTFMove(gstsample),
            WebCore::FloatSize(), String());
        videoSampleAvailable(sample);
    }
};


CaptureSourceOrError MockRealtimeVideoSource::create(const String& deviceID,
    const String& name, const MediaConstraints* constraints)
{
    auto source = adoptRef(*new MockLibWebRTCVideoCaptureSource(deviceID, name));

    if (constraints && source->applyConstraints(*constraints))
        return { };

    return CaptureSourceOrError(WTFMove(source));
}

void MockLibWebRTCVideoCaptureSource::startProducingData()
{
    LibWebRTCVideoCaptureSource::startProducingData();
    m_mockedSource.start();
}


void MockLibWebRTCVideoCaptureSource::stopProducingData()
{
    m_mockedSource.stop();

    LibWebRTCVideoCaptureSource::stopProducingData();
}

void MockLibWebRTCVideoCaptureSource::videoSampleAvailable(MediaSample& sample)
{
    auto src = m_capturer->source();

    if (src) {
        auto gstsample = static_cast<MediaSampleGStreamer*>(&sample)->platformSample().sample.gstSample;
        gst_app_src_push_sample(GST_APP_SRC(src), gstsample);
    }
    GST_ERROR ("Sample avalaible!");
}

MockLibWebRTCVideoCaptureSource::MockLibWebRTCVideoCaptureSource(const String& deviceID,
        const String& name)
    : LibWebRTCVideoCaptureSource(deviceID, name, "appsrc")
    , m_mockedSource(*new MockLibwebrtcRealtimeVideoSource(deviceID, name))
{
    m_mockedSource.addObserver(*this);
}

const RealtimeMediaSourceCapabilities& MockLibWebRTCVideoCaptureSource::capabilities() const
{
    m_capabilities = m_mockedSource.capabilities();
    m_currentSettings = m_mockedSource.settings();
    return m_mockedSource.capabilities();
}

void MockLibWebRTCVideoCaptureSource::captureFailed()
{
    stop();

    RealtimeMediaSource::captureFailed();
}


} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)