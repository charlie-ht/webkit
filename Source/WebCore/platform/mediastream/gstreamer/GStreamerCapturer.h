/*
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

#pragma once

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)

#include "GRefPtrGStreamer.h"

#include "LibWebRTCMacros.h"
#include "gstreamer/GStreamerCaptureDevice.h"

#include <gst/gst.h>

#pragma once

namespace WebCore {

class GStreamerCapturer {
public:
    GStreamerCapturer(GStreamerCaptureDevice device, GRefPtr<GstCaps> caps);
    GStreamerCapturer(const gchar * source_factory, GRefPtr<GstCaps> caps);
    virtual void setupPipeline();
    virtual void play();
    virtual void stop();
    GstCaps * getCaps();
    void addSink(GstElement *sink);
    GstElement * makeElement(const gchar *factory_name);
    GstElement * createSource();
    virtual const gchar* Name() = 0;

    GRefPtr<GstElement> m_src;
    GRefPtr<GstElement> m_sink;
    GRefPtr<GstElement> m_tee;
    GRefPtr<GstElement> m_capsfilter;
    GRefPtr<GstDevice> m_device;
    GRefPtr<GstCaps> m_caps;
    GRefPtr<GstElement> m_pipeline;
    const gchar * m_sourceFactory;
};

} // namespace WebCore
#endif //ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)

