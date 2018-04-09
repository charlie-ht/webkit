/*
 * Copyright (C) 2018 Igalia S.L. All rights reserved.
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

#include <gst/app/gstappsrc.h>

#include "MediaSampleGStreamer.h"
#include "GRefPtrGStreamer.h"
#include "GStreamerMediaStreamSource.h"
#include "gstreamer/GStreamerAudioData.h"
#include "gstreamer/GStreamerCapturer.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "LibWebRTCAudioCaptureSource.h"
#include "GStreamerVideoDecoderFactory.h"

namespace WebCore {

#define WEBKIT_IS_MEDIA_STREAM_SRC(o)           (G_TYPE_CHECK_INSTANCE_TYPE  ((o), WEBKIT_TYPE_MEDIA_STREAM_SRC))
#define WEBKIT_MEDIA_STREAM_SRC_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), WEBKIT_TYPE_MEDIA_STREAM_SRC, WebKitMediaStreamSrcClass))
#define WEBKIT_IS_MEDIA_STREAM_SRC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), WEBKIT_TYPE_MEDIA_STREAM_SRC))
#define WEBKIT_MEDIA_STREAM_SRC_GET_CLASS(o)    (G_TYPE_INSTANCE_GET_CLASS ((o), WEBKIT_TYPE_MEDIA_STREAM_SRC, WebKitMediaStreamSrcClass))

static void webkit_media_stream_src_push_video_sample (WebKitMediaStreamSrc * self, GstSample *gstsample);
static void webkit_media_stream_src_push_audio_sample (WebKitMediaStreamSrc * self, GstSample *gstsample);
static gboolean webkit_media_stream_src_setup_encoded_src (WebKitMediaStreamSrc * self,
    String track_id, GstElement * element);

class WebKitMediaStreamTrackObserver
    : public MediaStreamTrackPrivate::Observer
    , public GStreamerVideoDecoderFactory::Observer
{
public:
    virtual ~WebKitMediaStreamTrackObserver() {};
    WebKitMediaStreamTrackObserver(WebKitMediaStreamSrc *src)
        : m_mediaStreamSrc(src) {}
    void trackStarted(MediaStreamTrackPrivate&) final{};
    void trackEnded(MediaStreamTrackPrivate&) final{};
    void trackMutedChanged(MediaStreamTrackPrivate&) final {};
    void trackSettingsChanged(MediaStreamTrackPrivate&) final{};
    void trackEnabledChanged(MediaStreamTrackPrivate&) final{};
    void readyStateChanged(MediaStreamTrackPrivate&) final{};

    void sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample& sample) final
    {
        auto gstsample = static_cast<MediaSampleGStreamer*>(&sample)->platformSample().sample.gstSample;

        webkit_media_stream_src_push_video_sample (m_mediaStreamSrc, gstsample);
    }

    void audioSamplesAvailable(MediaStreamTrackPrivate&, const MediaTime&, const PlatformAudioData& audioData, const AudioStreamDescription&, size_t) final
    {
        auto audiodata = static_cast<const GStreamerAudioData&>(audioData);

        webkit_media_stream_src_push_audio_sample (m_mediaStreamSrc, audiodata.getSample());
    }

    // GStreamerVideoDecoderFactory::Observer implementation.
    bool newSource(String track_id, GstElement *source) {
        return webkit_media_stream_src_setup_encoded_src (m_mediaStreamSrc, track_id, source);
    }

private:
    WebKitMediaStreamSrc * m_mediaStreamSrc;
};

typedef struct _WebKitMediaStreamSrcClass   WebKitMediaStreamSrcClass;
struct _WebKitMediaStreamSrc {
  GstBin parent_instance;

  gchar *uri;

  GstElement * audioSrc;
  GstElement * videoSrc;

  WebKitMediaStreamTrackObserver *observer;
  String videoTrackID;
};

struct _WebKitMediaStreamSrcClass {
  GstBinClass parent_class;
};

static GstURIType
webkit_media_stream_src_uri_get_type (GType)
{
  return GST_URI_SRC;
}

static const gchar *const *
webkit_media_stream_src_uri_get_protocols (GType)
{
  static const gchar *protocols[] = { "mediastream", NULL };

  return protocols;
}

static gchar *
webkit_media_stream_src_uri_get_uri (GstURIHandler * handler)
{
  WebKitMediaStreamSrc  *self = WEBKIT_MEDIA_STREAM_SRC (handler);

  /* FIXME: make thread-safe */
  return g_strdup (self->uri);
}

static gboolean
webkit_media_stream_src_uri_set_uri (GstURIHandler * handler, const gchar * uri,
    GError **)
{
  WebKitMediaStreamSrc *self = WEBKIT_MEDIA_STREAM_SRC (handler);
  self->uri = g_strdup (uri);
  
  return TRUE;
}

static void
webkit_media_stream_src_uri_handler_init (gpointer g_iface, gpointer)
{
  GstURIHandlerInterface *iface = (GstURIHandlerInterface *) g_iface;

  iface->get_type = webkit_media_stream_src_uri_get_type;
  iface->get_protocols = webkit_media_stream_src_uri_get_protocols;
  iface->get_uri = webkit_media_stream_src_uri_get_uri;
  iface->set_uri = webkit_media_stream_src_uri_set_uri;
}

