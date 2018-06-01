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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
#include <wtf/text/WTFString.h>

#include "GRefPtrGStreamer.h"
#include "GStreamerCommon.h"
#include "GStreamerVideoDecoderFactory.h"

#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
#include <gst/video/video.h>

#include "webrtc/common_video/h264/h264_common.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"
#include "webrtc/modules/video_coding/codecs/vp8/include/vp8.h"
#include "webrtc/modules/video_coding/codecs/vp9/include/vp9.h"
#include <webrtc/common_video/h264/profile_level_id.h>
#include <webrtc/media/base/codec.h>
#include <webrtc/modules/video_coding/include/video_codec_interface.h>

#include <mutex>
#include <wtf/glib/RunLoopSourcePriority.h>

// Required for unified builds
#ifdef GST_CAT_DEFAULT
#undef GST_CAT_DEFAULT
#endif

GST_DEBUG_CATEGORY(webkit_webrtcdec_debug);
#define GST_CAT_DEFAULT webkit_webrtcdec_debug

namespace WebCore {

class GStreamerVideoDecoder : public webrtc::VideoDecoder {
public:
    GStreamerVideoDecoder()
        : m_pictureId(0)
        , m_firstBufferPts(GST_CLOCK_TIME_NONE)
        , m_firstBufferDts(GST_CLOCK_TIME_NONE)
    {
    }

    static void decodebin_pad_added_cb(GstElement*,
        GstPad* srcpad,
        GstPad* sinkpad)
    {
        GST_INFO_OBJECT(srcpad, "connecting pad with %" GST_PTR_FORMAT, sinkpad);
        g_assert(gst_pad_link(srcpad, sinkpad) == GST_PAD_LINK_OK);
    }

    GstElement* makeElement(const gchar* factory_name)
    {
        gchar* name = g_strdup_printf("%s_dec_%s_%p", Name(), factory_name, this);
        auto elem = gst_element_factory_make(factory_name, name);
        g_free(name);

        return elem;
    }

    int32_t InitDecode(const webrtc::VideoCodec*, int32_t)
    {
        m_src = makeElement("appsrc");
        if (GStreamerVideoDecoderFactory::newSource(String::fromUTF8(m_stream_id.c_str()), m_src)) {
            GST_INFO ("Let a mediastreamsrc handle the decoding!");

            return WEBRTC_VIDEO_CODEC_OK;
        }

        m_capsfilter = CreateFilter();
        m_decoder = makeElement("decodebin");
        auto sinkpad = gst_element_get_static_pad(m_capsfilter, "sink");
        g_signal_connect(m_decoder, "pad-added", G_CALLBACK(decodebin_pad_added_cb), sinkpad);

        m_pipeline = makeElement("pipeline");
        connectSimpleBusMessageCallback(m_pipeline.get());

        m_sink = makeElement("appsink");
        gst_app_sink_set_emit_signals(GST_APP_SINK(m_sink), TRUE);
        g_signal_connect(m_sink, "new-sample", G_CALLBACK(newSampleCallbackTramp), this);

        gst_bin_add_many(GST_BIN(m_pipeline.get()), m_src, m_decoder, m_capsfilter, m_sink, nullptr);
        g_assert(gst_element_link_many(m_src, m_decoder, nullptr));
        g_assert(gst_element_link_many(m_capsfilter, m_sink, nullptr));

        gst_element_set_state(m_pipeline.get(), GST_STATE_PLAYING);

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t RegisterDecodeCompleteCallback(webrtc::DecodedImageCallback* callback)
    {
        m_image_ready_cb = callback;

        return WEBRTC_VIDEO_CODEC_OK;
    }

    virtual GstElement* CreateFilter()
    {
        return makeElement("videoconvert");
    }

    int32_t Release() final
    {
        if (m_pipeline.get()) {
            GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(m_pipeline.get())));
            gst_bus_set_sync_handler(bus.get(), nullptr, nullptr, nullptr);

            gst_element_set_state(m_pipeline.get(), GST_STATE_NULL);
            m_pipeline = nullptr;
        }

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t Decode(const webrtc::EncodedImage& input_image,
        bool,
        const webrtc::RTPFragmentationHeader*,
        const webrtc::CodecSpecificInfo*,
        int64_t render_time_ms) override
    {
        if (!GST_CLOCK_TIME_IS_VALID(m_firstBufferPts)) {
            GRefPtr<GstPad> srcpad = adoptGRef(gst_element_get_static_pad(m_src, "src"));
            m_firstBufferPts = ((guint64)render_time_ms) * GST_MSECOND;
            m_firstBufferDts = ((guint64)input_image._timeStamp) * GST_MSECOND;
        }

        // FIXME- Use a GstBufferPool.
        auto buffer = gst_buffer_new_wrapped(g_memdup(input_image._buffer, input_image._size),
            input_image._size);
        GST_BUFFER_DTS(buffer) = (((guint64)input_image._timeStamp) * GST_MSECOND) - m_firstBufferDts;
        GST_BUFFER_PTS(buffer) = ((guint64)(render_time_ms)*GST_MSECOND) - m_firstBufferPts;
        m_dts_pts_map[GST_BUFFER_PTS(buffer)] = input_image._timeStamp;

        GST_LOG("%ld Decoding: %" GST_PTR_FORMAT,
            render_time_ms, buffer);
        switch (gst_app_src_push_sample(GST_APP_SRC(m_src),
            gst_sample_new(buffer, GetCapsForFrame(input_image), nullptr, nullptr))) {
        case GST_FLOW_OK:
            return WEBRTC_VIDEO_CODEC_OK;
        case GST_FLOW_FLUSHING:
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        default:
            return WEBRTC_VIDEO_CODEC_ERROR;
        }
    }

