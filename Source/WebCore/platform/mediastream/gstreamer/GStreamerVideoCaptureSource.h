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

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
#include "GStreamerVideoCapturer.h"
#include "RealtimeMediaSource.h"

namespace WebCore {

class GStreamerVideoCaptureSource : public RealtimeMediaSource {
public:
    static CaptureSourceOrError create(const String& deviceID, const MediaConstraints*);
    WEBCORE_EXPORT static VideoCaptureFactory& factory();

    const RealtimeMediaSourceCapabilities& capabilities() const final;
    const RealtimeMediaSourceSettings& settings() const final;

private:
    GStreamerVideoCaptureSource(const String& deviceID, const String& name, const gchar * source_factory);
    virtual ~GStreamerVideoCaptureSource();

    GStreamerVideoCaptureSource(GStreamerCaptureDevice);

    static GstFlowReturn newSampleCallback(GstElement*, GStreamerVideoCaptureSource*);

    void startProducingData() final;
    void stopProducingData() final;

    bool isCaptureSource() const final { return true; }
    bool applySize(const IntSize&) final;
    bool applyFrameRate(double) final;
    bool applyAspectRatio(double) final { return true; }

    mutable std::optional<RealtimeMediaSourceCapabilities> m_capabilities;
    mutable std::optional<RealtimeMediaSourceSettings> m_currentSettings;
    std::unique_ptr<GStreamerVideoCapturer> m_capturer;
};

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
