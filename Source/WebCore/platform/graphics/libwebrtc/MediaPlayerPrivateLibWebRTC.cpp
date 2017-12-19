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

#include "ImageGStreamer.h"
#include "GStreamerMediaSample.h"

#include "GraphicsContext.h"
#include "LibWebRTCProvider.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "LibWebRTCAudioCaptureSource.h"
#include "RealtimeOutgoingAudioSourceLibWebRTC.h"
#include "MediaPlayerPrivateLibWebRTC.h"

#include <gst/app/gstappsrc.h>

#include "libyuv/convert_argb.h"
#include "webrtc/voice_engine/include/voe_base.h"
#include "webrtc/modules/audio_device/include/audio_device.h"
#include "webrtc/api/peerconnectioninterface.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/media/engine/webrtcvideocapturerfactory.h"
#include "GStreamerUtilities.h"
#include <wtf/glib/RunLoopSourcePriority.h>

#if G_BYTE_ORDER == G_LITTLE_ENDIAN
#define VIDEO_FORMAT "BGRx"
#else
#define VIDEO_FORMAT "xRGB"
#endif


namespace WebCore {

MediaPlayerPrivateLibWebRTC::MediaPlayerPrivateLibWebRTC(MediaPlayer* player)
    : m_player(player)
    , m_networkState(MediaPlayer::Empty)
    , m_drawTimer(RunLoop::main(), this, &MediaPlayerPrivateLibWebRTC::repaint)
{
    initializeGStreamer ();
}

static void busMessageCallback(GstBus*, GstMessage* message, GstBin *pipeline)
{
    switch (GST_MESSAGE_TYPE(message)) {
    case GST_MESSAGE_ERROR:
        GST_ERROR ("Got message: %" GST_PTR_FORMAT, message);

        GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (pipeline, GST_DEBUG_GRAPH_SHOW_ALL,
            "error");
        break;
    case GST_MESSAGE_STATE_CHANGED:
      if (GST_MESSAGE_SRC (message) == GST_OBJECT (pipeline)) {
        GstState oldstate, newstate, pending;
        gchar *dump_name;

        gst_message_parse_state_changed (message, &oldstate, &newstate,
            &pending);

        GST_ERROR ("State changed (old: %s, new: %s, pending: %s)",
            gst_element_state_get_name (oldstate),
            gst_element_state_get_name (newstate),
            gst_element_state_get_name (pending));

        dump_name = g_strdup_printf ("%s_%s_%s",
            GST_OBJECT_NAME (pipeline),
            gst_element_state_get_name (oldstate),
            gst_element_state_get_name (newstate));


        GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (GST_BIN (pipeline),
            GST_DEBUG_GRAPH_SHOW_ALL, dump_name);

        g_free (dump_name);
      }
      break;
        break;
    default:
        break;
    }

}

MediaPlayerPrivateLibWebRTC::~MediaPlayerPrivateLibWebRTC()
{
    m_mediaStreamPrivate->stopProducingData();

    m_drawTimer.stop();

    m_mediaStreamPrivate->removeObserver(*this);

    for (auto& track : m_mediaStreamPrivate->tracks()) {
        track->removeObserver(*this);
    }
}

void MediaPlayerPrivateLibWebRTC::registerMediaEngine(MediaEngineRegistrar registrar)
{
    registrar([](MediaPlayer* player) {
            return std::make_unique<MediaPlayerPrivateLibWebRTC>(player);
        }, getSupportedTypes, supportsType, nullptr, nullptr, nullptr, nullptr);
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

FloatSize MediaPlayerPrivateLibWebRTC::naturalSize() const
{
    int width, height;
    MediaStreamTrackPrivate* videoTrack = getVideoTrack();
    if (!videoTrack)
        return FloatSize();

    LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(videoTrack->source());
    source.GetInputSize(&width, &height);
    return FloatSize(width, height);
}

void MediaPlayerPrivateLibWebRTC::load(MediaStreamPrivate& stream)
{
    m_mediaStreamPrivate = &stream;
    m_mediaStreamPrivate->addObserver(*this);

    auto name = g_strdup_printf ("MediaPlayerPrivateLibWebRTCPipeline_%p", this);
    m_pipeline = gst_pipeline_new(name);
    g_free (name);
    /* FIXME: Update the tracks. Set the networkState and the ReadyState */
    for (auto &track : m_mediaStreamPrivate->tracks())
    {
        track->addObserver(*this);

        if (track->type() == RealtimeMediaSource::Type::Audio)
        {
            auto sink = gst_element_factory_make ("playsink", "MediaPlayerPrivate-audioplaysink");

            // TODO - Add error handling
            m_audioSource = gst_element_factory_make ("appsrc", "MediaPlayerPrivate-audiosrc");
            g_object_set (m_audioSource.get(), "is-live", true,
                "format", GST_FORMAT_TIME,
                "do-timestamp", true, 
                nullptr);

            gst_bin_add_many(GST_BIN(m_pipeline.get()), m_audioSource.get(), sink, nullptr);
            m_volume = adoptGRef(GST_STREAM_VOLUME (sink));

            GRefPtr<GstPad> srcpad = gst_element_get_static_pad (m_audioSource.get(), "src");
            GRefPtr<GstPad> sinkpad = gst_element_get_request_pad (sink, "audio_raw_sink");
            g_assert (gst_pad_link (srcpad.get(), sinkpad.get()) == GST_PAD_LINK_OK);

            gst_stream_volume_set_mute (m_volume.get(), m_player->muted());
        } else if (track->type() == RealtimeMediaSource::Type::Video) {
            m_videoSource = gst_element_factory_make ("appsrc", "MediaPlayerPrivate-videosrc");

            auto sink = gst_element_factory_make ("playsink", "MediaPlayerPrivate-videoplaysink");
            gst_bin_add_many(GST_BIN(m_pipeline.get()), m_videoSource.get(), sink, nullptr);

            GRefPtr<GstPad> srcpad = gst_element_get_static_pad (m_videoSource.get(), "src");
            GRefPtr<GstPad> sinkpad = gst_element_get_request_pad (sink, "video_raw_sink");
            g_assert (gst_pad_link (srcpad.get(), sinkpad.get()) == GST_PAD_LINK_OK);

            g_object_set (m_videoSource.get(), "is-live", true,
                "format", GST_FORMAT_TIME,
                "do-timestamp", true, 
                nullptr);

            GRefPtr<GstElement> vsink = gst_element_factory_make ("appsink",
                "MediaPlayerPrivate-videosink");
            gst_app_sink_set_emit_signals(GST_APP_SINK (vsink.get()), true);
            g_object_set (vsink.get(),
                "caps", adoptGRef(gst_caps_new_simple ("video/x-raw",
                    "format", G_TYPE_STRING, VIDEO_FORMAT, nullptr)).get(),
                nullptr);
            g_signal_connect(vsink.get(), "new-sample", G_CALLBACK(videoSinkSampleCb), this);

            g_object_set (sink, "video-sink", vsink.get(), nullptr);
        }
    }

    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(m_pipeline.get())));
    gst_bus_add_signal_watch_full(bus.get(), RunLoopSourcePriority::RunLoopDispatcher);
    g_signal_connect(bus.get(), "message", G_CALLBACK(busMessageCallback), this->m_pipeline.get());

