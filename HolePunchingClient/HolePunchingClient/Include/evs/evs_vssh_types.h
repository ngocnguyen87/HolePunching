
/**
 * @file vssh_types.h
 * Types definitions used in all other code.
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	Decoder and Encoder
 */


#ifndef __VSSH_TYPES_H__
#define __VSSH_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
#define VSSHAPI __cdecl
#else
#define VSSHAPI
#endif

// structure member alignment is 8 bytes
#pragma pack(push, vssh_types, 8)

/** @name API Version info
* @{
*/
#define VSSH_API_VERSION_MAGIC		20061215
#define VSSH_API_VERSION_MAJOR		3
#define VSSH_API_VERSION_MINOR		1
#define VSSH_API_VERSION_BUILD		0
/** @} */

// API Version info
/**
 * Obtain library version info (major.minor.rev.build, i.e. 2.2.3.2);
 * @param magic pointer to a variable to receive magic API number;
 * @param major pointer to a variable to receive major version number;
 * @param minor pointer to a variable to receive minor version number;
 * @param rev   pointer to a variable to receive revision number;
 * @param build pointer to a variable to receive build number;
 * @return VSSH_OK
 */
int VSSHAPI vssh_get_version(int *magic, int *major, int *minor, int *rev, int *build);

/// VSS H.264 Codec library demo limitations
typedef struct vssh_demo_limits_t
{
	int enabled;	///< demo limitations enabled? (0/1);
	int max_frames;	///< maximum frames processed in one session;
	int watermark;	///< watermark enabled? (0/1);
	int expire_enabled;	///< expiration enabled? (0/1);
	int expire_year;	///< expiration year, 4 digits;
	int expire_month;	///< expiration month [1..12];
	int expire_mday;	///< expiration day of month [1..31];
} vssh_demo_limits_t;

/// VSS H.264 Codec library capabilities info
typedef struct vssh_caps_info_t
{
	int size;	///< this structure size, bytes;
	int profile;	///< number of maximum H.264 profile allowed;
	int width;	///< maximum image width allowed, pixels;
	int height;	///< maximum image height allowed, pixels;
	int mt;		///< multithreading flags (0=disabled, 1=enabled);
	int opt;	///< assembly optimizations flags (0=disabled, 1=enabled);
	int er;		///< error resilience (encoder) flags (0=disabled, 1=enabled);
	int ec;		///< error concealment (decoder) flags (0=disabled, 1=enabled);
	vssh_demo_limits_t demo_limits;	///< demo limitations (if applied);
} vssh_caps_info_t;

// Library capabilities
/**
 * Obtain library capabilities info
 * @param caps - address of structure to receive capabilities information, not NULL;
 * @param size - size of structure, bytes;
 * @return VSSH_OK, VSSH_ERR_ARG, VSSH_ERR_MEMORY when size of structures does not match;
 */
int VSSHAPI vssh_get_caps(vssh_caps_info_t *caps, int size);

/** @defgroup defs_err_codes Definitions and Error Codes
* @{
*/

/* function return codes */
/** @name Error codes
*/

// @{
/// Everything is OK
#define VSSH_OK 0

/// Warning: data is not ready yet
#define VSSH_WARN_NOT_READY 1

/// Warning: timeout occured
#define VSSH_WARN_TIMEOUT 2

/// Warning: settings do not fit into profile/level limitations
/// (frame size exceed, mbps excced, bitrate exceed)
#define VSSH_WARN_LEVEL_LIMITS 3

/// Error: general fault
#define VSSH_ERR_GENERAL -1

/// Error: not enough memory
#define VSSH_ERR_MEMORY -2

/// Error: wrong function argument value
#define VSSH_ERR_ARG -3

/// Warning: evaluation expired
#define VSSH_ERR_EXPIRED -4

/// Warning: frame skipped
#define VSSH_ERR_SKIP_FRAME -5

/// Error: invalid input frame dimensions specified
#define VSSH_ERR_FRAME_DIMENSIONS -6

/// Error: invalid encoder settings specified
#define VSSH_ERR_SETTINGS -7

/// Error: more input data needed to perform operation
#define VSSH_ERR_MORE_DATA -8

/// Error: file operation failed
#define VSSH_ERR_FILE -9

