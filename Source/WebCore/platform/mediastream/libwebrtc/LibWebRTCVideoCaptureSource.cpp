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
#include "LibWebRTCVideoCaptureSource.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "LibWebRTCProviderGlib.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include "NotImplemented.h"
#include <WebCore/LibWebRTCMacros.h>
#include <wtf/NeverDestroyed.h>

#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/api/peerconnectioninterface.h"
#include "webrtc/media/base/videocommon.h"
#include "webrtc/media/engine/webrtcvideocapturer.h"
#include "webrtc/media/engine/webrtcvideocapturerfactory.h"
#include "webrtc/modules/video_capture/video_capture_defines.h"

namespace WebCore {

const static int defaultWidth = 640;
const static int defaultHeight = 480;
const static int defaultFramerate = 30;

class LibWebRTCVideoCaptureSourceFactory : public RealtimeMediaSource::VideoCaptureFactory {
public:
    CaptureSourceOrError createVideoCaptureSource(const String& deviceID, const MediaConstraints* constraints) final {
        return LibWebRTCVideoCaptureSource::create(deviceID, constraints);
    }
};

static LibWebRTCVideoCaptureSourceFactory& libWebRTCVideoCaptureSourceFactory()
{
    static NeverDestroyed<LibWebRTCVideoCaptureSourceFactory> factory;
    return factory.get();
}


CaptureSourceOrError LibWebRTCVideoCaptureSource::create(const String& deviceID, const MediaConstraints* constraints)
{
    auto source = adoptRef(*new LibWebRTCVideoCaptureSource(deviceID));

    if (constraints) {
        auto result = source->applyConstraints(*constraints);
        if (result)
            return WTFMove(result.value().first);
    }
    return CaptureSourceOrError(WTFMove(source));
}

RealtimeMediaSource::VideoCaptureFactory& LibWebRTCVideoCaptureSource::factory()
{
    return libWebRTCVideoCaptureSourceFactory();
}

LibWebRTCVideoCaptureSource::LibWebRTCVideoCaptureSource(const String& deviceID)
    : RealtimeMediaSource(deviceID, RealtimeMediaSource::Type::Video, deviceID)
{
    cricket::WebRtcVideoDeviceCapturerFactory factory;
    std::string deviceName = std::string(deviceID.ascii().data(), deviceID.ascii().length());

    std::unique_ptr<webrtc::VideoCaptureModule::DeviceInfo> deviceInfo(webrtc::VideoCaptureFactory::CreateDeviceInfo());

    if (!deviceInfo)
        return;

    int numberOfDevices = deviceInfo->NumberOfDevices();
    std::string deviceId;
    for (int i = 0; i < numberOfDevices; ++i) {
        const uint32_t deviceNameLength = 256;
        const uint32_t deviceIdLength = 256;
        char name[deviceNameLength] = {0};
        char id[deviceIdLength] = {0};
        if (deviceInfo->GetDeviceName(i, name, deviceNameLength, id, deviceIdLength) != -1) {
            if (deviceName == reinterpret_cast<char*>(name))
                deviceId = std::string(id);
        }
    }

    cricket::Device device = cricket::Device(deviceName, deviceId);
    m_capturer = factory.Create(device);
}

LibWebRTCVideoCaptureSource::~LibWebRTCVideoCaptureSource()
{
}

void LibWebRTCVideoCaptureSource::startProducingData()
{
    if (!m_capturer)
        return;

    // Make sure the factory it is initialized before calling from the thread.
    LibWebRTCRealtimeMediaSourceCenter::singleton().factory();

    LibWebRTCProvider::callOnWebRTCNetworkThread([protectedThis = makeRef(*this)]() {
            cricket::VideoFormatPod defaultFormat;
            defaultFormat.width = protectedThis->size().width();
            defaultFormat.height = protectedThis->size().height();
            defaultFormat.interval = cricket::VideoFormat::FpsToInterval(protectedThis->frameRate());
            defaultFormat.fourcc = cricket::FOURCC_ANY;
            cricket::VideoFormat desiredFormat = cricket::VideoFormat(defaultFormat);
            cricket::VideoFormat bestFormat;
            if (!protectedThis->m_capturer->GetBestCaptureFormat(desiredFormat, &bestFormat))
                return;

            protectedThis->m_currentSettings->setWidth(bestFormat.width);
            protectedThis->m_currentSettings->setHeight(bestFormat.height);
            protectedThis->m_currentSettings->setFrameRate(bestFormat.framerate());
            protectedThis->m_currentSettings->setAspectRatio((float)bestFormat.width / (float)bestFormat.height);

            protectedThis->m_capturer->Start(bestFormat);
        });
}

void LibWebRTCVideoCaptureSource::stopProducingData()
{
    if (!m_capturer)
        return;

    LibWebRTCProvider::callOnWebRTCNetworkThread([protectedThis = makeRef(*this)]() {
            protectedThis->m_capturer->Stop();
        });
}

const RealtimeMediaSourceCapabilities& LibWebRTCVideoCaptureSource::capabilities() const
{
    if (!m_capabilities) {
        RealtimeMediaSourceCapabilities capabilities(settings().supportedConstraints());
        capabilities.setDeviceId(id());

        std::unique_ptr<webrtc::VideoCaptureModule::DeviceInfo> deviceInfo(webrtc::VideoCaptureFactory::CreateDeviceInfo());
        if (deviceInfo) {
            std::string uniqueId = m_capturer->GetId();
            int32_t numberOfCapabilities = deviceInfo->NumberOfCapabilities(uniqueId.c_str());
            int32_t minWidth, minHeight, minFramerate = 0;
            float minAspectRatio = 0.0;
            int32_t maxWidth, maxHeight, maxFramerate = 0;
            float maxAspectRatio = 0.0;
            for (int i = 0; i < numberOfCapabilities; ++i) {
                webrtc::VideoCaptureCapability capability;
                deviceInfo->GetCapability(uniqueId.c_str(), i, capability);
                float capabilityAspectRatio = (float)capability.width / (float)capability.height;
                if (i == 0) {
                    minWidth = maxWidth = capability.width;
                    minHeight = maxHeight = capability.height;
                    minFramerate = maxFramerate = capability.maxFPS;
                    minAspectRatio = maxAspectRatio = capabilityAspectRatio;
                } else {
                    if (capability.width < minWidth)
                        minWidth = capability.width;
                    if (capability.width > maxWidth)
                        maxWidth = capability.width;
                    if (capability.height < minHeight)
                        minHeight = capability.height;
                    if (capability.height > maxHeight)
                        maxHeight = capability.height;
                    if (capability.maxFPS < minFramerate)
                        minFramerate = capability.maxFPS;
                    if (capability.maxFPS > maxFramerate)
                        maxFramerate = capability.maxFPS;
                    if (capabilityAspectRatio < minAspectRatio)
                        minAspectRatio = capabilityAspectRatio;
                    if (capabilityAspectRatio > maxAspectRatio)
                        maxAspectRatio = capabilityAspectRatio;
                }
            }

            m_currentSettings->setWidth(maxWidth);
            m_currentSettings->setHeight(maxHeight);
            m_currentSettings->setFrameRate(maxFramerate);
            m_currentSettings->setAspectRatio(maxAspectRatio);

            capabilities.setWidth(CapabilityValueOrRange(minWidth, maxWidth));
            capabilities.setHeight(CapabilityValueOrRange(minHeight, maxHeight));
            capabilities.setAspectRatio(CapabilityValueOrRange(minAspectRatio, maxAspectRatio));
            capabilities.setFrameRate(CapabilityValueOrRange(minFramerate, maxFramerate));
            m_capabilities = WTFMove(capabilities);
        }
    }

    return m_capabilities.value();
}

const RealtimeMediaSourceSettings& LibWebRTCVideoCaptureSource::settings() const
{
    if (!m_currentSettings) {
        RealtimeMediaSourceSettings settings;
        settings.setDeviceId(id());
        settings.setFrameRate(defaultFramerate);
        settings.setWidth(defaultWidth);
        settings.setHeight(defaultHeight);

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
    return m_currentSettings.value();
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