    GstCaps* GetCapsForFrame(const webrtc::EncodedImage&)
    {
        if (!m_caps)
            m_caps = adoptGRef(gst_caps_new_empty_simple(Caps()));

        return m_caps.get();
    }

    void AddDecoderIfSupported(std::vector<webrtc::SdpVideoFormat> codec_list)
    {
        if (HasGstDecoder()) {
            webrtc::SdpVideoFormat format = ConfigureSupportedDecoder();

            codec_list.push_back(format);
        }
    }

    virtual webrtc::SdpVideoFormat ConfigureSupportedDecoder()
    {
        return webrtc::SdpVideoFormat(Name());
    }

    bool HasGstDecoder()
    {

        auto all_decoders = gst_element_factory_list_get_elements(GST_ELEMENT_FACTORY_TYPE_DECODER,
            GST_RANK_MARGINAL);
        auto caps = adoptGRef(gst_caps_from_string(Caps()));
        auto decoders = gst_element_factory_list_filter(all_decoders,
            caps.get(), GST_PAD_SINK, FALSE);

        gst_plugin_feature_list_free(all_decoders);
        gst_plugin_feature_list_free(decoders);

        return decoders != nullptr;
    }

    GstFlowReturn newSampleCallback(GstElement* sink)
    {
        auto sample = gst_app_sink_pull_sample(GST_APP_SINK(sink));
        auto buffer = gst_sample_get_buffer(sample);

        // Make sure that the frame.timestamp == previsouly input_frame._timeStamp
        // as it is required by the VideoDecoder baseclass.
        GST_BUFFER_DTS(buffer) = m_dts_pts_map[GST_BUFFER_PTS(buffer)];
        m_dts_pts_map.erase(GST_BUFFER_PTS(buffer));
        std::unique_ptr<webrtc::VideoFrame> frame(GStreamerVideoFrameFromBuffer(sample, webrtc::kVideoRotation_0));
        GST_BUFFER_DTS(buffer) = GST_CLOCK_TIME_NONE;
        GST_LOG("Output decoded frame! %ld -> %" GST_PTR_FORMAT,
            frame->timestamp(), buffer);

        m_image_ready_cb->Decoded(*frame.get(), rtc::Optional<int32_t>(), rtc::Optional<uint8_t>());

        return GST_FLOW_OK;
    }