/// Error in stream: invalid prediction type
#define VSSH_ERR_STREAM_PRED_TYPE -10

/// Error in stream: invalid direct params
#define VSSH_ERR_STREAM_DIRECT -11

/// Error in stream: attempt to read after end of stream
#define VSSH_ERR_STREAM_EOS -12

/// Error in stream: error in CAVLC
#define VSSH_ERR_STREAM_CAVLC -13

/// Error in stream: error in REF_FRAME_NO
#define VSSH_ERR_STREAM_REF_FRAME_NO -14

/// Error in stream: error in CBP
#define VSSH_ERR_STREAM_CBP -15

/// Error in stream: error in subdiv type
#define VSSH_ERR_STREAM_SUBDIV_TYPE -16

/// Error in stream: error in sps type
#define VSSH_ERR_STREAM_SPS -17

/// Error in stream: error in mb type
#define VSSH_ERR_STREAM_MB_TYPE -18

/// Error in stream: error in subdiv 8x8 type
#define VSSH_ERR_STREAM_SUBDIV_8X8_TYPE -19

/// Error in stream: slice before sps or pps
#define VSSH_ERR_STREAM_SLICE_BEFORE_SPS_OR_PPS -20

#define VSSH_ERR_STREAM_WRONG_PPS_ID -21

#define VSSH_ERR_PPS_FMO_6_PARAM -22

#define VSSH_ERR_WRONG_REORDER_CODE -23

#define VSSH_ERR_PROFILE_NOT_SUPPORTED -24

#define VSSH_ERR_NON_REF_IDR_SLICE -25

/// the API function is not implemented
#define VSSH_ERR_NOTIMPL -26

/// Error in rfc3984 FU-nal
#define VSSH_ERR_STREAM_FU -27

/// Error in stream: more macroblocks required
#define VSSH_ERR_STREAM_EXTRA_MBS -28

/// Error in stream: invalid qp delta value
#define VSSH_ERR_STREAM_QP_DELTA -29

///Error: can't change sps while already decoded frames still persist in buffer
#define VSSH_ERR_SPS_CHANGE -30

/// error in first mb of slice
#define VSSH_ERR_FIRST_MB -31

/// error in SPS_ID. It must be in range [0,31]
#define VSSH_ERR_SPS_ID -32

/// error in LOG2_MAX_FRAME_NUM. It must be in range [4,16]
#define VSSH_ERR_LOG2_MAX_FRAME_NUM -33

/// error in LOG2_MAX_FRAME_POC. It must be in range [4,16]
#define VSSH_ERR_LOG2_MAX_POC -34

/// error in PIC_ORDER_CNT. It must be in range [0,2]
#define VSSH_ERR_PIC_ORDER_CNT -35

/// error in NUM_REF_FRAME It must be at least not bigger than 16
#define VSSH_ERR_NUM_REF_FRAMES -36

/// Error in stream: some frames before current were dropped
#define VSSH_ERR_FRAME_DROP_DETECTED -37

/// Error in stream: some slices of current frame were dropped
#define VSSH_ERR_SLICE_DROP_DETECTED -38

//This is a number of first fatal for whole stream
#define VSSH_ERR_FIRST_FATAL -100

#define VSSH_ERR_MMCO_CODE  -100
#define VSSH_ERR_NOT_SUPPORTED_SLICE_GROUPS -101
#define VSSH_ERR_NOT_SUPPORTED_ADAPTIVE_FRAME_FIELD -102
#define VSSH_ERR_NOT_SUPPORTED_FRAMES_AND_FIELDS_MUX -103
#define VSSH_ERR_NOT_SUPPORTED_SLICE_TYPE  -104
#define VSSH_ERR_NOT_SUPPORTED_PIC_TIMING_PIC_STRUCT -106

#define VSSH_ERR_USER_QUANT_MATRIX_NOT_EXIST_FILE  -107
#define VSSH_ERR_USER_QUANT_MATRIX_PARSE_FILE  -108
// @}
/** @} */

/* general data type representation */
#ifdef byte
	#undef byte
#endif
typedef unsigned char byte;	//!<  8 bit unsigned

#ifdef sword
	#undef sword
#endif

#ifdef uword
	#undef uword
#endif

typedef	short sword;
typedef unsigned short uword;


#ifdef GCC
	typedef long long timestamp_t;
