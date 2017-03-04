
/**
 * @file vssh_settings.h
 * Encoder settings structures.
 *
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS H.264 Codec
 * Module:	Encoder
 */


#ifndef __VSSH_SETTINGS_H__
#define __VSSH_SETTINGS_H__

#include "evs_vssh_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_FILENAME_LEN 1024

/// This structure could be used by encoding application to modify default slice encoding parameters
typedef struct frame_modifier_t
{
	int slice_type;	///< type of the slice to use (see slice_type_e), -1=ignore it;
	int idr_flag;	///< keyframe flag: 0=no key frame, 1=key frame, -1=ignore it;
	int qp;			///< Q(uant) P(arameter) for this slice, -1=ignore it;
} frame_modifier_t;

//"chunk" below means set of all slicess for
// P and all B preceding this P (but coded after)
typedef enum //this is enum "is_last_in_pict" param possible values
{
	NOT_LAST = 0, //not last in any sence
	LAST_IN_PICT =  1, //last in one field, but not last in frame
	LAST_IN_FRAME = 2, //Last in frame, but not last in "chunk"
	LAST_IN_CHUNK = 3 //Last in "chunk"
} last_in_pict_e;


/// Structure to receive encoded slice parameters
typedef struct vssh_slice_data_t
{
	/// input fields (to be filled in by caller)
	byte *slice_data;	///< encoder will put the pointer to slice bits here
	int  slice_size;  	///< encoder will put the size here;
	frame_info_t frame_info;	///< compressed slice/frame information;
	int is_sei; ///< 1=SEI, 0=other;
	int is_last_in_pict; ///<  see last_in_pict_e enum
} vssh_slice_data_t;

/// Structure to receive PPS/SPS NAL units contents
typedef struct vssh_spps_data_t
{
	byte *spps_data;	///< buffer where encoder will place pointer;
	int   spps_size;	///< number of bytes actually put by encoder into output buffer;
} vssh_spps_data_t;


/** @name User Settings
* High level user settings for automatic configuration
*/
//@{
/// Input video material specification
typedef struct user_input_t
{
	int material;	///< type of input material: 0=progressive, 1=interlaced; @see encode.cfg::input.material
	int noisy;	///< noisy level [0..64]; @see encode.cfg::input.noisy
} user_input_t;

/// Target output requirements
typedef struct user_output_t
{
	int target;	///< target usage: 0=playback, 1=streaming; @see encode.cfg::output.target
	int bitrate;	///< desired bitrate, kbps; @see encode.cfg::output.bitrate
	int interval;	///< maximum keyframe interval; @see encode.cfg::output.interval
	int detect;	///< enable scene change detection, 0=OFF, 1=ON; @see encode.cfg::output.detect
} user_output_t;

/// Codec performance
typedef struct user_codec_t
{
	int quality;	///< setup video quality: 0=real, 1=fast, 2=good, 3=best, 4=maxq, 5=live; @see encode.cfg::codec.quality
} user_codec_t;

/// All user settings together
typedef struct user_settings_t
{
	user_input_t    input;	///< input video information;
	user_output_t   output;	///< output settings;
	user_codec_t    codec;	///< codec operation settings;
	char config_file[MAX_FILENAME_LEN];	///< config file name for advanced settings;
} user_settings_t;
//@}

/** @addtogroup defs_err_codes */
// @{

/// SAD type enum
typedef enum
{
	SAD_TYPE_REGULAR,
	SAD_TYPE_HADAMARD
} sad_type_e;

/** Subdiv flags for Inter MBs enum.
* Can be used combined by "|".
*/
typedef enum
{
	MODE_16X16 = 1,
	MODE_16X8  = 2,
	MODE_8X16  = 4,
	MODE_8X8   = 8,
	MODE_8X4   = 16,
	MODE_4X8   = 32,
	MODE_4X4   = 64
} subdiv_flags_e;

#define ALL_SUBDIV_MODES (MODE_16X16+MODE_16X8+MODE_8X16+MODE_8X8+MODE_8X4+MODE_4X8+MODE_4X4)
#define SQR_SUBDIV_MODES (MODE_16X16+MODE_8X8+MODE_4X4)
#define MPG_SUBDIV_MODES (MODE_16X16+MODE_8X8)

