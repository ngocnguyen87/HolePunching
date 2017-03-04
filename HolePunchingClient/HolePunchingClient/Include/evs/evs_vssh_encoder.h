
/**
 * @file vssh_encoder.h
 * Exported encoder functions.
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	Encoder
 */

#ifndef __VSSH_ENCODER_H__
#define __VSSH_ENCODER_H__

#include "evs_vssh_types.h"
#include "evs_vssh_settings.h"


/** @addtogroup defs_err_codes */
// @{

/**
 * Compatibility number to be written to the output stream on the SYSTEMS level.
 * High level decoder must analyze the number from compressed stream
 * to determine whether it is supported/compatible.
 */
#define VSSH_ENC_MAGIC_NUMBER 20050910
// @}

/** @defgroup enc_func Encoder Functions
*
* @{
*/

/**
 * Create a new encoder instance.
 * @param phandle  - pointer to a variable which will receive encoder handle
 *		in case of success, can not be NULL;
 * @param settings - pointer to the vssh_encoder_settings_t structure
 *	containing initial encoder parameters to be used during this encoding session.
 *	Note: can not be NULL.
 *	Note: framerate should be assigned via "gop_settings" member;
 * @return VSSH_OK=success,
 *	VSSH_ERR_ARG=invalid arg (NULL),
 *	VSSH_ERR_SETTINGS=incorrect settings,
 *	VSSH_ERR_MEMORY=out of memory;
 *	VSSH_WARN_LEVEL_LIMITS=settings do not fit into profile/level limitations;
 */
int VSSHAPI evs_vssh_enc_open(void **phandle, vssh_encoder_settings_t *settings);

/**
 * Retrieve encoded Sequence Parameter Set (SPS) NAL unit.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param spps_data - structure to be filled in with SPS_ID and output buffer
 *		specification;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_get_sps(void *handle, vssh_spps_data_t *spps_data);

/**
 * Retrieve encoded Picture Parameter Set (PPS) NAL unit.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param spps_data - structure to be filled in with PPS_ID and output buffer
 *		specification;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_get_pps(void *handle, vssh_spps_data_t *spps_data);

/**
 * Obtain active encoder settings into local structure.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param settings - address of a destination settings buffer;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_get_settings(void *handle, vssh_encoder_settings_t *settings);

/**
 * Reset rate control settings on-the-fly (@see rate_control_settings_t).
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param settings - provide new rate control values here;
 *	Note: assign new value if you need to change it or pass "-1" to use previous value;
 *	Note: "qp_modulation" and "pass" fields could not be changed anyway;
 * 	Note: this call leads to subsequent I-frame insertion and full rc reset;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_change_rc_settings(void *handle, rate_control_settings_t *settings);

/**
 * Change bitrate "on-the-fly", could be called very frequently.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param kbps - new bitrate value, kbps;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_change_bitrate(void *handle, int kbps);

/**
 * Change high compression mode (HCM) flags on-the-fly.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param hcm - provide new HCM flag value here;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_change_hcm(void *handle, int hcm);

/**
 * Return status of internal input queue.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param queue_max - variable to receive maximum input queue length;
 * @param queue_len - variable to receive current input queue length;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_get_queue(void *handle, int *queue_max, int *queue_len);

/**
 * Return status of encoder.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param has_data - variable to receive result: 
 *	0=encoder does not have any buffered data, either input nor output;
 *	N=encoder does have buffered data which is under processing;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_has_data(void *handle, int *has_data);

/**
 * Waits for a next portion of encoder output in MT mode, returns immediately in ST mode;
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param timeout_ms - wait timeout, ms;
 * @return VSSH_OK, VSSH_WARN_TIMEOUT;
 */
int VSSHAPI evs_vssh_enc_wait_output(void *handle, int timeout_ms);