#elif (defined(WIN32) || defined(_WIN32_WCE))
	typedef __int64	  timestamp_t;
#else
	typedef long long timestamp_t;
#endif

#define NO_TIME_STAMP (-1) // This means that timestamp is not passed

/** @addtogroup defs_err_codes */
// @{

/// Types of slices
typedef enum
{
	P_SLICE = 0,
	B_SLICE,
	I_SLICE,
	SP_SLICE,
	SI_SLICE,
	NUMBER_SLICETYPES
} slice_type_e;

// @}

// CC data support according to "CS-TSG-659r2.pdf" document
typedef enum
{
	SEI_BUFFERING_PERIOD = 0,
	SEI_PICTURE_TIMING = 1,
	SEI_USER_DATA_REGISTERED_ITU_T_T35 = 4,
	SEI_USER_DATA_UNREGISTERED = 5,
	SEI_RECOVERY_POINT = 6
} sei_type_e;

typedef struct cc_item_t
{
	byte cc_valid;
	byte cc_type;
	byte cc_data_1;
	byte cc_data_2;
} cc_item_t;

#define MAX_CC_ITEMS	16

typedef struct cc_picture_t
{
	byte country_code;
	int provider_code;
	int cc_count;
	cc_item_t cc_items[MAX_CC_ITEMS];
} cc_picture_t;

// picture timestamp fields
typedef struct pic_timestamp_t
{
	byte clock_timestamp_flag;
	byte ct_type;
	byte nuit_field_based_flag;
	byte counting_type;
	byte full_timestamp_flag;
	byte discontinuity_flag;
	byte cnt_dropped_flag;
	byte n_frames;
	byte seconds_flag;
	byte seconds_value;
	byte minutes_flag;
	byte minutes_value;
	byte hours_flag;
	byte hours_value;
	int  time_offset;
	timestamp_t timestamp;
} pic_timestamp_t;

/// Supplemental Enhancement Information (SEI) message: picture timing
typedef struct sei_pic_timing_t
{
	byte cpb_dpb_delays_present_flag;
	unsigned int cpb_removal_delay;
	unsigned int dpb_output_delay;
	byte pic_struct_present_flag;
	byte pic_struct;
	byte num_clock_ts;
	pic_timestamp_t pic_timestamp[3];
} sei_pic_timing_t;

/// Generic frame information
typedef struct
{
	int	slice_type;	///< type of the slice (see slice_type_e)
	int	frame_num;	///< logical number of the frame
	int	slice_num;	///< logical number of the slice
	int	idr_flag;	///< 1=IDR (key) frame, 0=regular frame;
	int	qp_used;	///< qp used for the frame
	int	num_intra_mb;	///< number of intra mbs in encoded frame
	int	num_bits;	///< number of encoded bits in slice;
	int	is_ref;		///< reference frame?: 0=non-ref; 1=short-term ref; 2=long-term ref;
	int	error_no;	//< error number, non-zero value indicates some error happened while processing;
	timestamp_t timestamp;	///< 64-bit field to hold user-provided timestamp value;
	int pic_struct; ///< picture structure (see standard Table D-1);
	cc_picture_t cc_picture;	///< closed caption data;
	int field_indicator;	///< internal encoder flag: 0=frame, 1=top field, 2=bottom field;
	//byte sei_pic_timing_present_flag;	///< 1=sei pic_timing info is present;
	//sei_pic_timing_t sei_pic_timing;	///< optional SEI pic_timing information;
	void *sei_chain;	///< list of SEI messages attached to the frame by application
} frame_info_t;

/// YUV pixel domain image arrays for uncompressed video frame
typedef struct
{
	int	width;		///< frame (allocated) buffer width in bytes, always divisible by 16;
	int	height;		///< frame (allocated) buffer height in bytes;
	int	image_width;	///< actual image width in pixels, less or equal to buffer width;
	int	image_height;	///< actual image height in pixels, less or equal to buffer height;
	byte	*y;		///< pointer to Y component data
	byte	*u;		///< pointer to U component data
	byte	*v;		///< pointer to V component data
	frame_info_t info; 	///< frame info structure
	int image_offset_x; ///< x-offset where actual image is located
	int image_offset_y; ///< y-offset where actual image is located
	int stride_y; ///< stride of luma lines allocation
	int stride_uv; ///< stride of chroma lines allocation
} yuv_frame_t;

