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

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "gstreamer/GStreamerAudioData.h"
#include <gst/app/gstappsink.h>

#include "MediaSampleGStreamer.h"
#include "ImageGStreamer.h"

#include "GraphicsContext.h"
#include "LibWebRTCAudioCaptureSource.h"
#include "LibWebRTCProvider.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "MediaPlayerPrivateLibWebRTC.h"
#include "RealtimeOutgoingAudioSourceLibWebRTC.h"

#include <gst/app/gstappsrc.h>

#include "GStreamerUtils.h"
#include "GStreamerUtilities.h"
#include <wtf/glib/RunLoopSourcePriority.h>

#if G_BYTE_ORDER == G_LITTLE_ENDIAN
#define VIDEO_FORMAT "BGRx"
#else
#define VIDEO_FORMAT "xRGB"
#endif

GST_DEBUG_CATEGORY(webkit_webrtc_debug);
#define GST_CAT_DEFAULT webkit_webrtc_debug

namespace WebCore {

MediaPlayerPrivateLibWebRTC::MediaPlayerPrivateLibWebRTC(MediaPlayer* player)
    : MediaPlayerPrivateGStreamerBase(player)
{
    initializeGStreamerAndGStreamerDebugging();
}

MediaPlayerPrivateLibWebRTC::~MediaPlayerPrivateLibWebRTC()
{
    m_streamPrivate->stopProducingData();
    for (auto& track : m_streamPrivate->tracks()) {
        track->removeObserver(*this);
    }
}

bool MediaPlayerPrivateLibWebRTC::initializeGStreamerAndGStreamerDebugging()
{
    if (!initializeGStreamer())
        return false;

    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_webrtc_debug, "webkitlibwebrtcplayer", 0, "WebKit WebRTC player");
    });
    rtc::LogMessage::LogToDebug(rtc::LS_INFO);

    return true;
}

void MediaPlayerPrivateLibWebRTC::registerMediaEngine(MediaEngineRegistrar registrar)
{
    if (initializeGStreamerAndGStreamerDebugging()) {
        registrar([](MediaPlayer* player) {
            return std::make_unique<MediaPlayerPrivateLibWebRTC>(player);
        },
            getSupportedTypes, supportsType, nullptr, nullptr, nullptr, nullptr);
    }
}

void MediaPlayerPrivateLibWebRTC::getSupportedTypes(HashSet<String, ASCIICaseInsensitiveHash>& types)
{
    // Not supported in this media player.
    static NeverDestroyed<HashSet<String, ASCIICaseInsensitiveHash>> cache;
    types = cache;
}

MediaPlayer::SupportsType MediaPlayerPrivateLibWebRTC::supportsType(const MediaEngineSupportParameters& parameters)
{
    if (parameters.isMediaStream)
        return MediaPlayer::IsSupported;
    return MediaPlayer::IsNotSupported;
}

float MediaPlayerPrivateLibWebRTC::currentTime() const
{
    gint64 position = GST_CLOCK_TIME_NONE;

    gst_element_query_duration(m_pipeline.get(), GST_FORMAT_TIME, &position);

    float result = 0;
    if (static_cast<GstClockTime>(position) != GST_CLOCK_TIME_NONE)
        result = static_cast<double>(position) / GST_SECOND;

    GST_INFO("Position %" GST_TIME_FORMAT, GST_TIME_ARGS(position));

    return result;
}

FloatSize MediaPlayerPrivateLibWebRTC::naturalSize() const
{
    if (m_videoTrack && m_videoTrack->isCaptureTrack()) {
        LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(m_videoTrack->source());
        return source.size();
    }

    return MediaPlayerPrivateGStreamerBase::naturalSize();
}