/// Macroblock Subdivision modes
typedef enum
{
	SD_MODE_16X16 = 0,
	SD_MODE_16X8  = 1,
	SD_MODE_8X16  = 2,
	SD_MODE_8X8   = 3,
	SD_MODE_8X4   = 4,
	SD_MODE_4X8   = 5,
	SD_MODE_4X4   = 6
} subdiv_modes_e;

/// Pel (pixel) Resolutions
typedef enum
{
	FULL_PEL = 0,
	HALF_PEL = 1,
	QUARTER_PEL = 2
} pel_resolutions_e;

/// Types of Rate Control
typedef enum
{
	RATE_CONTROL_QP  = 0,
	RATE_CONTROL_VBR = 1,
	RATE_CONTROL_CBR = 2,
	RATE_CONTROL_CBR_WITH_FILLER = 3
} rate_control_types_e;

#define IS_RC_CBR(type) ((type) == RATE_CONTROL_CBR || (type) == RATE_CONTROL_CBR_WITH_FILLER)

/// High Compression mode flags (see meaning below)
typedef enum
{
/**
Use high compression mode decision for
inter macroblocks of the P-frames.
High compression mode takes more time but
suppose to be more precise and produce better
compression
*/
	HCM_INTER_DECIDE_P       = 1,
/**
This bit controls how "mb_decide" function
decide between intra and inter macroblocks
in P-frames. Typically, after doing motion
estimation encoder calculates so called
"intra hints" for each macroblock.
This intra-hints marks macroblocks,
which "suspected" to be INTRA. "mb_decide"
function tries INTRA coding only for
these macroblocks. But if this bit
is set to 1 "mb_decide" tries intra coding
for each macroblock. This takes more time,
but suppose to be more precise and produce
better compression.
*/
	HCM_IGNORE_INTRA_HINTS_IN_P = 0x0002,
/**
The same as HCM_INTER_DECIDE_P but
for B-frames
*/
	HCM_INTER_DECIDE_B          = 0x0004,
/**
If this bit is not set to 1 "mb_decide" never
use intra-macroblocks in B-frames. It saves
time. If this bit is set, "mb_decide" tries
intra macroblocks in B-frames.
*/
	HCM_USE_INTRA_MB_IN_B       = 0x0008,
/**
The same as HCM_IGNORE_INTRA_HINTS_IN_P but
for B-frames. This bit has some effect only
if bit HCM_USE_INTRA_MB_IN_B is set to 1.
*/
	HCM_IGNORE_INTRA_HINTS_IN_B = 0x0010,
/**
Intra macroblocks in H264 can be be coded
as "big" (one 16x16 block) or "small"
(16 4x4 blocks). If this bit is not set,
only "big" coding is tested in "mb_decide"
function. If this bit is set to 1, "small"
coding is also tested. This takes more time,
but suppose to be more precise and produce
better compression.
*/
	HCM_USE_INTRA_4X4           = 0x0020,
/**
"small" intra macroblock coding has
a lot of variants. Not all of them are
likely to produce better compression.
Thus "mb_decide" use some heuristic to
reduce search. But if this bit is set
to 1, all variants are tested. This
takes more time, but suppose to be more
precise and produce better compression.
This bit has some effect only if bit
HCM_USE_INTRA_4X4 is set to 1.
*/
	HCM_FULL_INTRA_4X4_CHOOSING = 0x0040,
	//0x80 - reserverv
	HCM_MBAFF_FULL_DECIDE       = 0x0080,

/**
When coding texture, encoder can use
some heuristic to delete small rare
coefficients. This will reduce quality
a little, but also reduce bitrate.
Integrally compression should be better.
This bit enables "mb_decide" to use
this heuristic for intra macroblocks.
*/
	HCM_DELETE_RARE_COEFFS_INTRA = 0x0100,
/**
The same as HCM_DELETE_RARE_COEFFS_INTRA
but for INTER macroblocks.
*/
	HCM_DELETE_RARE_COEFFS_INTER = 0x0200,

	HCM_CALC_SNR                 = 0x0400,
	// Can be expanded till 0x8000
	HCM_MV_SET_BY_CALLER         = 0x10000,
	HCM_DECIDE_BY_CALLER         = 0x20000,
	HCM_MV_DECISION_BY_CALLER    = 0x40000 /**< mv decision received from caller (and intra must decide inside)*/
} high_compression_flags_e;

