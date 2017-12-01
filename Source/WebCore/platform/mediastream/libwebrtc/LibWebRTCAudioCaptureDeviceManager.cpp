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
#include "LibWebRTCAudioCaptureDeviceManager.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "LibWebRTCAudioCaptureDevice.h"
#include <wtf/NeverDestroyed.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

LibWebRTCAudioCaptureDeviceManager& LibWebRTCAudioCaptureDeviceManager::singleton()
{
    static NeverDestroyed<LibWebRTCAudioCaptureDeviceManager> manager;
    return manager;
}

Vector<CaptureDevice>& LibWebRTCAudioCaptureDeviceManager::captureDevices()
{
    static bool initialized;
    if (!initialized) {
        initialized = true;
        getAudioCaptureDevices();
    }

    return m_devices;
}

void LibWebRTCAudioCaptureDeviceManager::getAudioCaptureDevices()
{
    m_voiceEngine = webrtc::VoiceEngine::Create();
    m_voiceEngineBase = webrtc::VoEBase::GetInterface(m_voiceEngine);

    m_voiceEngineBase->Init();

    m_audioDeviceModule = m_voiceEngineBase->audio_device_module();

    if (!m_audioDeviceModule)
        return;

    // Length of the vectors supplied in the API
    const uint16_t idLenght = 128;

    for (int i = 0; i < m_audioDeviceModule->RecordingDevices(); ++i) {
        char id[idLenght] = {0};
        char guid[idLenght] = {0};
        if (m_audioDeviceModule->RecordingDeviceName(i, id, guid) != 1) {
            auto device = LibWebRTCAudioCaptureDevice::create(WTF::String::fromUTF8(id));
            if (!device)
                continue;

            bool available;
            m_audioDeviceModule->SetRecordingDevice(i);
            m_audioDeviceModule->RecordingIsAvailable(&available);
            device->setEnabled(available);
            m_devices.append(WTFMove(device.value()));
        }
    }
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