    gst_element_set_state(m_pipeline.get(), GST_STATE_PLAYING);
}

void MediaPlayerPrivateLibWebRTC::load(const String &)
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

void MediaPlayerPrivateLibWebRTC::setMuted(bool muted)
{
    gst_stream_volume_set_mute (m_volume.get(), muted);
}

void MediaPlayerPrivateLibWebRTC::play()
{
    GST_ERROR ("State PLAYING");
}

void MediaPlayerPrivateLibWebRTC::pause()
{
}

void MediaPlayerPrivateLibWebRTC::paint(GraphicsContext& context, const FloatRect& rect)
{
    if (context.paintingDisabled())
        return;

    if (!m_player->visible())
        return;

    if (!m_sample)
        return;

    std::lock_guard<Lock> lock(m_sampleMutex);

    ImagePaintingOptions paintingOptions(CompositeCopy);
    auto gstimage = ImageGStreamer::createImage(m_sample.get());
    RefPtr<BitmapImage> image = gstimage.get().image();
    context.drawImage(*reinterpret_cast<Image*>(image.get()), rect, image->rect(), paintingOptions);
}

void MediaPlayerPrivateLibWebRTC::repaint()
{
    ASSERT(m_sample);
    ASSERT(isMainThread());

    m_player->repaint();
}

GstFlowReturn MediaPlayerPrivateLibWebRTC::videoSinkSampleCb(GstElement* sink, MediaPlayerPrivateLibWebRTC * source)
{
    std::lock_guard<Lock> lock(source->m_sampleMutex);

    source->m_sample = gst_sample_ref (gst_app_sink_pull_sample (GST_APP_SINK (sink)));
    source->m_drawTimer.startOneShot(0_s);

    return GST_FLOW_OK;
}

void MediaPlayerPrivateLibWebRTC::audioSamplesAvailable(MediaStreamTrackPrivate&,
    const MediaTime&, const PlatformAudioData& audioData, const AudioStreamDescription&, size_t)
{
    if (!m_audioSource)
        return;

    auto gstdata = static_cast<const GStreamerAudioData&>(audioData);
    g_assert (gst_app_src_push_sample (GST_APP_SRC (m_audioSource.get()), gstdata.getSample()) == GST_FLOW_OK);
}

void MediaPlayerPrivateLibWebRTC::setVolumeDouble(double volume)
{
    gst_stream_volume_set_volume (m_volume.get(),
        (GstStreamVolumeFormat) GST_STREAM_VOLUME_FORMAT_LINEAR, volume);
}

void MediaPlayerPrivateLibWebRTC::trackMutedChanged(MediaStreamTrackPrivate& track)
{
    gst_stream_volume_set_mute (m_volume.get(), track.muted());
}

void MediaPlayerPrivateLibWebRTC::sampleBufferUpdated(MediaStreamTrackPrivate& privateTrack, MediaSample& sample)
{
    auto gstsample = static_cast<GStreamerMediaSample *>(&sample)->sample();
    gst_app_src_push_sample(GST_APP_SRC(m_videoSource.get()), gstsample);
}

MediaStreamTrackPrivate* MediaPlayerPrivateLibWebRTC::getVideoTrack() const
{
    // It assumes we just have 1 video for rendering.
    for (auto& track : m_mediaStreamPrivate->tracks())
        if (track->type() == RealtimeMediaSource::Type::Video)
            return track.get();

    return nullptr;
}
}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
