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

#include "config.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
#include "GStreamerCapturer.h"

#include <gst/app/gstappsink.h>
#include <gst/app/gstappsrc.h>
#include <mutex>
#include <webrtc/api/mediastreaminterface.h>

GST_DEBUG_CATEGORY(webkit_capturer_debug);
#define GST_CAT_DEFAULT webkit_capturer_debug

namespace WebCore {

static void initializeGStreamerAndDebug()
{
    initializeGStreamer();

    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_capturer_debug, "webkitcapturer", 0, "WebKit Capturer");
    });
}

GStreamerCapturer::GStreamerCapturer(GStreamerCaptureDevice device, GRefPtr<GstCaps> caps)
    : m_device(adoptGRef(device.Device()))
    , m_caps(caps)
    , m_sourceFactory(nullptr)
{
    initializeGStreamerAndDebug();
}

GStreamerCapturer::GStreamerCapturer(const char* sourceFactory, GRefPtr<GstCaps> caps)
    : m_device(nullptr)
    , m_caps(caps)
    , m_sourceFactory(sourceFactory)
{
    initializeGStreamerAndDebug();
}

GstElement* GStreamerCapturer::createSource()
{
    if (m_sourceFactory) {
        m_src = makeElement(m_sourceFactory);
        if (GST_IS_APP_SRC(m_src.get()))
            g_object_set(m_src.get(), "is-live", true, "format", GST_FORMAT_TIME, nullptr);

        ASSERT(m_src);
        return m_src.get();
    }

    ASSERT(m_device);
    GUniquePtr<char> sourceName(g_strdup_printf("%s_%p", name(), this));
    m_src = gst_device_create_element(m_device.get(), sourceName.get());
    ASSERT(m_src);

    return m_src.get();
}

GstCaps* GStreamerCapturer::caps()
{
    if (m_sourceFactory) {
        auto element = adoptGRef(makeElement(m_sourceFactory));
        auto pad = adoptGRef(gst_element_get_static_pad(element.get(), "src"));

        return gst_pad_query_caps(pad.get(), nullptr);
    }

    ASSERT(m_device);
    return gst_device_get_caps(m_device.get());
}

void GStreamerCapturer::setupPipeline()
{
    connectSimpleBusMessageCallback(pipeline());
}

GstElement* GStreamerCapturer::makeElement(const char* factoryName)
{
    auto element = gst_element_factory_make(factoryName, nullptr);
    GUniquePtr<char> capturerName(g_strdup_printf("%s_capturer_%s_%p", name(), GST_OBJECT_NAME(element), this));
    gst_object_set_name(GST_OBJECT(element), capturerName.get());

    return element;
}

bool GStreamerCapturer::addSink(GstElement* newSink)
{
    g_return_val_if_fail(m_pipeline.get(), false);
    g_return_val_if_fail(m_tee.get(), false);

    auto queue = makeElement("queue");
    gst_bin_add_many(GST_BIN(m_pipeline.get()), queue, newSink, nullptr);
    gst_element_sync_state_with_parent(queue);
    gst_element_sync_state_with_parent(newSink);

    if (!gst_element_link(queue, newSink)) {
        GST_ERROR_OBJECT(m_pipeline.get(),
            "Could not link %" GST_PTR_FORMAT " and %" GST_PTR_FORMAT,
            queue, newSink);
        return false;
    }

    if (!gst_element_link_pads(m_tee.get(), "src_%u", queue, "sink")) {
        GST_ERROR_OBJECT(m_pipeline.get(),
            "Could not link %" GST_PTR_FORMAT " and %" GST_PTR_FORMAT,
            m_tee.get(), queue);
        return false;
    }

    if (newSink == m_sink.get()) {
        GST_INFO_OBJECT(m_pipeline.get(), "Setting queue as leaky upstream",
            " so that the player can set the sink to PAUSED without "
            " setting the whole capturer to PAUSED");
        g_object_set(queue, "leaky", 2 /* upstream */, nullptr);
    }

    GST_INFO_OBJECT(pipeline(), "Adding sink: %" GST_PTR_FORMAT, newSink);

    GUniquePtr<char> dumpName(g_strdup_printf("%s_sink_%s_added", GST_OBJECT_NAME(pipeline()), GST_OBJECT_NAME(newSink)));
    GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN(pipeline()), GST_DEBUG_GRAPH_SHOW_ALL, dumpName.get());

    return true;
}

void GStreamerCapturer::play()
{
    ASSERT(m_pipeline);

    gst_element_set_state(m_pipeline.get(), GST_STATE_PLAYING);
}

void GStreamerCapturer::stop()
{
    ASSERT(m_pipeline);

    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(pipeline())));
    gst_bus_set_sync_handler(bus.get(), nullptr, nullptr, nullptr);

    GST_INFO_OBJECT((gpointer) pipeline(), "Tearing down!");

    gst_element_set_state(pipeline(), GST_STATE_NULL);
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
