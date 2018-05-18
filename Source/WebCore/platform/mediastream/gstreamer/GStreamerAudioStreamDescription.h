/*
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

#include "AudioStreamDescription.h"
#include <gst/audio/audio.h>

namespace WebCore {

class GStreamerAudioStreamDescription final: public AudioStreamDescription {
public:
    GStreamerAudioStreamDescription(GstAudioInfo info)
        : m_info(info)
        , m_caps(adoptGRef(gst_audio_info_to_caps(&m_info)))
    {
    }

    GStreamerAudioStreamDescription(GstAudioInfo *info)
        : m_info(*info)
        , m_caps(adoptGRef(gst_audio_info_to_caps(&m_info)))
    {
    }

    GStreamerAudioStreamDescription()
    {
        gst_audio_info_init(&m_info);
    }

    WEBCORE_EXPORT ~GStreamerAudioStreamDescription() { };

    const PlatformDescription& platformDescription() const
    {
        m_platformDescription = { PlatformDescription::GStreamerAudioStreamDescription, (AudioStreamBasicDescription*) &m_info };

        return m_platformDescription;
    }

    WEBCORE_EXPORT PCMFormat format() const final {
        switch (GST_AUDIO_INFO_FORMAT(&m_info)) {
        case GST_AUDIO_FORMAT_S16LE:
        case GST_AUDIO_FORMAT_S16BE:
            return Int16;
        case GST_AUDIO_FORMAT_S32LE:
        case GST_AUDIO_FORMAT_S32BE:
            return Int32;
        case GST_AUDIO_FORMAT_F32LE:
        case GST_AUDIO_FORMAT_F32BE:
            return Float32;
        case GST_AUDIO_FORMAT_F64LE:
        case GST_AUDIO_FORMAT_F64BE:
            return Float64;
        default:
            break;
        }
        return None;
    }

    double sampleRate() const final { return GST_AUDIO_INFO_RATE (&m_info); }
    bool isPCM() const final { return format() != None; }
    bool isInterleaved() const final { return GST_AUDIO_INFO_LAYOUT (&m_info) == GST_AUDIO_LAYOUT_INTERLEAVED; }
    bool isSignedInteger() const final { return GST_AUDIO_INFO_IS_INTEGER (&m_info); }
    bool isNativeEndian() const final { return GST_AUDIO_INFO_ENDIANNESS (&m_info) == G_BYTE_ORDER; }
    bool isFloat() const final { return GST_AUDIO_INFO_IS_FLOAT (&m_info); }

    uint32_t numberOfInterleavedChannels() const final { return isInterleaved() ? GST_AUDIO_INFO_CHANNELS (&m_info) : TRUE; }
    uint32_t numberOfChannelStreams() const final { return GST_AUDIO_INFO_CHANNELS (&m_info); }
    uint32_t numberOfChannels() const final { return GST_AUDIO_INFO_CHANNELS (&m_info); }
    uint32_t sampleWordSize() const final { return GST_AUDIO_INFO_BPS (&m_info); }

    bool operator==(const GStreamerAudioStreamDescription& other) { return gst_audio_info_is_equal (&m_info, &other.m_info); }
    bool operator!=(const GStreamerAudioStreamDescription& other) { return !operator == (other); }

    GstCaps* caps() { return m_caps.get(); }
    GstAudioInfo* getInfo() { return &m_info; }

private:
    GstAudioInfo m_info;
    GRefPtr<GstCaps> m_caps;
    mutable PlatformDescription m_platformDescription;
};

} // WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
