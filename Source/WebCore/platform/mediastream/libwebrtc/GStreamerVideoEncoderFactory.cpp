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
#include "GRefPtrGStreamer.h"
#include "GStreamerCommon.h"
#include "GStreamerVideoEncoderFactory.h"

#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
#include <gst/pbutils/encoding-profile.h>
#include <gst/video/video.h>

#include "webrtc/common_video/h264/h264_common.h"
#include "webrtc/modules/video_coding/codecs/h264/include/h264.h"
#include "webrtc/modules/video_coding/codecs/vp8/include/vp8.h"
#include "webrtc/modules/video_coding/codecs/vp9/include/vp9.h"
#include <webrtc/common_video/h264/profile_level_id.h>
#include <webrtc/media/base/codec.h>
#include <webrtc/modules/video_coding/include/video_codec_interface.h>

#define GST_USE_UNSTABLE_API 1
#include <gst/codecparsers/gsth264parser.h>
#undef GST_USE_UNSTABLE_API

#include <mutex>

// Required for unified builds
#ifdef GST_CAT_DEFAULT
#undef GST_CAT_DEFAULT
#endif

GST_DEBUG_CATEGORY(webkit_webrtcenc_debug);
#define GST_CAT_DEFAULT webkit_webrtcenc_debug

namespace WebCore {

class GStreamerVideoEncoder : public webrtc::VideoEncoder {
public:
    GStreamerVideoEncoder(const webrtc::SdpVideoFormat&)
        : m_pictureId(0)
        , m_firstFramePts(GST_CLOCK_TIME_NONE)
        , m_restrictionCaps(adoptGRef(gst_caps_new_empty_simple ("video/x-raw")))
    {
    }
    GStreamerVideoEncoder()
        : m_pictureId(0)
        , m_firstFramePts(GST_CLOCK_TIME_NONE)
        , m_restrictionCaps(adoptGRef(gst_caps_new_empty_simple ("video/x-raw")))
    {
    }

    int SetRates(uint32_t new_bitrate_kbit, uint32_t frame_rate) override
    {
        // FIXME- What should we do here?
        GST_INFO_OBJECT(m_pipeline.get(), "New bitrate: %d - framerate is %d",
            new_bitrate_kbit, frame_rate);

        auto caps = gst_caps_make_writable (m_restrictionCaps.get());
        gst_caps_set_simple (caps, "framerate", GST_TYPE_FRACTION, frame_rate, 1, nullptr);

        SetRestrictionCaps (caps);

        return 0;
    }

    GstElement * makeElement(const gchar *factory_name) {
        gchar* name = g_strdup_printf("%s_enc_%s_%p", Name(), factory_name, this);
        auto elem = gst_element_factory_make(factory_name, name);
        g_free(name);

        return elem;
    }

    int32_t InitEncode(const webrtc::VideoCodec* codec_settings, int32_t, size_t)
    {
        g_return_val_if_fail(codec_settings, WEBRTC_VIDEO_CODEC_ERR_PARAMETER);
        g_return_val_if_fail(codec_settings->codecType == CodecType(), WEBRTC_VIDEO_CODEC_ERR_PARAMETER);

        m_pipeline = makeElement("pipeline");

        connectSimpleBusMessageCallback(m_pipeline.get());
        auto encodebin = CreateEncoder(&m_encoder);
        g_assert(m_encoder);

        m_src = makeElement("appsrc");
        g_object_set(m_src, "is-live", true, "format", GST_FORMAT_TIME, nullptr);

        m_capsfilter = CreateFilter();
        m_sink = makeElement("appsink");
        gst_app_sink_set_emit_signals(GST_APP_SINK(m_sink), TRUE);
        g_signal_connect(m_sink, "new-sample", G_CALLBACK(newSampleCallbackTramp), this);

        gst_bin_add_many(GST_BIN(m_pipeline.get()), m_src, encodebin, m_capsfilter, m_sink, nullptr);
        g_assert(gst_element_link_many(m_src, encodebin, m_capsfilter, m_sink, nullptr));

        gst_element_set_state(m_pipeline.get(), GST_STATE_PLAYING);

        return WEBRTC_VIDEO_CODEC_OK;
    }

    bool SupportsNativeHandle() const final { return true; }
    virtual GstElement* CreateFilter() { return makeElement("capsfilter"); }

    int32_t RegisterEncodeCompleteCallback(webrtc::EncodedImageCallback* callback) final
    {
        m_image_ready_cb = callback;

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t Release() final
    {
        GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(m_pipeline.get())));
        gst_bus_set_sync_handler(bus.get(), nullptr, nullptr, nullptr);

        gst_element_set_state(m_pipeline.get(), GST_STATE_NULL);
        m_pipeline = nullptr;

        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t SetChannelParameters(uint32_t, int64_t) final
    {
        return WEBRTC_VIDEO_CODEC_OK;
    }

