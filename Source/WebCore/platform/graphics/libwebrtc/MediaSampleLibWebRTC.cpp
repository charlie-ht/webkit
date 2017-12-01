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

#include "config.h"

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "MediaSampleLibWebRTC.h"

namespace WebCore {

MediaTime MediaSampleLibWebRTC::presentationTime() const
{
    return MediaTime();
}

MediaTime MediaSampleLibWebRTC::outputPresentationTime() const
{
    return MediaTime();
}

MediaTime MediaSampleLibWebRTC::decodeTime() const
{
    return MediaTime();
}

MediaTime MediaSampleLibWebRTC::duration() const
{
    return MediaTime();
}

MediaTime MediaSampleLibWebRTC::outputDuration() const
{
    return MediaTime();
}

MediaSample::SampleFlags MediaSampleLibWebRTC::flags() const
{
    return MediaSample::None;
}

FloatSize MediaSampleLibWebRTC::presentationSize() const
{
    return FloatSize();
}

Ref<MediaSample> MediaSampleLibWebRTC::createNonDisplayingCopy() const
{
    webrtc::VideoFrame frame = webrtc::VideoFrame(m_buffer, static_cast<webrtc::VideoRotation>(m_rotation), m_timestamp);
    return adoptRef(*new MediaSampleLibWebRTC(frame, String()));
}

webrtc::I420BufferInterface* MediaSampleLibWebRTC::getBuffer()
{
    return m_buffer.get();
}

}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
