
/**
 * @file vssh_nalu.h
 * NAL Unit public API
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	Decoder
 */


#ifndef __VSSH_NALUNIT_H__
#define __VSSH_NALUNIT_H__

#include "evs_vssh_types.h"

#ifdef __cplusplus
extern "C" {
#endif


#define MAXSPS	 32
#define MAXPPS	256
#define MAX_VALUE_OF_CPB_CNT	32
#define TMP_MAX_NUM_REFS	33
#define MAX_NUM_SLICE_GROUPS	 8
#define MAX_NUM_REF_FRAMES_IN_PIC_ORDER_CNT_CYCLE  256

/// NALU (network abstraction layer unit) types
typedef enum
{
	NALU_TYPE_SLICE = 1,
	NALU_TYPE_DPA   = 2,
	NALU_TYPE_DPB   = 3,
	NALU_TYPE_DPC   = 4,
	NALU_TYPE_IDR   = 5,
	NALU_TYPE_SEI   = 6,
	NALU_TYPE_SPS   = 7,
	NALU_TYPE_PPS   = 8,
	NALU_TYPE_PD    = 9,
	NALU_TYPE_ESEQ  = 10,
	NALU_TYPE_ESTRM = 11,
	NALU_TYPE_FILL  = 12,
	/* 13...23 -> Reserved */
	/* 24...29 -> RFC-3984 */
	NALU_TYPE_STAP_A = 24,		// Single-time aggregation packet
	NALU_TYPE_STAP_B = 25,		// Single-time aggregation packet
	NALU_TYPE_MTAP16 = 26,		// Multi-time aggregation packet
	NALU_TYPE_MTAP24 = 27,		// Multi-time aggregation packet
	NALU_TYPE_FU_A   = 28,		// Fragmentation unit
	NALU_TYPE_FU_B   = 29		// Fragmentation unit
	/* 30...31 -> Unspecified */
} nalu_type_e;

/// NALU (network abstraction layer unit) structure
typedef struct nal_unit_t
{
	unsigned int len;	///< length of the NALU in bytes (excluding start code, which does not belong to the NALU)
	byte *buf;		///< points to the first byte of the EBSP (right after startcode)
	timestamp_t timestamp; ///< timestamp of this nal_unit
	int nal_unit_type;
} nal_unit_t;

/**
 * nal unit destructor function prototype
 * appropriate callback function must be set via decoder_settings
 * if decoder is opened in "external nals" mode
*/ 
typedef void release_nal_unit_t(nal_unit_t *nal_unit);  

/// macro to determine NAL unit type
#define NAL_UNIT_TYPE(nal_unit)     ((nal_unit)->buf[0]&0x1f)

/// macro to determine NAL unit reference idc
#define NAL_REFERENCE_IDC(nal_unit) (((nal_unit)->buf[0]>>5)&3)

/// macro to determine NAL unit reference idc
#define NAL_FORBIDDEN_ZERO(nal_unit) ((nal_unit)->buf[0]&0x80)

/// Slice header structure
typedef struct vssh_slice_header_t
{
	byte slice_type;
	byte field_pic_flag;
	byte bottom_field_flag;
	byte disable_deblocking_filter_idc;
	char slice_alpha_c0_offset;
	char slice_beta_offset;
	char qp;
	byte idr_flag;
	int  first_mb_in_slice;
	byte pic_parameter_set_id;
	byte redundant_pic_cnt;
	byte direct_spatial_mv_pred_flag;
	byte num_ref_pic_active_fwd;
	byte num_ref_pic_active_bwd;
	byte long_term_reference_flag;
	byte model_number;
	byte no_output_of_prior_pics_flag;
	byte adaptive_ref_pic_buffering_flag;
	byte ref_pic_list_reordering_flag[2];
	uword frame_num;
	uword idr_pic_id;
	uword pic_order_cnt_lsb;
	uword slice_group_change_cycle;
	int  delta_pic_order_cnt_bottom;
	int  delta_pic_order_cnt[2];
} vssh_slice_header_t;

/// HRD parameters
typedef struct vssh_hrd_parameters_t
{
	byte  cpb_cnt;
	byte  bit_rate_scale;
	byte  cpb_size_scale;
	unsigned  bit_rate_value[MAX_VALUE_OF_CPB_CNT];
	unsigned  cpb_size_value[MAX_VALUE_OF_CPB_CNT];
	unsigned  cbr_flag[MAX_VALUE_OF_CPB_CNT];
	unsigned  initial_cpb_removal_delay_length;
	unsigned  cpb_removal_delay_length;
	unsigned  dpb_output_delay_length;
	unsigned  time_offset_length;
} vssh_hrd_parameters_t;

/// VUI parameters
typedef struct vssh_vui_seq_parameters_t
{
	int       aspect_ratio_info_present_flag;
	unsigned  aspect_ratio_idc;
	unsigned  sar_width;
	unsigned  sar_height;

	int       overscan_info_present_flag;
	int       overscan_appropriate_flag;

	int       video_signal_type_present_flag;
	unsigned  video_format;
	int       video_full_range_flag;
	int       colour_description_present_flag;
	unsigned  colour_primaries;
	unsigned  transfer_characteristics;
	unsigned  matrix_coefficients;

	int       chroma_loc_info_present_flag;
	unsigned  chroma_sample_loc_type_top_field;
	unsigned  chroma_sample_loc_type_bottom_field;

	unsigned  timing_info_present_flag;
	unsigned  num_units_in_tick;
	unsigned  time_scale;
	int       fixed_frame_rate_flag;

	int       nal_hrd_parameters_present_flag;
	vssh_hrd_parameters_t nal_hrd_parameters;

	int       vcl_hrd_parameters_present_flag;
	vssh_hrd_parameters_t vcl_hrd_parameters;

	int       low_delay_hrd_flag;
	int       pic_struct_present_flag;

	int       bitstream_restriction_flag;
	int       motion_vectors_over_pic_boundaries_flag;
	unsigned  max_bytes_per_pic_denom;
	unsigned  max_bits_per_mb_denom;
	unsigned  log2_max_mv_length_vertical;
	unsigned  log2_max_mv_length_horizontal;
	unsigned  num_reorder_frames;
	unsigned  max_dec_frame_buffering;
} vssh_vui_seq_parameters_t;

/// Picture Parameter Set structure
typedef struct vssh_pps_t
{
	sword error_no;	  ///< indicates whether the parameter set is valid, 0 means OK;
	byte  pic_parameter_set_id;
	byte  seq_parameter_set_id;
	byte  entropy_coding_mode;
	byte  pic_order_present_flag;
	byte  num_slice_groups;
	byte  slice_group_map_type;
	byte  slice_group_change_direction_flag;
	char  pic_init_qp;
	char  pic_init_qs;
	char  chroma_qp_index_offset;
	byte  deblocking_filter_parameters_present_flag;
	byte  constrained_intra_pred_flag;
	byte  redundant_pic_cnt_present_flag;
	byte  weighted_pred_flag;
	byte  weighted_bipred_idc;
} vssh_pps_t;

/// Sequence Parameter Set structure
typedef struct vssh_sps_t
{
	sword error_no;		///< 0 indicates whether the parameter set is valid , 0 means OK;
	uword pic_width_in_mbs;
	uword frame_height_in_mbs;
	uword pic_height_in_map_units;

	byte profile_idc;
	byte level_idc;
	byte seq_parameter_set_id;
	byte log2_max_frame_num;

	byte pic_order_cnt_type;
	byte log2_max_pic_order_cnt_lsb;
	byte delta_pic_order_always_zero_flag;
	byte num_ref_frames_in_pic_order_cnt_cycle;

	byte num_ref_frames;
	byte gaps_in_frame_num_value_allowed_flag;
	byte frame_mbs_only_flag;
	byte mb_adaptive_frame_field_flag;

	byte direct_8x8_inference_flag;
	byte vui_parameters_present_flag;
	byte constrained_set0_flag;
	byte constrained_set1_flag;

	byte constrained_set2_flag;
	byte constrained_set3_flag;
	byte dpb_size; //decoded picture bufer size, calculated from profile, level and constrains
	byte frame_cropping_flag;

	uword frame_cropping_rect_left_offset;
	uword frame_cropping_rect_right_offset;
	uword frame_cropping_rect_top_offset;
	uword frame_cropping_rect_bottom_offset;
	
	int offset_for_non_ref_pic;
	int offset_for_top_to_bottom_field;

	byte chroma_format_idc;
	byte bit_depth_luma_minus8;
	byte bit_depth_chroma_minus8;
	byte qpprime_y_zero_transform_bypass_flag;

	byte seq_scaling_matrix_present_flag;

	int offset_for_ref_frame[255];

	byte seq_scaling_list_present_flag[8];
	byte scaling_list4x4[6][16];
	byte scaling_list8x8[2][64];
	byte use_default_scaling_matrix4x4_flag[6];
	byte use_default_scaling_matrix8x8_flag[2];

	vssh_vui_seq_parameters_t vui_info;	  ///< vui_seq_parameters_t
} vssh_sps_t;

/// input buffer for NALU parsing (forward declaration)
struct vssh_input_buffer_t;

/** @addtogroup func_list
* @{
*/

/** @name NALU parsing
*/
// @{
	
/**
 * Init input stream buffer
 * @param initial_size data buffer initial size
 * @return pointer to a structure created
 */
struct vssh_input_buffer_t * VSSHAPI vssh_input_buffer_create(int initial_size);

/**
 * Release stream buffer
 * @param input_buffer input stream structure
 * @return error code
 */
int VSSHAPI vssh_input_buffer_close(struct vssh_input_buffer_t *input_buffer);

/**
 * Put bytes into stream buffer
 * @param input_buffer input stream structure
 * @param data input bytes
 * @param size number of bytes
 * @param timestamp Timestamp of the data (or NO_TIME_STAMP value if no timestmap)
 * @return error code
 */
int VSSHAPI vssh_input_buffer_feed_data_ex(struct vssh_input_buffer_t *input_buffer, byte *data, int size, timestamp_t timestamp);

/**
 * The same as vssh_input_buffer_feed_data_ex(..., NO_TIME_STAMP)
 */
int VSSHAPI vssh_input_buffer_feed_data(struct vssh_input_buffer_t *input_buffer, byte *data, int size);


/**
 * Put bytes of one entire nal units into stream buffer
 * the data must not include startcodes
 * this function will flush the previously accumulated data
 * and copy all bytes into new internal nal units
 * @param input_buffer input stream structure
 * @param data input nal unit bytes
 * @param size number of bytes
 * @param timestamp Timestamp of the data (or NO_TIME_STAMP value if no timestmap)
 * @return error code
 */
int VSSHAPI vssh_input_buffer_feed_nal_unit_ex(struct vssh_input_buffer_t *input_buffer, byte *data, int size, timestamp_t timestamp);

/**
 * The same as vssh_input_buffer_feed_nal_unit(..., NO_TIME_STAMP)
 */
int VSSHAPI vssh_input_buffer_feed_nal_unit(struct vssh_input_buffer_t *input_buffer, byte *data, int size);

/**
 * Extract next NAL unit from the buffer (or NULL if nothing available)
 * This nal unit must be released by caller via vssh_input_buffer_release_nalu function
 * when it is done with it. 
 * @param input_buffer input stream structure
 * @return nal unit or NULL if nothing ready
 */
nal_unit_t * VSSHAPI vssh_input_buffer_get_nalu(struct vssh_input_buffer_t *input_buffer);

/**
 * Returns NAL unit into the buffer and make it first available
 * @param input_buffer input stream structure
 * @param nal_unit nal unit or NULL if nothing ready
 */
void vssh_input_buffer_return_nalu(struct vssh_input_buffer_t *input_buffer, nal_unit_t *nal_unit);

/**
 * Flush the input buffer forcing all incomplete NAL units go out on next call
 * to get_nalu()
 * @param input_buffer input stream structure
 * @return VSSH_OK
 */
int VSSHAPI vssh_input_buffer_flush(struct vssh_input_buffer_t *input_buffer);

// @}

/** @} */

release_nal_unit_t vssh_input_buffer_release_nalu;

#ifdef __cplusplus
}
#endif

#endif	// __VSSH_NALUNIT_H__