/// Interlace flags
typedef enum
{
	INT_PREDICT_BOTTOM_FROM_TOP = 1,	///< disable motion estimation from bottom field to top one
	INT_INTRA_FOR_BOTH_FIELD    = 2, ///< encode both fields as intra slices (default is only first intra)
	INT_MBAFF_BOTTOM_FIRST      = 4, ///< show bottom field first when mbaff coding (default - top field first)
	INT_FORCE_INTERLACE_PICTS   = 8, ///< force a decoder to play a frame structure stream as an interlaced
	INT_MBAFF_BOTTOM_ZERO_POC   = 16 ///< put zero POC offsets for both top & bottom fields;
} interlace_flags_e;

typedef enum
{
	QP_MODULATION_OFF = 0,
	QP_MODULATION_ON = 1,
	QP_MODULATION_2_ON = 2
} qp_modulation_mode_t;

// @}

/** me flags enum
* Can be used combined by "|".
*/
typedef enum
{
	ME_USE_MB_ME_P    = 0x0001,    ///< Use macroblock level me for P-slices
	ME_USE_MB_ME_B    = 0x0002,    ///< Use macroblock level me for B-slices
	ME_USE_SMALL_ME_P = 0x0004,    ///< Use preliminary me on the reduced pictures P-slices
	ME_USE_SMALL_ME_B = 0x0008,    ///< Use preliminary me on the reduced pictures B-slices
	ME_LIMIT_B_REFS   = 0x0010,    ///< Set num_refs for B-frames to (1,1) even if max_ref_frames_num > 1
	ME_USE_ORIGINAL   = 0x0100     ///< use original pixels for motion estimation (not compensated)
} me_flags_e;

/// Motion Estimation settings
typedef struct me_settings_t
{
	int sad_type;           ///< [obsolete] Hadamard transform (0=not used, 1=used), @see sad_type_e;
	int search_range;       ///< Maximum search range, full pels; @see encode.cfg::me.search_range
	int max_ref_frames_num; ///< Number of previous frames used for inter motion search (1-5); @see encode.cfg::me.max_refs
	int use_idr_long_term;  ///< [obsolete] Use long term idr frames? (0/1);
	int subdiv_flags;       ///< subdiv_flags_e combinated by "|"; @see encode.cfg::me.subdiv
	int pel_resolution;     ///< [obsolete] 0=full-pel, 1=half-pel, 2=q-pel;
	int flags;              ///< bitwise flags; @see me_flags_e; @see encode.cfg::me.flags
	int scale_for_reduced_me;	///< scale factor for reduced ME (1=1/2, 2=1/4); @see encode.cfg::me.scale
} me_settings_t;

/// Slicing settings
typedef struct slice_settings_t
{
	int slice_mode;  ///< slicing mode (0=off; 1=mbs in slice; 2=bytes in slice; 3=slices in picture); @see encode.cfg::slice.mode
	int slice_param; ///< slice argument (arguments to modes 1,2,3 above); @see encode.cfg::slice.param
	int slice_i_param; ///< slice argument for i-pictures; @see encode.cfg::slice.i_param
	int slice_b_param; ///< slice argument for all non-ref pictures; @see encode.cfg::slice.b_param
	int fmo_type;    ///< [TBD] Not used in current version;
} slice_settings_t;

/// Loop filter (deblocking) settings
typedef struct loop_filter_settings_t
{
	int flag; ///< Configure loop filter (0=parameter below ingored, 1=parameters sent); @see encode.cfg::deblock.flag
	int disable; ///< Disable loop filter in slice header (0=enable, 1=disable); @see encode.cfg::deblock.disable
	int alpha_c0_offset; ///< Alpha & C0 offset div. 2, [-6..6]; @see encode.cfg::deblock.alpha_c0
	int beta_offset; ///< Beta offset div. 2, [-6..6]; @see encode.cfg::beta_c0
} loop_filter_settings_t;

/// CABAC settings (obsolete)
typedef struct cabac_settings_t
{
	int context_init_method; ///< [obsolete] Context init (0: fixed, 1: adaptive);
	int fixed_model_num;     ///< [obsolete] model number for fixed decision for inter slices ( 0, 1, or 2);
} cabac_settings_t;

