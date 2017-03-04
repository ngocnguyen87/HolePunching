
/**
 * @file vssh_decoder.h
 * Exported decoder functions.
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	Decoder
 */

#ifndef __VSSH_DECODER_H__
#define __VSSH_DECODER_H__

#include "evs_vssh_types.h"
#include "evs_vssh_nalu.h"

/// decoder flags
typedef enum
{
	/**
	 * This flag allows to control decoder input buffer logic.
	 * value of "0" selects default behaviour when decoder uses own input buffer to hold and manipulate
	 * with input data.
	 * if this flag is set, decoder selects external input buffer mode, when application creates own input buffer
	 * and uses it for input data parsing to NAL units. Though these NAL units could be put into decoder for
	 * decoding as well. In this mode, application should call "vssh_dec_put_nalu()" to pass NAL unit to decoder,
	 * provide optional "release_nal_unit_callback" function. This mode allows for avoiding input data copying
	 * from application buffer to decoder internal buffer.
	 */
	DEC_EXTERN_BUFFER = 1,

	/**
	 * This flag controls how decoder will deal with pic_struct received by timing SEI.
	 * if this flag is 0 nothing is done.
	 * if this flag is 1 decoder interpret this parameter inside. I.e. make telecine and other actions.
	 */
	DEC_INTERP_PIC_STRUCT = 2,

	/**
	 * enable "postprocessing" deblocking when "inloop" deblocking is disabled
	 */
	DEC_POST_DEBLOCK = 4,

	/**
	 * enable full error concealment for lost data;
	 */
	DEC_FULL_ERR_CONC = 8,

	/**
	 * output bottom field first (effective only when DEC_INTERP_PIC_STRUCT is set);
	 */
	DEC_BOTTOM_FIELD_FIRST = 0x10,

	/**
	 * this flag enables in_slice multithreading
	 */
	DEC_USE_IN_SLICE_MT = 0x20,

	/**
	 * this flag adds decoding of the next slice in parallel with current slice where it possible
	 */
	DEC_USE_DEC_IN_ADVANCE = 0x40,

	/**
	 * this flag force decoder to trace SEI NAL units associated with each frame.
	 * see vssh_dec_get_frame_sei() function  
	 */
	DEC_ATTACH_SEI_TO_FRAME = 0x80,

	/**
	 * this flag force decoder to skip deblocking for nonreference pictures
	 * can be used for decoder speedup  
	 */
	DEC_SKIP_NON_REF_DEBLOCKING = 0x100,

	/**
	 * this flag force decoder to skip deblocking for reference pictures
	 * can be used for decoder speedup  
	 */
	DEC_SKIP_REF_DEBLOCKING = 0x200
} dec_flags_e;



#define VSS

/**
 * Advanced decoder settings.
 */
typedef struct vssh_decoder_settings_t
{
	unsigned int dec_flags; ///< bitwise combination of flags to control decoder behaviour (see flags values above)
	int typical_nal_size;	///< select typical NAL unit size in bytes, 0 means default value;
	release_nal_unit_t *release_nal_unit_callback; ///< must be set if input_mode is equal to "1";
	int mt_num_threads; ///< multi-threading control: 0=disable; N=number of working threads to run;
	int skip_non_ref_frames; ///< 0 - don't skip, 1 - skip 1 from sequence, 2 - skip 2 from sequence ...
} vssh_decoder_settings_t;

/** @defgroup func_list API Functions
*
* @{
*/

/**
 * starts decoder, allocates memory etc.
 * @return Handle to the decoder instance or NULL if error (out of memory).
 */
void * VSSHAPI evs_vssh_dec_open();

/**
 * Create decoder instance using given settings;
 * @return Handle to the decoder instance or NULL if error (out of memory).
 */
int VSSHAPI evs_vssh_dec_open_ex(void **phandle, vssh_decoder_settings_t *settings);

/**
 * Set output delay in frames (-1 means default behave)
 * Maximum value for delay is 16.
 * Sufficient output delay is calculated according to decoded pictures buffer (DPB)
 * size received form SPS and other stream data. If calculated delay is less,
 * then delay, set by this function, then calculated delay is used.
 * The call to this function with maximum delay value (16), will force decoder
 * to use calculated sufficient delay, required by the standard.
 * @return -1 if error, 0 if Ok.
 */
int VSSHAPI evs_vssh_dec_set_output_delay(void *phandle, int delay);

/**
 * Sends the data to the decoder.
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param data pointer to the input buffer
 * @param size number of input bytes, pass zero to signal end of stream.
 * @param is_nal_unit 0=bytestream, 1=complete NAL unit,
 *                    2=several complete NAL units separated by start-codes
 * @param timestamp Timestamp of the data (or NO_TIME_STAMP value if no timestmap)
 * @return -1 if error, 0 if Ok.
 */
