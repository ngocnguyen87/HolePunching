//==========================================================================;
//
// File: h264company.h
//
// Desc: Company dependent IDs
//
// Copyright (c) 2000-2004, MainConcept AG.  All rights reserved.
//--------------------------------------------------------------------------;
//
// $Id: 
// 
//------------------------------------------------------------------------------


#ifndef _h264company_h_
#define _h264company_h_

////////////////////////////////////////////////////////////

#define H264COMPANY_SHORTNAME "MainConcept"
#define H264COMPANY_WSHORTNAME L"MainConcept"

#define H264COMPANY_NAME "MainConcept AG"
#define H264COMPANY_WNAME L"MainConcept AG"

#define H264COMPANY_REGISTRYNAME "MainConcept"

#undef  H264COMPANY_HIDEICON

#define H264COMPANY_DS_MERIT_DECODER   MERIT_NORMAL
#define H264COMPANY_DS_MERIT_DECODER   MERIT_NORMAL
#define H264COMPANY_DECODER_NAME       "MCDSH264.AX"
#define H264COMPANY_ENCODER_NAME       "MCESH264.AX"
#define H264COMPANY_VIDEOENCODER_NAME  "MCEVH264.AX"


// status defines
#define H264COMPANY_STATUS_NONE  0
#define H264COMPANY_STATUS_TRIAL 1
#define H264COMPANY_STATUS_FULL  2
#define H264COMPANY_GETSTATUS(dwParam, lpData) H264COMPANY_STATUS_FULL


// guid base number {03AF8740-1764-42f0-A458-6875E492C077}
#define HGB_DW 0x3af8700
#define HGB_W0 0x1764
#define HGB_W1 0x42f0
#define HGB_B0 0xa4
#define HGB_B1 0x58
#define HGB_B2 0x68
#define HGB_B3 0x75
#define HGB_B4 0xe4
#define HGB_B5 0x92
#define HGB_B6 0xc0
#define HGB_B7 0x77



////////////////////////////////////////////////////////////

#endif // _h264company_h_
