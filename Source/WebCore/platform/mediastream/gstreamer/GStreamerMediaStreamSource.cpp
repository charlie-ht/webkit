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

#if GST_CHECK_VERSION(1, 10, 0)

#include "GRefPtrGStreamer.h"
#include "GStreamerMediaStreamSource.h"
#include "GStreamerVideoDecoderFactory.h"
#include "LibWebRTCAudioCaptureSource.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "MediaSampleGStreamer.h"
#include "gstreamer/GStreamerAudioData.h"
#include "gstreamer/GStreamerCapturer.h"

namespace WebCore {

#define WEBKIT_MEDIA_STREAM_SRC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), WEBKIT_TYPE_MEDIA_STREAM_SRC, WebKitMediaStreamSrcClass))
#define WEBKIT_IS_MEDIA_STREAM_SRC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), WEBKIT_TYPE_MEDIA_STREAM_SRC))
#define WEBKIT_MEDIA_STREAM_SRC_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS((o), WEBKIT_TYPE_MEDIA_STREAM_SRC, WebKitMediaStreamSrcClass))

static void webkit_media_stream_src_push_video_sample(WebKitMediaStreamSrc* self, GstSample* gstsample);
static void webkit_media_stream_src_push_audio_sample(WebKitMediaStreamSrc* self, GstSample* gstsample);
static gboolean webkit_media_stream_src_setup_encoded_src(WebKitMediaStreamSrc* self,
    String track_id, GstElement* element);

static GstStaticPadTemplate video_src_template = GST_STATIC_PAD_TEMPLATE("video_src",
    GST_PAD_SRC,
    GST_PAD_SOMETIMES,
    GST_STATIC_CAPS("video/x-raw"));

static GstStaticPadTemplate encoded_video_src_template = GST_STATIC_PAD_TEMPLATE("video_src",
    GST_PAD_SRC,
    GST_PAD_SOMETIMES,
    GST_STATIC_CAPS("video/x-h264;video/x-vp8;video/x-vp9"));

static GstStaticPadTemplate audio_src_template = GST_STATIC_PAD_TEMPLATE("audio_src",
    GST_PAD_SRC,
    GST_PAD_SOMETIMES,
    GST_STATIC_CAPS("audio/x-raw(ANY);"));

G_DECLARE_FINAL_TYPE(WebKitMediaStreamStream, webkit_media_stream_stream, WEBKIT, MEDIA_STREAM_STREAM, GstStream);

struct _WebKitMediaStreamStream {
    GstStream parent;

    gboolean observing;
    RefPtr<MediaStreamTrackPrivate> track;
};

G_DEFINE_TYPE(WebKitMediaStreamStream, webkit_media_stream_stream, GST_TYPE_STREAM);

static void
webkit_media_stream_stream_init(WebKitMediaStreamStream*)
{
}

static void
webkit_media_stream_stream_class_init(WebKitMediaStreamStreamClass*)
{
}

GstStream*
webkit_media_stream_stream_new(MediaStreamPrivate* stream, MediaStreamTrackPrivate* track)
{
    GRefPtr<GstCaps> caps;
    GstStreamType type;

    if (track->type() == RealtimeMediaSource::Type::Audio) {
        caps = adoptGRef(gst_static_pad_template_get_caps(&audio_src_template));
        type = GST_STREAM_TYPE_AUDIO;
    } else if (track->type() == RealtimeMediaSource::Type::Video) {
        if (stream->hasCaptureVideoSource())
            caps = adoptGRef(gst_static_pad_template_get_caps(&video_src_template));
        else
            caps = adoptGRef(gst_static_pad_template_get_caps(&encoded_video_src_template));
        type = GST_STREAM_TYPE_VIDEO;
    } else {
        GST_FIXME("Handle %d type", track->type());
        return NULL;
    }

    auto gststream = (GstStream*)g_object_new(webkit_media_stream_stream_get_type(),
        "stream-id", track->id().utf8().data(),
        "caps", caps.get(),
        "stream-type", type,
        "stream-flags", GST_STREAM_FLAG_SELECT, NULL);
    ((WebKitMediaStreamStream*)gststream)->track = track;

    return gststream;
}

class WebKitMediaStreamTrackObserver
    : public MediaStreamTrackPrivate::Observer,
      public GStreamerVideoDecoderFactory::Observer {
public:
    virtual ~WebKitMediaStreamTrackObserver(){};
    WebKitMediaStreamTrackObserver(WebKitMediaStreamSrc* src)
        : m_mediaStreamSrc(src)
    {
    }
    void trackStarted(MediaStreamTrackPrivate&) final{};
    void trackEnded(MediaStreamTrackPrivate&) final{};
    void trackMutedChanged(MediaStreamTrackPrivate&) final{};
    void trackSettingsChanged(MediaStreamTrackPrivate&) final{};
    void trackEnabledChanged(MediaStreamTrackPrivate&) final{};
    void readyStateChanged(MediaStreamTrackPrivate&) final{};

    void sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample& sample) final
    {
        auto gstsample = static_cast<MediaSampleGStreamer*>(&sample)->platformSample().sample.gstSample;

        webkit_media_stream_src_push_video_sample(m_mediaStreamSrc, gstsample);
    }