int VSSHAPI evs_vssh_dec_feed_data_ex(void *handle, byte *data, int size, int is_nal_unit, timestamp_t timestamp);

/**
 * The same as vssh_dec_feed_data_ex(..., NO_TIME_STAMP)
 */
int VSSHAPI evs_vssh_dec_feed_data(void *handle, byte *data, int size, int is_nal_unit);

/**
 * Puts a NAL unit to the decoder input queue
 * @param nal_unit pointer to the NAL unit structure
 * @param handle decoder instance handle
 * @return error code
 */
int VSSHAPI evs_vssh_dec_put_nalu(void *handle, nal_unit_t *nal_unit);

/**
 * Enable/disable flush on decoder output
 * When the flag is enabled, decoder will output all the frames without waiting for display order;
 * @note decoder input should be flushed separately - call vssh_dec_feed_data(handle,0,0,0);
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param flag pass "1" to signal decoder to start flush, pass "0" to stop it;
 * @return error code
 */
int VSSHAPI evs_vssh_dec_flush(void *handle, int flag);

/**
 * Decode given SPS NAL unit, return it's values;
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param nal_unit structure holding SPS NAL unit payload bytes;
 * @param sps_info structure to receive decoded SPS information;
 * @return error code
 */
int VSSHAPI evs_vssh_decode_sps(void *handle, nal_unit_t *nal_unit, sps_info_t *sps_info);

/**
 * Decode given PPS NAL unit, return it's values;
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param nal_unit structure holding PPS NAL unit payload bytes;
 * @param pps_info structure to receive decoded PPS information;
 * @return error code
 */
int VSSHAPI evs_vssh_decode_pps(void *handle, nal_unit_t *nal_unit, pps_info_t *pps_info);

typedef void sei_callback_t(void *ctx, int payload_type, int payload_size, void *info);

/**
 * Decode given SEI NAL unit, return it's values;
 * @param handle - handle of the decoder instance (returned by vssh_dec_open)
 * @param nal_unit - structure holding SEI NAL unit payload bytes;
 * @param ctx - user context for callback identification;
 * @param func - sei callback function of type "sei_callback_t" to be called while decoding;
 * @return error code
 */
int VSSHAPI evs_vssh_decode_sei(void *handle, nal_unit_t *nal_unit, void *ctx, sei_callback_t *func);

/**
 * Decode given Slice NAL unit header, return slice header values;
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param nal_unit structure holding slice NAL unit payload bytes;
 * @param slice_hdr structure to receive decoded slice header information;
 * @return error code
 */
int VSSHAPI evs_vssh_decode_slice_hdr(void *handle, nal_unit_t *nal_unit, vssh_slice_header_t *slice_hdr);

/**
 * Decodes one frame. Puts YUV pointers and other info to yuv frame structure.
 * Note: YUV pointers will be actual till next subsequent call to this function.
 * @param handle Handle of the decoder instance (returned by vssh_dec_open);
 * @param frame buffer to receive output frame pointers;
 * @return number of decoded frames: -1=error, 1=OK, 0=no more frames available;
 */
int VSSHAPI evs_vssh_dec_decode_frame(void *handle, yuv_frame_t *frame);

/**
 * Returns pointer to the SEI NAL unit, associated with the last frame
 * returned by last call to vssh_dec_decode_frame() function.
 * As there can be several SEIs associated with one frame sei_index
 * parameter is used to indicate index in decoding order.
 * This function will work only if decoder instance was created with 
 * DEC_ATTACH_SEI_TO_FRAME bit of settings->dec_flags set to 1.
 * @param handle Handle of the decoder instance (returned by vssh_dec_open);
 * @param sei_index index of sei in decoding order
 * @return nal_unit, containing SEI or NULL if no SEI with such index;
 */
nal_unit_t * VSSHAPI evs_vssh_dec_get_frame_sei(void *handle, int sei_index);

/**
 * Returns the pointer to the active SPS
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @return pointer to the active SPS or NULL if no active SPS decoded
 */
vssh_sps_t * VSSHAPI evs_vssh_dec_get_sps(void *handle);


/**
 * Obtain active SPS. Note: SPS nal must be already decoded.
 * @param handle Handle of the decoder instance (returned by vssh_dec_open)
 * @param sps_info pointer to the structure to receive information about active SPS;
 * @return -1 = error, 0 = OK;
 */
int VSSHAPI evs_vssh_dec_get_sps_info(void *handle, sps_info_t *sps_info);

/**
 * Closes given decoder instance, flashes output buffer, releases memory etc.
 * @param handle - active decoder instance (returned by vssh_dec_open);
 * @return -1 = error, 0 = OK;
 */
int VSSHAPI evs_vssh_dec_close(void *handle);

/** @} */


#endif	// __VSSH_DECODER_H__