/// GOP (group of pictures) settings
typedef struct gop_settings_t
{
	int num_units;	///< num units per tick; @see encode.cfg::gop.num_units
	int time_scale;	///< time scale; @see encode.cfg::time_scale
	int intra_period; ///< Period of I-Frames (0=only first); @see encode.cfg::gop.keyframes
	int idr_period; ///< Period of IDR I-Frames (0=only first); @see encode.cfg::idr_period
	int bframes_num;  ///< number of B-frames (0=disable); @see encode.cfg::gop.bframes
	int emulate_b_by_p;  ///< enable B-frames emulation using non-ref P-frames (0/1); @see encode.cfg::emulate_b
} gop_settings_t;

/// VUI (video usability indormation) settings
typedef struct vui_settings_t
{
	int aspect_ratio_idc;	///< aspect ratio IDC; @see encode.cfg::vui.aspect_ratio_idc
	int sar_width;	///< sample aspect ratio width; @see encode.cfg::vui.sar_width
	int sar_height;	///< sample aspect ratio height; @see encode.cfg::vui.sar_height
	int fixed_frame_rate_flag;	///< fixed framerate flag (0/1); @see encode.cfg::vui.fixed_frame_rate_flag
	int low_delay_hrd_flag;
	int overscan_info_present_flag;
	int overscan_appropriate_flag;
	int video_signal_type_present_flag;	///< 0/1
	int video_format;		///< video format as specified in Table E-2; @see encode.cfg::vui.video_format
	int video_full_range_flag;	///< 0/1
	int colour_description_present_flag;	///< 0/1
	int colour_primaries;	///< Table E-3; @see encode.cfg::vui.colour_primaries
	int transfer_characteristics;	///< Table E-4; @see encode.cfg::vui.transfer_characteristics
	int matrix_coefficients;	///< Table E-5; @see encode.cfg::vui.matrix_coefficients
	int chroma_loc_info_present_flag;
	int chroma_sample_loc_type_top_field;
	int chroma_sample_loc_type_bottom_field;
	int bitstream_restriction_flag;
	int motion_vectors_over_pic_boundaries_flag;
	int max_bytes_per_pic_denom;
	int max_bits_per_mb_denom;
	int log2_max_mv_length_horizontal;
	int log2_max_mv_length_vertical;
	int num_reorder_frames;
	int max_dec_frame_buffering;
} vui_settings_t;

/// Rate Control settings
typedef struct rate_control_settings_t
{
	rate_control_types_e type;  ///< rate control mode (0=QP; 1=VBR, 2=CBR); @see rate_control_types_e; @see encode.cfg::rc.type
	int kbps;	 ///< desided bitrate (kbits per sec); @see encode.cfg::rc.kbps
	int qp_intra;     ///< init param for intra frames (0..51); @see encode.cfg::rc.qp_intra
	int qp_modulation;///< enable QP modulation (0/1); @see encode.cfg::rc.qp_modulation
	int scene_detect; ///< scene change detection threshold (0..100), default 70; @see encode.cfg::rc.scene_detect
	int qp_delta_p;		///< basic delta QP between I and P frames (0..51); @see encode.cfg::rc.qp_delta_p
	int qp_delta_b;		///< basic delta QP between P and B frames (0..51); @see encode.cfg::rc.qp_delta_b
	int auto_qp; ///< enable automatic start, max and min qp calulation (0/1); @see encode.cfg::rc.auto_qp
	int qp_max;	///< select maximum allowed QP (0..51), 0 means n/a; @see encode.cfg::rc.qp_max
	int qp_min;	///< select minimum allowed QP (0..51), 0 means n/a; @see encode.cfg::rc.qp_min
	int cbr_delay_ms;	///< CBR delay in msec, default 1000; @see encode.cfg::rc.cbr_delay_ms
	int vbr_delay_ms;	///< VBR delay in msec, default 2000; @see encode.cfg::rc.vbr_delay_ms
	int framerate;		///< [obsolete] frame rate, frames per 10,000 seconds;
	int mb_update; ///< macroblocks per group for mb-level update; @see encode.cfg::rc.mb_update
	char log_file[MAX_FILENAME_LEN];	///< [obsolete] name of log file for multipass statistics;
	char stat_file[MAX_FILENAME_LEN];	///< [obsolete] name of stat file for multipass statistics;
} rate_control_settings_t;

