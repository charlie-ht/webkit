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
#include "RealtimeMediaSource.h"
#include <wtf/HashMap.h>
#include <wtf/Lock.h>
#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>
#include "GRefPtrGStreamer.h"
#include "gstreamer/GStreamerAudioCapturer.h"
#include "gstreamer/GStreamerCaptureDevice.h"

#include "LibWebRTCMacros.h"
#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/modules/audio_device/include/audio_device_defines.h"

namespace WTF {
class MediaTime;
}

namespace WebCore {

class LibWebRTCAudioCaptureSource: public RealtimeMediaSource {
public:
    static CaptureSourceOrError create(const String& deviceID, const MediaConstraints*);
    WEBCORE_EXPORT static AudioCaptureFactory& factory();

    GstElement *Pipeline() { return m_capturer->m_pipeline.get(); }
    GStreamerCapturer *Capturer() { return m_capturer.get(); }

protected:
    LibWebRTCAudioCaptureSource(const String& deviceID, const String& name);
    virtual ~LibWebRTCAudioCaptureSource();

    const RealtimeMediaSourceCapabilities& capabilities() const override;
    const RealtimeMediaSourceSettings& settings() const override;

    mutable std::optional<RealtimeMediaSourceCapabilities> m_capabilities;
    mutable std::optional<RealtimeMediaSourceSettings> m_currentSettings;

private:
    LibWebRTCAudioCaptureSource(GStreamerCaptureDevice device);

    friend class LibWebRTCAudioCaptureSourceFactory;

    bool applySampleRate(int) final;
    bool isCaptureSource() const final { return true; }
    void startProducingData() final;
    void stopProducingData() final;

    bool applyVolume(double) final { return true; }

    rtc::scoped_refptr<webrtc::AudioTrackInterface> m_audioTrack;
    std::unique_ptr<GStreamerAudioCapturer> m_capturer;

    static GstFlowReturn newSampleCallback(GstElement*, LibWebRTCAudioCaptureSource*);
    void triggerSampleAvailable(GstSample* sample);
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