    virtual const gchar* Caps() = 0;
    virtual webrtc::VideoCodecType CodecType() = 0;
    const char* ImplementationName() const { return "GStreamer"; }
    virtual const gchar* Name() = 0;
    std::string m_stream_id;

protected:
    GRefPtr<GstCaps> m_caps;
    gint m_pictureId;

private:
    static GstFlowReturn newSampleCallbackTramp(GstElement* sink, GStreamerVideoDecoder* enc)
    {
        return enc->newSampleCallback(sink);
    }

    GRefPtr<GstElement> m_pipeline;
    GstElement* m_src;
    GstElement* m_decoder;
    GstElement* m_capsfilter;
    GstElement* m_sink;

    GstVideoInfo m_info;
    webrtc::DecodedImageCallback* m_image_ready_cb;

    std::map<GstClockTime, GstClockTime> m_dts_pts_map;
    GstClockTime m_firstBufferPts;
    GstClockTime m_firstBufferDts;
};

class H264Decoder : public GStreamerVideoDecoder {
public:
    H264Decoder() {}
    const gchar* Caps() final { return "video/x-h264"; }
    const gchar* Name() final { return cricket::kH264CodecName; }
    webrtc::VideoCodecType CodecType() final { return webrtc::kVideoCodecH264; }
};

class VP8Decoder : public GStreamerVideoDecoder {
public:
    VP8Decoder() {}
    const gchar* Caps() final { return "video/x-vp8"; }
    const gchar* Name() final { return cricket::kVp8CodecName; }
    webrtc::VideoCodecType CodecType() final { return webrtc::kVideoCodecVP8; }

    GstCaps* GetCapsForFrame(const webrtc::EncodedImage& image)
    {
        if (!m_caps)
            m_caps = adoptGRef(gst_caps_new_simple(Caps(),
                "width", G_TYPE_INT, image._encodedWidth,
                "height", G_TYPE_INT, image._encodedHeight,
                nullptr));

        return m_caps.get();
    }
};

// FIME- Make MT safe!
Vector<GStreamerVideoDecoderFactory::Observer*> OBSERVERS;

bool GStreamerVideoDecoderFactory::newSource(String track_id, GstElement *source)
{
    GST_ERROR ("New decoder!");
    for (Observer* observer : OBSERVERS) {
        GST_ERROR ("?? New decoder!");
        if (observer->newSource(track_id, source))
            return true;
    }
    GST_ERROR ("Nothing.");

    return false;
}

void GStreamerVideoDecoderFactory::addObserver(Observer& observer)
{
    OBSERVERS.append(&observer);
}

void GStreamerVideoDecoderFactory::removeObserver(Observer& observer)
{
    size_t pos = OBSERVERS.find(&observer);
    if (pos != notFound)
        OBSERVERS.remove(pos);
}

std::unique_ptr<webrtc::VideoDecoder> GStreamerVideoDecoderFactory::CreateVideoDecoder(const webrtc::SdpVideoFormat& format)
{
    GStreamerVideoDecoder* dec;

    if (format.name == cricket::kH264CodecName)
        dec = new H264Decoder();
    else if (format.name == cricket::kVp8CodecName)
        dec = new VP8Decoder();
    else {
        GST_ERROR("Could not create decoder for %s", format.name.c_str());

        return nullptr;
    }

    dec->m_stream_id = format.parameters.find("receive-stream-id")->second;

    return std::unique_ptr<webrtc::VideoDecoder>(dec);
}

GStreamerVideoDecoderFactory::GStreamerVideoDecoderFactory()
{
    static std::once_flag debugRegisteredFlag;

    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_webrtcdec_debug, "webkitlibwebrtcvideodecoder", 0, "WebKit WebRTC video decoder");
    });
}
std::vector<webrtc::SdpVideoFormat> GStreamerVideoDecoderFactory::GetSupportedFormats() const
{
    std::vector<webrtc::SdpVideoFormat> res;

    VP8Decoder().AddDecoderIfSupported(res);
    H264Decoder().AddDecoderIfSupported(res);

    return res;
}
}
#endif
