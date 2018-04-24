/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 * Copyright (C) 2017 Igalia S.L. All rights reserved.
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

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
#include "GStreamerVideoCaptureSource.h"

#include "GStreamerCaptureDeviceManager.h"
#include "MediaSampleGStreamer.h"

#include <gst/app/gstappsink.h>
#include <webrtc/api/mediastreaminterface.h>
#include <webrtc/api/peerconnectioninterface.h>
#include <webrtc/media/base/videocommon.h>
#include <webrtc/media/engine/webrtcvideocapturer.h>
#include <webrtc/media/engine/webrtcvideocapturerfactory.h>
#include <webrtc/modules/video_capture/video_capture_defines.h>

namespace WebCore {

const static int defaultWidth = 640;
const static int defaultHeight = 480;

GST_DEBUG_CATEGORY(webkit_video_capture_source_debug);
#define GST_CAT_DEFAULT webkit_video_capture_source_debug

static void initializeGStreamerDebug()
{
    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_video_capture_source_debug, "webkitvideocapturesource", 0,
            "WebKit Video Capture Source.");
    });
}

class GStreamerVideoCaptureSourceFactory final : public RealtimeMediaSource::VideoCaptureFactory {
public:
    CaptureSourceOrError createVideoCaptureSource(const CaptureDevice& device, const MediaConstraints* constraints) final
    {
        return GStreamerVideoCaptureSource::create(device.persistentId(), constraints);
    }
};

RealtimeMediaSource::VideoCaptureFactory& libWebRTCVideoCaptureSourceFactory()
{
    static NeverDestroyed<GStreamerVideoCaptureSourceFactory> factory;
    return factory.get();
}

CaptureSourceOrError GStreamerVideoCaptureSource::create(const String& deviceID, const MediaConstraints* constraints)
{
    auto device = GStreamerVideoCaptureDeviceManager::singleton().gstreamerDeviceWithUID(deviceID);
    if (!device) {
        auto errorMessage = String::format("GStreamerVideoCaptureSource::create(): GStreamer did not find the device: %s.", deviceID.utf8().data());
        return CaptureSourceOrError(WTFMove(errorMessage));
    }

    auto source = adoptRef(*new GStreamerVideoCaptureSource(device.value()));

    if (constraints) {
        auto result = source->applyConstraints(*constraints);
        if (result)
            return WTFMove(result.value().first);
    }
    return CaptureSourceOrError(WTFMove(source));
}

RealtimeMediaSource::VideoCaptureFactory& GStreamerVideoCaptureSource::factory()
{
    return libWebRTCVideoCaptureSourceFactory();
}

GStreamerVideoCaptureSource::GStreamerVideoCaptureSource(const String& deviceID, const String& name, const gchar *source_factory)
    : RealtimeMediaSource(deviceID, RealtimeMediaSource::Type::Video, name)
    , m_capturer(std::make_unique<GStreamerVideoCapturer>(source_factory))
{
    initializeGStreamerDebug();
}

GStreamerVideoCaptureSource::GStreamerVideoCaptureSource(GStreamerCaptureDevice device)
    : RealtimeMediaSource(device.persistentId(), RealtimeMediaSource::Type::Video, device.label())
    , m_capturer(std::make_unique<GStreamerVideoCapturer>(device))
{
    initializeGStreamerDebug();
}

GStreamerVideoCaptureSource::~GStreamerVideoCaptureSource()
{
}

bool GStreamerVideoCaptureSource::applySize(const IntSize &size)
{
    m_capturer->setSize(size.width(), size.height());

    return true;
}

bool GStreamerVideoCaptureSource::applyFrameRate(double framerate)
{
    m_capturer->setFrameRate(framerate);

    return true;
}

void GStreamerVideoCaptureSource::startProducingData()
{
    m_capturer->setupPipeline();
    m_capturer->setSize(size().width(), size().height());
    m_capturer->setFrameRate(frameRate());
    g_signal_connect(m_capturer->sink(), "new-sample", G_CALLBACK(newSampleCallback), this);
    m_capturer->play();
}

GstFlowReturn GStreamerVideoCaptureSource::newSampleCallback(GstElement* sink, GStreamerVideoCaptureSource* source)
{
    auto gstSample = adoptGRef(gst_app_sink_pull_sample(GST_APP_SINK(sink)));
    auto mediaSample = MediaSampleGStreamer::create(WTFMove(gstSample), WebCore::FloatSize(), String());

    // FIXME - Check how presentationSize is supposed to be used here.
    callOnMainThread([protectedThis = makeRef(*source), mediaSample = WTFMove(mediaSample)] {
        protectedThis->videoSampleAvailable(mediaSample.get());
    });

    return GST_FLOW_OK;
}

void GStreamerVideoCaptureSource::stopProducingData()
{
    m_capturer->stop();

    GST_INFO("Reset height and width after stopping source");
    setHeight(0);
    setWidth(0);
}

