/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
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
#include "LibWebRTCAudioCaptureSource.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "NotImplemented.h"
#include <wtf/NeverDestroyed.h>

namespace WebCore {

class LibWebRTCAudioCaptureSourceFactory : public RealtimeMediaSource::AudioCaptureFactory {
public:
    CaptureSourceOrError createAudioCaptureSource(const String& deviceID, const MediaConstraints* constraints) final {
        return LibWebRTCAudioCaptureSource::create(deviceID, constraints);
    }
};

static LibWebRTCAudioCaptureSourceFactory& libWebRTCAudioCaptureSourceFactory()
{
    static NeverDestroyed<LibWebRTCAudioCaptureSourceFactory> factory;
    return factory.get();
}


CaptureSourceOrError LibWebRTCAudioCaptureSource::create(const String& deviceID, const MediaConstraints* constraints)
{
    auto source = adoptRef(*new LibWebRTCAudioCaptureSource(deviceID));

    if (constraints) {
        auto result = source->applyConstraints(*constraints);
        if (result)
            return WTFMove(result.value().first);
    }
    return CaptureSourceOrError(WTFMove(source));
}

RealtimeMediaSource::AudioCaptureFactory& LibWebRTCAudioCaptureSource::factory()
{
    return libWebRTCAudioCaptureSourceFactory();
}

LibWebRTCAudioCaptureSource::LibWebRTCAudioCaptureSource(const String& deviceID)
    : RealtimeMediaSource(deviceID, RealtimeMediaSource::Type::Audio, deviceID)
{
}

LibWebRTCAudioCaptureSource::~LibWebRTCAudioCaptureSource()
{
}

void LibWebRTCAudioCaptureSource::startProducingData()
{
    notImplemented();
}

void LibWebRTCAudioCaptureSource::stopProducingData()
{
    notImplemented();
}

const RealtimeMediaSourceCapabilities& LibWebRTCAudioCaptureSource::capabilities() const
{
    if (!m_capabilities) {
        RealtimeMediaSourceCapabilities capabilities(settings().supportedConstraints());
        capabilities.setDeviceId(id());
        capabilities.setEchoCancellation(RealtimeMediaSourceCapabilities::EchoCancellation::ReadWrite);
        capabilities.setVolume(CapabilityValueOrRange(0.0, 1.0));
        capabilities.setSampleRate(CapabilityValueOrRange(8000, 96000));
        m_capabilities = WTFMove(capabilities);
    }
    return m_capabilities.value();
}

const RealtimeMediaSourceSettings& LibWebRTCAudioCaptureSource::settings() const
{
    if (!m_currentSettings) {
        RealtimeMediaSourceSettings settings;
        settings.setVolume(volume());
        settings.setSampleRate(sampleRate());
        settings.setDeviceId(id());
        settings.setEchoCancellation(echoCancellation());

        RealtimeMediaSourceSupportedConstraints supportedConstraints;
        supportedConstraints.setSupportsDeviceId(true);
        supportedConstraints.setSupportsEchoCancellation(true);
        supportedConstraints.setSupportsVolume(true);
        supportedConstraints.setSupportsSampleRate(true);
        settings.setSupportedConstraints(supportedConstraints);

        m_currentSettings = WTFMove(settings);
    }
    return m_currentSettings.value();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