/**
 * Provide next uncompressed YUV frame for encoding.
 * @param handle - handle of the encoder instance (returned by vssh_enc_open);
 * @param frame  - uncompressed YUV frame data, pass NULL to force all encoded slices go to output;
 * @param modifier - settings to be altered for given frame. Pass NULL to use defaults.
 * Specify (-1) for fields you do not want to change.
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_set_frame(void *handle, yuv_frame_t *frame, frame_modifier_t *modifier);

/**
 * Attach custom SEI data to the input frame before calling to "vssh_enc_set_frame()";
 * @param frame_info - frame info structure to attach SEI message to;
 * @param sei_id - SEI identifier, @see "vssh_types.h"::sei_type_e;
 * @param sei_data - pointer to appropriate data structure, could be freed just after the call;
 * @param sei_size - size of data structure, bytes;
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_attach_sei(frame_info_t *frame_info, int sei_id, void *sei_data, int sei_size);

/**
 * Sets "alloc_by_caller" flag.
 * @param handle - handle of the encoder instance (returned by vssh_enc_open);
 * @param flag  - uncompressed YUV frame data;
 * @return VSSH_OK or error code;
 */
void VSSHAPI evs_vssh_enc_set_alloc_by_caller(void *handle, int flag);

/**
 * Retrieve next free YUV frame buffer.
 * Application must call this function to receive yuv_frame_t instances.
 * @param handle - handle of the encoder instance (returned by vssh_enc_open);
 * @return yuv_frame_t if OK or NULL if error.
 *	On OK application must fill this frame with raw video data and return it
 * back to encoder via call to vssh_enc_set_frame().
 * Reconstructed frame YUV 4:2:0 data will be placed here after encoding.
 */
yuv_frame_t * VSSHAPI evs_vssh_enc_get_free_frame(void *handle);

/**
 * Retrieve next available encoded slice.
 * Make call vssh_enc_set_frame(handle, NULL, NULL) to force all encoded slices
 * be marked as available and thus go to output.
 * @param handle  - handle of the encoder instance (returned by vssh_enc_open);
 * @param slice_data - structure where encoder will put size and data pointer.
 *	Examine "slice_data.frame_info" field for detailed information about
 *	the slice just received. The data will be valid until next call to vssh_enc_get_slice().
 * @return VSSH_OK=slice encoded OK,
 *	VSSH_ERR_MORE_DATA=application must provide more input data (next frame);
 *	VSSH_ERR_SKIP_FRAME=CBR rate control decided to skip this frame;
 */
int VSSHAPI evs_vssh_enc_get_slice(void *handle, vssh_slice_data_t *slice_data);

/**
 * Close encoder, release memory etc.
 * @param handle - handle of the encoder instance (returned by vssh_enc_open);
 * @return VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_close(void *handle);

/**
 * Parse encoder settings from given string;
 * @param settings - structure to receive configuration values;
 * @param cmd_line - aray of config strings to parse;
 * @return VSSH_OK=OK;
 */
int VSSHAPI evs_vssh_enc_parse_settings(vssh_encoder_settings_t *settings, char **cmd_line);

/**
 * Fills encoder settings with default values (Normal mode - compromise between quality and speed).
 * @param settings - pointer to vssh_encoder_settings_t structure which will
 *	receive default values.
 * @return void
 */
void VSSHAPI evs_vssh_enc_default_settings(vssh_encoder_settings_t *settings);

/**
 * Provides maximum speed encoder settings.
 * @param settings - pointer to vssh_encoder_settings_t structure which will
 *	receive new values.
 * @return void
 */
void VSSHAPI evs_vssh_enc_maxspeed_settings(vssh_encoder_settings_t *settings);

/**
 * Provides maximum quality encoder settings.
 * @param settings - pointer to vssh_encoder_settings_t structure which will
 *	receive new values.
 * @return void
 */
void VSSHAPI evs_vssh_enc_maxquality_settings(vssh_encoder_settings_t *settings);

/**
 * Get last encoded frame info.
 * @param handle - Handle of the encoder instance (returned by vssh_enc_open)
 * @param info - pointer to structure to receive frame information;
 * @returns VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_get_frame_info(void *handle, frame_info_t *info);

/**
 * Resets on-the-fly the encoder error resillience settings according
 * to the new value of the expected loss rate.
 * @param handle - Handle of the encoder instance (returned by vssh_enc_open)
 * @param new_expected_loss_percents - new value (%, [0..100]) of the expected losses;
 */
void VSSHAPI evs_vssh_enc_set_current_loss_percents(void *handle, int new_expected_loss_percents);


/** @} */

