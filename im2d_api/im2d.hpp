/*
 * Copyright (C) 2020 Rockchip Electronics Co., Ltd.
 * Authors:
 *  PutinLee <putin.lee@rock-chips.com>
 *  Cerf Yu <cerf.yu@rock-chips.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _im2d_hpp_
#define _im2d_hpp_

#include "im2d.h"
#include "RgaUtils.h"

#ifdef ANDROID

#include <ui/GraphicBuffer.h>

using namespace android;

IM_API rga_buffer_t wrapbuffer_GraphicBuffer_handle(buffer_handle_t hnd);
IM_API rga_buffer_t wrapbuffer_GraphicBuffer(sp<GraphicBuffer> buf);

#if USE_AHARDWAREBUFFER
#include <android/hardware_buffer.h>
IM_API rga_buffer_t wrapbuffer_AHardwareBuffer(AHardwareBuffer *buf);

#endif /* USE_AHARDWAREBUFFER */
#endif /* ANDROID */

/*
 * process
 *
 * @param src
 * @param dst
 * @param pat
 * @param srect
 * @param drect
 * @param prect
 * @param acquire_fence_fd
 * @param release_fence_fd
 * @param opt
 * @param usage
 *
 * @returns success or else negative error code.
 */
IM_API IM_STATUS improcess(rga_buffer_t src, rga_buffer_t dst, rga_buffer_t pat,
                           im_rect srect, im_rect drect, im_rect prect,
                           int acquire_fence_fd, int *release_fence_fd, im_opt_t *opt, int usage);

#endif /* _im2d_hpp_ */