    int32_t Encode(const webrtc::VideoFrame& frame,
        const webrtc::CodecSpecificInfo*,
        const std::vector<webrtc::FrameType>*) final
    {
        if (!m_image_ready_cb) {
            GST_INFO_OBJECT(m_pipeline.get(), "No encoded callback set yet!");

            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        }
        auto sample = adoptGRef(GStreamerSampleFromVideoFrame(frame));
        auto buffer = gst_sample_get_buffer (sample.get());

        if (!GST_CLOCK_TIME_IS_VALID (m_firstFramePts)) {
            m_firstFramePts = GST_BUFFER_PTS (buffer);
            auto pad = adoptGRef(gst_element_get_static_pad(m_src, "src"));
            gst_pad_set_offset (pad.get(), -m_firstFramePts);
        }
        
        switch (gst_app_src_push_sample(GST_APP_SRC(m_src), sample.get())) {
        case GST_FLOW_OK:
            return WEBRTC_VIDEO_CODEC_OK;
        case GST_FLOW_FLUSHING:
            return WEBRTC_VIDEO_CODEC_UNINITIALIZED;
        default:
            return WEBRTC_VIDEO_CODEC_ERROR;
        }
    }

    GstFlowReturn newSampleCallback(GstElement* sink)
    {
        auto sample = adoptGRef(gst_app_sink_pull_sample(GST_APP_SINK(sink)));
        auto buffer = gst_sample_get_buffer(sample.get());
        auto caps = gst_sample_get_caps(sample.get());

        webrtc::RTPFragmentationHeader* frag_info;
        auto frame = Fragmentize(buffer, &frag_info);
        if (!frame._size)
            return GST_FLOW_OK;

        gst_structure_get(gst_caps_get_structure(caps, 0),
            "width", G_TYPE_INT, &frame._encodedWidth,
            "height", G_TYPE_INT, &frame._encodedHeight,
            nullptr);

        frame._frameType = GST_BUFFER_FLAG_IS_SET(buffer, GST_BUFFER_FLAG_DELTA_UNIT) ? webrtc::kVideoFrameDelta : webrtc::kVideoFrameKey;
        frame._completeFrame = true;
        frame.capture_time_ms_ = GST_TIME_AS_MSECONDS (GST_BUFFER_PTS(buffer));
        frame._timeStamp = GST_TIME_AS_MSECONDS (GST_BUFFER_DTS(buffer));
        GST_LOG_OBJECT(m_pipeline.get(), "Got buffer TS: %" GST_TIME_FORMAT, GST_TIME_ARGS(GST_BUFFER_PTS(buffer)));

        webrtc::CodecSpecificInfo codec_specific;
        PopulateCodecSpecific(&codec_specific, buffer);

        webrtc::EncodedImageCallback::Result res = m_image_ready_cb->OnEncodedImage(frame, &codec_specific, frag_info);
        m_pictureId++;
        if (res.error != webrtc::EncodedImageCallback::Result::OK) {
            GST_ELEMENT_ERROR(m_pipeline.get(), LIBRARY, FAILED, (nullptr),
                ("Encode callback failed: %d", res.error));

            return GST_FLOW_ERROR;
        }

        return GST_FLOW_OK;
    }

    GstElement* CreateEncoder(GstElement** encoder)
    {
        GstElement* enc = NULL;

        m_profile = GST_ENCODING_PROFILE(gst_encoding_video_profile_new(
            adoptGRef(gst_caps_from_string(Caps())).get(),
            ProfileName(),
            gst_caps_ref (m_restrictionCaps.get()),
            1));
        auto encodebin = makeElement("encodebin");

        if (!encodebin) {
            GST_ERROR ("No encodebin present... can't use GStreamer based encoders");
            return nullptr;
        }
        g_object_set(encodebin, "profile", m_profile.get(), nullptr);

        for (GList* tmp = GST_BIN_CHILDREN(encodebin); tmp; tmp = tmp->next) {
            GstElement* elem = GST_ELEMENT(tmp->data);
            GstElementFactory* factory = gst_element_get_factory((elem));

            if (!factory || !gst_element_factory_list_is_type(factory, GST_ELEMENT_FACTORY_TYPE_VIDEO_ENCODER))
                continue;

            enc = elem;
            break;
        }

        if (!enc) {
            gst_object_unref(encodebin);
            return nullptr;
        }

        if (encoder)
            *encoder = enc;

        return encodebin;
    }

    void AddCodecIfSupported(std::vector<webrtc::SdpVideoFormat> *supported_formats)
    {
        GstElement* encoder;

        if (CreateEncoder(&encoder) != nullptr) {
            webrtc::SdpVideoFormat format = ConfigureSupportedCodec(encoder);

            supported_formats->push_back(format);
        }
    }