GST_DEBUG_CATEGORY_STATIC(webkit_media_stream_src_debug);
#define GST_CAT_DEFAULT webkit_media_stream_src_debug

#define _do_init \
  G_IMPLEMENT_INTERFACE (GST_TYPE_URI_HANDLER, webkit_media_stream_src_uri_handler_init); \
  GST_DEBUG_CATEGORY_INIT(webkit_media_stream_src_debug, "webkitwebmediastreamsrc", 0, "mediastreamsrc element");

G_DEFINE_TYPE_WITH_CODE (WebKitMediaStreamSrc, webkit_media_stream_src, GST_TYPE_BIN, _do_init);

static void
webkit_media_stream_src_finalize (GObject *object)
{
  WebKitMediaStreamSrc *self = WEBKIT_MEDIA_STREAM_SRC (object);

  g_clear_pointer (&self->uri, g_free);
}

static void
webkit_media_stream_src_class_init (WebKitMediaStreamSrcClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->finalize = webkit_media_stream_src_finalize;
}

static void
webkit_media_stream_src_init (WebKitMediaStreamSrc *self)
{  
    self->observer = new WebKitMediaStreamTrackObserver(self);
}

static gboolean
webkit_media_stream_src_setup_src (WebKitMediaStreamSrc * self,
    MediaStreamTrackPrivate * track, GstElement * element,
    const gchar * track_type_name)
{
    gst_bin_add (GST_BIN(self), element);
    gst_element_set_state (element, GST_STATE_PLAYING);

    CString padname = String::format("%s_src", track_type_name).utf8();
    auto pad = gst_ghost_pad_new (padname.data(),
        adoptGRef(gst_element_get_static_pad (element, "src")).get());

    gst_element_add_pad (GST_ELEMENT (self), pad);

    if (track)
        track->addObserver(*self->observer);

    return TRUE;
}

static gboolean
webkit_media_stream_src_setup_app_src (WebKitMediaStreamSrc * self,
    MediaStreamTrackPrivate * track, GstElement ** element,
    const gchar * track_type_name)
{
    *element = gst_element_factory_make("appsrc", NULL);
    g_object_set(*element, "is-live", true, "format", GST_FORMAT_TIME, NULL);

    return webkit_media_stream_src_setup_src (self, track, *element, track_type_name);
}

static gboolean
webkit_media_stream_src_setup_from_capturer (WebKitMediaStreamSrc * self,
    GStreamerCapturer * capturer, GstElement **element,
    const gchar *track_type_name)
{
    GstElement *proxysink = gst_element_factory_make ("proxysink", NULL);
    *element = gst_element_factory_make ("proxysrc", NULL);

    g_object_set (*element, "proxysink", proxysink, NULL);
    
    webkit_media_stream_src_setup_src (self, NULL, *element, track_type_name);

    capturer->addSink(proxysink);

    return TRUE;
}

static gboolean
webkit_media_stream_src_setup_encoded_src (WebKitMediaStreamSrc * self,
    String track_id, GstElement * element)
{
    if (track_id != self->videoTrackID) {
        GST_INFO_OBJECT (self, "Decoder for %s not wanted.", track_id.utf8().data());

        return FALSE;
    }

    self->videoSrc = element;
    return webkit_media_stream_src_setup_src (self, NULL, element, "video");
}

gboolean
webkit_media_stream_src_set_stream (WebKitMediaStreamSrc * self, MediaStreamPrivate * stream)
{
    for (auto& track : stream->tracks()) {
        if (track->type() == RealtimeMediaSource::Type::Audio) {
            if (stream->hasCaptureAudioSource()) {
                LibWebRTCAudioCaptureSource& source = static_cast<LibWebRTCAudioCaptureSource&>(track->source());
                auto capturer = source.Capturer();

                webkit_media_stream_src_setup_from_capturer (self, capturer, &self->audioSrc,
                    "audio");
            } else {
                webkit_media_stream_src_setup_app_src (self, track.get(), &self->audioSrc,
                    "audio");
            }
        } else if (track->type() == RealtimeMediaSource::Type::Video) {
            if (stream->hasCaptureVideoSource()) {
                LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(track->source());
                auto capturer = source.Capturer();

                webkit_media_stream_src_setup_from_capturer (self, capturer, &self->videoSrc,
                    "video");
            } else if (track->source().persistentID().length()) {
                GStreamerVideoDecoderFactory::addObserver(*self->observer);
            } else {
                webkit_media_stream_src_setup_app_src (self, track.get(), &self->videoSrc,
                    "video");
            }
        } else {
            GST_INFO("Unsuported track type: %d", track->type());
            continue;
        }
    }

    gst_element_no_more_pads (GST_ELEMENT (self));

    return TRUE;
}

static void
webkit_media_stream_src_push_video_sample (WebKitMediaStreamSrc * self, GstSample *gstsample)
{
    g_assert(gst_app_src_push_sample(GST_APP_SRC(self->videoSrc), gstsample) == GST_FLOW_OK);
}

static void
webkit_media_stream_src_push_audio_sample (WebKitMediaStreamSrc * self, GstSample *gstsample)
{
    g_assert(gst_app_src_push_sample(GST_APP_SRC(self->audioSrc), gstsample) == GST_FLOW_OK);
}

} // WebCore
#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

