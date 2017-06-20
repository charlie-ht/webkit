/*
 * Copyright (C) 2013-2016 Apple, Inc. All rights reserved.
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
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
 * 3. Neither the name of Ericsson nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
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

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "LibWebRTCAudioCaptureDeviceManager.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include <wtf/MainThread.h>

namespace WebCore {

LibWebRTCRealtimeMediaSourceCenter& LibWebRTCRealtimeMediaSourceCenter::singleton()
{
    ASSERT(isMainThread());
    static NeverDestroyed<LibWebRTCRealtimeMediaSourceCenter> center;
    return center;
}

RealtimeMediaSourceCenter& RealtimeMediaSourceCenter::platformCenter()
{
    return LibWebRTCRealtimeMediaSourceCenter::singleton();
}

LibWebRTCRealtimeMediaSourceCenter::LibWebRTCRealtimeMediaSourceCenter()
{
    m_supportedConstraints.setSupportsSampleRate(false);
    m_supportedConstraints.setSupportsSampleSize(false);
    m_supportedConstraints.setSupportsEchoCancellation(false);
    m_supportedConstraints.setSupportsGroupId(true);
}

LibWebRTCRealtimeMediaSourceCenter::~LibWebRTCRealtimeMediaSourceCenter()
{
}

RealtimeMediaSource::AudioCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::defaultAudioFactory()
{
    return m_defaultAudioFactory;
}

RealtimeMediaSource::VideoCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::defaultVideoFactory()
{
    return m_defaultVideoFactory;
}

CaptureDeviceManager& LibWebRTCRealtimeMediaSourceCenter::defaultAudioCaptureDeviceManager()
{
    return LibWebRTCAudioCaptureDeviceManager::singleton();
}

CaptureDeviceManager& LibWebRTCRealtimeMediaSourceCenter::defaultVideoCaptureDeviceManager()
{
    return m_defaultVideoCaptureDeviceManager;
}

CaptureSourceOrError LibWebRTCAudioCaptureFactory::createAudioCaptureSource(const String&, const MediaConstraints*)
{
    return { };
}

CaptureSourceOrError LibWebRTCVideoCaptureFactory::createVideoCaptureSource(const String&, const MediaConstraints*)
{
    return { };
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