const RealtimeMediaSourceCapabilities& GStreamerVideoCaptureSource::capabilities() const
{
    if (!m_capabilities) {
        RealtimeMediaSourceCapabilities capabilities(settings().supportedConstraints());
        GRefPtr<GstCaps> caps = adoptGRef(m_capturer->caps());
        int32_t minWidth = G_MAXINT32, minHeight = G_MAXINT32, minFramerate = G_MAXINT32;
        int32_t maxWidth = G_MININT32, maxHeight = G_MININT32, maxFramerate = G_MININT32;

        for (guint i = 0; i < gst_caps_get_size(caps.get()); i++) {
            GstStructure* str = gst_caps_get_structure(caps.get(), i);

            // Only accept raw video for now.
            if (!gst_structure_has_name(str, "video/x-raw"))
                continue;

            int32_t tmpMinWidth, tmpMinHeight, tmpMinFPSNumerator, tmpMinFPSDenominator, tmpMinFramerate;
            int32_t tmpMaxWidth, tmpMaxHeight, tmpMaxFPSNumerator, tmpMaxFPSDenominator, tmpMaxFramerate;

            if (!gst_structure_get(str, "width", GST_TYPE_INT_RANGE, &tmpMinWidth, &tmpMaxWidth, "height", GST_TYPE_INT_RANGE, &tmpMinHeight, &tmpMaxHeight, nullptr)) {

                g_assert(gst_structure_get(str, "width", G_TYPE_INT, &tmpMinWidth, "height", G_TYPE_INT, &tmpMinHeight, nullptr));
                tmpMaxWidth = tmpMinWidth;
                tmpMaxHeight = tmpMinHeight;
            }

            if (gst_structure_get(str, "framerate", GST_TYPE_FRACTION_RANGE, &tmpMinFPSNumerator, &tmpMinFPSDenominator, &tmpMaxFPSNumerator, &tmpMaxFPSDenominator, nullptr)) {
                tmpMinFramerate = (int)(tmpMinFPSNumerator / tmpMinFPSDenominator);
                tmpMaxFramerate = (int)(tmpMaxFPSNumerator / tmpMaxFPSDenominator);
            } else if (gst_structure_get(str,
                "framerate", GST_TYPE_FRACTION, &tmpMinFPSNumerator, &tmpMinFPSDenominator, nullptr)) {
                tmpMaxFPSNumerator = tmpMinFPSNumerator;
                tmpMaxFPSDenominator = tmpMinFPSDenominator;
                tmpMinFramerate = (int)(tmpMinFPSNumerator / tmpMinFPSDenominator);
                tmpMaxFramerate = (int)(tmpMaxFPSNumerator / tmpMaxFPSDenominator);
            } else {
                const GValue* frameRates(gst_structure_get_value(str, "framerate"));
                tmpMinFramerate = G_MAXINT;
                tmpMaxFramerate = 0;

                guint frameRatesLength = static_cast<guint>(gst_value_list_get_size(frameRates)) - 1;

                for (guint i = 0; i < frameRatesLength; i++) {
                    const GValue* val = gst_value_list_get_value(frameRates, i);

                    g_assert(G_VALUE_TYPE(val) == GST_TYPE_FRACTION);
                    gint framerate = (int)(gst_value_get_fraction_numerator(val) / gst_value_get_fraction_denominator(val));

                    tmpMinFramerate = std::min(tmpMinFramerate, framerate);
                    tmpMaxFramerate = std::max(tmpMaxFramerate, framerate);
                }

                if (i > 0) {
                    minWidth = std::min(tmpMinWidth, minWidth);
                    minHeight = std::min(tmpMinHeight, minHeight);
                    minFramerate = std::min(tmpMinFramerate, minFramerate);

                    maxWidth = std::max(tmpMaxWidth, maxWidth);
                    maxHeight = std::max(tmpMaxHeight, maxHeight);
                    maxFramerate = std::max(tmpMaxFramerate, maxFramerate);
                } else {
                    minWidth = tmpMinWidth;
                    minHeight = tmpMinHeight;
                    minFramerate = tmpMinFramerate;

                    maxWidth = tmpMaxWidth;
                    maxHeight = tmpMaxHeight;
                    maxFramerate = tmpMaxFramerate;
                }
            }

            capabilities.setDeviceId(id());
            capabilities.setWidth(CapabilityValueOrRange(minWidth, maxWidth));
            capabilities.setHeight(CapabilityValueOrRange(minHeight, maxHeight));
            capabilities.setFrameRate(CapabilityValueOrRange(minFramerate, maxFramerate));
            m_capabilities = WTFMove(capabilities);
        }
    }

    return m_capabilities.value();
}

const RealtimeMediaSourceSettings& GStreamerVideoCaptureSource::settings() const
{
    if (!m_currentSettings) {
        RealtimeMediaSourceSettings settings;
        settings.setDeviceId(id());

        RealtimeMediaSourceSupportedConstraints supportedConstraints;
        supportedConstraints.setSupportsDeviceId(true);
        supportedConstraints.setSupportsFacingMode(true);
        supportedConstraints.setSupportsWidth(true);
        supportedConstraints.setSupportsHeight(true);
        supportedConstraints.setSupportsAspectRatio(true);
        supportedConstraints.setSupportsFrameRate(true);
        settings.setSupportedConstraints(supportedConstraints);

        m_currentSettings = WTFMove(settings);
    }

    m_currentSettings->setWidth(size().width());
    m_currentSettings->setHeight(size().height());
    m_currentSettings->setFrameRate(frameRate());
    m_currentSettings->setAspectRatio(aspectRatio());
    m_currentSettings->setFacingMode(facingMode());
    return m_currentSettings.value();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