/** @addtogroup defs_err_codes */
// @{

/// Typical values for profile IDC
typedef enum
{
	PROFILE_IDC_BASELINE = 66,
	PROFILE_IDC_MAIN     = 77,
	PROFILE_IDC_EXTENDED = 88,
	PROFILE_IDC_HIGH = 100,
	PROFILE_IDC_HIGH_10 = 110,
	PROFILE_IDC_HIGH_422 = 122,
	PROFILE_IDC_HIGH_444 = 144
} profile_idc_e;

/// Typical values for level IDC
typedef enum
{
	LEVEL_IDC_12 = 12,
	LEVEL_IDC_32 = 32,
	LEVEL_IDC_40 = 40
} level_idc_e;

/// Interlace mode
typedef enum
{
	INTERLACE_MODE_NONE = 0,
	INTERLACE_MODE_ALL_FIELD_TOP_FIRST = 1,
	INTERLACE_MODE_ALL_FIELD_BOTTOM_FIRST = 2,
	INTERLACE_MODE_FRAME_MBAFF = 3
} interlace_mode_e;

// @}

/// Video usability information (see JVT-g050r1)
typedef struct vui_info_t
{
	unsigned short sar_width;	///< aspect ratio width;
	unsigned short sar_height;	///< aspect ratio height;
	unsigned int num_units_in_tick; ///< frame rate divider;
	unsigned int time_scale;	///< fps = time_scale/num_units_in_tick;
	unsigned char fixed_frame_rate_flag;	///< 0/1;
	unsigned char pic_struct_present_flag;
	//< To be expanded...
} vui_info_t;


/// Cropping information of the allocated yuv frames
typedef struct cropping_info_t
{
	int luma_offset;	///< offset in pixels of actual luma data;
	int chroma_offset;	///< offset in pixels of actual chroma data;
	int frame_width;	///< actual frame width;
	int frame_height;	///< actual frame height;
} cropping_info_t;

/// Sequence Parameter Set (SPS) information
typedef struct sps_info_t
{
	int	profile_idc;	///< profile idc
	int	level_idc;	///< level
	int	is_interlace;	///< 0 - progressive; 1 - interlace
	int	allocated_frame_width;	///< frame width in pixels
	int	allocated_frame_height;	///< frame height in pixels
	int	cropping_info_present_flag;	///< whether the cropping info presents
	cropping_info_t cropping_info;	///< cropping info from sps header
	int	vui_info_present_flag;	///< whether the vui info presents
	vui_info_t vui_info;	///< vui info (fps and resize can obtained from here);
	int	error_no;  ///< non-zero indicates that some error was detected in SPS
	int yuv_format; ///< yuv_format (0 - YUV4:0:0 , 1 - YUV 4:2:0)
} sps_info_t;

/// Picture Parameter Set (PPS) information
typedef struct pps_info_t
{
	byte pic_parameter_set_id;
	byte seq_parameter_set_id;
	byte entropy_coding_mode;	///< 0=CAVLC, 1=CABAC;
	byte pic_order_present_flag;
	byte num_slice_groups;
	char pic_init_qp;
	byte deblocking_filter_parameters_present_flag;
	byte constrained_intra_pred_flag;
	byte redundant_pic_cnt_present_flag;
	byte weighted_pred_flag;
} pps_info_t;

typedef struct bp_delay_t
{
	unsigned int initial_cpb_removal_delay;
	unsigned int initial_cpb_removal_delay_offset;
} bp_delay_t;

typedef struct sei_buffering_period_t
{
	unsigned int seq_parameter_set_id;
	byte nal_hrd_bp_present_flag;
	byte nal_cpb_cnt_minus1;
	bp_delay_t nal_bp;
	byte vcl_hrd_bp_present_flag;
	byte vcl_cpb_cnt_minus1;
	bp_delay_t vcl_bp;	
} sei_buffering_period_t;

typedef struct sei_recovery_point_t
{
	unsigned int recovery_frame_cnt;
	byte exact_match_flag;
	byte broken_link_flag;
	byte changing_slice_group_idc;
} sei_recovery_point_t;

#pragma pack(pop, vssh_types)

#ifdef __cplusplus
}
#endif

#endif //__VSSH_TYPES_H__
