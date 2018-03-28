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

 #pragma once

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)

#include "LibWebRTCVideoCaptureSource.h"
#include "MockRealtimeMediaSource.h"

namespace WebCore {

// We are subclassing LibWebRTCVideoCaptureSource and not MockRealtimeMediaSource
// because the MediaPlayer expected LibWebRTCVideoCaptureSource to be able to properly
// build the GStreamer pipeline. Still we make it so that it behaves as closely as possible
// to the MockRealtimeMediaSource class.
class MockLibWebRTCVideoCaptureSource final : public LibWebRTCVideoCaptureSource {
public:
    MockLibWebRTCVideoCaptureSource(const String& deviceID, const String& name);

private:
    RealtimeMediaSource &m_mocked_source;
    const RealtimeMediaSourceCapabilities& capabilities() const final;
    MockRealtimeMediaSource::MockDevice device() const { return m_device; }
    MockRealtimeMediaSource::MockDevice m_device { MockRealtimeMediaSource::MockDevice::Invalid };
    bool mockCamera() const { return device() == MockRealtimeMediaSource::MockDevice::Camera1 || device() == MockRealtimeMediaSource::MockDevice::Camera2; }
    bool mockScreen() const { return device() == MockRealtimeMediaSource::MockDevice::Screen1 || device() == MockRealtimeMediaSource::MockDevice::Screen2; }
    void captureFailed() override;
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)