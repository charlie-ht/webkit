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

#pragma once

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "CaptureDevice.h"
#include "CaptureDeviceManager.h"
#include <wtf/HashMap.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>

#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/modules/audio_device/include/audio_device.h"

namespace WebCore {

class LibWebRTCAudioCaptureDevice;

class LibWebRTCAudioCaptureDeviceManager final : public CaptureDeviceManager {
    friend class NeverDestroyed<LibWebRTCAudioCaptureDeviceManager>;
public:
    static LibWebRTCAudioCaptureDeviceManager& singleton();

    Vector<CaptureDevice>& captureDevices() final;

private:
    LibWebRTCAudioCaptureDeviceManager() = default;
    ~LibWebRTCAudioCaptureDeviceManager() = default;

    void getAudioCaptureDevices();

    Vector<CaptureDevice> m_devices;

    webrtc::VoiceEngine* m_voiceEngine;
    webrtc::VoEBase* m_voiceEngineBase;
    webrtc::AudioDeviceModule* m_audioDeviceModule;

};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
