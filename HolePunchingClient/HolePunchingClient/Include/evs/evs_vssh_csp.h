
/**
 * @file vssh_csp.h
 * Colorspace conversion library
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	colorspace conversion
 */

#ifndef __COLORSPACE_H__
#define __COLORSPACE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "evs_vssh_types.h"

/** @addtogroup defs_err_codes */
// @{

typedef enum
{
	COLORSPACE_RGB555,		///< RGB555
	COLORSPACE_RGB565,		///< RGB565
	COLORSPACE_RGB24,		///< RGB 24 bit
	COLORSPACE_RGB32,		///< RGB 24 bit + alpha channel
	COLORSPACE_YV12,		///< YUV 4:2:0 planar (U&V swapped);
	COLORSPACE_YUY2,		///< YUV 4:2:2 channel
	COLORSPACE_YUYV,		///< YUV 4:2:2 channel
	COLORSPACE_YVYU,		///< YUV 4:2:2 channel
	COLORSPACE_UYVY,		///< YUV 4:2:2 channel
	COLORSPACE_I420,		///< YUV 4:2:0 planar = out internal YUV format;
	COLORSPACE_IYUV,		///< YUV 4:2:0 planar = the same as I420
	COLORSPACE_UNKNOWN
} colorspace_e;

// @}

/// structure holding external image and it's characteristics
typedef struct
{
	colorspace_e colorspace;	///< colorspace format specification;
	int width;		///< width of the picture in pixels;
	int height;		///< height of the picture in pixels, negative value allowed;
	int stride;		///< width of the buffer in bytes (typically aligned by 4 bytes);
	int bit_count;		///< bits per pixel
	int image_size;	///< number of bytes allocated for image buffer
	byte *image;			///< pointer to image buffer;
} rgb_frame_t;

/** @addtogroup func_list
*
* @{
*/

/**
 * Converts external colorspace to codec internal (YUV 4:2:0)
 * Note: RGB picture always flipped upside down.
 * @param rgb_frame - source image to be converted;
 * @param yuv_frame - destination YUV frame, must be allocated by caller;
 * @return 0=OK, -1=unsupported mode;
 */
int VSSHAPI vssh_colorspace_rgb2yuv(
	rgb_frame_t *rgb_frame,
	yuv_frame_t *yuv_frame
);

/**
 * Converts codec internal (YUV 4:2:0) frame to external colorspace format.
 * Note: YUV picture flipped upside down for positive RGB height, not flipped for negative.
 * @param yuv_frame - source YUV frame;
 * @param rgb_frame - destination image buffer;
 *	pass "rgb_frame.image_size = 0" to query actual image size (width, height,
 *	colorspace fields must be filled in;
 * @return 0=OK, -1=unsupported mode, 1=image size query OK;
 */
int VSSHAPI vssh_colorspace_yuv2rgb(
	yuv_frame_t *yuv_frame,
	rgb_frame_t *rgb_frame
);

/** @} */

#ifdef __cplusplus
}
#endif

#endif	//__COLORSPACE_H__