/// SEI (supplemental enhancement information) messages settings
typedef struct sei_settings_t
{
	int pic_timing_flag; ///< enable picture timing SEI messages (0/1); @see encode.cfg::sei.pic_timing
} sei_settings_t;


/**
 * definition of the application function to be called by codec to deliver ready slice to;
 * @param param - user-defined parameter (context);
 * @param slice_data - ready slice data;
 */
typedef int mt_user_callback_t(void *param, vssh_slice_data_t *slice_data);

/// Multi-Threading settings
typedef struct mt_settings_t
{
	int disable;	 ///< flag to disable multithreading;
	int num_cpus;	 ///< number of virtual CPUs detected;
	int num_threads; ///< number of worker threads to run, zero means automatic value equal to number of CPUs;
	mt_user_callback_t  *user_callback;	///< application function to deliver next ready slice to;
	void *user_param;	///< application context for callback function;
	int num_groups; ///< number of slice groups of one picture, which can be encoded simultaneously
} mt_settings_t;

/// Rate Distortion Optimization (RDOpt) settings
typedef struct rd_settings_t
{
	int enable_i;	///< enable RDO for I-slices (0=disable, 1=slow, 2=fast); @see encode.cfg::rd.enable_i
	int enable_p;	///< enable RDO for P-slices (0=disable, 1=slow, 2=fast); @see encode.cfg::rd.enable_p
	int enable_b;	///< enable RDO for B-slices (0=disable, 1=slow, 2=fast); @see encode.cfg::rd.enable_b
} rd_settings_t;

/// Settings for error resilience in encoder
typedef struct error_resilience_settings_t
{
	int enable;	///< enable ER (0/1); @see encode.cfg::error_resilience.enable
	int initial_expected_loss_percent;	///< The initial expected loss rate in percents; @see encode.cfg::error_resilience.initial_expected_loss_percent
	int intra_update_method;	///< 0=none, 1=adaptive,  2=horizontal, 3=random; @see encode.cfg::error_resilience.intra_update_method
	int full_motion_update_period;	///< long update period, frames. 0=none, 1..3=recommended; @see encode.cfg::error_resilience.full_motion_update_period
	int fast_motion_update_period;	///< short update period, frames. 0=none, 5..15=recommended; @see encode.cfg::error_resilience.fast_motion_update_period
	int enable_isolated_regions;	///< [obsolete]
	int me_region_height_in_mbs;	///< motion estimation vertical constraint; @see encode.cfg::error_resilience.me_region_height_in_mbs
	int me_region_width_in_mbs;	///< [obsolete] motion estimation horizontal constraint;
} error_resilience_settings_t;

/// Fidelity Range Extensions (FRExt) settings
typedef struct frext_t
{
	int transform_8x8_mode_flag;  ///< enable 8x8 transform (High profile only); @see encode.cfg::frext.transform8x8
} frext_t;

/// Denoise settings
typedef struct denoise_settings_t
{
	int level; ///< denoise level (0=disabled, 1=weak, 2=moderate, 3=middle, 4=strong, 5=very strong, 6=crazy); @see encode.cfg::denoise.level
	int skip_chroma;	///< whether to skip U and V processing (0/1); @see encode.cfg::denoise.skip_chroma
	int skip_luma;		///< whether to skip Y processing (0/1); @see encode.cfg::denoise.skip_luma
	int force_fields;	///< enable interlaced processing (0/1); @see encode.cfg::denoise.force_fields
} denoise_settings_t;

/// RTP packetization modes
typedef enum
{
	single_nal_packet_mode = 0,		///< whole NAL unit placed in packet payload;
	noninterleaved_packet_mode = 1,		///< fragmentation for large NAL units;
	interleaved_packet_mode = 2		///< fragmentation for large NAL units, aggregation for small NAL units;
} packet_mode_e;

/// RTP payload (RFC-3984) settings
typedef struct rtp_settings_t
{
	int packet_mode;	///< RTP packetization mode, @see packet_mode_e;
	int payload_size;	///< desired payload size, bytes;
} rtp_settings_t;

