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

#include "gstreamer/GStreamerCaptureDeviceManager.h"
#include "gstreamer/GStreamerCaptureDevice.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include "LibWebRTCVideoCaptureDeviceManager.h"
#include <wtf/MainThread.h>

namespace WebCore {

class VideoCaptureSourceFactoryLibWebRTC final : public RealtimeMediaSource::VideoCaptureFactory
{
public:
    CaptureSourceOrError createVideoCaptureSource(const CaptureDevice& device, const MediaConstraints* constraints) final
    {
        return LibWebRTCVideoCaptureSource::create(device.persistentId(), constraints);
    }
};

RealtimeMediaSource::VideoCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::videoCaptureSourceFactory()
{
    static NeverDestroyed<VideoCaptureSourceFactoryLibWebRTC> factory;
    return factory.get();
}

RealtimeMediaSource::AudioCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::audioCaptureSourceFactory()
{
    return LibWebRTCRealtimeMediaSourceCenter::singleton().audioFactory();
}

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
    : m_libWebRTCProvider(makeUniqueRef<LibWebRTCProvider>())
{
}

LibWebRTCRealtimeMediaSourceCenter::~LibWebRTCRealtimeMediaSourceCenter()
{
}

RealtimeMediaSource::AudioCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::audioFactory()
{
    if (m_audioFactoryOverride)
        return *m_audioFactoryOverride;

    return LibWebRTCAudioCaptureSource::factory();
}

RealtimeMediaSource::VideoCaptureFactory& LibWebRTCRealtimeMediaSourceCenter::videoFactory()
{
    return videoCaptureSourceFactory();
}

CaptureDeviceManager& LibWebRTCRealtimeMediaSourceCenter::audioCaptureDeviceManager()
{
    return GStreamerAudioCaptureDeviceManager::singleton();
}

CaptureDeviceManager& LibWebRTCRealtimeMediaSourceCenter::videoCaptureDeviceManager()
{
    return GStreamerVideoCaptureDeviceManager::singleton();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
