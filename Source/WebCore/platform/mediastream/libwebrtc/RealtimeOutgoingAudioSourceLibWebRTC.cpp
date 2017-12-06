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

#include "config.h"
#if USE(LIBWEBRTC)

#include "LibWebRTCAudioFormat.h"
#include "webrtc/AudioDataGStreamer.h"
#include "RealtimeOutgoingAudioSourceLibWebRTC.h"

namespace WebCore {

RealtimeOutgoingAudioSourceLibWebRTC::RealtimeOutgoingAudioSourceLibWebRTC(Ref<MediaStreamTrackPrivate>&& audioSource)
    : RealtimeOutgoingAudioSource(WTFMove(audioSource)),
      m_inputStreamDescription(*new AudioStreamDescriptionGStreamer()),
      m_outputStreamDescription(*new AudioStreamDescriptionGStreamer())
{
      g_mutex_init(&m_adapterMutex);
      m_Adapter = gst_adapter_new(),
      m_sampleConverter = nullptr;
}

RealtimeOutgoingAudioSourceLibWebRTC::~RealtimeOutgoingAudioSourceLibWebRTC() {
    g_mutex_clear(&m_adapterMutex);
}

Ref<RealtimeOutgoingAudioSource> RealtimeOutgoingAudioSource::create(Ref<MediaStreamTrackPrivate>&& audioSource)
{
    fprintf(stderr, "create\n");
    return RealtimeOutgoingAudioSourceLibWebRTC::create(WTFMove(audioSource));
}

void RealtimeOutgoingAudioSourceLibWebRTC::audioSamplesAvailable(const MediaTime&,
    const PlatformAudioData& audioData, const AudioStreamDescription& streamDescription,
    size_t /* sampleCount */)
{
    auto data = static_cast<const AudioDataGStreamer&>(audioData);
    auto desc = static_cast<const AudioStreamDescriptionGStreamer&>(streamDescription);

    if (m_sampleConverter && !gst_audio_info_is_equal (&m_inputStreamDescription.m_Info, &desc.m_Info)) {
        GST_ERROR_OBJECT(this, "FIXME - Audio format renegotiation is not possible yet!");
        g_clear_pointer (&m_sampleConverter, gst_audio_converter_free);
    }

    if (!m_sampleConverter) {
        m_inputStreamDescription = *new AudioStreamDescriptionGStreamer(&desc.m_Info);
        m_outputStreamDescription = *new AudioStreamDescriptionGStreamer(&desc.m_Info);

        m_sampleConverter = gst_audio_converter_new (GST_AUDIO_CONVERTER_FLAG_IN_WRITABLE,
            &m_inputStreamDescription.m_Info,
            &m_inputStreamDescription.m_Info,
            NULL);
    }

    WTF::GMutexLocker<GMutex> lock(m_adapterMutex);
    gst_adapter_push (m_Adapter.get(), gst_buffer_ref(gst_sample_get_buffer(data.getSample())));
    LibWebRTCProvider::callOnWebRTCSignalingThread([protectedThis = makeRef(*this)] {
        protectedThis->pullAudioData();
    });
}

void RealtimeOutgoingAudioSourceLibWebRTC::handleMutedIfNeeded()
{
    fprintf(stderr, "handleMutedIfNeeded\n");
}

void RealtimeOutgoingAudioSourceLibWebRTC::sendSilence()
{
    fprintf(stderr, "sendSilence\n");
}

void RealtimeOutgoingAudioSourceLibWebRTC::pullAudioData()
{
    // libwebrtc expects 10 ms chunks.
    size_t chunkSampleCount = m_outputStreamDescription.sampleRate() / 100;
    size_t bufferSize = chunkSampleCount * LibWebRTCAudioFormat::sampleByteSize *
        m_outputStreamDescription.numberOfChannels();

    WTF::GMutexLocker<GMutex> lock(m_adapterMutex);
    GstBuffer *buf = gst_adapter_get_buffer(m_Adapter.get(), bufferSize);
    GstSample * sample = gst_sample_new (buf, m_outputStreamDescription.getCaps(),
        NULL, NULL);
    gst_buffer_unref (buf);

    auto platform_data = static_cast<PlatformAudioData>(AudioDataGStreamer(sample));
    for (auto sink : m_sinks) {
        GST_ERROR_OBJECT (sink, "Sending data to sinks OnData.");
        sink->OnData(&platform_data,
            LibWebRTCAudioFormat::sampleSize,
            m_outputStreamDescription.sampleRate(),
            m_outputStreamDescription.numberOfChannels(),
            chunkSampleCount);
    }
}

bool RealtimeOutgoingAudioSourceLibWebRTC::isReachingBufferedAudioDataHighLimit()
{
    fprintf(stderr, "isReachingBufferedAudioDataHighLimit\n");
    return false;
}

bool RealtimeOutgoingAudioSourceLibWebRTC::isReachingBufferedAudioDataLowLimit()
{
    fprintf(stderr, "isReachingBufferedAudioDataHighLimit\n");
    return false;
}

bool RealtimeOutgoingAudioSourceLibWebRTC::hasBufferedEnoughData()
{
    fprintf(stderr, "hasBufferedEnoughData\n");
    return false;
}

} // namespace WebCore

#endif // USE(LIBWEBRTC)
