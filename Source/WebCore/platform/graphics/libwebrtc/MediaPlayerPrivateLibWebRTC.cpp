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

#include "GraphicsContext.h"
#include "LibWebRTCProvider.h"
#include "LibWebRTCRealtimeMediaSourceCenter.h"
#include "LibWebRTCVideoCaptureSource.h"
#include "MediaPlayerPrivateLibWebRTC.h"

#include <cairo.h>
#include "libyuv/convert_argb.h"
#include "webrtc/api/peerconnectioninterface.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/media/engine/webrtcvideocapturerfactory.h"

namespace WebCore {

MediaPlayerPrivateLibWebRTC::MediaPlayerPrivateLibWebRTC(MediaPlayer* player)
    : m_player(player)
    , m_networkState(MediaPlayer::Empty)
    , m_drawTimer(RunLoop::main(), this, &MediaPlayerPrivateLibWebRTC::repaint)
{
}

MediaPlayerPrivateLibWebRTC::~MediaPlayerPrivateLibWebRTC()
{
    m_mediaStreamPrivate->stopProducingData();

    m_videoTrack->RemoveSink(this);

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
    LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(videoTrack->source());
    source.capturer()->GetInputSize(&width, &height);
    return FloatSize(width, height);
}

void MediaPlayerPrivateLibWebRTC::load(MediaStreamPrivate& stream)
{
    m_mediaStreamPrivate = &stream;
    m_mediaStreamPrivate->addObserver(*this);

    webrtc::PeerConnectionFactoryInterface* peerConnectionFactory = LibWebRTCProvider::factory();
    m_stream = peerConnectionFactory->CreateLocalMediaStream("stream");

    for (auto& track : m_mediaStreamPrivate->tracks()) {
        track->addObserver(*this);

        if (track->type() == RealtimeMediaSource::Type::Video) {
            LibWebRTCVideoCaptureSource& source = static_cast<LibWebRTCVideoCaptureSource&>(track->source());

            cricket::WebRtcVideoDeviceCapturerFactory factory;

            m_videoTrack = peerConnectionFactory->CreateVideoTrack("video", peerConnectionFactory->CreateVideoSource(source.capturer(), nullptr));

            m_videoTrack->AddOrUpdateSink(this, rtc::VideoSinkWants());

            m_stream->AddTrack(m_videoTrack);
        }

        if (track->type() == RealtimeMediaSource::Type::Audio) {
            m_audioTrack = peerConnectionFactory->CreateAudioTrack("audio", peerConnectionFactory->CreateAudioSource(nullptr));

            m_stream->AddTrack(m_audioTrack);
        }
    }
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

void MediaPlayerPrivateLibWebRTC::play()
{
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

    std::lock_guard<Lock> lock(m_bufferMutex);

    if (!m_buffer)
        return;

    ImagePaintingOptions paintingOptions(CompositeCopy);
    RefPtr<cairo_surface_t> surface;

    int imageStride = m_buffer->width() * 4;

    uint8_t *pixelData = static_cast<uint8_t *>(fastMalloc(m_buffer->height() * imageStride));
    libyuv::I420ToARGB(m_buffer->DataY(), m_buffer->StrideY(),
                       m_buffer->DataU(), m_buffer->StrideU(),
                       m_buffer->DataV(), m_buffer->StrideV(),
                       pixelData,
                       imageStride,
                       m_buffer->width(),
                       m_buffer->height());

    surface = adoptRef(cairo_image_surface_create_for_data(static_cast<unsigned char*>(pixelData), CAIRO_FORMAT_ARGB32, m_buffer->width(), m_buffer->height(), imageStride));
    RefPtr<BitmapImage> image = BitmapImage::create(WTFMove(surface));
    context.drawImage(*reinterpret_cast<Image*>(image.get()), rect, image->rect(), paintingOptions);
    fastFree(pixelData);
}

void MediaPlayerPrivateLibWebRTC::repaint()
{
    ASSERT(m_buffer);
    ASSERT(isMainThread());

    m_player->repaint();
}

void MediaPlayerPrivateLibWebRTC::OnFrame(const webrtc::VideoFrame& frame)
{
    if (!frame.video_frame_buffer())
        return;

    std::lock_guard<Lock> lock(m_bufferMutex);

    m_buffer = frame.video_frame_buffer()->ToI420();

    if (frame.rotation() != webrtc::kVideoRotation_0)
        m_buffer = webrtc::I420Buffer::Rotate(*m_buffer, frame.rotation());

    m_drawTimer.startOneShot(0_s);
}

MediaStreamTrackPrivate* MediaPlayerPrivateLibWebRTC::getVideoTrack() const
{
    // It assumes we just have 1 video for rendering.
    for (auto& track : m_mediaStreamPrivate->tracks())
        if (track->type() == RealtimeMediaSource::Type::Video)
            return track.get();;

    return nullptr;
}

}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
