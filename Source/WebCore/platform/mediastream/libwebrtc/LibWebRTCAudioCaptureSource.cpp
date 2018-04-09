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
#include "LibWebRTCAudioCaptureSource.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "NotImplemented.h"
#include <wtf/NeverDestroyed.h>
#include "MockRealtimeAudioSource.h"
#include "gstreamer/GStreamerAudioData.h"
#include "gstreamer/GStreamerAudioStreamDescription.h"
#include "gstreamer/GStreamerCaptureDeviceManager.h"

#include <gst/gst.h>
#include <gst/app/gstappsink.h>

GST_DEBUG_CATEGORY(webkit_audio_capture_source_debug);
#ifdef GST_CAT_DEFAULT
#undef GST_CAT_DEFAULT
#endif

#define GST_CAT_DEFAULT webkit_audio_capture_source_debug

namespace WebCore {

static void initializeGStreamerDebug()
{
    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_audio_capture_source_debug, "webkitaudiocapturesource", 0,
            "WebKit Audio Capture Source.");
    });
}

class LibWebRTCAudioCaptureSourceFactory : public RealtimeMediaSource::AudioCaptureFactory {
public:
    CaptureSourceOrError createAudioCaptureSource(const CaptureDevice& device, const MediaConstraints* constraints) final {
        return LibWebRTCAudioCaptureSource::create(device.persistentId(), constraints);
    }
};

static LibWebRTCAudioCaptureSourceFactory& libWebRTCAudioCaptureSourceFactory()
{
    static NeverDestroyed<LibWebRTCAudioCaptureSourceFactory> factory;
    return factory.get();
}

CaptureSourceOrError LibWebRTCAudioCaptureSource::create(const String& deviceID, const MediaConstraints* constraints)
{
    auto device = GStreamerAudioCaptureDeviceManager::singleton().gstreamerDeviceWithUID(deviceID);
    if (!device)
        return { };

    auto source = adoptRef(*new LibWebRTCAudioCaptureSource(
        static_cast<GStreamerCaptureDevice>(device.value())));

    if (constraints) {
        auto result = source->applyConstraints(*constraints);
        if (result)
            return WTFMove(result.value().first);
    }
    return CaptureSourceOrError(WTFMove(source));
}

RealtimeMediaSource::AudioCaptureFactory& LibWebRTCAudioCaptureSource::factory()
{
    return libWebRTCAudioCaptureSourceFactory();
}

LibWebRTCAudioCaptureSource::LibWebRTCAudioCaptureSource(GStreamerCaptureDevice device)
    : RealtimeMediaSource(device.persistentId(), RealtimeMediaSource::Type::Audio, device.label()),
    m_capturer(std::make_unique<GStreamerAudioCapturer>(device))
{
    initializeGStreamerDebug();
}

LibWebRTCAudioCaptureSource::LibWebRTCAudioCaptureSource(const String& deviceID, const String& name)
    : RealtimeMediaSource(deviceID, RealtimeMediaSource::Type::Audio, name),
    m_capturer(std::make_unique<GStreamerAudioCapturer>())
{
    initializeGStreamerDebug();
}

LibWebRTCAudioCaptureSource::~LibWebRTCAudioCaptureSource()
{
}

void LibWebRTCAudioCaptureSource::startProducingData()
{
    webrtc::PeerConnectionFactoryInterface* peerConnectionFactory = LibWebRTCRealtimeMediaSourceCenter::singleton().factory();

    // FIXME - This does not sound 100% right
    m_audioTrack = peerConnectionFactory->CreateAudioTrack("audio",
        peerConnectionFactory->CreateAudioSource(nullptr));

    m_capturer->setupPipeline();
    g_signal_connect(m_capturer->m_sink.get(), "new-sample", G_CALLBACK(newSampleCallback), this);
    m_capturer->play();
}

GstFlowReturn LibWebRTCAudioCaptureSource::newSampleCallback(GstElement* sink, LibWebRTCAudioCaptureSource* source)
{
    auto sample = adoptGRef(gst_app_sink_pull_sample(GST_APP_SINK(sink)));

    // FIXME - figure out a way to avoid copying (on write) the data.
    GstBuffer *buf = gst_sample_get_buffer (sample.get());
    auto frames(std::unique_ptr<GStreamerAudioData>(new GStreamerAudioData(WTFMove(sample))));
    auto streamDesc(std::unique_ptr<GStreamerAudioStreamDescription>(new GStreamerAudioStreamDescription(frames->getAudioInfo())));

    source->audioSamplesAvailable(
        MediaTime(GST_TIME_AS_USECONDS (GST_BUFFER_PTS (buf)), G_USEC_PER_SEC),
        *frames, *streamDesc, gst_buffer_get_size (buf) / frames->getAudioInfo().bpf);

    return GST_FLOW_OK;
}

void LibWebRTCAudioCaptureSource::stopProducingData()
{
    m_capturer->stop();
}

const RealtimeMediaSourceCapabilities& LibWebRTCAudioCaptureSource::capabilities() const
{
    if (!m_capabilities) {
        GRefPtr<GstCaps> caps = m_capturer->getCaps();
        gint min_samplerate = 0, max_samplerate = 0;
        guint i;

        for (i = 0; i < gst_caps_get_size (caps.get()); i++) {
            GstStructure * str = gst_caps_get_structure (caps.get(), i);

            if (gst_structure_has_name (str, "audio/x-raw")) {
                g_assert (gst_structure_get (str, "rate",
                    GST_TYPE_INT_RANGE, &min_samplerate, &max_samplerate,
                    nullptr));

                break;
            }
        }

        RealtimeMediaSourceCapabilities capabilities(settings().supportedConstraints());
        capabilities.setDeviceId(id());
        capabilities.setEchoCancellation(RealtimeMediaSourceCapabilities::EchoCancellation::ReadWrite);
        capabilities.setVolume(CapabilityValueOrRange(0.0, 1.0));
        capabilities.setSampleRate(CapabilityValueOrRange(min_samplerate, max_samplerate));
        m_capabilities = WTFMove(capabilities);
    }
    return m_capabilities.value();
}

bool LibWebRTCAudioCaptureSource::applySampleRate(int sampleRate)
{
    return m_capturer->setSampleRate(sampleRate);
}

const RealtimeMediaSourceSettings& LibWebRTCAudioCaptureSource::settings() const
{
    if (!m_currentSettings) {
        RealtimeMediaSourceSettings settings;
        settings.setVolume(volume());
        settings.setSampleRate(sampleRate());
        settings.setDeviceId(id());
        settings.setEchoCancellation(echoCancellation());

        RealtimeMediaSourceSupportedConstraints supportedConstraints;
        supportedConstraints.setSupportsDeviceId(true);
        supportedConstraints.setSupportsEchoCancellation(true);
        supportedConstraints.setSupportsVolume(true);
        supportedConstraints.setSupportsSampleRate(true);
        settings.setSupportedConstraints(supportedConstraints);

        m_currentSettings = WTFMove(settings);
    }
    return m_currentSettings.value();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
