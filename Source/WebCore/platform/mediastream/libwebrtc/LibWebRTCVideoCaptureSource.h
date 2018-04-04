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
#include <LibWebRTCMacros.h>
#include <wtf/HashMap.h>
#include <wtf/Lock.h>
#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>
#include <wtf/text/WTFString.h>

#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/media/base/videocapturer.h"
#include "webrtc/api/videosinkinterface.h"

#include "gstreamer/GStreamerVideoCapturer.h"

namespace WTF {
class MediaTime;
}

namespace WebCore {

class LibWebRTCVideoCaptureSource : public RealtimeMediaSource {
public:
    static CaptureSourceOrError create(const String& deviceID, const MediaConstraints*);
    void addSink(GstElement *sink) { m_capturer.addSink(sink); }
    GstElement *Pipeline() { return m_capturer.m_pipeline.get(); }

protected:
    LibWebRTCVideoCaptureSource(const String& deviceID, const String& name);
    virtual ~LibWebRTCVideoCaptureSource();

    const RealtimeMediaSourceSettings& settings() const override;
    const RealtimeMediaSourceCapabilities& capabilities() const;

    mutable std::optional<RealtimeMediaSourceCapabilities> m_capabilities;
    mutable std::optional<RealtimeMediaSourceSettings> m_currentSettings;

private:
    LibWebRTCVideoCaptureSource(GStreamerCaptureDevice device);

    friend class LibWebRTCVideoCaptureSourceFactory;

    static GstFlowReturn newSampleCallback(GstElement*, LibWebRTCVideoCaptureSource*);

    bool isCaptureSource() const final { return true; }
    void startProducingData() final;
    void stopProducingData() final;
    bool applySize(const IntSize&) final;
    bool applyFrameRate(double) final;
    bool applyAspectRatio(double) final { return true; }

    GStreamerVideoCapturer& m_capturer;
    rtc::scoped_refptr<webrtc::VideoTrackInterface> m_videoTrack;
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
