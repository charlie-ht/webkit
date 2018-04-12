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

#include "RealtimeMediaSourceCenterLibWebRTC.h"

#include "gstreamer/GStreamerCaptureDeviceManager.h"
#include "gstreamer/GStreamerCaptureDevice.h"
#include "gstreamer/GStreamerAudioCaptureSource.h"
#include "gstreamer/GStreamerVideoCaptureSource.h"
#include <wtf/MainThread.h>

namespace WebCore {

class GStreamerVideoCaptureSourceFactory final : public RealtimeMediaSource::VideoCaptureFactory
{
public:
    CaptureSourceOrError createVideoCaptureSource(const CaptureDevice& device, const MediaConstraints* constraints) final
    {
        return GStreamerVideoCaptureSource::create(device.persistentId(), constraints);
    }
};

RealtimeMediaSource::VideoCaptureFactory& RealtimeMediaSourceCenterLibWebRTC::videoCaptureSourceFactory()
{
    static NeverDestroyed<GStreamerVideoCaptureSourceFactory> factory;
    return factory.get();
}

RealtimeMediaSource::AudioCaptureFactory& RealtimeMediaSourceCenterLibWebRTC::audioCaptureSourceFactory()
{
    return RealtimeMediaSourceCenterLibWebRTC::singleton().audioFactory();
}

RealtimeMediaSourceCenterLibWebRTC& RealtimeMediaSourceCenterLibWebRTC::singleton()
{
    ASSERT(isMainThread());
    static NeverDestroyed<RealtimeMediaSourceCenterLibWebRTC> center;
    return center;
}

RealtimeMediaSourceCenter& RealtimeMediaSourceCenter::platformCenter()
{
    return RealtimeMediaSourceCenterLibWebRTC::singleton();
}

RealtimeMediaSourceCenterLibWebRTC::RealtimeMediaSourceCenterLibWebRTC()
    : m_libWebRTCProvider(LibWebRTCProvider::create())
{
}

RealtimeMediaSourceCenterLibWebRTC::~RealtimeMediaSourceCenterLibWebRTC()
{
}

RealtimeMediaSource::AudioCaptureFactory& RealtimeMediaSourceCenterLibWebRTC::audioFactory()
{
    if (m_audioFactoryOverride)
        return *m_audioFactoryOverride;

    return GStreamerAudioCaptureSource::factory();
}

RealtimeMediaSource::VideoCaptureFactory& RealtimeMediaSourceCenterLibWebRTC::videoFactory()
{
    return videoCaptureSourceFactory();
}

CaptureDeviceManager& RealtimeMediaSourceCenterLibWebRTC::audioCaptureDeviceManager()
{
    return GStreamerAudioCaptureDeviceManager::singleton();
}

CaptureDeviceManager& RealtimeMediaSourceCenterLibWebRTC::videoCaptureDeviceManager()
{
    return GStreamerVideoCaptureDeviceManager::singleton();
}

CaptureDeviceManager& RealtimeMediaSourceCenterLibWebRTC::displayCaptureDeviceManager()
{
    return GStreamerDisplayCaptureDeviceManager::singleton();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
