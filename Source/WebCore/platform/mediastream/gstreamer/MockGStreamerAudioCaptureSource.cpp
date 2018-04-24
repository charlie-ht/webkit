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
#include "MockGStreamerAudioCaptureSource.h"

#include "MockRealtimeAudioSource.h"

namespace WebCore {

class WrappedMockRealtimeAudioSource : public MockRealtimeAudioSource {
public:
    WrappedMockRealtimeAudioSource(const String& deviceID, const String& name)
        : MockRealtimeAudioSource(deviceID, name)
    {
    }
};

CaptureSourceOrError MockRealtimeAudioSource::create(const String& deviceID,
    const String& name, const MediaConstraints* constraints)
{
    auto source = adoptRef(*new MockGStreamerAudioCaptureSource(deviceID, name));

    if (constraints && source->applyConstraints(*constraints))
        return { };

    return CaptureSourceOrError(WTFMove(source));
}

std::optional<std::pair<String, String>> MockGStreamerAudioCaptureSource::applyConstraints(const MediaConstraints& constraints)
{
    m_wrappedSource->applyConstraints(constraints);
    return GStreamerAudioCaptureSource::applyConstraints(constraints);
}

void MockGStreamerAudioCaptureSource::applyConstraints(const MediaConstraints& constraints, SuccessHandler&& successHandler, FailureHandler&& failureHandler)
{
    m_wrappedSource->applyConstraints(constraints, std::move(successHandler), std::move(failureHandler));
}

MockGStreamerAudioCaptureSource::MockGStreamerAudioCaptureSource(const String& deviceID, const String& name)
    : GStreamerAudioCaptureSource(deviceID, name)
    , m_wrappedSource(std::make_unique<WrappedMockRealtimeAudioSource>(deviceID, name))
{
    m_wrappedSource->addObserver(*this);
}

MockGStreamerAudioCaptureSource::~MockGStreamerAudioCaptureSource()
{
    m_wrappedSource->removeObserver(*this);
}

void MockGStreamerAudioCaptureSource::stopProducingData()
{
    m_wrappedSource->stop();

    GStreamerAudioCaptureSource::stopProducingData();
}

void MockGStreamerAudioCaptureSource::startProducingData()
{
    GStreamerAudioCaptureSource::startProducingData();
    m_wrappedSource->start();
}

const RealtimeMediaSourceSettings& MockGStreamerAudioCaptureSource::settings() const
{
    return m_wrappedSource->settings();
}

const RealtimeMediaSourceCapabilities& MockGStreamerAudioCaptureSource::capabilities() const
{
    m_capabilities = m_wrappedSource->capabilities();
    m_currentSettings = m_wrappedSource->settings();
    return m_wrappedSource->capabilities();
}

void MockGStreamerAudioCaptureSource::captureFailed()
{
    stop();
    RealtimeMediaSource::captureFailed();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