/// FMO (flexible macroblock ordering) settings
typedef struct fmo_settings_t
{
	int num_slice_groups;	///< total number of slice groups (1=FMO disabled); @see encode.cfg::fmo.num_slice_groups
	int type;	///< FMO type (0=interleaved, 1=dispersed); @see encode.cfg::fmo.type
	int type0_mb_lines_in_group_run; ///< lines per group in mode 0; @see encode.cfg::fmo.type0_mb_lines_in_group_run
	int internal_group_slice_mode;	///< @see slice_settings_t::slice_mode; @see encode.cfg::fmo.internal_group_slice_mode
	int internal_group_slice_param;	///< @see slice_settings_t::slice_param; @see encode.cfg::fmo.internal_group_slice_param
	int internal_group_slice_i_param;	///< @see slice_settings_t::slice_i_param; @see encode.cfg::fmo.internal_group_slice_i_param
} fmo_settings_t;

/// auto config modes
typedef enum
{
	 AUTO_CONFIG_DISABLED = 0
	,AUTO_CONFIG_ENABLED = 1
	,AUTO_CONFIG_ARIB = 2
} auto_config_e;

/// custom quant matrices flags
typedef enum
{
	CQM_INTRA_Y_4X4 = 0x01,
	CQM_INTRA_U_4X4 = 0x02,
	CQM_INTRA_V_4X4 = 0x04,
	CQM_INTER_Y_4X4 = 0x08,
	CQM_INTER_U_4X4 = 0x10,
	CQM_INTER_V_4X4 = 0x20,
	CQM_INTRA_Y_8X8 = 0x40,
	CQM_INTER_Y_8X8 = 0x80,
} cqm_flags_e;

/// custom quant matrices methods
typedef enum
{
	CQM_METHOD_SETTINGS = 1,
	CQM_METHOD_AUTO = 2,
} cqm_methods_e;

/// custom quant matrix settings
typedef struct cqm_settings_t
{
	int method;	///< custom quant matrix method: 0=disabled, 1=settings, 2=auto; @see cqm_methods_e; @see encode.cfg::cqm.method
	int flags;	///< ccustom quant matrix bitwise flags: 0=CQM disabled; @see cqm_flags_e; @see encode.cfg::cqm.flags
	unsigned char intra4x4_luma[16]; ///< @see encode.cfg::cqm.intra4x4y
	unsigned char intra4x4_chromau[16]; ///< @see encode.cfg::cqm.intra4x4u
	unsigned char intra4x4_chromav[16]; ///< @see encode.cfg::cqm.intra4x4v
	unsigned char inter4x4_luma[16]; ///< @see encode.cfg::cqm.inter4x4y
	unsigned char inter4x4_chromau[16]; ///< @see encode.cfg::cqm.inter4x4u
	unsigned char inter4x4_chromav[16]; ///< @see encode.cfg::cqm.inter4x4v
	unsigned char intra8x8_luma[64]; ///< @see encode.cfg::cqm.intra8x8y
	unsigned char inter8x8_luma[64]; ///< @see encode.cfg::cqm.inter8x8y
} cqm_settings_t;

typedef enum
{
	ARIB_FLAG_NONE = 0,		///< no ARIB regulation
	ARIB_FLAG_CS = 1,		///< ARIB regulation according to "H.264|MPEG-4 AVC Operation Regulation for the Advanced Narrow-band CS Digital Broadcasting Service in Japan (Draft)"
	ARIB_FLAG_12 = 2		///< ARIB Baseline 1.2 according to "ARIB TR-B14"
} arib_flag_e;

