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

#include <wtf/glib/RunLoopSourcePriority.h>

#include "GStreamerCapturer.h"
#include <gst/app/gstappsink.h>
#include "GStreamerUtilities.h"
#include "GStreamerUtils.h"

#if ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)

GST_DEBUG_CATEGORY(webkit_capturer_debug);
#define GST_CAT_DEFAULT webkit_capturer_debug

namespace WebCore {

GStreamerCapturer::GStreamerCapturer(GStreamerCaptureDevice device,
    GRefPtr<GstCaps> caps)
    : m_device(device),
      m_caps(caps)
{
    static std::once_flag debugRegisteredFlag;
    std::call_once(debugRegisteredFlag, [] {
        GST_DEBUG_CATEGORY_INIT(webkit_capturer_debug, "webkitcapturer", 0, "WebKit Capturer");
    });
}

void GStreamerCapturer::setupPipeline()
{
    GStreamer::connectSimpleBusMessageCallback(m_pipeline.get());
}

GstElement * GStreamerCapturer::makeElement(const gchar *factory_name) {
    auto elem = gst_element_factory_make(factory_name, nullptr);
    gchar* name = g_strdup_printf("%s_capturer_%s_%p", Name(), GST_OBJECT_NAME (elem), this);
    gst_object_set_name (GST_OBJECT (elem), name);
    g_free(name);

    return elem;
}

void GStreamerCapturer::addSink(GstElement *sink)
{
    g_return_if_fail(m_pipeline.get());
    g_return_if_fail(m_tee.get());

    auto queue = makeElement("queue");
    gst_bin_add_many (GST_BIN (m_pipeline.get()), queue, sink, nullptr);
    gst_element_sync_state_with_parent (queue);
    gst_element_sync_state_with_parent (sink);
    gst_element_link_pads (m_tee.get(), "src_%u", queue, "sink");
    gst_element_link (queue, sink);

    GST_INFO_OBJECT(m_pipeline.get(), "Adding sink: %" GST_PTR_FORMAT, sink);
    gchar* dump_name;
    dump_name = g_strdup_printf("%s_sink_%s_added", GST_OBJECT_NAME(m_pipeline.get()),
        GST_OBJECT_NAME (sink));
    GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN (m_pipeline.get()), GST_DEBUG_GRAPH_SHOW_ALL,
        dump_name);
    g_free (dump_name);
}

void GStreamerCapturer::play() {
    g_assert(m_pipeline.get());

    GST_INFO_OBJECT ((gpointer) m_pipeline.get(), "Going to PLAYING!");

    gst_element_set_state (m_pipeline.get(), GST_STATE_PLAYING);
}

void GStreamerCapturer::stop() {
    g_assert(m_pipeline.get());

    GST_INFO_OBJECT ((gpointer) m_pipeline.get(), "Tearing down!");

    gst_element_set_state (m_pipeline.get(), GST_STATE_NULL);
}

} // namespace WebCore
#endif //ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC) && USE(GSTREAMER)
