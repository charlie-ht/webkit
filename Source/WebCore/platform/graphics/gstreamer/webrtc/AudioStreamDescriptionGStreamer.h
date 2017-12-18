/*
 * Copyright (C) 2017 Igalia S.L
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * aint with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#pragma once

#include "config.h"

#if USE(LIBWEBRTC)

#include "AudioStreamDescription.h"
#include <gst/audio/audio.h>

namespace WebCore {

class AudioStreamDescriptionGStreamer final: public AudioStreamDescription {
public:
    WEBCORE_EXPORT AudioStreamDescriptionGStreamer(GstAudioInfo info):
        m_Info(info) {
        m_Caps = gst_audio_info_to_caps (&m_Info);
    }

    WEBCORE_EXPORT AudioStreamDescriptionGStreamer(GstAudioInfo *info):
        m_Info(*info) {
        m_Caps = gst_audio_info_to_caps (&m_Info);
    }

    WEBCORE_EXPORT AudioStreamDescriptionGStreamer() {
        gst_audio_info_init (&m_Info);
        m_Caps = nullptr;
    }

    WEBCORE_EXPORT ~AudioStreamDescriptionGStreamer() {};

    const PlatformDescription& platformDescription() const {
        return { PlatformDescription::AudioStreamDescriptionGStreamer, nullptr };
    }

    WEBCORE_EXPORT PCMFormat format() const final { return Int16; } // FIXME
    double sampleRate() const final { return GST_AUDIO_INFO_RATE (&m_Info); }
    bool isPCM() const final { return true; }
    bool isInterleaved() const final { return GST_AUDIO_INFO_LAYOUT (&m_Info) == GST_AUDIO_LAYOUT_INTERLEAVED; }
    bool isSignedInteger() const final { return GST_AUDIO_INFO_IS_INTEGER (&m_Info); }
    bool isNativeEndian() const final { return GST_AUDIO_INFO_ENDIANNESS (&m_Info) == G_BYTE_ORDER; }
    bool isFloat() const final { return GST_AUDIO_INFO_IS_FLOAT (&m_Info); }

    uint32_t numberOfInterleavedChannels() const final { return isInterleaved() ? GST_AUDIO_INFO_CHANNELS (&m_Info) : TRUE; }
    uint32_t numberOfChannelStreams() const final { return GST_AUDIO_INFO_CHANNELS (&m_Info); }
    uint32_t numberOfChannels() const final { return GST_AUDIO_INFO_CHANNELS (&m_Info); }
    uint32_t sampleWordSize() const final { return GST_AUDIO_INFO_BPS (&m_Info); }

    bool operator==(const AudioStreamDescriptionGStreamer& other) { return gst_audio_info_is_equal (&m_Info, &other.m_Info); }
    bool operator!=(const AudioStreamDescriptionGStreamer& other) { return !operator == (other); }

    GstCaps *getCaps() {return m_Caps.get(); }

    GstAudioInfo m_Info;
private:
    GRefPtr<GstCaps> m_Caps;
};

} // WebCore 

#endif // USE(LIBWEBRTC)