    void audioSamplesAvailable(MediaStreamTrackPrivate&, const MediaTime&, const PlatformAudioData& audioData, const AudioStreamDescription&, size_t) final
    {
        auto audiodata = static_cast<const GStreamerAudioData&>(audioData);

        webkit_media_stream_src_push_audio_sample(m_mediaStreamSrc, audiodata.getSample());
    }

    // GStreamerVideoDecoderFactory::Observer implementation.
    bool newSource(String track_id, GstElement* source)
    {
        return webkit_media_stream_src_setup_encoded_src(m_mediaStreamSrc, track_id, source);
    }

    void addStream(String id, WebKitMediaStreamStream* stream)
    {
        m_streamMap.add(id, stream);
    }

private:
    WebKitMediaStreamSrc* m_mediaStreamSrc;
    HashMap<String, GRefPtr<WebKitMediaStreamStream>> m_streamMap;
};

typedef struct _WebKitMediaStreamSrcClass WebKitMediaStreamSrcClass;
struct _WebKitMediaStreamSrc {
    GstBin parent_instance;

    gchar* uri;

    GstElement* audioSrc;
    GstElement* videoSrc;

    WebKitMediaStreamTrackObserver* observer;
    String videoTrackID;
    volatile gint npads;
    GRefPtr<GstStreamCollection> stream_collection;
};

struct _WebKitMediaStreamSrcClass {
    GstBinClass parent_class;
};

enum {
    PROP_0,
    PROP_IS_LIVE,
    PROP_LAST
};

static GstURIType
    webkit_media_stream_src_uri_get_type(GType)
{
    return GST_URI_SRC;
}

static const gchar* const*
    webkit_media_stream_src_uri_get_protocols(GType)
{
    static const gchar* protocols[] = { "mediastream", NULL };

    return protocols;
}

static gchar*
webkit_media_stream_src_uri_get_uri(GstURIHandler* handler)
{
    WebKitMediaStreamSrc* self = WEBKIT_MEDIA_STREAM_SRC(handler);

    /* FIXME: make thread-safe */
    return g_strdup(self->uri);
}

static gboolean
webkit_media_stream_src_uri_set_uri(GstURIHandler* handler, const gchar* uri,
    GError**)
{
    WebKitMediaStreamSrc* self = WEBKIT_MEDIA_STREAM_SRC(handler);
    self->uri = g_strdup(uri);

    return TRUE;
}

static void
webkit_media_stream_src_uri_handler_init(gpointer g_iface, gpointer)
{
    GstURIHandlerInterface* iface = (GstURIHandlerInterface*)g_iface;

    iface->get_type = webkit_media_stream_src_uri_get_type;
    iface->get_protocols = webkit_media_stream_src_uri_get_protocols;
    iface->get_uri = webkit_media_stream_src_uri_get_uri;
    iface->set_uri = webkit_media_stream_src_uri_set_uri;
}

GST_DEBUG_CATEGORY_STATIC(webkit_media_stream_src_debug);
#define GST_CAT_DEFAULT webkit_media_stream_src_debug

#define _do_init                                                                           \
    G_IMPLEMENT_INTERFACE(GST_TYPE_URI_HANDLER, webkit_media_stream_src_uri_handler_init); \
    GST_DEBUG_CATEGORY_INIT(webkit_media_stream_src_debug, "webkitwebmediastreamsrc", 0, "mediastreamsrc element");

G_DEFINE_TYPE_WITH_CODE(WebKitMediaStreamSrc, webkit_media_stream_src, GST_TYPE_BIN, _do_init);

