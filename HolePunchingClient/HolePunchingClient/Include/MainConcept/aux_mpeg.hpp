//------------------------------------------------------------------------------
// File: AUX_MPEG.HPP
//
// Desc: defines aux-exchange-structures for a/v-encoders and MUXer
//
// Copyright (c) 2000-2002, MainConcept AG.  All rights reserved.
//--------------------------------------------------------------------------
//
// $Id: aux_mpeg.hpp,v 1.2 2004/11/01 10:52:00 petern Exp $
// 
// $Log: aux_mpeg.hpp,v $
// Revision 1.2  2004/11/01 10:52:00  petern
// updated
//
// Revision 1.27  2004/09/22 07:34:05  brentb
// Added STREAM_END_CODE
//
// Revision 1.26  2004/05/27 06:19:49  brentb
// Added new DVD fixup and synci items
//
// Revision 1.25  2004/02/10 06:42:19  brentb
// Added length field to the audio_au_info_xml structure
//
// Revision 1.24  2004/01/20 10:23:03  brentb
// Added XML generation items
//
// Revision 1.23  2003/09/28 11:58:27  brentb
// Changed all references of INT64 to LONGLONG
//
// Revision 1.22  2003/09/17 09:28:20  brentb
// Added DVHS message
//
// Revision 1.21  2003/06/17 09:57:58  brentb
// Added the DVD_GET_RLBN_COUNT and FILESIZE_INFO messages
//
// Revision 1.20  2003/05/11 03:26:36  brentb
// Added and removed some messages
//
// Revision 1.19  2003/03/17 07:58:18  brentb
// Change the names of the NIT and PMT TS message.
//
// Revision 1.18  2003/02/24 10:39:46  brentb
// Added a few more transport stream messages.
//
// Revision 1.17  2003/02/17 05:39:11  brentb
// Added TS PID customization messages
//
// Revision 1.16  2003/01/22 13:32:06  serge
// added VIDEO_AU_START enum und corresponding structure
//
// Revision 1.15  2003/01/12 09:27:41  brentb
// Added the SWAP_ENDIAN message.
//
// Revision 1.14  2002/10/24 08:05:50  brentb
// Made changes to support DVD cells.
//
// Revision 1.13  2002/09/10 07:37:44  brentb
// Added additional messages and structures to support dvd authoring.
//
// Revision 1.12  2002/07/05 08:27:48  brentb
// Changed the video index header to be less than 256 bytes.
//
// Revision 1.11  2002/06/07 09:13:19  brentb
// Added another DVD navigation message.
//
// Revision 1.10  2002/05/23 09:26:44  brentb
// Added PID to a/v index information.
//
// Revision 1.9  2002/05/03 13:30:28  thorstens
// Copyright changed
//
// Revision 1.8  2002/04/29 08:38:05  brentb
// Added FILENUMBER_INFO and FILENAME_INFO auxinfo messages.
//
// Revision 1.7  2002/03/05 08:09:09  brentb
// Added several auxinfo messages and structures.
//
// Revision 1.6  2001/10/30 08:14:35  brentb
// Added a BYTECOUNT_INFO auxinfo message to retrieve the total bytecount
// of the stream.
//
// Revision 1.5  2001/10/18 08:46:48  serge
// removed warning in GCC v3.02
//
// Revision 1.4  2001/10/02 08:19:07  brentb
// Added a DVD nav info abort auxinfo message.
//
// Revision 1.3  2001/10/01 11:41:20  brentb
// Updated for DVD navigation support.
//
// Revision 1.2  2001/05/23 14:52:08  thorstens
// Header added to files
//
//
//------------------------------------------------------------------------------

#ifndef _AUX_MPEG_H_
#define _AUX_MPEG_H_


#ifndef LONGLONG
 #ifdef __GNUC__
  #define LONGLONG long long
 #else
  #define LONGLONG __int64
 #endif
#endif

