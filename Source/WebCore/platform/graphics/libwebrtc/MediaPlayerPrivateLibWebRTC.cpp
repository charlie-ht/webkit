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

#include "VideoTrackPrivateMediaStream.h"
#include "AudioTrackPrivateMediaStream.h"
#include "gstreamer/GStreamerMediaStreamSource.h"

#if G_BYTE_ORDER == G_LITTLE_ENDIAN
#define VIDEO_FORMAT "BGRx"
#else
#define VIDEO_FORMAT "xRGB"
#endif

GST_DEBUG_CATEGORY(webkit_webrtc_debug);
#define GST_CAT_DEFAULT webkit_webrtc_debug

namespace WebCore {

MediaPlayerPrivateLibWebRTC::MediaPlayerPrivateLibWebRTC(MediaPlayer* player)
    : MediaPlayerPrivateGStreamer(player)
{
    initializeGStreamerAndGStreamerDebugging();
}

MediaPlayerPrivateLibWebRTC::~MediaPlayerPrivateLibWebRTC()
{
    for (auto& track : m_streamPrivate->tracks()) {
        track->removeObserver(*this);
    }
    GStreamerVideoDecoderFactory::removeObserver(*this);
}

void MediaPlayerPrivateLibWebRTC::sourceSetup(GstElement *source)
{
    webkit_media_stream_src_set_stream(WEBKIT_MEDIA_STREAM_SRC(source),
        m_streamPrivate.get());
}

bool MediaPlayerPrivateLibWebRTC::initializeGStreamerAndGStreamerDebugging()
{
    bool res = initializeGStreamer();

    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_webrtc_debug, "webkitlibwebrtcplayer", 0, "WebKit WebRTC player");
        gst_element_register(nullptr, "mediastreamsrc", GST_RANK_PRIMARY, WEBKIT_TYPE_MEDIA_STREAM_SRC);
        rtc::LogMessage::LogToDebug(rtc::LS_WARNING);
    });

    return res;
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

MediaTime MediaPlayerPrivateLibWebRTC::durationMediaTime() const
{
    return MediaTime::positiveInfiniteTime();
}

float MediaPlayerPrivateLibWebRTC::currentTime() const
{
    gint64 position = GST_CLOCK_TIME_NONE;

    gst_element_query_position(m_pipeline.get(), GST_FORMAT_TIME, &position);

    float result = 0;
    if (GST_CLOCK_TIME_IS_VALID (position))
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

void MediaPlayerPrivateLibWebRTC::handleExternalPipelineBusMessagesSync(GstElement *pipeline)
{
    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(pipeline)));
    gst_bus_set_sync_handler(bus.get(), [](GstBus*, GstMessage* message, gpointer userData) {
        auto& player = *static_cast<MediaPlayerPrivateGStreamerBase*>(userData);

        if (player.handleSyncMessage(message)) {
            gst_message_unref(message);
            return GST_BUS_DROP;
        }

        return GST_BUS_PASS;
    }, this, nullptr);

}

