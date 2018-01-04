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

#include "webrtc/api/mediastreaminterface.h"
#include "webrtc/media/base/videosinkinterface.h"
#include "webrtc/media/engine/webrtcvideocapturer.h"

#include "MediaPlayerPrivateGStreamerBase.h"

#include <gst/gst.h>
#include <gst/audio/streamvolume.h>

namespace WebCore {

class MediaPlayerPrivateLibWebRTC : public MediaPlayerPrivateGStreamerBase, private MediaStreamPrivate::Observer, private MediaStreamTrackPrivate::Observer {
public:
    explicit MediaPlayerPrivateLibWebRTC(MediaPlayer*);
    ~MediaPlayerPrivateLibWebRTC();

    static void registerMediaEngine(MediaEngineRegistrar);

private:
    static bool initializeGStreamerAndGStreamerDebugging();
    static void getSupportedTypes(HashSet<String, ASCIICaseInsensitiveHash>&);
    static MediaPlayer::SupportsType supportsType(const MediaEngineSupportParameters&);

#if ENABLE(MEDIA_SOURCE)
    void load(const String& url, MediaSourcePrivateClient*);
#endif
    void load(MediaStreamPrivate&) final;
    void load(const String&) final;
    void cancelLoad() final;

    void prepareToPlay() final;
    void play() final;
    void pause() final;

    FloatSize naturalSize() const final;

    bool hasVideo() const final { return getVideoTrack(); }
    bool hasAudio() const final { return getAudioTrack(); }

    double durationDouble() const final { return 0; }

    double currentTimeDouble() const final { return 0; }
    void seekDouble(double) final { }
    bool seeking() const final { return false; }

    void setRateDouble(double) final { }
    void setPreservesPitch(bool) final { }
    bool paused() const final { return false; }

    bool isLiveStream() const override { return true; }

    bool hasClosedCaptions() const final { return false; }
    void setClosedCaptionsVisible(bool) final { };

    MediaPlayer::NetworkState networkState() const final { return MediaPlayer::Empty; }
    MediaPlayer::ReadyState readyState() const final { return MediaPlayer::HaveNothing; }

    float maxTimeSeekable() const final { return 0; }
    double minTimeSeekable() const final { return 0; }
    std::unique_ptr<PlatformTimeRanges> buffered() const final { return std::make_unique<PlatformTimeRanges>(); }

    double seekableTimeRangesLastModifiedTime() const final { return 0; }
    double liveUpdateInterval() const final { return 0; }

    unsigned long long totalBytes() const final { return 0; }
    bool didLoadingProgress() const final { return false; }

    void setSize(const IntSize&) final { }

    bool canLoadPoster() const final { return false; }
    void setPoster(const String&) final { }

    bool hasSingleSecurityOrigin() const final { return true; }

    // MediaStreamPrivate::Observer
    void activeStatusChanged() final { };
    void characteristicsChanged() final { };
    void didAddTrack(MediaStreamTrackPrivate&) final { };
    void didRemoveTrack(MediaStreamTrackPrivate&) final { };

    // MediaStreamPrivateTrack::Observer
    void trackStarted(MediaStreamTrackPrivate&) final { };
    void trackEnded(MediaStreamTrackPrivate&) final { };
    void trackMutedChanged(MediaStreamTrackPrivate&) final;
    void trackSettingsChanged(MediaStreamTrackPrivate&) final { };
    void trackEnabledChanged(MediaStreamTrackPrivate&) final { };
    void sampleBufferUpdated(MediaStreamTrackPrivate&, MediaSample&) final;
    void audioSamplesAvailable(MediaStreamTrackPrivate&, const MediaTime&, const PlatformAudioData&, const AudioStreamDescription&, size_t) final;
    void readyStateChanged(MediaStreamTrackPrivate&) final { };

    static GstFlowReturn videoSinkSampleCb(GstElement* sink, MediaPlayerPrivateLibWebRTC * source);

    MediaStreamTrackPrivate* getAudioTrack() const;
    MediaStreamTrackPrivate* getVideoTrack() const;

    MediaPlayer::NetworkState m_networkState;

    RefPtr<MediaStreamPrivate> m_mediaStreamPrivate;
    Lock m_sampleMutex;
    GRefPtr<GstSample> m_sample;
    GRefPtr<GstElement> m_audioSource;
    GRefPtr<GstElement> m_videoSource;
};

}

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