typedef struct
{
	short x,y;	// vector value;
	int SAD;	// calculated weight coefficient = SAD + vector cost;
} mv_t;

/** @addtogroup enc_func
* @{
*/

/**
 * Set externally calculated motion vectors for given subdivision map;
 * @param handle - Handle of the encoder instance (returned by vssh_enc_open)
 * @param subdiv - subdivision constant which determines map we are providing motion vectors for;
 * @param mvs    - array of motion vectors, it's size depends on the given subdivision;
 * @par Usage:
 * @code
 *	int mw = picture_width  / 16;
 *	int mh = picture_height / 16;
 *	mv_t *mvs = (mv_t*) malloc(mw*mh*sizeof(mv_t));
 *	vssh_enc_set_mvs(enc_handle, SD_MODE_16X16, mvs);
 * @endcode
 * @returns VSSH_OK or error code;
 */
int VSSHAPI evs_vssh_enc_set_mvs(void *handle, subdiv_modes_e subdiv, mv_t *mvs);

/**
 * Encodes all slices of the current frame separating them by START CODE (0,0,0,1).
 * I-frame will contain also SPS & PPS NAL units.
 * Output buffer must be large enough to receive encoded bits;
 * @param handle - Handle of the encoder instance (returned by vssh_enc_open)
 * @param frame_data - all input/output params for this frame;
 * @param num_in_chunk - Number of coded frames already accumulated in current (AVI) chunk, use
 *	it to prevent storing different P-frames inside one chunk;
 * @return VSSH_OK=slice encoded OK,
 *	VSSH_ERR_MORE_DATA=application must provide more input data (next frame);
 *	VSSH_ERR_SKIP_FRAME=CBR rate control decided to skip this frame;
 */
int VSSHAPI evs_vssh_enc_encode_frame(void *handle, vssh_slice_data_t *frame_data, int num_in_chunk);

/**
 * Encodes one RFC-3984 packet.
 * Buffer memory (packet_data->slice_data) must be allocated by caller
 * packet_data->slice_size must be set to allocated buffer size.
 * Encoder will copy payload bytes to this buffer.
 * Encoder is expected to either aggregate or fragment slices to fit in the "payload_size".
 * On return encoder will put actual size into "actual_size" argument.
 * @param handle - Handle of the encoder instance (returned by vssh_enc_open)
 * @param packet_data - defines memory buffer to receive packet bytes;
 * @param packet_mode - 0=Single-NAL, 1=Non-Interleaved, 2=Interleaved;
 * @param payload_size - required size of packets;
 * @param pactual_size - variable to receive actual encoded packet size;
 * @return VSSH_OK=slice encoded OK,
 *	VSSH_ERR_MORE_DATA=application must provide more input data (next frame);
 *	VSSH_ERR_SKIP_FRAME=CBR rate control decided to skip this frame;
 */
int VSSHAPI evs_vssh_enc_encode_packet(void *handle, vssh_slice_data_t *packet_data, int packet_mode, int payload_size, int *pactual_size);

/** @name PSNR functions
 * Functions providing access to PSNR values (Peak signal to noise ratio between original and
 *	reconstructed image pixels). Note: PSNR values remain zero in MT (multithreading) builds.
 */

// @{

/**
 * Retrieve average PSNR values collected during encoder session.
 */
void VSSHAPI evs_vssh_enc_get_average_rec_psnr(void *handle,
	double *res_psnr_y, double *res_psnr_u, double *res_psnr_v);
/**
 * Retrieve current frame PSNR values.
 */
void VSSHAPI evs_vssh_enc_get_curr_frame_rec_psnr(void *handle,
	double *res_psnr_y, double *res_psnr_u, double *res_psnr_v);
/**
 * Calculate PSNR values between given frames.
 */
void VSSHAPI evs_calc_snr(yuv_frame_t *frame0, yuv_frame_t *frame1,
	double *res_snr_y, double *res_snr_u, double *res_snr_v);
/**
 * Retrieve current field PSNR values.
 */
void VSSHAPI evs_vssh_enc_get_curr_field_rec_psnr(void *handle, int field_no,
	double *res_psnr_y, double *res_psnr_u, double *res_psnr_v);
// @}

/** @} */


#endif	//__VSSH_ENCODER_H__