    virtual const gchar* ProfileName() { return nullptr; }

    virtual const gchar* Caps()
    {
        return nullptr;
    }

    virtual webrtc::VideoCodecType CodecType() = 0;
    virtual webrtc::SdpVideoFormat ConfigureSupportedCodec(GstElement*)
    {
        return webrtc::SdpVideoFormat(Name());
    }

    virtual void PopulateCodecSpecific(webrtc::CodecSpecificInfo* codec_specific, GstBuffer* buffer) = 0;

    virtual webrtc::EncodedImage Fragmentize(GstBuffer* buffer, webrtc::RTPFragmentationHeader** out_frag_info)
    {
        GstMapInfo map;

        gst_buffer_map(buffer, &map, GST_MAP_READ);
        webrtc::EncodedImage frame(map.data, map.size, map.size);
        gst_buffer_unmap(buffer, &map);

        // No fragmentation by default.
        webrtc::RTPFragmentationHeader* frag_info = new webrtc::RTPFragmentationHeader();

        int part_idx = 0;
        frag_info->VerifyAndAllocateFragmentationHeader(1);
        frag_info->fragmentationOffset[part_idx] = 0;
        frag_info->fragmentationLength[part_idx] = gst_buffer_get_size(buffer);
        frag_info->fragmentationPlType[part_idx] = 0;
        frag_info->fragmentationTimeDiff[part_idx] = 0;

        *out_frag_info = frag_info;

        return frame;
    }

    const char* ImplementationName() const
    {
        g_return_val_if_fail(m_encoder, nullptr);

        return GST_OBJECT_NAME(gst_element_get_factory(m_encoder));
    }

    virtual const gchar* Name() = 0;

    void SetRestrictionCaps(GstCaps *caps)
    {
        if (caps && m_profile.get()) {
            g_object_set (m_profile.get(), "restriction-caps", caps, nullptr);
        }
        m_restrictionCaps = caps;
    }

protected:
    gint m_pictureId;

private:
    static GstFlowReturn newSampleCallbackTramp(GstElement* sink, GStreamerVideoEncoder* enc)
    {
        return enc->newSampleCallback(sink);
    }

    GRefPtr<GstElement> m_pipeline;
    GstElement* m_src;
    GstElement* m_encoder;
    GstElement* m_capsfilter;
    GstElement* m_sink;

    webrtc::EncodedImageCallback* m_image_ready_cb;
    GstClockTime m_firstFramePts;
    GRefPtr<GstCaps> m_restrictionCaps;
    GRefPtr<GstEncodingProfile> m_profile;
};

class H264Encoder : public GStreamerVideoEncoder {
public:
    H264Encoder() {}

    H264Encoder(const webrtc::SdpVideoFormat& format)
        : m_parser(gst_h264_nal_parser_new())
        , packetization_mode_(webrtc::H264PacketizationMode::NonInterleaved)
    {
        auto it = format.parameters.find(cricket::kH264FmtpPacketizationMode);

        if (it != format.parameters.end() && it->second == "1") {
            packetization_mode_ = webrtc::H264PacketizationMode::NonInterleaved;
        }
    }

    // FIXME - MT. safety!
    webrtc::EncodedImage Fragmentize(GstBuffer* gstbuffer, webrtc::RTPFragmentationHeader** out_frag_info) final
    {
        GstMapInfo map;
        GstH264NalUnit nalu;
        auto pres = GST_H264_PARSER_OK;

        gsize offset = 0;
        size_t required_size = 0;

        std::vector<GstH264NalUnit> nals;
        webrtc::EncodedImage encoded_image;

        const uint8_t start_code[4] = { 0, 0, 0, 1 };
        gst_buffer_map(gstbuffer, &map, GST_MAP_READ);
        while (pres == GST_H264_PARSER_OK) {
            pres = gst_h264_parser_identify_nalu(m_parser, map.data, offset, map.size, &nalu);

            nalu.sc_offset = offset;
            nalu.offset = offset + sizeof(start_code);
            if (pres != GST_H264_PARSER_OK && pres != GST_H264_PARSER_NO_NAL_END)
                break;

            required_size += nalu.size + sizeof(start_code);
            nals.push_back(nalu);
            offset = nalu.offset + nalu.size;
        }

        encoded_image._size = required_size;
        encoded_image._buffer = new uint8_t[encoded_image._size];
        // Iterate nal units and fill the Fragmentation info
        webrtc::RTPFragmentationHeader* frag_header = new webrtc::RTPFragmentationHeader();
        frag_header->VerifyAndAllocateFragmentationHeader(nals.size());
        size_t frag = 0;
        encoded_image._length = 0;
        for (std::vector<GstH264NalUnit>::iterator nal = nals.begin();
             nal != nals.end(); ++nal, frag++) {

            g_assert(map.data[nal->sc_offset + 0] == start_code[0]);
            g_assert(map.data[nal->sc_offset + 1] == start_code[1]);
            g_assert(map.data[nal->sc_offset + 2] == start_code[2]);
            g_assert(map.data[nal->sc_offset + 3] == start_code[3]);

            frag_header->fragmentationOffset[frag] = nal->offset;
            frag_header->fragmentationLength[frag] = nal->size;

            memcpy(encoded_image._buffer + encoded_image._length, &map.data[nal->sc_offset],
                sizeof(start_code) + nal->size);
            encoded_image._length += nal->size + sizeof(start_code);
        }

        *out_frag_info = frag_header;
        gst_buffer_unmap(gstbuffer, &map);
        return encoded_image;
    }

