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
#include "LibWebRTCVideoCaptureDeviceManager.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "LibWebRTCVideoCaptureDevice.h"
#include <wtf/NeverDestroyed.h>

#include "webrtc/media/engine/webrtcvideocapturerfactory.h"
#include "webrtc/modules/video_capture/video_capture_factory.h"

namespace WebCore {

LibWebRTCVideoCaptureDeviceManager& LibWebRTCVideoCaptureDeviceManager::singleton()
{
    static NeverDestroyed<LibWebRTCVideoCaptureDeviceManager> manager;
    return manager;
}

Vector<CaptureDevice>& LibWebRTCVideoCaptureDeviceManager::captureDevices()
{
    static bool initialized;
    if (!initialized) {
        initialized = true;
        getVideoCaptureDevices();
    }

    return m_devices;
}

void LibWebRTCVideoCaptureDeviceManager::getVideoCaptureDevices()
{
    std::unique_ptr<webrtc::VideoCaptureModule::DeviceInfo> deviceInfo(webrtc::VideoCaptureFactory::CreateDeviceInfo());

    if (!deviceInfo)
        return;

    int numberOfDevices = deviceInfo->NumberOfDevices();
    for (int i = 0; i < numberOfDevices; ++i) {
        const uint32_t deviceNameLength = 256;
        const uint32_t deviceIdLength = 256;
        char name[deviceNameLength] = {0};
        char id[deviceIdLength] = {0};
        if (deviceInfo->GetDeviceName(i, name, deviceNameLength, id, deviceIdLength) != -1) {
            auto device = LibWebRTCVideoCaptureDevice::create(String(name));
            if (!device)
                continue;

            device->setEnabled(true);
            m_devices.append(WTFMove(device.value()));
        }
    }
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

