//==========================================================================;
//
// File: company.h
//
// Desc: Company dependent IDs
//
// Copyright (c) 2000-2002, MainConcept AG.  All rights reserved.
//--------------------------------------------------------------------------;
//
// $Id: 
// 
//------------------------------------------------------------------------------


#ifndef _company_h_
#define _company_h_

////////////////////////////////////////////////////////////

#define COMPANY_SHORTNAME "MainConcept"
#define COMPANY_WSHORTNAME L"MainConcept"

#define COMPANY_NAME "MainConcept AG"
#define COMPANY_WNAME L"MainConcept AG"

#define COMPANY_PREFIX ""

#define COMPANY_REGISTRYNAME "MainConcept"

#undef  COMPANY_HIDEICON

#define COMPANY_DS_MERIT_VIDEODECODER (MERIT_NORMAL)
#define COMPANY_DS_MERIT_AUDIODECODER (MERIT_NORMAL)
#define COMPANY_DS_MERIT_SPLITTER     (MERIT_NORMAL+2)


#define COMPANY_MPEGSPLITTER_NAME      "MCSPMPEG.AX"
#define COMPANY_MPEGDECODER_NAME       "MCDSMPEG.AX"
#define COMPANY_MPEGENCODER_NAME       "MCESMPEG.AX"
#define COMPANY_MPEGVIDEOENCODER_NAME  "MCEVMPEG.AX"
#define COMPANY_MPEGAUDIOENCODER_NAME  "MCEAMPEG.AX"
#define COMPANY_MPEGMUXER_NAME         "MCMUXMPEG.AX"

// status defines
#define COMPANY_STATUS_NONE  0
#define COMPANY_STATUS_TRIAL 1
#define COMPANY_STATUS_FULL  2
#define COMPANY_GETSTATUS(dwParam, lpData) COMPANY_STATUS_FULL


// guid base number {2BE4D100-6F2E-4b3a-B0BD-E880917238DC}
#define GB_DW 0x2be4d100
#define GB_W0 0x6f2e
#define GB_W1 0x4b3a
#define GB_B0 0xb0
#define GB_B1 0xbd
#define GB_B2 0xe8
#define GB_B3 0x80
#define GB_B4 0x91
#define GB_B5 0x72
#define GB_B6 0x38
#define GB_B7 0xdc



////////////////////////////////////////////////////////////

#endif // _company_h_
