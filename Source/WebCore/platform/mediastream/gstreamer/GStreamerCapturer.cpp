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

#include "GStreamerUtilities.h"

#include <gst/app/gstappsink.h>
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
        g_assert(m_src);

        return m_src.get();
    }

    char* sourceName = g_strdup_printf("%s_%p", name(), this);
    m_src = gst_device_create_element(m_device.get(), sourceName);
    g_free(sourceName);

    return m_src.get();
}

GstCaps* GStreamerCapturer::getCaps()
{
    if (m_sourceFactory) {
        auto element = adoptGRef((GstElement*) gst_object_ref_sink(makeElement(m_sourceFactory)));
        auto pad = adoptGRef(gst_element_get_static_pad(element.get(), "src"));

        return gst_pad_query_caps (pad.get(), nullptr);
    }

    return gst_device_get_caps (m_device.get());
}

void GStreamerCapturer::setupPipeline()
{
    connectSimpleBusMessageCallback(m_pipeline.get());
}

GstElement* GStreamerCapturer::makeElement(const char* factoryName)
{
    auto element = gst_element_factory_make(factoryName, nullptr);
    char* capturerName = g_strdup_printf("%s_capturer_%s_%p", name(), GST_OBJECT_NAME(element), this);
    gst_object_set_name(GST_OBJECT(element), capturerName);
    g_free(capturerName);

    return element;
}

void GStreamerCapturer::addSink(GstElement *sink)
{
    g_return_if_fail(m_pipeline.get());
    g_return_if_fail(m_tee.get());

    auto queue = makeElement("queue");
    gst_bin_add_many(GST_BIN(m_pipeline.get()), queue, sink, nullptr);
    gst_element_sync_state_with_parent(queue);
    gst_element_sync_state_with_parent(sink);
    g_assert(gst_element_link_pads(m_tee.get(), "src_%u", queue, "sink"));
    g_assert(gst_element_link(queue, sink));

    if (sink == m_sink.get()) {
        GST_INFO_OBJECT(m_pipeline.get(), "Setting queue as leaky upstream",
            " so that the player can set the sink as to PAUSED without "
            " setting the whole capturer to PAUSED");
        g_object_set(queue, "leaky", 2 /* upstream */, nullptr);
    }

    GST_INFO_OBJECT(m_pipeline.get(), "Adding sink: %" GST_PTR_FORMAT, sink);

    char* dumpName;
    dumpName = g_strdup_printf("%s_sink_%s_added", GST_OBJECT_NAME(m_pipeline.get()), GST_OBJECT_NAME(sink));
    GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN(m_pipeline.get()), GST_DEBUG_GRAPH_SHOW_ALL, dumpName);
    g_free(dumpName);
}

void GStreamerCapturer::play()
{
    g_assert(m_pipeline.get());

    GST_ERROR_OBJECT((gpointer) m_pipeline.get(), "Going to PLAYING!");

    gst_element_set_state(m_pipeline.get(), GST_STATE_PLAYING);
    GstState state;
    GST_ERROR_OBJECT((gpointer) m_pipeline.get(), "STATE: %s", gst_element_state_get_name(state));
    GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN(m_pipeline.get()), GST_DEBUG_GRAPH_SHOW_ALL, gst_element_state_get_name(state));
}

void GStreamerCapturer::stop()
{
    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(m_pipeline.get())));
    gst_bus_set_sync_handler(bus.get(), nullptr, nullptr, nullptr);
    g_assert(m_pipeline.get());

    GST_INFO_OBJECT((gpointer) m_pipeline.get(), "Tearing down!");

    gst_element_set_state(m_pipeline.get(), GST_STATE_NULL);
}

} // namespace WebCore

#endif // ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