enum aux_ID
{
/* AcessUnit Identification */
  UNSPECIFIED_AU        = 0x000F0000L,
  VIDEO_AU_CODE         = 0x000F0001L,
  AUDIO_AU_CODE         = 0x000F0002L,
  SP_AU_CODE            = 0x000F0004L,
  VIDEO_AU_START        = 0x000F0008L,

/* use to get contents of bytecount field */
  BYTECOUNT_INFO        = 0x000F0010L,
  FLUSH_BUFFER          = 0x000F0020L,
  SPLIT_OUTPUT          = 0x000F0040L,

/* used to signal end of stream */
  STREAM_END_CODE		= 0x000F0080L,
  
/* muxer output information codes */
  VIDEO_STREAM_INFO     = 0x000F0100L,
  VIDEO_AU_INFO         = 0x000F0200L,
  AUDIO_STREAM_INFO     = 0x000F0400L,
  AUDIO_AU_INFO         = 0x000F0800L,

  VIDEO_SEQ_INFO_XML    = 0x000F0810L,
  VIDEO_AU_INFO_XML     = 0x000F0811L,
  AUDIO_SEQ_INFO_XML    = 0x000F0812L,
  AUDIO_AU_INFO_XML     = 0x000F0813L,

/* DVD navigation codes */
  DVD_DO_NAV_INFO       = 0x000F1000L,
  DVD_SECTOR_NUM        = 0x000F2000L,
  DVD_PTM_TIME          = 0x000F4000L,
  DVD_ABORT_NAV_INFO    = 0x000F8000L,

  DVD_FIXUP_LAST_VOBU   = 0x000E0000L,
  DVD_SETUP_VOBIDN      = 0x000E0001L,
  DVD_RLBN_INFO         = 0x000E0002L,
  DVD_SEQ_END_CODE      = 0x000E0004L,
  DVD_GET_LAST_RLBN     = 0x000E0008L,
  DVD_GET_RLBN_COUNT    = 0x000E0009L,
  DVD_SET_HLI_INFO      = 0x000E0010L,
  DVD_DO_HLI_PTM_TIME   = 0x000E0020L,
  DVD_SETUP_CELLIDN     = 0x000E0040L,
  DVD_CELL_CHANGE       = 0x000E0080L,

  //DVD_DO_ASYNCI_INFO    = 0x000E0101L,  // return value is the stream ID which must be passed back to DVD_ASYNCI_INFO
  //DVD_ASYNCI_INFO       = 0x000E0102L,
  //DVD_DO_SPSYNCI_INFO   = 0x000E0201L,  // return value is the stream ID which must be passed back to DVD_SPSYNCI_INFO
  //DVD_SPSYNCI_INFO      = 0x000E0202L,
  DVD_FIXUP_SYNCI       = 0x000E0203L,
  //DVD_A1SYNCI_INFO      = 0x000E0800L,
  //DVD_A2SYNCI_INFO      = 0x000E1000L,

  DVD_DO_A1SYNCI_INFO   = 0x000E0100L,
  DVD_DO_A2SYNCI_INFO   = 0x000E0200L,
  DVD_DO_SPSYNCI_INFO   = 0x000E0400L,
  DVD_A1SYNCI_INFO      = 0x000E0800L,
  DVD_A2SYNCI_INFO      = 0x000E1000L,
  DVD_SPSYNCI_INFO      = 0x000E2000L,

/* VCD items */
  VCD_UPDATE_VBV        = 0x000D0000L,

/* transport stream ID messages */
  TS_MICROMV            = 0x000C0001L,
  TS_DVB                = 0x000C0002L,
  TS_DVHS               = 0x000C0004L,

/* filename and filenumber codes */
  FILENUMBER_INFO       = 0x00F00001L,
  FILENAME_INFO         = 0x00F00002L,
  SWAP_ENDIAN           = 0x00F00004L,
  FILESIZE_INFO         = 0x00F00008L, // only when opened for reading!!!

/* Audio-sync Identification */
  AUDIO_SYNC_CODE       = 0xFFF00000L,

/* Video-sync (exactly the same as MPEG-Codes) */
  ID_PICTURE_START_CODE = 0x00000100L,
  ID_SLICE_MIN_START    = 0x00000101L,
  ID_USER_START_CODE    = 0x000001B2L,
  ID_SEQ_START_CODE     = 0x000001B3L,
  ID_EXT_START_CODE     = 0x000001B5L,
  ID_SEQ_END_CODE       = 0x000001B7L,
  ID_GOP_START_CODE     = 0x000001B8L,
  ID_ISO_END_CODE       = 0x000001B9L,
  ID_PACK_START_CODE    = 0x000001BAL,
  ID_SYSTEM_START_CODE  = 0x000001BBL,

/* Auxiliary information */
  TIMESTAMP_INFO        = 0x0F000000L   // currently used to pass actual timestamps
};


