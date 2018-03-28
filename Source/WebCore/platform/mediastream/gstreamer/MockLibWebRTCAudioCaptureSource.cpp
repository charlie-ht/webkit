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

#include "MockRealtimeAudioSource.h"
#include "MockLibWebRTCAudioCaptureSource.h"

namespace WebCore {

class MockLibwebrtcRealtimeAudioSource : public MockRealtimeAudioSource {
public:
    MockLibwebrtcRealtimeAudioSource(const String& deviceID, const String& name)
        : MockRealtimeAudioSource(deviceID, name) {}

};


CaptureSourceOrError MockRealtimeAudioSource::create(const String& deviceID,
    const String& name, const MediaConstraints* constraints)
{
    auto source = adoptRef(*new MockLibWebRTCAudioCaptureSource(deviceID, name));

    if (constraints && source->applyConstraints(*constraints))
        return { };

    return CaptureSourceOrError(WTFMove(source));
}

MockLibWebRTCAudioCaptureSource::MockLibWebRTCAudioCaptureSource(const String& deviceID, const String& name)
    : LibWebRTCAudioCaptureSource(deviceID)
    , m_mocked_source(*new MockLibwebrtcRealtimeAudioSource(deviceID, name))
{

}

const RealtimeMediaSourceSettings& MockLibWebRTCAudioCaptureSource::settings() const
{
    m_capabilities = m_mocked_source.capabilities();
    m_currentSettings = m_mocked_source.settings();

    return m_currentSettings.value();
}

const RealtimeMediaSourceCapabilities& MockLibWebRTCAudioCaptureSource::capabilities() const
{
    m_capabilities = m_mocked_source.capabilities();
    m_currentSettings = m_mocked_source.settings();
    return m_mocked_source.capabilities();
}

void MockLibWebRTCAudioCaptureSource::captureFailed()
{
    stop();
    RealtimeMediaSource::captureFailed();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)