/*
 * Copyright (C) 2017 Igalia S.L.
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

#pragma once

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "BitmapImage.h"
#include "LibWebRTCMacros.h"
#include "MediaPlayerPrivate.h"
#include "MediaSampleLibWebRTC.h"
#include "MediaStreamPrivate.h"
#include "MediaStreamTrackPrivate.h"
#include "RealtimeMediaSource.h"
#include "GStreamerVideoDecoderFactory.h"

#include "MediaPlayerPrivateGStreamer.h"

#include <gst/audio/streamvolume.h>
#include <gst/gst.h>

namespace WebCore {

class MediaPlayerPrivateLibWebRTC
    : public MediaPlayerPrivateGStreamer
    , private MediaStreamTrackPrivate::Observer
    , GStreamerVideoDecoderFactory::Observer {
public:
    explicit MediaPlayerPrivateLibWebRTC(MediaPlayer*);
    ~MediaPlayerPrivateLibWebRTC();

    static void registerMediaEngine(MediaEngineRegistrar);

private:
    void sourceSetup(GstElement*) final;
    String engineDescription() const final { return "GStreamerLibWebRTC"; }

    static bool initializeGStreamerAndGStreamerDebugging();
    static void getSupportedTypes(HashSet<String, ASCIICaseInsensitiveHash>&);
    static MediaPlayer::SupportsType supportsType(const MediaEngineSupportParameters&);

#if ENABLE(MEDIA_SOURCE)
    void load(const String& url, MediaSourcePrivateClient*);
#endif
    void load(MediaStreamPrivate&) final;
    void load(const String&) final;
    void cancelLoad() final;

    // void prepareToPlay() final;
    // void play() final;
    // void pause() final;

    FloatSize naturalSize() const final;

    bool hasVideo() const final { return m_videoTrack; }
    bool hasAudio() const final { return m_audioTrack; }

    MediaTime durationMediaTime() const override;

    float currentTime() const final;
    void seekDouble(double) final {}
    bool seeking() const final { return false; }

    void setRateDouble(double) final {}
    void setPreservesPitch(bool) final {}
    bool paused() const final { return false; }

    bool isLiveStream() const override { return true; }

    bool hasClosedCaptions() const final { return false; }
    void setClosedCaptionsVisible(bool) final{};

    float maxTimeSeekable() const final { return 0; }
    double minTimeSeekable() const final { return 0; }
    std::unique_ptr<PlatformTimeRanges> buffered() const final { return std::make_unique<PlatformTimeRanges>(); }

    double seekableTimeRangesLastModifiedTime() const final { return 0; }
    double liveUpdateInterval() const final { return 0; }

    unsigned long long totalBytes() const final { return 0; }
    bool didLoadingProgress() const final { return false; }

    bool canLoadPoster() const final { return false; }
    void setPoster(const String&) final {}

    // MediaStreamPrivateTrack::Observer
    void trackStarted(MediaStreamTrackPrivate&) final{};
    void trackEnded(MediaStreamTrackPrivate&) final{};
    void trackMutedChanged(MediaStreamTrackPrivate&) final;
    void trackSettingsChanged(MediaStreamTrackPrivate&) final{};
    void trackEnabledChanged(MediaStreamTrackPrivate&) final{};
    void sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample&) final;
    void audioSamplesAvailable(MediaStreamTrackPrivate&, const MediaTime&, const PlatformAudioData&, const AudioStreamDescription&, size_t) final;
    void readyStateChanged(MediaStreamTrackPrivate&) final{};

    void loadingFailed(MediaPlayer::NetworkState error);
    void setState(GstState state);

    // GStreamerVideoDecoderFactory::Observer implementation.
    virtual GstElement* requestSink (String track_id, GstElement *pipeline);

    void handleExternalPipelineBusMessagesSync(GstElement *pipeline);

    RefPtr<MediaStreamTrackPrivate> m_videoTrack;
    RefPtr<MediaStreamTrackPrivate> m_audioTrack;
    RefPtr<MediaStreamPrivate> m_streamPrivate;
    GRefPtr<GstElement> m_audioSrc;
    GRefPtr<GstElement> m_videoSrc;
    GRefPtr<GstElement> m_sink;
};
}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
