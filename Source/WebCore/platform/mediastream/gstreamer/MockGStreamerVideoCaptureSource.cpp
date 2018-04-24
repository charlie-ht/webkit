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
#include "MockGStreamerVideoCaptureSource.h"

#include "MediaSampleGStreamer.h"
#include "MockRealtimeVideoSource.h"

#include <gst/app/gstappsrc.h>

namespace WebCore {

class WrappedMockRealtimeVideoSource : public MockRealtimeVideoSource {
public:
    WrappedMockRealtimeVideoSource(const String& deviceID, const String& name)
        : MockRealtimeVideoSource(deviceID, name)
    {
    }

    void updateSampleBuffer()
    {
        int fpsNumerator, fpsDenominator;
        auto imageBuffer = this->imageBuffer();

        if (!imageBuffer)
            return;

        gst_util_double_to_fraction(frameRate(), &fpsNumerator, &fpsDenominator);
        auto data = imageBuffer->toBGRAData();
        auto size = data.size();
        auto image_size = imageBuffer->internalSize();
        auto gstsample = gst_sample_new(gst_buffer_new_wrapped((guint8*)data.releaseBuffer().get(), size),
            adoptGRef(gst_caps_new_simple("video/x-raw",
                "format", G_TYPE_STRING, "BGRA",
                "width", G_TYPE_INT, image_size.width(),
                "height", G_TYPE_INT, image_size.height(),
                "framerate", GST_TYPE_FRACTION, fpsNumerator, fpsDenominator,
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
    auto source = adoptRef(*new MockGStreamerVideoCaptureSource(deviceID, name));

    if (constraints && source->applyConstraints(*constraints))
        return { };

    return CaptureSourceOrError(WTFMove(source));
}

void MockGStreamerVideoCaptureSource::startProducingData()
{
    GStreamerVideoCaptureSource::startProducingData();
    m_wrappedSource->start();
}

void MockGStreamerVideoCaptureSource::stopProducingData()
{
    m_wrappedSource->stop();

    GStreamerVideoCaptureSource::stopProducingData();
}

void MockGStreamerVideoCaptureSource::videoSampleAvailable(MediaSample& sample)
{
    auto src = capturer()->source();

    if (src) {
        auto gstsample = static_cast<MediaSampleGStreamer*>(&sample)->platformSample().sample.gstSample;
        gst_app_src_push_sample(GST_APP_SRC(src), gstsample);
    }
}

MockGStreamerVideoCaptureSource::MockGStreamerVideoCaptureSource(const String& deviceID, const String& name)
    : GStreamerVideoCaptureSource(deviceID, name, "appsrc")
    , m_wrappedSource(std::make_unique<WrappedMockRealtimeVideoSource>(deviceID, name))
{
    m_wrappedSource->addObserver(*this);
}

MockGStreamerVideoCaptureSource::~MockGStreamerVideoCaptureSource()
{
    m_wrappedSource->removeObserver(*this);
}

std::optional<std::pair<String, String>> MockGStreamerVideoCaptureSource::applyConstraints(const MediaConstraints& constraints)
{
    m_wrappedSource->applyConstraints(constraints);
    return GStreamerVideoCaptureSource::applyConstraints(constraints);
}

void MockGStreamerVideoCaptureSource::applyConstraints(const MediaConstraints& constraints, SuccessHandler&& successHandler, FailureHandler&& failureHandler)
{
    m_wrappedSource->applyConstraints(constraints, std::move(successHandler), std::move(failureHandler));
}

const RealtimeMediaSourceSettings& MockGStreamerVideoCaptureSource::settings() const
{
    return m_wrappedSource->settings();
}

const RealtimeMediaSourceCapabilities& MockGStreamerVideoCaptureSource::capabilities() const
{
    m_capabilities = m_wrappedSource->capabilities();
    m_currentSettings = m_wrappedSource->settings();
    return m_capabilities.value();
}

void MockGStreamerVideoCaptureSource::captureFailed()
{
    stop();

    RealtimeMediaSource::captureFailed();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