//VIDEO_AU_CODE
struct v_au_struct
{
  unsigned long length;
  unsigned short int type;
  // hold the SEQHDR_FLAG and/or GOPHDR_FLAG (see mpegdef.h) if the
  // headers
  // are present in this au
  unsigned short int flags;
  // this can always be set to zero by the encoder
  // it is used by the muxer to add user data blocks to streams that
  // don't have them
  unsigned short int svcd_offset;
  unsigned short int pict_hdr_offset;
  unsigned long first_frame_offset;
  LONGLONG DTS;
  LONGLONG PTS;
};


//AUDIO_AU_CODE
struct a_au_struct
{
  unsigned long length	; 
  LONGLONG         pts;
};


//SP_AU_CODE
struct sp_au_struct
{
  unsigned long length	; 
  LONGLONG         pts;
};


//AUDIO_SYNC_CODE
struct aud_info 
{
  int version;
  int lay;
  int error_protection;
  int bitrate_index;
  int sampling_frequency;
  int padding;
  int extension;
  int mode;
  int mode_ext;
  int copyright;
  int original;
  int emphasis;
};


//SEQ_START_CODE,            (without size, I will correct it later, not used)
struct seq_start_info
{
  unsigned long video_type;
  unsigned long frame_rate_code;
  unsigned long bit_rate;
  unsigned long max_bit_rate;
  unsigned long pulldown_flag;
  unsigned long vbv_buffer_size;    
};


//PICTURE_START_CODE,        (without size, I will correct it later, not used)
struct pic_start_info
{
  unsigned long pict_type;
  unsigned long temp_ref;
  unsigned long repeat_first_field;
};


//USER_START_CODE,            (without size, I will correct it later, not used)
struct userdata_info
{
  unsigned char tag_name;
  unsigned char size;
  unsigned char userdata[0];
};


//DVD_SECTOR_NUM,   
struct dvd_sector_info
{
  int sector_num;     // sector number
  int sector_length;  // length of sector in 90000 mHz clocks
};

//DVD_PTM_TIME,       
struct dvd_ptm_info
{
  unsigned int PTM_time;      // ending time of VOB
};


struct dvd_fixup_info
{
  int sec_present;    // a sequence end code is present
  int first_sector;   // the first sector number of the added sectors
  int sectors_to_add; // number of sectors to add to the last vobu
  int sector_length;  // length of sector in 90000 mHz clocks
};


struct dvd_vobidn_info
{
  int vob_idn;        // new vob idn number
  int sectors_to_add; // number of sectors to add to the NV_PCK_LBN entries
};


struct dvd_nv_info
{
  unsigned int nv_sa;
  unsigned int frame_num;
  int vob_num;
  int cell_num;
};


struct dvd_synci_info
{
  int stream_num;
  int sector_offset;
};


//GOP_START_CODE, NULL
//EXT_START_CODE, NULL
//SEQ_END_CODE, NULL
//SLICE_MIN_START+j, &j       (without size, I will correct it later, not used)
//SLICE_MIN_START+(j&127), &j (without size, I will correct it later, not used)


#ifdef __GNUC__
#pragma pack(push,1)
#else
#pragma pack(push)
#pragma pack(1)
#endif