    GstElement* CreateFilter() final
    {
        GstElement* filter = makeElement("capsfilter");
        auto caps = gst_caps_new_simple(Caps(),
            "alignment", G_TYPE_STRING, "au",
            "stream-format", G_TYPE_STRING, "byte-stream",
            nullptr);
        g_object_set(filter, "caps", caps, nullptr);
        gst_caps_unref(caps);

        return filter;
    }

    webrtc::SdpVideoFormat ConfigureSupportedCodec(GstElement*) final
    {
        // TODO- We should create that from the encoder srcpad caps!
        return webrtc::SdpVideoFormat(cricket::kH264CodecName,
                                {{cricket::kH264FmtpProfileLevelId, cricket::kH264ProfileLevelConstrainedBaseline},
                                {cricket::kH264FmtpLevelAsymmetryAllowed, "1"},
                                {cricket::kH264FmtpPacketizationMode, "1"}});
    }

    const gchar* Caps() final { return "video/x-h264"; }
    const gchar* Name() final { return cricket::kH264CodecName; }
    GstH264NalParser* m_parser;
    webrtc::VideoCodecType CodecType() final { return webrtc::kVideoCodecH264; }

    void PopulateCodecSpecific(webrtc::CodecSpecificInfo* codec_specific, GstBuffer*) final
    {
        codec_specific->codecType = CodecType();
        codec_specific->codec_name = ImplementationName();
        webrtc::CodecSpecificInfoH264* h264_info = &(codec_specific->codecSpecific.H264);
        h264_info->packetization_mode = packetization_mode_;
    }

    webrtc::H264PacketizationMode packetization_mode_;
};

class VP8Encoder : public GStreamerVideoEncoder {
public:
    VP8Encoder() {}
    VP8Encoder(const webrtc::SdpVideoFormat&) {}
    const gchar* Caps() final { return "video/x-vp8"; }
    const gchar* Name() final { return cricket::kVp8CodecName; }
    webrtc::VideoCodecType CodecType() final { return webrtc::kVideoCodecVP8; }
    virtual const gchar* ProfileName() { return "Profile Realtime"; }

    void PopulateCodecSpecific(webrtc::CodecSpecificInfo* codec_specific, GstBuffer* buffer) final
    {
        codec_specific->codecType = webrtc::kVideoCodecVP8;
        codec_specific->codec_name = ImplementationName();
        webrtc::CodecSpecificInfoVP8* vp8_info = &(codec_specific->codecSpecific.VP8);
        vp8_info->temporalIdx = 0;
        vp8_info->pictureId = m_pictureId;
        vp8_info->simulcastIdx = 0; // TODO(thiblahute) populate this
        vp8_info->keyIdx = webrtc::kNoKeyIdx; // TODO(thiblahute) populate this
        vp8_info->nonReference = GST_BUFFER_FLAG_IS_SET(buffer, GST_BUFFER_FLAG_DELTA_UNIT);
        vp8_info->tl0PicIdx = -1; // TODO(thiblahute) populate this
    }
};

std::unique_ptr<webrtc::VideoEncoder> GStreamerVideoEncoderFactory::CreateVideoEncoder(const webrtc::SdpVideoFormat& format)
{
    if (format.name == cricket::kVp8CodecName)
        return std::make_unique<VP8Encoder>(format);
    else if (format.name == cricket::kH264CodecName)
        return std::make_unique<H264Encoder>(format);

    return nullptr;
}

GStreamerVideoEncoderFactory::GStreamerVideoEncoderFactory()
{
    static std::once_flag debugRegisteredFlag;

    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_webrtcenc_debug, "webkitlibwebrtcvideoencoder", 0, "WebKit WebRTC video encoder");
    });
}

std::vector<webrtc::SdpVideoFormat> GStreamerVideoEncoderFactory::GetSupportedFormats() const {
    std::vector<webrtc::SdpVideoFormat> supportedCodecs;

    VP8Encoder().AddCodecIfSupported(&supportedCodecs);
    H264Encoder().AddCodecIfSupported(&supportedCodecs);


    return supportedCodecs;
}

} // namespace WebCore
#endif