static void
webkit_media_stream_src_set_property(GObject* object, guint prop_id,
    const GValue*, GParamSpec* pspec)
{
    switch (prop_id) {
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

static void
webkit_media_stream_src_get_property(GObject* object, guint prop_id, GValue* value,
    GParamSpec* pspec)
{
    switch (prop_id) {
    case PROP_IS_LIVE:
        g_value_set_boolean(value, TRUE);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}

static void
webkit_media_stream_src_finalize(GObject* object)
{
    WebKitMediaStreamSrc* self = WEBKIT_MEDIA_STREAM_SRC(object);

    g_clear_pointer(&self->uri, g_free);
}

static GstStateChangeReturn
webkit_media_stream_src_change_state(GstElement* element, GstStateChange transition)
{
    GstStateChangeReturn res;
    auto* self = WEBKIT_MEDIA_STREAM_SRC(element);

    if (transition == GST_STATE_CHANGE_PAUSED_TO_READY) {
        auto collection = self->stream_collection.get();

        if (collection) {
            for (guint i = 0; i < gst_stream_collection_get_size(collection); i++) {
                auto stream = (WebKitMediaStreamStream*)gst_stream_collection_get_stream(collection, i);
                auto track = stream->track.get();

                if (track)
                    track->removeObserver(*self->observer);
            }
        }
        GStreamerVideoDecoderFactory::removeObserver(*self->observer);
    }

    res = GST_ELEMENT_CLASS(webkit_media_stream_src_parent_class)->change_state(element, transition);

    if (transition == GST_STATE_CHANGE_READY_TO_PAUSED) {
        res = GST_STATE_CHANGE_NO_PREROLL;
    }

    return res;
}

static void
webkit_media_stream_src_class_init(WebKitMediaStreamSrcClass* klass)
{
    GObjectClass* gobject_class = G_OBJECT_CLASS(klass);
    GstElementClass* gstelement_klass = (GstElementClass*)klass;

    gobject_class->finalize = webkit_media_stream_src_finalize;
    gobject_class->get_property = webkit_media_stream_src_get_property;
    gobject_class->set_property = webkit_media_stream_src_set_property;

    /**
   * WebKitMediaStreamSrcClass::is-live:
   *
   * Instruct the source to behave like a live source. This includes that it
   * will only push out buffers in the PLAYING state.
   */
    g_object_class_install_property(gobject_class, PROP_IS_LIVE,
        g_param_spec_boolean("is-live", "Is Live",
            "Let playbin3 we are a live source.",
            TRUE, (GParamFlags)(G_PARAM_READABLE | G_PARAM_STATIC_STRINGS)));

    gstelement_klass->change_state = webkit_media_stream_src_change_state;
    gst_element_class_add_pad_template(gstelement_klass,
        gst_static_pad_template_get(&video_src_template));
    gst_element_class_add_pad_template(gstelement_klass,
        gst_static_pad_template_get(&encoded_video_src_template));
    gst_element_class_add_pad_template(gstelement_klass,
        gst_static_pad_template_get(&audio_src_template));
}

static void
webkit_media_stream_src_init(WebKitMediaStreamSrc* self)
{
    self->observer = new WebKitMediaStreamTrackObserver(self);
}

static gboolean
copy_sticky_events(GstPad*, GstEvent** event, gpointer user_data)
{
    GstPad* gpad = GST_PAD_CAST(user_data);

    GST_DEBUG_OBJECT(gpad, "store sticky event %" GST_PTR_FORMAT, *event);
    gst_pad_store_sticky_event(gpad, *event);

    return TRUE;
}

typedef struct {
    WebKitMediaStreamSrc* self;
    GstStaticPadTemplate* pad_template;
} ProbeData;

static GstPadProbeReturn
pad_probe_cb(GstPad* pad, GstPadProbeInfo* info, ProbeData* data)
{
    GstEvent* event = GST_PAD_PROBE_INFO_EVENT(info);

    if (GST_EVENT_TYPE(event) == GST_EVENT_CAPS) {
        CString padname = String::format("src_%u",
            g_atomic_int_add(&(data->self->npads), 1))
                              .utf8();
        auto ghostpad = gst_ghost_pad_new_from_template(padname.data(), pad,
            gst_static_pad_template_get(data->pad_template));

        gst_pad_set_active(ghostpad, TRUE);
        gst_pad_sticky_events_foreach(pad, copy_sticky_events, ghostpad);

        GST_INFO("%s Ghosting %" GST_PTR_FORMAT,
            gst_object_get_path_string(GST_OBJECT_CAST(data->self)),
            pad);

        g_assert(gst_element_add_pad(GST_ELEMENT(data->self), (GstPad*)ghostpad));

        return GST_PAD_PROBE_REMOVE;
    }

    return GST_PAD_PROBE_OK;
}

static gboolean
webkit_media_stream_src_setup_src(WebKitMediaStreamSrc* self,
    MediaStreamTrackPrivate* track, GstElement* element,
    GstStaticPadTemplate* pad_template)
{
    gst_bin_add(GST_BIN(self), element);
    gst_element_set_state(element, GST_STATE_PLAYING);

    auto pad = adoptGRef(gst_element_get_static_pad(element, "src"));

    ProbeData* data = (ProbeData*)g_malloc(sizeof(ProbeData));
    data->self = self;
    data->pad_template = pad_template;
    gst_pad_add_probe(pad.get(), (GstPadProbeType)GST_PAD_PROBE_TYPE_EVENT_DOWNSTREAM,
        (GstPadProbeCallback)pad_probe_cb, data, g_free);

    if (track) {
        track->addObserver(*self->observer);
    }

    return TRUE;
}

static gboolean
webkit_media_stream_src_setup_app_src(WebKitMediaStreamSrc* self,
    MediaStreamTrackPrivate* track, GstElement** element,
    GstStaticPadTemplate* pad_template)
{
    *element = gst_element_factory_make("appsrc", NULL);
    g_object_set(*element, "is-live", true, "format", GST_FORMAT_TIME, NULL);

    return webkit_media_stream_src_setup_src(self, track, *element, pad_template);
}

static gboolean
webkit_media_stream_src_setup_from_capturer(WebKitMediaStreamSrc* self,
    GStreamerCapturer* capturer, GstElement** element,
    GstStaticPadTemplate* pad_template)
{
    GstElement* proxysink = gst_element_factory_make("proxysink", NULL);
    *element = gst_element_factory_make("proxysrc", NULL);

    g_object_set(*element, "proxysink", proxysink, NULL);

    webkit_media_stream_src_setup_src(self, NULL, *element, pad_template);

    capturer->addSink(proxysink);

    return TRUE;
}

static gboolean
webkit_media_stream_src_setup_encoded_src(WebKitMediaStreamSrc* self,
    String track_id, GstElement* element)
{
    if (track_id != self->videoTrackID) {
        GST_INFO_OBJECT(self, "Decoder for %s not wanted.", track_id.utf8().data());

        return FALSE;
    }

    self->videoSrc = element;
    return webkit_media_stream_src_setup_src(self, NULL, element, &encoded_video_src_template);
}

static void
webkit_media_stream_src_post_stream_collection(WebKitMediaStreamSrc* self, MediaStreamPrivate* stream)
{
    self->stream_collection = adoptGRef(gst_stream_collection_new(stream->id().utf8().data()));

    for (auto& track : stream->tracks()) {
        auto gststream = webkit_media_stream_stream_new(stream, track.get());

        if (!gststream)
            continue;

        self->observer->addStream(track->id(), (WebKitMediaStreamStream*)gststream);
        gst_stream_collection_add_stream(self->stream_collection.get(), gststream);
    }

    gst_element_post_message(GST_ELEMENT(self),
        gst_message_new_stream_collection(GST_OBJECT(self), self->stream_collection.get()));
}

gboolean
webkit_media_stream_src_set_stream(WebKitMediaStreamSrc* self, MediaStreamPrivate* stream)
{
    webkit_media_stream_src_post_stream_collection(self, stream);

    for (auto& track : stream->tracks()) {
        if (track->type() == RealtimeMediaSource::Type::Audio) {
            if (FALSE) { // FIXME!! make proxysink/src working (stream->hasCaptureAudioSource()) {
                LibWebRTCAudioCaptureSource& source = static_cast<LibWebRTCAudioCaptureSource&>(track->source());
                auto capturer = source.Capturer();

                webkit_media_stream_src_setup_from_capturer(self, capturer, &self->audioSrc,
                    &audio_src_template);
            } else {
                webkit_media_stream_src_setup_app_src(self, track.get(), &self->audioSrc,
                    &audio_src_template);
            }
        } else if (track->type() == RealtimeMediaSource::Type::Video) {
            if (FALSE) { // FIXME!! make proxysink/src working (stream->hasCaptureVideoSource()) {
                LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(track->source());
                auto capturer = source.Capturer();

                webkit_media_stream_src_setup_from_capturer(self, capturer, &self->videoSrc,
                    &video_src_template);

                webkit_media_stream_src_setup_app_src(self, track.get(), &self->videoSrc,
                    &video_src_template);
            } else if (!stream->hasCaptureVideoSource() && track->source().persistentID().length()) {
                self->videoTrackID = track->id();
                GStreamerVideoDecoderFactory::addObserver(*self->observer);
            } else {
                webkit_media_stream_src_setup_app_src(self, track.get(), &self->videoSrc,
                    &video_src_template);
            }
        } else {
            GST_INFO("Unsuported track type: %d", track->type());
            continue;
        }
    }

    gst_element_no_more_pads(GST_ELEMENT(self));

    return TRUE;
}

static void
webkit_media_stream_src_push_video_sample(WebKitMediaStreamSrc* self, GstSample* gstsample)
{
    g_assert(gst_app_src_push_sample(GST_APP_SRC(self->videoSrc), gstsample) == GST_FLOW_OK);
}

static void
webkit_media_stream_src_push_audio_sample(WebKitMediaStreamSrc* self, GstSample* gstsample)
{
    g_assert(gst_app_src_push_sample(GST_APP_SRC(self->audioSrc), gstsample) == GST_FLOW_OK);
}

} // WebCore

#endif // GST_CHECK_VERSION(1, 10, 0)
#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