// NOTE! the size of these structures must be < 256 bytes or they
// cannot be passed to an auxinfo function!

// VIDEO_STREAM_INFO
struct video_stream_info
{
  unsigned char ID[4];
  int length;
  int program_stream_flag;
  int stream_id;
  int PID;
  int pulldown;
  int reserved[19];
  int seqhdr_length;
  unsigned char seq_hdr[150];
};

// AUDIO_STREAM_INFO
struct audio_stream_info
{
  unsigned char ID[4];
  int length;
  int program_stream_flag;
  int stream_id;
  int substream_id;
  int PID;
  int audio_type;
  int reserved[20];
  int audhdr_length;
  unsigned char audhdr[84];
  int pvt1hdr_length;
  unsigned char pvt1hdr[8];
};


// VIDEO_AU_INFO
struct video_au_info
{
  LONGLONG filePos;
  unsigned char num_in_sector;
  unsigned char frame_type; 
  short temp_ref;
  int forw_ref_frame;
  int coding_order;
  int display_order;
  LONGLONG PTS;
};

// VIDEO_AU_START
struct video_au_start
{
  unsigned long chapter_state; /* chapter, scene-change what else? */
  unsigned long tc_frame_nr;   /* frame_nr used to generate GOP-timecode */
  unsigned long ts_frame_nr;   /* frame_nr used to generate PTS/DTS-timestamps */
  unsigned long flags;         /* nothing */
};
      

// AUDIO_AU_INFO
struct audio_au_info
{
  LONGLONG filePos;
  int num_in_sector;
  LONGLONG PTS;
};


// VIDEO_SEQ_INFO_XML
struct video_seq_info_xml
{
  unsigned char pulldown_flag;
  unsigned char frame_rate_code;
  unsigned char reserved[62]; 
};


// VIDEO_AU_INFO_XML
struct video_au_info_xml
{
  LONGLONG filePos;
  unsigned int flags;
  int length;
  unsigned char repeat_first_field;
  LONGLONG PTS;
  int hdr_length;
  unsigned char *hdr;
  unsigned char reserved[31]; 
};


// AUDIO_SEQ_INFO_XML
struct audio_seq_info_xml
{
  LONGLONG clocks_per_audio_frame;
  unsigned char reserved[56]; 
};


// AUDIO_AU_INFO_XML
struct audio_au_info_xml
{
  LONGLONG PTS;
  int length;
  unsigned char reserved[52]; 
};

//////////////////////  DVD HLI structures  ///////////////////////////////

// section 4.4.3.2 Highlight General Information (HL_GI)

// table 4.4.3.2-1 HL_GI
struct HL_GI
{
  unsigned char HLI_SS[2];
  unsigned char HLI_S_PTM[4];
  unsigned char HLI_E_PTM[4];
  unsigned char BTN_SL_E_PTM[4];
  unsigned char BTN_MD[2];
  unsigned char BTN_OFN[1];
  unsigned char BTN_Ns[1];
  unsigned char NSL_BTN_Ns[1];
  unsigned char reserved1[1];
  unsigned char FOSL_BTNN[1];
  unsigned char FOAC_BTNN[1];
};


// section 4.4.3.3 Button Color Information Table (BTN_COLIT)

// figure 4.4.3.3-1 BTN_COLI
struct BTN_COLI
{
  unsigned char SL_COLI[4];
  unsigned char AC_COLI[4];
};


// section 4.4.3.4 Button Information Table (BTNIT)

// figure 4.4.3.4-1 BTNI
struct BTNI
{
  unsigned char BTN_POSI[6];
  unsigned char AJBTN_POSI[4];
  unsigned char BTN_CMD[8];
};


struct HLI
{
  HL_GI hl_gi;
  BTN_COLI btn_coli[3];
  BTNI bnti[36];
};


// pointer to an HLI structure with size
struct HLI_PTR
{
  int still_menu;
  int size;
  HLI *hli;
};


#pragma pack(pop)

#endif /* _AUX_MPEG_H_ */
