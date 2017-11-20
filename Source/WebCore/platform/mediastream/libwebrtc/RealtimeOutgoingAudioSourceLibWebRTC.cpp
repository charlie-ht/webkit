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

#if USE(LIBWEBRTC)
#include "webrtc/AudioDataGStreamer.h"
#include "RealtimeOutgoingAudioSourceLibWebRTC.h"
#include "config.h"

namespace WebCore {

RealtimeOutgoingAudioSourceLibWebRTC::RealtimeOutgoingAudioSourceLibWebRTC(Ref<MediaStreamTrackPrivate>&& audioSource)
    : RealtimeOutgoingAudioSource(WTFMove(audioSource)),
      m_inputStreamDescription(*new AudioStreamDescriptionGStreamer()),
      m_outputStreamDescription(*new AudioStreamDescriptionGStreamer()),
      m_Adapter(adoptGRef(gst_adapter_new()))
{
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

    // FIXME - Actually support audio format changes.
    if (&m_inputStreamDescription != &desc && m_sampleConverter)
        g_clear_pointer (&m_sampleConverter, NULL);

    if (!m_sampleConverter) {
        m_inputStreamDescription = *new AudioStreamDescriptionGStreamer(&desc.m_Info);

        m_sampleConverter = gst_audio_converter_new (GST_AUDIO_CONVERTER_FLAG_IN_WRITABLE,
            &m_inputStreamDescription.m_Info,
            &m_inputStreamDescription.m_Info,
            NULL);
    }

    fprintf(stderr, "Audio samples my friend!\n");
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
    fprintf(stderr, "pullAudioData\n");
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
