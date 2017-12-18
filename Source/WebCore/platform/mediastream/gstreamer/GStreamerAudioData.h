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

#if USE(LIBWEBRTC)

#include <gst/audio/audio.h>
#include "PlatformAudioData.h"
#include "GRefPtrGStreamer.h"

namespace WebCore {
class GStreamerAudioData: public PlatformAudioData
{
  public:
    GStreamerAudioData(GstSample *sample) {

        gst_audio_info_from_caps (&m_AudioInfo,
          gst_sample_get_caps (sample));

        m_sample = adoptGRef(sample);
    }

    GStreamerAudioData(const void *audio_data,
                       const size_t number_of_frames,
                       const size_t number_of_channels,
                       const uint32_t sample_rate)
    {
        gst_audio_info_set_format(&m_AudioInfo,
                                  GST_AUDIO_FORMAT_S16LE, // Forced format in libwebrtc
                                  sample_rate, number_of_channels, NULL);
        GstBuffer *buf = gst_buffer_new_wrapped(
          g_memdup(audio_data, GST_AUDIO_INFO_BPF(&m_AudioInfo) * number_of_frames),
          GST_AUDIO_INFO_BPF(&m_AudioInfo) * number_of_frames);

        m_sample = adoptGRef(gst_sample_new(buf,
            gst_audio_info_to_caps (&m_AudioInfo), nullptr, nullptr));
        gst_buffer_unref (buf);
    }

    GstSample * getSample() { return m_sample.get(); }

    GstAudioInfo m_AudioInfo;

  private:
    Kind kind() const { return Kind::LibWebRTCAudioData; }
    GRefPtr<GstSample> m_sample;
    GRefPtr<GstCaps> m_caps;
};
} // namespace WebCore

#endif // USE(LIBWEBRTC)
