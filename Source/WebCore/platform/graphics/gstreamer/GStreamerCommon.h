/*
 *  Copyright (C) 2012, 2015, 2016 Igalia S.L
 *  Copyright (C) 2015, 2016 Metrological Group B.V.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once

#if USE(GSTREAMER)
#include "FloatSize.h"
#include "GRefPtrGStreamer.h"
#include "GUniquePtrGStreamer.h"
#include <gst/gst.h>
#include <gst/video/video-format.h>
#include <gst/video/video-info.h>
#include <wtf/MediaTime.h>

#if USE(LIBWEBRTC)
#include <gst/video/video.h>

#include "GRefPtrGStreamer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/common_video/include/video_frame_buffer.h"
#include "webrtc/api/video/video_frame.h"
#include "webrtc/api/video/i420_buffer.h"
#include "webrtc/common_video/include/video_frame_buffer.h"

#include "LibWebRTCMacros.h"
#include <webrtc/common_video/include/i420_buffer_pool.h>
#endif

namespace WebCore {

class IntSize;

inline bool webkitGstCheckVersion(guint major, guint minor, guint micro)
{
    guint currentMajor, currentMinor, currentMicro, currentNano;
    gst_version(&currentMajor, &currentMinor, &currentMicro, &currentNano);

    if (currentMajor < major)
        return false;
    if (currentMajor > major)
        return true;

    if (currentMinor < minor)
        return false;
    if (currentMinor > minor)
        return true;

    if (currentMicro < micro)
        return false;

    return true;
}

#define GST_VIDEO_CAPS_TYPE_PREFIX  "video/"
#define GST_AUDIO_CAPS_TYPE_PREFIX  "audio/"
#define GST_TEXT_CAPS_TYPE_PREFIX   "text/"

GstPad* webkitGstGhostPadFromStaticTemplate(GstStaticPadTemplate*, const gchar* name, GstPad* target);
#if ENABLE(VIDEO)
bool getVideoSizeAndFormatFromCaps(GstCaps*, WebCore::IntSize&, GstVideoFormat&, int& pixelAspectRatioNumerator, int& pixelAspectRatioDenominator, int& stride);
std::optional<FloatSize> getVideoResolutionFromCaps(const GstCaps*);
bool getSampleVideoInfo(GstSample*, GstVideoInfo&);
#endif
GstBuffer* createGstBuffer(GstBuffer*);
GstBuffer* createGstBufferForData(const char* data, int length);
char* getGstBufferDataPointer(GstBuffer*);
const char* capsMediaType(const GstCaps*);
bool doCapsHaveType(const GstCaps*, const char*);
bool areEncryptedCaps(const GstCaps*);
void mapGstBuffer(GstBuffer*, uint32_t);
void unmapGstBuffer(GstBuffer*);
Vector<String> extractGStreamerOptionsFromCommandLine();
bool initializeGStreamer(std::optional<Vector<String>>&& = std::nullopt);
unsigned getGstPlayFlag(const char* nick);
uint64_t toGstUnsigned64Time(const MediaTime&);

inline GstClockTime toGstClockTime(const MediaTime &mediaTime)
{
    return static_cast<GstClockTime>(toGstUnsigned64Time(mediaTime));
}

bool gstRegistryHasElementForMediaType(GList* elementFactories, const char* capsString);
void connectSimpleBusMessageCallback(GstElement *pipeline);
void disconnectSimpleBusMessageCallback(GstElement *pipeline);

#if USE(LIBWEBRTC)

GstSample * GStreamerSampleFromVideoFrame(const webrtc::VideoFrame& frame);
webrtc::VideoFrame *GStreamerVideoFrameFromBuffer(GstSample *sample, webrtc::VideoRotation rotation);

class GStreamerVideoFrame : public webrtc::VideoFrameBuffer {
public:
    GStreamerVideoFrame(GstSample * sample, GstVideoInfo info)
        : m_sample(adoptGRef(sample))
        , m_info(info) {
    }

    static GStreamerVideoFrame * Create(GstSample * sample) {
        GstVideoInfo info;

        g_assert (gst_video_info_from_caps (&info, gst_sample_get_caps (sample)));

        return new GStreamerVideoFrame (sample, info);
    }

    GstSample *GetSample();
    rtc::scoped_refptr<webrtc::I420BufferInterface> ToI420() final;

    // Reference count; implementation copied from rtc::RefCountedObject.
    // FIXME- Should we rely on GStreamer Buffer refcounting here?!
    void AddRef() const override {
        rtc::AtomicOps::Increment(&ref_count_);
    }

    rtc::RefCountReleaseStatus Release() const {
        int count = rtc::AtomicOps::Decrement(&ref_count_);
        if (!count) {
            delete this;

            return rtc::RefCountReleaseStatus::kDroppedLastRef;
        }

        return rtc::RefCountReleaseStatus::kOtherRefsRemained;
    }

    int width() const override { return GST_VIDEO_INFO_WIDTH (&m_info); }
    int height() const override { return GST_VIDEO_INFO_HEIGHT (&m_info); }

private:
    webrtc::VideoFrameBuffer::Type type() const override;
    mutable volatile int ref_count_ = 0;
    GRefPtr<GstSample> m_sample;
    GstVideoInfo m_info;
    webrtc::I420BufferPool m_bufferPool;
};
#endif // USE(LIBWEBRTC)

}

#ifndef GST_BUFFER_DTS_OR_PTS
#define GST_BUFFER_DTS_OR_PTS(buffer) (GST_BUFFER_DTS_IS_VALID(buffer) ? GST_BUFFER_DTS(buffer) : GST_BUFFER_PTS(buffer))
#endif
#endif // USE(GSTREAMER)