/// All encoder settings
typedef struct vssh_encoder_settings_t
{
	/// flag whether to use high level user settings
	int auto_config;	///< 0=manual config, 1=auto config, 2=ARIB spec; @see encode.cfg::auto_config
	/// high level user settings:
	user_settings_t user_settings;	///< settings for auto config;
	/// low level encoder settings:
	int profile_idc;	///< profile IDC selection; @see profile_idc_e; @see encode.cfg::profile_idc
	int level_idc;		///< level IDC selection; @see level_idc_e; @see encode.cfg::level_idc
	int frame_width;	///< frame width (pixels), must be multiple of 2; [to be provided by application]
	int frame_height;	///< frame height (pixels), must be multiple of 2 for progressive or 4 for interlaced; [to be provided by application]
	int symbol_mode;	///< select symbol mode: 0=UVLC; 1=CABAC;  @see encode.cfg::symbol_mode
	int interlace_mode; ///< 0=progressive; 1=top field first; 2=bottom field first, 3=MBAFF;  @see encode.cfg::interlace_mode
	cabac_settings_t cabac_settings;    ///< CABAC settings;
	int constraint_intra_pred; ///< [obsolete] 1=Inter pixels are not used for Intra macroblock prediction;
	int poc_type;     ///< select POC mode (0/1/2);  @see encode.cfg::poc_type
	int direct_mode; ///< select direct mode for B-frames (0=temporal, 1=spatial); @see encode.cfg::direct_mode

	int calc_snr;	///< calculate snr (0/1);  @see encode.cfg::calc_snr
	int interlace_flags; ///< Bitwise interlace flags (@see interlace_flags_e); @see encode.cfg::interlace_flags
	int high_compression_mode; ///< compression modes bitwise flags;  @see encode.cfg::high_compression_mode
	int weighted_pred_flag; ///< weighted prediction for P slices (0/1);  @see encode.cfg::wp.enable_p
	int weighted_bipred_idc; ///< weighted prediction for B slices (0/1); @see encode.cfg::wp.enable_b

	int sps_id; ///< [obsolete] select SPS id (0..32);
	int pps_id; ///< [obsolete] select PPS id (0..64);

	gop_settings_t gop_settings;         ///< GOP settings
	rate_control_settings_t rc_settings; ///< Rate Control settings
	me_settings_t me_settings;           ///< Motion estimation settings
	rd_settings_t rd_settings;           ///< Rate-Distortion optimization settings
	slice_settings_t slice_settings;     ///< Slice settings
	loop_filter_settings_t lf_settings;  ///< Deblocking filter settings
	/// encoder log file
	int  enc_log_enabled;
	char enc_log_file[MAX_FILENAME_LEN];
	/// cpu flags
	int  cpu_disable;	///< CPU features to disable (AMD=1,VIAC3=2,MMX=4,SSE=8,SSE2=16); @see encode.cfg::cpu_disable
	sei_settings_t sei_settings;	///< SEI messages settings
	mt_settings_t mt_settings;	///< multi-threading settings
	frext_t frext;  ///< FRext (fidelity range extensions) settings
	denoise_settings_t denoise_settings;	///< denoise settings
	rtp_settings_t rtp_settings;	///< RTP packetization settings
	error_resilience_settings_t error_resilience;	///< Error resilience settings
	fmo_settings_t fmo;	///< FMO settings
	vui_settings_t vui;	///< VUI settings
	cqm_settings_t cqm;		///< custom quant matrix
	/// other flags
	int delimiter_flag; ///< access units delimiter flag (0/1);  @see encode.cfg::delimiter_flag
	int level_limits_flag;	///< for vssh_enc_open(): whether to warn on level limits exceeded (0/1);  @see encode.cfg::level_limits_flag
	int arib_flag;		///< ARIB regulation compatibility mode flags (0/1);
} vssh_encoder_settings_t;

/**
 * Provide default encoder settings into given structure
 */
void set_default_settings(vssh_encoder_settings_t * settings);
/**
 * Provide maximum speed configuration into given structure
 */
void set_maxspeed_settings(vssh_encoder_settings_t * settings);
/**
 * Provide maximum quality configuration into given structure
 */
void set_maxquality_settings(vssh_encoder_settings_t * settings);
/**
 * Load encoder settings from a command line arguments
 */
void read_settings_from_cmd_line(vssh_encoder_settings_t * settings, char *argv[]);

/**
 * Load given configuration text file
 * @return 0=OK, -1=the file could not be opened for read;
 */
int  read_settings_from_file(vssh_encoder_settings_t * settings, char * filename);

/**
 * Print given settings to stdout
 * @return void
 */
void dump_settings(vssh_encoder_settings_t *settings);

#ifdef __cplusplus
}
#endif

#endif	//__VSSH_SETTINGS_H__
