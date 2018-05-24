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
#include "GStreamerAudioCaptureSource.h"

#include "GStreamerAudioData.h"
#include "GStreamerAudioStreamDescription.h"
#include "GStreamerCaptureDeviceManager.h"

#include <gst/app/gstappsink.h>
#include <gst/gst.h>
#include <wtf/NeverDestroyed.h>

namespace WebCore {

const static CapabilityValueOrRange defaultVolumeCapability = CapabilityValueOrRange(0.0, 1.0);
const static RealtimeMediaSourceCapabilities::EchoCancellation defaultEchoCancellationCapability = RealtimeMediaSourceCapabilities::EchoCancellation::ReadWrite;

GST_DEBUG_CATEGORY(webkit_audio_capture_source_debug);
#define GST_CAT_DEFAULT webkit_audio_capture_source_debug

static void initializeGStreamerDebug()
{
    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_audio_capture_source_debug, "webkitaudiocapturesource", 0, "WebKit Audio Capture Source.");
    });
}

class GStreamerAudioCaptureSourceFactory : public RealtimeMediaSource::AudioCaptureFactory {
public:
    CaptureSourceOrError createAudioCaptureSource(const CaptureDevice& device, const MediaConstraints* constraints) final
    {
        return GStreamerAudioCaptureSource::create(device.persistentId(), constraints);
    }
};

static GStreamerAudioCaptureSourceFactory& libWebRTCAudioCaptureSourceFactory()
{
    static NeverDestroyed<GStreamerAudioCaptureSourceFactory> factory;
    return factory.get();
}

CaptureSourceOrError GStreamerAudioCaptureSource::create(const String& deviceID, const MediaConstraints* constraints)
{
    auto device = GStreamerAudioCaptureDeviceManager::singleton().gstreamerDeviceWithUID(deviceID);
    if (!device) {
        auto errorMessage = String::format("GStreamerAudioCaptureSource::create(): GStreamer did not find the device: %s.", deviceID.utf8().data());
        return CaptureSourceOrError(WTFMove(errorMessage));
    }

    auto source = adoptRef(*new GStreamerAudioCaptureSource(device.value()));

    if (constraints) {
        auto result = source->applyConstraints(*constraints);
        if (result)
            return WTFMove(result.value().first);
    }
    return CaptureSourceOrError(WTFMove(source));
}

RealtimeMediaSource::AudioCaptureFactory& GStreamerAudioCaptureSource::factory()
{
    return libWebRTCAudioCaptureSourceFactory();
}

GStreamerAudioCaptureSource::GStreamerAudioCaptureSource(GStreamerCaptureDevice device)
    : RealtimeMediaSource(device.persistentId(), RealtimeMediaSource::Type::Audio, device.label())
    , m_capturer(std::make_unique<GStreamerAudioCapturer>(device))
{
    initializeGStreamerDebug();
}

GStreamerAudioCaptureSource::GStreamerAudioCaptureSource(const String& deviceID, const String& name)
    : RealtimeMediaSource(deviceID, RealtimeMediaSource::Type::Audio, name)
    , m_capturer(std::make_unique<GStreamerAudioCapturer>())
{
    initializeGStreamerDebug();
}

GStreamerAudioCaptureSource::~GStreamerAudioCaptureSource()
{
}

void GStreamerAudioCaptureSource::startProducingData()
{
    m_capturer->setupPipeline();
    m_capturer->setSampleRate(sampleRate());
    g_signal_connect(m_capturer->sink(), "new-sample", G_CALLBACK(newSampleCallback), this);
    m_capturer->play();
}

GstFlowReturn GStreamerAudioCaptureSource::newSampleCallback(GstElement* sink, GStreamerAudioCaptureSource* source)
{
    auto sample = adoptGRef(gst_app_sink_pull_sample(GST_APP_SINK(sink)));

    // FIXME - figure out a way to avoid copying (on write) the data.
    GstBuffer* buf = gst_sample_get_buffer(sample.get());
    auto frames(std::unique_ptr<GStreamerAudioData>(new GStreamerAudioData(WTFMove(sample))));
    auto streamDesc(std::unique_ptr<GStreamerAudioStreamDescription>(new GStreamerAudioStreamDescription(frames->getAudioInfo())));

    source->audioSamplesAvailable(
        MediaTime(GST_TIME_AS_USECONDS(GST_BUFFER_PTS(buf)), G_USEC_PER_SEC),
        *frames, *streamDesc, gst_buffer_get_size(buf) / frames->getAudioInfo().bpf);

    return GST_FLOW_OK;
}

void GStreamerAudioCaptureSource::stopProducingData()
{
    m_capturer->stop();
}

const RealtimeMediaSourceCapabilities& GStreamerAudioCaptureSource::capabilities() const
{
    if (!m_capabilities) {
        GRefPtr<GstCaps> caps = m_capturer->caps();
        int minSampleRate = 0, maxSampleRate = 0;
        uint i;

        for (i = 0; i < gst_caps_get_size(caps.get()); i++) {
            int capabilityMinSampleRate = 0, capabilityMaxSampleRate = 0;
            GstStructure* str = gst_caps_get_structure(caps.get(), i);

            // Only accept raw audio for now.
            if (!gst_structure_has_name(str, "audio/x-raw"))
                continue;

            gst_structure_get(str, "rate", GST_TYPE_INT_RANGE, &capabilityMinSampleRate, &capabilityMaxSampleRate, nullptr);
            if (i > 0) {
                minSampleRate = std::min(minSampleRate, capabilityMinSampleRate);
                maxSampleRate = std::max(maxSampleRate, capabilityMaxSampleRate);
            } else {
                minSampleRate = capabilityMinSampleRate;
                maxSampleRate = capabilityMaxSampleRate;
            }
        }

        RealtimeMediaSourceCapabilities capabilities(settings().supportedConstraints());
        capabilities.setDeviceId(id());
        capabilities.setEchoCancellation(defaultEchoCancellationCapability);
        capabilities.setVolume(defaultVolumeCapability);
        capabilities.setSampleRate(CapabilityValueOrRange(minSampleRate, maxSampleRate));
        m_capabilities = WTFMove(capabilities);
    }
    return m_capabilities.value();
}

bool GStreamerAudioCaptureSource::applySampleRate(int sampleRate)
{
    return m_capturer->setSampleRate(sampleRate);
}

const RealtimeMediaSourceSettings& GStreamerAudioCaptureSource::settings() const
{
    if (!m_currentSettings) {
        RealtimeMediaSourceSettings settings;
        settings.setDeviceId(id());

        RealtimeMediaSourceSupportedConstraints supportedConstraints;
        supportedConstraints.setSupportsDeviceId(true);
        supportedConstraints.setSupportsEchoCancellation(true);
        supportedConstraints.setSupportsVolume(true);
        supportedConstraints.setSupportsSampleRate(true);
        settings.setSupportedConstraints(supportedConstraints);

        m_currentSettings = WTFMove(settings);
    }

    m_currentSettings->setVolume(volume());
    m_currentSettings->setSampleRate(sampleRate());
    m_currentSettings->setEchoCancellation(echoCancellation());

    return m_currentSettings.value();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
