
/*
 * Copyright (C) 2018 Igalia S.L. All rights reserved.
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

#include "config.h"

#if ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)

#include "MediaStreamPrivate.h"
#include "MediaStreamTrackPrivate.h"

#include <gst/gst.h>

#define WEBKIT_MEDIA_STREAM_TAG_CAPTURING_WIDTH "webkit-media-stream-width"
#define WEBKIT_MEDIA_STREAM_TAG_CAPTURING_HEIGHT "webkit-media-stream-height"

namespace WebCore {

typedef struct _WebKitMediaStreamSrc WebKitMediaStreamSrc;

#define WEBKIT_MEDIA_STREAM_SRC(o) (G_TYPE_CHECK_INSTANCE_CAST((o), WEBKIT_TYPE_MEDIA_STREAM_SRC, WebKitMediaStreamSrc))
#define WEBKIT_IS_MEDIA_STREAM_SRC(o) (G_TYPE_CHECK_INSTANCE_TYPE((o), WEBKIT_TYPE_MEDIA_STREAM_SRC))
#define WEBKIT_TYPE_MEDIA_STREAM_SRC (webkit_media_stream_src_get_type())
GType webkit_media_stream_src_get_type(void) G_GNUC_CONST;
gboolean webkit_media_stream_src_set_stream(WebKitMediaStreamSrc* src, MediaStreamPrivate* stream);

#define WEBKIT_TYPE_MEDIA_STREAM (webkit_media_stream_get_type())
G_DECLARE_FINAL_TYPE(WebKitMediaStream, webkit_media_stream, WEBKIT, MEDIA_STREAM, GstStream);
FloatSize webkit_media_stream_get_size(WebKitMediaStream* self);
MediaStreamTrackPrivate* webkit_media_stream_get_media_stream_track(WebKitMediaStream* self);

} // WebCore

#endif // ENABLE(VIDEO) && ENABLE(MEDIA_STREAM) && USE(LIBWEBRTC)