void MediaPlayerPrivateLibWebRTC::load(MediaStreamPrivate& stream)
{
    m_streamPrivate = &stream;

    auto name = g_strdup_printf("LibWebRTC%sPipeline_%p",
        stream.hasCaptureVideoSource() ? "Local" : "Remote", this);
    setPipeline(gst_pipeline_new(name));
    g_free(name);

    GST_INFO_OBJECT(m_pipeline.get(), "hasCaptureVideoSource() %d", stream.hasCaptureVideoSource());

    /* FIXME: Update the tracks. Set the networkState and the ReadyState */
    m_readyState = MediaPlayer::HaveNothing;
    m_networkState = MediaPlayer::Loading;
    m_player->networkStateChanged();
    m_player->readyStateChanged();
    for (auto& track : m_streamPrivate->tracks()) {

        if (!track->enabled()) {
            GST_DEBUG("Track %s disabled", track->label().ascii().data());
            continue;
        }

        if (track->type() == RealtimeMediaSource::Type::Audio) {
            if (m_audioTrack) {
                GST_FIXME("Support multiple track of the same type.");
                continue;
            }

            m_audioTrack = track;

            auto sink = gst_element_factory_make("playsink", "webrtcplayer_audiosink");
            m_audioSrc = gst_element_factory_make("appsrc", "webrtcplayer_audiosrc");
            g_object_set(m_audioSrc.get(), "is-live", true, "format", GST_FORMAT_TIME, nullptr);

            gst_bin_add_many(GST_BIN(m_pipeline.get()), m_audioSrc.get(), sink, nullptr);
            setStreamVolumeElement(GST_STREAM_VOLUME(sink));
            g_assert(gst_element_link_pads(m_audioSrc.get(), "src", sink, "audio_sink"));

            setMuted(m_player->muted());
        } else if (track->type() == RealtimeMediaSource::Type::Video) {
            if (m_videoTrack) {
                GST_FIXME("Support multiple track of the same type.");
                continue;
            }

            m_videoTrack = track;
            GstElement* sink = createVideoSink();
            m_videoSrc = gst_element_factory_make("appsrc", "webrtcplayer_videosrc");
            g_object_set(m_videoSrc.get(), "is-live", true, "format", GST_FORMAT_TIME, nullptr);

            gst_bin_add_many(GST_BIN(m_pipeline.get()), m_videoSrc.get(), sink, nullptr);
            gst_element_link(m_videoSrc.get(), sink);

            if (stream.hasCaptureVideoSource()) {
                LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(m_videoTrack->source());
                source.addObserver(*this);
            }
        } else {
            GST_INFO("Unsuported track type: %d", track->type());

            continue;
        }

        track->addObserver(*this);
    }

    GStreamer::connectSimpleBusMessageCallback(m_pipeline.get());

    m_readyState = MediaPlayer::HaveEnoughData;
    m_player->readyStateChanged();

    // FIXME - why isn't it called even if the player is "autoplay"
    m_player->play();
}

void MediaPlayerPrivateLibWebRTC::load(const String&)
{
    m_networkState = MediaPlayer::FormatError;
    m_player->networkStateChanged();
}

#if ENABLE(MEDIA_SOURCE)
void MediaPlayerPrivateLibWebRTC::load(const String&, MediaSourcePrivateClient*)
{
    m_networkState = MediaPlayer::FormatError;
    m_player->networkStateChanged();
}
#endif

void MediaPlayerPrivateLibWebRTC::cancelLoad()
{
}

void MediaPlayerPrivateLibWebRTC::prepareToPlay()
{
}

void MediaPlayerPrivateLibWebRTC::sourceStopping()
{
    gst_element_send_event (m_videoSrc.get(), gst_event_new_flush_start());
    gst_element_send_event (m_videoSrc.get(), gst_event_new_flush_stop(false));
}

void MediaPlayerPrivateLibWebRTC::loadingFailed(MediaPlayer::NetworkState error)
{
    if (m_networkState != error) {
        GST_WARNING("Loading failed, error: %d", error);
        m_networkState = error;
        m_player->networkStateChanged();
    }
    if (m_readyState != MediaPlayer::HaveNothing) {
        m_readyState = MediaPlayer::HaveNothing;
        m_player->readyStateChanged();
    }
}

void MediaPlayerPrivateLibWebRTC::play()
{
    GST_DEBUG("Play");

    if (!m_streamPrivate || !m_streamPrivate->active()) {
        m_readyState = MediaPlayer::HaveNothing;
        loadingFailed(MediaPlayer::Empty);
        return;
    }

    GST_DEBUG("Connecting to live stream, descriptor: %p", m_streamPrivate.get());

    gst_element_set_state(pipeline(), GST_STATE_PLAYING);
}

void MediaPlayerPrivateLibWebRTC::pause()
{
}

void MediaPlayerPrivateLibWebRTC::audioSamplesAvailable(MediaStreamTrackPrivate&,
    const MediaTime&, const PlatformAudioData& audioData, const AudioStreamDescription&, size_t)
{
    if (!m_audioSrc)
        return;

    auto audiodata = static_cast<const GStreamerAudioData&>(audioData);
    auto gstsample = audiodata.getSample();
    g_assert(gst_app_src_push_sample(GST_APP_SRC(m_audioSrc.get()), gstsample) == GST_FLOW_OK);
}

void MediaPlayerPrivateLibWebRTC::trackMutedChanged(MediaStreamTrackPrivate& track)
{
    setMuted(track.muted());
}

void MediaPlayerPrivateLibWebRTC::sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample& sample)
{
    auto gstsample = static_cast<MediaSampleGStreamer*>(&sample)->platformSample().sample.gstSample;
    gst_app_src_push_sample(GST_APP_SRC(m_videoSrc.get()), gstsample);
}
}
#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