void MediaPlayerPrivateLibWebRTC::load(MediaStreamPrivate& stream)
{
    m_streamPrivate = &stream;

    MediaPlayerPrivateGStreamer::load(String("mediastream://") + stream.id());

    return;

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

        auto observe = true;
        if (track->type() == RealtimeMediaSource::Type::Audio) {
            auto trackpriv = AudioTrackPrivateMediaStream::create(*track.get());

            m_player->addAudioTrack(*trackpriv);
            if (m_audioTrack ) {
                GST_FIXME("Support multiple track of the same type.");
                continue;
            } else if (!track->enabled()) {
                GST_DEBUG("Track %s disabled", track->label().utf8().data());
                continue;
            }

            trackpriv->setEnabled(!track->muted());
            m_audioTrack = track;

            auto sink = gst_element_factory_make("playsink", "webrtcplayer_audiosink");
            setStreamVolumeElement(GST_STREAM_VOLUME (sink));
            setMuted(m_player->muted());
            if (stream.hasCaptureVideoSource()) {
                LibWebRTCAudioCaptureSource& source = static_cast<LibWebRTCAudioCaptureSource&>(m_audioTrack->source());

                handleExternalPipelineBusMessagesSync(source.Pipeline());
                source.addSink(sink);
                observe = false;
            } else {
                m_audioSrc = gst_element_factory_make("appsrc", "webrtcplayer_audiosrc");
                g_object_set(m_audioSrc.get(), "is-live", true, "format", GST_FORMAT_TIME, nullptr);

                gst_bin_add_many(GST_BIN(m_pipeline.get()), m_audioSrc.get(), sink, nullptr);
                g_assert(gst_element_link_pads(m_audioSrc.get(), "src", sink, "audio_sink"));
            }
        } else if (track->type() == RealtimeMediaSource::Type::Video) {
            auto trackpriv = VideoTrackPrivateMediaStream::create(*track.get());
            m_player->addVideoTrack(*trackpriv);

            if (m_videoTrack) {
                GST_FIXME("Support multiple track of the same type.");
                continue;
            } else if (!track->enabled()) {
                GST_DEBUG("Track %s disabled", track->label().utf8().data());

                continue;
            }

            trackpriv->setSelected(true);
            m_videoTrack = track;
            m_sink = createVideoSink();

            LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(m_videoTrack->source());
            if (stream.hasCaptureVideoSource()) {
                handleExternalPipelineBusMessagesSync(source.Pipeline());
                source.addSink(m_sink.get());
                observe = false;
            } else if (source.persistentID().length()) {
                GStreamerVideoDecoderFactory::addObserver(*this);
                observe = false;
            } else {
                m_videoSrc = gst_element_factory_make("appsrc", "webrtcplayer_videosrc");
                g_object_set(m_videoSrc.get(), "is-live", true, "format", GST_FORMAT_TIME, nullptr);

                gst_bin_add_many(GST_BIN(m_pipeline.get()), m_videoSrc.get(), m_sink.get(), nullptr);
                gst_element_link(m_videoSrc.get(), m_sink.get());
            }
            ensureGLVideoSinkContext();
        } else {
            GST_INFO("Unsuported track type: %d", track->type());

            continue;
        }

        if (observe)
            track->addObserver(*this);
    }

    GStreamer::connectSimpleBusMessageCallback(m_pipeline.get());

    m_readyState = MediaPlayer::HaveEnoughData;
    m_player->readyStateChanged();
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

void MediaPlayerPrivateLibWebRTC::setState(GstState state)
{
    // Do not set state on an empty pipeline.
    // It will have to be set at the moment elements get added
    // to the pipeline.
    if (GST_BIN_CHILDREN (pipeline()))
        gst_element_set_state(pipeline(), state);

    GstElement* sinks[2] = { audioSink(), videoSink() };
    for (auto i = 0; i < 2; i++) {
        GstElement *sink = sinks[i];

        if (!sink)
            continue;

        GstElement *parent = GST_ELEMENT (gst_object_get_parent (GST_OBJECT (sink)));

        if (parent != pipeline()) {
            GST_INFO_OBJECT (pipeline(), "%" GST_PTR_FORMAT
                " not inside us, setting its state separately.", sink);
            gst_element_set_state(sink, state);
        }
    }
}

void MediaPlayerPrivateLibWebRTC::play()
{
    GST_ERROR("Play");

    if (!m_streamPrivate || !m_streamPrivate->active()) {
        m_readyState = MediaPlayer::HaveNothing;
        loadingFailed(MediaPlayer::Empty);
        return;
    }

    GST_DEBUG("Connecting to live stream, descriptor: %p", m_streamPrivate.get());

    setState(GST_STATE_PLAYING);
}

void MediaPlayerPrivateLibWebRTC::pause()
{
    setState(GST_STATE_PAUSED);
}

void MediaPlayerPrivateLibWebRTC::audioSamplesAvailable(MediaStreamTrackPrivate&, const MediaTime&, const PlatformAudioData& audioData, const AudioStreamDescription&, size_t)
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

GstElement* MediaPlayerPrivateLibWebRTC::requestSink (String track_id, GstElement *pipeline) {
    String current_track_id = m_videoTrack->source().persistentID();
    if (track_id == current_track_id) {
        GST_INFO_OBJECT (pipeline, "Plugin our sink directly to the decoder.");

        handleExternalPipelineBusMessagesSync(pipeline);
        return m_sink.get();
    }

    GST_INFO_OBJECT (m_pipeline.get(), "Not our track: %s != %s", track_id.utf8().data(),
        current_track_id.utf8().data());

    return nullptr;
}

}
#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
