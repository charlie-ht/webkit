/*
 * Copyright (C) 2016 Apple Inc. All rights reserved.
 * Copyright (C) 2017 Igalia S.L
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

#include "MediaSample.h"

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/api/video/video_frame.h"

namespace WebCore {

class MediaSampleLibWebRTC final : public MediaSample {
public:
    static Ref<MediaSampleLibWebRTC> create(const webrtc::VideoFrame& sample, const AtomicString& trackID) { return adoptRef(*new MediaSampleLibWebRTC(sample, trackID)); }

    webrtc::I420BufferInterface* getBuffer();

private:
    MediaSampleLibWebRTC(const webrtc::VideoFrame& frame, const AtomicString& trackID)
        : m_trackID(trackID)
        , m_rotation(static_cast<MediaSample::VideoRotation>(frame.rotation()))
        , m_width(frame.width())
        , m_height(frame.height())
        , m_timestamp(frame.timestamp_us())
    {
        m_buffer = frame.video_frame_buffer()->ToI420();

        if (m_rotation != VideoRotation::None)
            m_buffer = webrtc::I420Buffer::Rotate(*m_buffer, frame.rotation());
    }

    virtual ~MediaSampleLibWebRTC() = default;

    MediaTime presentationTime() const override;
    MediaTime outputPresentationTime() const override;
    MediaTime decodeTime() const override;
    MediaTime duration() const override;
    MediaTime outputDuration() const override;

    AtomicString trackID() const override { return m_trackID; }
    void setTrackID(const String& trackID) override { m_trackID = trackID; }

    size_t sizeInBytes() const override { return 0; }
    FloatSize presentationSize() const override;

    SampleFlags flags() const override;
    PlatformSample platformSample() override { return PlatformSample(); }
    void dump(PrintStream&) const override { }
    void offsetTimestampsBy(const MediaTime&) override { }
    void setTimestamps(const MediaTime&, const MediaTime&) override { }
    bool isDivisable() const override { return false; }
    std::pair<RefPtr<MediaSample>, RefPtr<MediaSample>> divide(const MediaTime&) override { return { nullptr, nullptr }; }
    Ref<MediaSample> createNonDisplayingCopy() const override;

    VideoRotation videoRotation() const final { return m_rotation; }

    AtomicString m_trackID;
    VideoRotation m_rotation { VideoRotation::None };
    rtc::scoped_refptr<webrtc::I420BufferInterface> m_buffer;
    int m_width { 0 };
    int m_height { 0 };
    int64_t m_timestamp { 0 };
};

}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
