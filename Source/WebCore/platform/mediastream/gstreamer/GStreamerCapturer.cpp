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

static void busMessageCallback(GstBus*, GstMessage* message, GstBin *pipeline)
{
    switch (GST_MESSAGE_TYPE(message)) {
    case GST_MESSAGE_ERROR:
        GST_ERROR_OBJECT (pipeline, "Got: %" GST_PTR_FORMAT, message);

        GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS (pipeline, GST_DEBUG_GRAPH_SHOW_ALL,
            "error");
        break;
    case GST_MESSAGE_STATE_CHANGED:
        if (GST_MESSAGE_SRC(message) == GST_OBJECT(pipeline)) {
            GstState oldstate, newstate, pending;
            gchar* dump_name;

            gst_message_parse_state_changed(message, &oldstate, &newstate,
                &pending);

            GST_INFO_OBJECT (pipeline, "State changed (old: %s, new: %s, pending: %s)",
                gst_element_state_get_name(oldstate),
                gst_element_state_get_name(newstate),
                gst_element_state_get_name(pending));

            dump_name = g_strdup_printf("%s_%s_%s",
                GST_OBJECT_NAME(pipeline),
                gst_element_state_get_name(oldstate),
                gst_element_state_get_name(newstate));

            GST_DEBUG_BIN_TO_DOT_FILE_WITH_TS(GST_BIN(pipeline),
                GST_DEBUG_GRAPH_SHOW_ALL, dump_name);

            g_free(dump_name);
        }
        break;
    default:
        break;
    }

}

void GStreamerCapturer::setupPipeline()
{
    GRefPtr<GstBus> bus = adoptGRef(gst_pipeline_get_bus(GST_PIPELINE(m_pipeline.get())));
    gst_bus_add_signal_watch_full(bus.get(), RunLoopSourcePriority::RunLoopDispatcher);
    g_signal_connect(bus.get(), "message", G_CALLBACK(busMessageCallback), this->m_pipeline.get());
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
