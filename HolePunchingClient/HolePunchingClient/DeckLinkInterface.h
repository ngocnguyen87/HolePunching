

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Wed Nov 18 10:08:30 2009
 */
/* Compiler settings for .\DecklinkInterface.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __DeckLinkInterface_h__
#define __DeckLinkInterface_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __DecklinkVideoCaptureFilter_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter DecklinkVideoCaptureFilter;
#else
typedef struct DecklinkVideoCaptureFilter DecklinkVideoCaptureFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureProperties_FWD_DEFINED__
#define __DecklinkVideoCaptureProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureProperties DecklinkVideoCaptureProperties;
#else
typedef struct DecklinkVideoCaptureProperties DecklinkVideoCaptureProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureProperties_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureProperties2_FWD_DEFINED__
#define __DecklinkVideoCaptureProperties2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureProperties2 DecklinkVideoCaptureProperties2;
#else
typedef struct DecklinkVideoCaptureProperties2 DecklinkVideoCaptureProperties2;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureProperties2_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter DecklinkAudioCaptureFilter;
#else
typedef struct DecklinkAudioCaptureFilter DecklinkAudioCaptureFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureProperties_FWD_DEFINED__
#define __DecklinkAudioCaptureProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureProperties DecklinkAudioCaptureProperties;
#else
typedef struct DecklinkAudioCaptureProperties DecklinkAudioCaptureProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureProperties_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureProperties2_FWD_DEFINED__
#define __DecklinkAudioCaptureProperties2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureProperties2 DecklinkAudioCaptureProperties2;
#else
typedef struct DecklinkAudioCaptureProperties2 DecklinkAudioCaptureProperties2;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureProperties2_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter_FWD_DEFINED__
#define __DecklinkVideoRenderFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter DecklinkVideoRenderFilter;
#else
typedef struct DecklinkVideoRenderFilter DecklinkVideoRenderFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderProperties_FWD_DEFINED__
#define __DecklinkVideoRenderProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderProperties DecklinkVideoRenderProperties;
#else
typedef struct DecklinkVideoRenderProperties DecklinkVideoRenderProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderProperties_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter_FWD_DEFINED__
#define __DecklinkAudioRenderFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter DecklinkAudioRenderFilter;
#else
typedef struct DecklinkAudioRenderFilter DecklinkAudioRenderFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderProperties_FWD_DEFINED__
#define __DecklinkAudioRenderProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderProperties DecklinkAudioRenderProperties;
#else
typedef struct DecklinkAudioRenderProperties DecklinkAudioRenderProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderProperties_FWD_DEFINED__ */


#ifndef __DecklinkCaptureFilter_FWD_DEFINED__
#define __DecklinkCaptureFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkCaptureFilter DecklinkCaptureFilter;
#else
typedef struct DecklinkCaptureFilter DecklinkCaptureFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkCaptureFilter_FWD_DEFINED__ */


#ifndef __DecklinkRenderFilter_FWD_DEFINED__
#define __DecklinkRenderFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkRenderFilter DecklinkRenderFilter;
#else
typedef struct DecklinkRenderFilter DecklinkRenderFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkRenderFilter_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter2_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter2 DecklinkVideoCaptureFilter2;
#else
typedef struct DecklinkVideoCaptureFilter2 DecklinkVideoCaptureFilter2;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter2_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter3_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter3_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter3 DecklinkVideoCaptureFilter3;
#else
typedef struct DecklinkVideoCaptureFilter3 DecklinkVideoCaptureFilter3;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter3_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter4_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter4_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter4 DecklinkVideoCaptureFilter4;
#else
typedef struct DecklinkVideoCaptureFilter4 DecklinkVideoCaptureFilter4;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter4_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter5_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter5_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter5 DecklinkVideoCaptureFilter5;
#else
typedef struct DecklinkVideoCaptureFilter5 DecklinkVideoCaptureFilter5;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter5_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter6_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter6_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter6 DecklinkVideoCaptureFilter6;
#else
typedef struct DecklinkVideoCaptureFilter6 DecklinkVideoCaptureFilter6;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter6_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter7_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter7_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter7 DecklinkVideoCaptureFilter7;
#else
typedef struct DecklinkVideoCaptureFilter7 DecklinkVideoCaptureFilter7;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter7_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter8_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter8_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter8 DecklinkVideoCaptureFilter8;
#else
typedef struct DecklinkVideoCaptureFilter8 DecklinkVideoCaptureFilter8;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter8_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter9_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter9_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter9 DecklinkVideoCaptureFilter9;
#else
typedef struct DecklinkVideoCaptureFilter9 DecklinkVideoCaptureFilter9;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter9_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter10_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter10_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter10 DecklinkVideoCaptureFilter10;
#else
typedef struct DecklinkVideoCaptureFilter10 DecklinkVideoCaptureFilter10;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter10_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter11_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter11_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter11 DecklinkVideoCaptureFilter11;
#else
typedef struct DecklinkVideoCaptureFilter11 DecklinkVideoCaptureFilter11;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter11_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter12_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter12_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter12 DecklinkVideoCaptureFilter12;
#else
typedef struct DecklinkVideoCaptureFilter12 DecklinkVideoCaptureFilter12;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter12_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter13_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter13_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter13 DecklinkVideoCaptureFilter13;
#else
typedef struct DecklinkVideoCaptureFilter13 DecklinkVideoCaptureFilter13;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter13_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter14_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter14_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter14 DecklinkVideoCaptureFilter14;
#else
typedef struct DecklinkVideoCaptureFilter14 DecklinkVideoCaptureFilter14;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter14_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter15_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter15_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter15 DecklinkVideoCaptureFilter15;
#else
typedef struct DecklinkVideoCaptureFilter15 DecklinkVideoCaptureFilter15;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter15_FWD_DEFINED__ */


#ifndef __DecklinkVideoCaptureFilter16_FWD_DEFINED__
#define __DecklinkVideoCaptureFilter16_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoCaptureFilter16 DecklinkVideoCaptureFilter16;
#else
typedef struct DecklinkVideoCaptureFilter16 DecklinkVideoCaptureFilter16;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoCaptureFilter16_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter2_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter2 DecklinkAudioCaptureFilter2;
#else
typedef struct DecklinkAudioCaptureFilter2 DecklinkAudioCaptureFilter2;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter2_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter3_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter3_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter3 DecklinkAudioCaptureFilter3;
#else
typedef struct DecklinkAudioCaptureFilter3 DecklinkAudioCaptureFilter3;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter3_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter4_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter4_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter4 DecklinkAudioCaptureFilter4;
#else
typedef struct DecklinkAudioCaptureFilter4 DecklinkAudioCaptureFilter4;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter4_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter5_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter5_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter5 DecklinkAudioCaptureFilter5;
#else
typedef struct DecklinkAudioCaptureFilter5 DecklinkAudioCaptureFilter5;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter5_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter6_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter6_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter6 DecklinkAudioCaptureFilter6;
#else
typedef struct DecklinkAudioCaptureFilter6 DecklinkAudioCaptureFilter6;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter6_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter7_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter7_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter7 DecklinkAudioCaptureFilter7;
#else
typedef struct DecklinkAudioCaptureFilter7 DecklinkAudioCaptureFilter7;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter7_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter8_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter8_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter8 DecklinkAudioCaptureFilter8;
#else
typedef struct DecklinkAudioCaptureFilter8 DecklinkAudioCaptureFilter8;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter8_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter9_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter9_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter9 DecklinkAudioCaptureFilter9;
#else
typedef struct DecklinkAudioCaptureFilter9 DecklinkAudioCaptureFilter9;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter9_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter10_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter10_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter10 DecklinkAudioCaptureFilter10;
#else
typedef struct DecklinkAudioCaptureFilter10 DecklinkAudioCaptureFilter10;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter10_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter11_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter11_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter11 DecklinkAudioCaptureFilter11;
#else
typedef struct DecklinkAudioCaptureFilter11 DecklinkAudioCaptureFilter11;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter11_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter12_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter12_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter12 DecklinkAudioCaptureFilter12;
#else
typedef struct DecklinkAudioCaptureFilter12 DecklinkAudioCaptureFilter12;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter12_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter13_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter13_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter13 DecklinkAudioCaptureFilter13;
#else
typedef struct DecklinkAudioCaptureFilter13 DecklinkAudioCaptureFilter13;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter13_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter14_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter14_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter14 DecklinkAudioCaptureFilter14;
#else
typedef struct DecklinkAudioCaptureFilter14 DecklinkAudioCaptureFilter14;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter14_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter15_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter15_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter15 DecklinkAudioCaptureFilter15;
#else
typedef struct DecklinkAudioCaptureFilter15 DecklinkAudioCaptureFilter15;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter15_FWD_DEFINED__ */


#ifndef __DecklinkAudioCaptureFilter16_FWD_DEFINED__
#define __DecklinkAudioCaptureFilter16_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioCaptureFilter16 DecklinkAudioCaptureFilter16;
#else
typedef struct DecklinkAudioCaptureFilter16 DecklinkAudioCaptureFilter16;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioCaptureFilter16_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter2_FWD_DEFINED__
#define __DecklinkVideoRenderFilter2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter2 DecklinkVideoRenderFilter2;
#else
typedef struct DecklinkVideoRenderFilter2 DecklinkVideoRenderFilter2;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter2_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter3_FWD_DEFINED__
#define __DecklinkVideoRenderFilter3_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter3 DecklinkVideoRenderFilter3;
#else
typedef struct DecklinkVideoRenderFilter3 DecklinkVideoRenderFilter3;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter3_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter4_FWD_DEFINED__
#define __DecklinkVideoRenderFilter4_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter4 DecklinkVideoRenderFilter4;
#else
typedef struct DecklinkVideoRenderFilter4 DecklinkVideoRenderFilter4;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter4_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter5_FWD_DEFINED__
#define __DecklinkVideoRenderFilter5_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter5 DecklinkVideoRenderFilter5;
#else
typedef struct DecklinkVideoRenderFilter5 DecklinkVideoRenderFilter5;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter5_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter6_FWD_DEFINED__
#define __DecklinkVideoRenderFilter6_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter6 DecklinkVideoRenderFilter6;
#else
typedef struct DecklinkVideoRenderFilter6 DecklinkVideoRenderFilter6;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter6_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter7_FWD_DEFINED__
#define __DecklinkVideoRenderFilter7_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter7 DecklinkVideoRenderFilter7;
#else
typedef struct DecklinkVideoRenderFilter7 DecklinkVideoRenderFilter7;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter7_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter8_FWD_DEFINED__
#define __DecklinkVideoRenderFilter8_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter8 DecklinkVideoRenderFilter8;
#else
typedef struct DecklinkVideoRenderFilter8 DecklinkVideoRenderFilter8;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter8_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter9_FWD_DEFINED__
#define __DecklinkVideoRenderFilter9_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter9 DecklinkVideoRenderFilter9;
#else
typedef struct DecklinkVideoRenderFilter9 DecklinkVideoRenderFilter9;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter9_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter10_FWD_DEFINED__
#define __DecklinkVideoRenderFilter10_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter10 DecklinkVideoRenderFilter10;
#else
typedef struct DecklinkVideoRenderFilter10 DecklinkVideoRenderFilter10;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter10_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter11_FWD_DEFINED__
#define __DecklinkVideoRenderFilter11_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter11 DecklinkVideoRenderFilter11;
#else
typedef struct DecklinkVideoRenderFilter11 DecklinkVideoRenderFilter11;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter11_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter12_FWD_DEFINED__
#define __DecklinkVideoRenderFilter12_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter12 DecklinkVideoRenderFilter12;
#else
typedef struct DecklinkVideoRenderFilter12 DecklinkVideoRenderFilter12;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter12_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter13_FWD_DEFINED__
#define __DecklinkVideoRenderFilter13_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter13 DecklinkVideoRenderFilter13;
#else
typedef struct DecklinkVideoRenderFilter13 DecklinkVideoRenderFilter13;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter13_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter14_FWD_DEFINED__
#define __DecklinkVideoRenderFilter14_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter14 DecklinkVideoRenderFilter14;
#else
typedef struct DecklinkVideoRenderFilter14 DecklinkVideoRenderFilter14;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter14_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter15_FWD_DEFINED__
#define __DecklinkVideoRenderFilter15_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter15 DecklinkVideoRenderFilter15;
#else
typedef struct DecklinkVideoRenderFilter15 DecklinkVideoRenderFilter15;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter15_FWD_DEFINED__ */


#ifndef __DecklinkVideoRenderFilter16_FWD_DEFINED__
#define __DecklinkVideoRenderFilter16_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkVideoRenderFilter16 DecklinkVideoRenderFilter16;
#else
typedef struct DecklinkVideoRenderFilter16 DecklinkVideoRenderFilter16;
#endif /* __cplusplus */

#endif 	/* __DecklinkVideoRenderFilter16_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter2_FWD_DEFINED__
#define __DecklinkAudioRenderFilter2_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter2 DecklinkAudioRenderFilter2;
#else
typedef struct DecklinkAudioRenderFilter2 DecklinkAudioRenderFilter2;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter2_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter3_FWD_DEFINED__
#define __DecklinkAudioRenderFilter3_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter3 DecklinkAudioRenderFilter3;
#else
typedef struct DecklinkAudioRenderFilter3 DecklinkAudioRenderFilter3;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter3_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter4_FWD_DEFINED__
#define __DecklinkAudioRenderFilter4_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter4 DecklinkAudioRenderFilter4;
#else
typedef struct DecklinkAudioRenderFilter4 DecklinkAudioRenderFilter4;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter4_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter5_FWD_DEFINED__
#define __DecklinkAudioRenderFilter5_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter5 DecklinkAudioRenderFilter5;
#else
typedef struct DecklinkAudioRenderFilter5 DecklinkAudioRenderFilter5;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter5_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter6_FWD_DEFINED__
#define __DecklinkAudioRenderFilter6_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter6 DecklinkAudioRenderFilter6;
#else
typedef struct DecklinkAudioRenderFilter6 DecklinkAudioRenderFilter6;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter6_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter7_FWD_DEFINED__
#define __DecklinkAudioRenderFilter7_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter7 DecklinkAudioRenderFilter7;
#else
typedef struct DecklinkAudioRenderFilter7 DecklinkAudioRenderFilter7;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter7_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter8_FWD_DEFINED__
#define __DecklinkAudioRenderFilter8_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter8 DecklinkAudioRenderFilter8;
#else
typedef struct DecklinkAudioRenderFilter8 DecklinkAudioRenderFilter8;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter8_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter9_FWD_DEFINED__
#define __DecklinkAudioRenderFilter9_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter9 DecklinkAudioRenderFilter9;
#else
typedef struct DecklinkAudioRenderFilter9 DecklinkAudioRenderFilter9;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter9_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter10_FWD_DEFINED__
#define __DecklinkAudioRenderFilter10_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter10 DecklinkAudioRenderFilter10;
#else
typedef struct DecklinkAudioRenderFilter10 DecklinkAudioRenderFilter10;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter10_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter11_FWD_DEFINED__
#define __DecklinkAudioRenderFilter11_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter11 DecklinkAudioRenderFilter11;
#else
typedef struct DecklinkAudioRenderFilter11 DecklinkAudioRenderFilter11;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter11_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter12_FWD_DEFINED__
#define __DecklinkAudioRenderFilter12_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter12 DecklinkAudioRenderFilter12;
#else
typedef struct DecklinkAudioRenderFilter12 DecklinkAudioRenderFilter12;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter12_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter13_FWD_DEFINED__
#define __DecklinkAudioRenderFilter13_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter13 DecklinkAudioRenderFilter13;
#else
typedef struct DecklinkAudioRenderFilter13 DecklinkAudioRenderFilter13;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter13_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter14_FWD_DEFINED__
#define __DecklinkAudioRenderFilter14_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter14 DecklinkAudioRenderFilter14;
#else
typedef struct DecklinkAudioRenderFilter14 DecklinkAudioRenderFilter14;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter14_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter15_FWD_DEFINED__
#define __DecklinkAudioRenderFilter15_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter15 DecklinkAudioRenderFilter15;
#else
typedef struct DecklinkAudioRenderFilter15 DecklinkAudioRenderFilter15;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter15_FWD_DEFINED__ */


#ifndef __DecklinkAudioRenderFilter16_FWD_DEFINED__
#define __DecklinkAudioRenderFilter16_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkAudioRenderFilter16 DecklinkAudioRenderFilter16;
#else
typedef struct DecklinkAudioRenderFilter16 DecklinkAudioRenderFilter16;
#endif /* __cplusplus */

#endif 	/* __DecklinkAudioRenderFilter16_FWD_DEFINED__ */


#ifndef __DecklinkUpsampleFilter_FWD_DEFINED__
#define __DecklinkUpsampleFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkUpsampleFilter DecklinkUpsampleFilter;
#else
typedef struct DecklinkUpsampleFilter DecklinkUpsampleFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkUpsampleFilter_FWD_DEFINED__ */


#ifndef __DecklinkEffectsFilter_FWD_DEFINED__
#define __DecklinkEffectsFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkEffectsFilter DecklinkEffectsFilter;
#else
typedef struct DecklinkEffectsFilter DecklinkEffectsFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkEffectsFilter_FWD_DEFINED__ */


#ifndef __DecklinkEffectsProperties_FWD_DEFINED__
#define __DecklinkEffectsProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkEffectsProperties DecklinkEffectsProperties;
#else
typedef struct DecklinkEffectsProperties DecklinkEffectsProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkEffectsProperties_FWD_DEFINED__ */


#ifndef __DecklinkMJPEGEncoderFilter_FWD_DEFINED__
#define __DecklinkMJPEGEncoderFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkMJPEGEncoderFilter DecklinkMJPEGEncoderFilter;
#else
typedef struct DecklinkMJPEGEncoderFilter DecklinkMJPEGEncoderFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkMJPEGEncoderFilter_FWD_DEFINED__ */


#ifndef __DecklinkMJPEGEncoderProperties_FWD_DEFINED__
#define __DecklinkMJPEGEncoderProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkMJPEGEncoderProperties DecklinkMJPEGEncoderProperties;
#else
typedef struct DecklinkMJPEGEncoderProperties DecklinkMJPEGEncoderProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkMJPEGEncoderProperties_FWD_DEFINED__ */


#ifndef __DecklinkMJPEGDecoderFilter_FWD_DEFINED__
#define __DecklinkMJPEGDecoderFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkMJPEGDecoderFilter DecklinkMJPEGDecoderFilter;
#else
typedef struct DecklinkMJPEGDecoderFilter DecklinkMJPEGDecoderFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkMJPEGDecoderFilter_FWD_DEFINED__ */


#ifndef __DecklinkMJPEGDecoderProperties_FWD_DEFINED__
#define __DecklinkMJPEGDecoderProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkMJPEGDecoderProperties DecklinkMJPEGDecoderProperties;
#else
typedef struct DecklinkMJPEGDecoderProperties DecklinkMJPEGDecoderProperties;
#endif /* __cplusplus */

#endif 	/* __DecklinkMJPEGDecoderProperties_FWD_DEFINED__ */


#ifndef __DecklinkStillSequenceSourceFilter_FWD_DEFINED__
#define __DecklinkStillSequenceSourceFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkStillSequenceSourceFilter DecklinkStillSequenceSourceFilter;
#else
typedef struct DecklinkStillSequenceSourceFilter DecklinkStillSequenceSourceFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkStillSequenceSourceFilter_FWD_DEFINED__ */


#ifndef __DecklinkStillSequenceSinkFilter_FWD_DEFINED__
#define __DecklinkStillSequenceSinkFilter_FWD_DEFINED__

#ifdef __cplusplus
typedef class DecklinkStillSequenceSinkFilter DecklinkStillSequenceSinkFilter;
#else
typedef struct DecklinkStillSequenceSinkFilter DecklinkStillSequenceSinkFilter;
#endif /* __cplusplus */

#endif 	/* __DecklinkStillSequenceSinkFilter_FWD_DEFINED__ */


#ifndef __MEDIASUBTYPE_V210_FWD_DEFINED__
#define __MEDIASUBTYPE_V210_FWD_DEFINED__
typedef interface MEDIASUBTYPE_V210 MEDIASUBTYPE_V210;
#endif 	/* __MEDIASUBTYPE_V210_FWD_DEFINED__ */


#ifndef __MEDIASUBTYPE_v210a_FWD_DEFINED__
#define __MEDIASUBTYPE_v210a_FWD_DEFINED__
typedef interface MEDIASUBTYPE_v210a MEDIASUBTYPE_v210a;
#endif 	/* __MEDIASUBTYPE_v210a_FWD_DEFINED__ */


#ifndef __MEDIASUBTYPE_r210_FWD_DEFINED__
#define __MEDIASUBTYPE_r210_FWD_DEFINED__
typedef interface MEDIASUBTYPE_r210 MEDIASUBTYPE_r210;
#endif 	/* __MEDIASUBTYPE_r210_FWD_DEFINED__ */


#ifndef __MEDIASUBTYPE_HDYC_FWD_DEFINED__
#define __MEDIASUBTYPE_HDYC_FWD_DEFINED__
typedef interface MEDIASUBTYPE_HDYC MEDIASUBTYPE_HDYC;
#endif 	/* __MEDIASUBTYPE_HDYC_FWD_DEFINED__ */


#ifndef __IDecklinkKeyer_FWD_DEFINED__
#define __IDecklinkKeyer_FWD_DEFINED__
typedef interface IDecklinkKeyer IDecklinkKeyer;
#endif 	/* __IDecklinkKeyer_FWD_DEFINED__ */


#ifndef __IADecklinkKeyer_FWD_DEFINED__
#define __IADecklinkKeyer_FWD_DEFINED__
typedef interface IADecklinkKeyer IADecklinkKeyer;
#endif 	/* __IADecklinkKeyer_FWD_DEFINED__ */


#ifndef __IDecklinkRawDeviceControl_FWD_DEFINED__
#define __IDecklinkRawDeviceControl_FWD_DEFINED__
typedef interface IDecklinkRawDeviceControl IDecklinkRawDeviceControl;
#endif 	/* __IDecklinkRawDeviceControl_FWD_DEFINED__ */


#ifndef __IADecklinkRawDeviceControl_FWD_DEFINED__
#define __IADecklinkRawDeviceControl_FWD_DEFINED__
typedef interface IADecklinkRawDeviceControl IADecklinkRawDeviceControl;
#endif 	/* __IADecklinkRawDeviceControl_FWD_DEFINED__ */


#ifndef __IDecklinkStatus_FWD_DEFINED__
#define __IDecklinkStatus_FWD_DEFINED__
typedef interface IDecklinkStatus IDecklinkStatus;
#endif 	/* __IDecklinkStatus_FWD_DEFINED__ */


#ifndef __IADecklinkStatus_FWD_DEFINED__
#define __IADecklinkStatus_FWD_DEFINED__
typedef interface IADecklinkStatus IADecklinkStatus;
#endif 	/* __IADecklinkStatus_FWD_DEFINED__ */


#ifndef __IDecklinkCaptureBanner_FWD_DEFINED__
#define __IDecklinkCaptureBanner_FWD_DEFINED__
typedef interface IDecklinkCaptureBanner IDecklinkCaptureBanner;
#endif 	/* __IDecklinkCaptureBanner_FWD_DEFINED__ */


#ifndef __IADecklinkCaptureBanner_FWD_DEFINED__
#define __IADecklinkCaptureBanner_FWD_DEFINED__
typedef interface IADecklinkCaptureBanner IADecklinkCaptureBanner;
#endif 	/* __IADecklinkCaptureBanner_FWD_DEFINED__ */


#ifndef __IDecklinkIOControl_FWD_DEFINED__
#define __IDecklinkIOControl_FWD_DEFINED__
typedef interface IDecklinkIOControl IDecklinkIOControl;
#endif 	/* __IDecklinkIOControl_FWD_DEFINED__ */


#ifndef __IADecklinkIOControl_FWD_DEFINED__
#define __IADecklinkIOControl_FWD_DEFINED__
typedef interface IADecklinkIOControl IADecklinkIOControl;
#endif 	/* __IADecklinkIOControl_FWD_DEFINED__ */


#ifndef __IDecklinkMediaSample_FWD_DEFINED__
#define __IDecklinkMediaSample_FWD_DEFINED__
typedef interface IDecklinkMediaSample IDecklinkMediaSample;
#endif 	/* __IDecklinkMediaSample_FWD_DEFINED__ */


#ifndef __IADecklinkMediaSample_FWD_DEFINED__
#define __IADecklinkMediaSample_FWD_DEFINED__
typedef interface IADecklinkMediaSample IADecklinkMediaSample;
#endif 	/* __IADecklinkMediaSample_FWD_DEFINED__ */


#ifndef __IDecklinkSampleGrabberCB_FWD_DEFINED__
#define __IDecklinkSampleGrabberCB_FWD_DEFINED__
typedef interface IDecklinkSampleGrabberCB IDecklinkSampleGrabberCB;
#endif 	/* __IDecklinkSampleGrabberCB_FWD_DEFINED__ */


#ifndef __IDecklinkSampleGrabber_FWD_DEFINED__
#define __IDecklinkSampleGrabber_FWD_DEFINED__
typedef interface IDecklinkSampleGrabber IDecklinkSampleGrabber;
#endif 	/* __IDecklinkSampleGrabber_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "strmif.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __DecklinkPublicLib_LIBRARY_DEFINED__
#define __DecklinkPublicLib_LIBRARY_DEFINED__

/* library DecklinkPublicLib */
/* [helpstring][version][uuid] */ 

typedef struct DecklinkRawCommandAsync
    {
    byte *command;
    UINT lenCommand;
    long asyncResult;
    byte *response;
    UINT lenResponse;
    long commandComplete;
    } 	DecklinkRawCommandAsync;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0417_0001
    {	DECKLINK_INPUT_NONE	= 0,
	DECKLINK_INPUT_PRESENT	= DECKLINK_INPUT_NONE + 1,
	DECKLINK_INPUT_MAX	= DECKLINK_INPUT_PRESENT + 1
    } 	DECKLINK_INPUT;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0417_0002
    {	DECKLINK_GENLOCK_NOTSUPPORTED	= 0,
	DECKLINK_GENLOCK_NOTCONNECTED	= DECKLINK_GENLOCK_NOTSUPPORTED + 1,
	DECKLINK_GENLOCK_LOCKED	= DECKLINK_GENLOCK_NOTCONNECTED + 1,
	DECKLINK_GENLOCK_NOTLOCKED	= DECKLINK_GENLOCK_LOCKED + 1,
	DECKLINK_GENLOCK_MAX	= DECKLINK_GENLOCK_NOTLOCKED + 1
    } 	DECKLINK_GENLOCK;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0001
    {	DECKLINK_BLACKINCAPTURE_NONE	= 0,
	DECKLINK_BLACKINCAPTURE_DIGITAL	= DECKLINK_BLACKINCAPTURE_NONE + 1,
	DECKLINK_BLACKINCAPTURE_ANALOGUE	= DECKLINK_BLACKINCAPTURE_DIGITAL + 1,
	DECKLINK_BLACKINCAPTURE_MAX	= DECKLINK_BLACKINCAPTURE_ANALOGUE + 1
    } 	DECKLINK_BLACKINCAPTURE;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0002
    {	DECKLINK_HDDOWNCONVERSION_OFF	= 0,
	DECKLINK_HDDOWNCONVERSION_LB16X9	= DECKLINK_HDDOWNCONVERSION_OFF + 1,
	DECKLINK_HDDOWNCONVERSION_ANA	= DECKLINK_HDDOWNCONVERSION_LB16X9 + 1,
	DECKLINK_HDDOWNCONVERSION_CENTER	= DECKLINK_HDDOWNCONVERSION_ANA + 1,
	DECKLINK_HDDOWNCONVERSION_MAX	= DECKLINK_HDDOWNCONVERSION_CENTER + 1
    } 	DECKLINK_HDDOWNCONVERSION;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0003
    {	DECKLINK_AUDIOINPUTSOURCE_EMBEDDED	= 0,
	DECKLINK_AUDIOINPUTSOURCE_AESEBU	= DECKLINK_AUDIOINPUTSOURCE_EMBEDDED + 1,
	DECKLINK_AUDIOINPUTSOURCE_ANALOGUE	= DECKLINK_AUDIOINPUTSOURCE_AESEBU + 1,
	DECKLINK_AUDIOINPUTSOURCE_MAX	= DECKLINK_AUDIOINPUTSOURCE_ANALOGUE + 1,
	DECKLINK_AUDIOINPUTSOURCE_SDI	= DECKLINK_AUDIOINPUTSOURCE_EMBEDDED
    } 	DECKLINK_AUDIOINPUTSOURCE;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0004
    {	DECKLINK_IOFEATURES_SUPPORTSRGB10BITCAPTURE	= 1 << 0,
	DECKLINK_IOFEATURES_SUPPORTSRGB10BITPLAYBACK	= 1 << 1,
	DECKLINK_IOFEATURES_SUPPORTSINTERNALKEY	= 1 << 4,
	DECKLINK_IOFEATURES_SUPPORTSEXTERNALKEY	= 1 << 5,
	DECKLINK_IOFEATURES_HASCOMPONENTVIDEOOUTPUT	= 1 << 6,
	DECKLINK_IOFEATURES_HASCOMPOSITEVIDEOOUTPUT	= 1 << 7,
	DECKLINK_IOFEATURES_HASDIGITALVIDEOOUTPUT	= 1 << 8,
	DECKLINK_IOFEATURES_HASDVIVIDEOOUTPUT	= 1 << 9,
	DECKLINK_IOFEATURES_HASCOMPONENTVIDEOINPUT	= 1 << 10,
	DECKLINK_IOFEATURES_HASCOMPOSITEVIDEOINPUT	= 1 << 11,
	DECKLINK_IOFEATURES_HASDIGITALVIDEOINPUT	= 1 << 12,
	DECKLINK_IOFEATURES_HASDUALLINKOUTPUT	= 1 << 13,
	DECKLINK_IOFEATURES_HASDUALLINKINPUT	= 1 << 14,
	DECKLINK_IOFEATURES_SUPPORTSHD	= 1 << 15,
	DECKLINK_IOFEATURES_SUPPORTS2KOUTPUT	= 1 << 16,
	DECKLINK_IOFEATURES_SUPPORTSHDDOWNCONVERSION	= 1 << 17,
	DECKLINK_IOFEATURES_HASAESAUDIOINPUT	= 1 << 18,
	DECKLINK_IOFEATURES_HASANALOGUEAUDIOINPUT	= 1 << 19,
	DECKLINK_IOFEATURES_HASSVIDEOINPUT	= 1 << 20,
	DECKLINK_IOFEATURES_HASSVIDEOOUTPUT	= 1 << 21,
	DECKLINK_IOFEATURES_SUPPORTSMULTICAMERAINPUT	= 1 << 22,
	DECKLINK_IOFEATURES_HASRS422SERIALPORT	= 1 << 23,
	DECKLINK_IOFEATURES_HASHDMIINPUT	= 1 << 24,
	DECKLINK_IOFEATURES_HASHDMIOUTPUT	= 1 << 25,
	DECKLINK_IOFEATURES_MAX	= DECKLINK_IOFEATURES_HASHDMIOUTPUT + 1
    } 	DECKLINK_IOFEATURES;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0005
    {	DECKLINK_TIMECODESOURCE_VITC	= 0,
	DECKLINK_TIMECODESOURCE_HANC	= DECKLINK_TIMECODESOURCE_VITC + 1,
	DECKLINK_TIMECODESOURCE_MAX	= DECKLINK_TIMECODESOURCE_HANC + 1
    } 	DECKLINK_TIMECODESOURCE;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0006
    {	DECKLINK_VIDEOINPUT_SDI	= 0,
	DECKLINK_VIDEOINPUT_COMPONENT	= DECKLINK_VIDEOINPUT_SDI + 1,
	DECKLINK_VIDEOINPUT_COMPOSITE	= DECKLINK_VIDEOINPUT_COMPONENT + 1,
	DECKLINK_VIDEOINPUT_SVIDEO	= DECKLINK_VIDEOINPUT_COMPOSITE + 1,
	DECKLINK_VIDEOINPUT_HDMI	= DECKLINK_VIDEOINPUT_SVIDEO + 1,
	DECKLINK_VIDEOINPUT_MAX	= DECKLINK_VIDEOINPUT_HDMI + 1
    } 	DECKLINK_VIDEOINPUT;

typedef /* [v1_enum] */ 
enum __MIDL___MIDL_itf_DecklinkInterface_0421_0007
    {	DECKLINK_VIDEOOUTPUT_COMPONENT	= 0,
	DECKLINK_VIDEOOUTPUT_COMPOSITE	= DECKLINK_VIDEOOUTPUT_COMPONENT + 1,
	DECKLINK_VIDEOOUTPUT_SVIDEO	= DECKLINK_VIDEOOUTPUT_COMPOSITE + 1,
	DECKLINK_VIDEOOUTPUT_MAX	= DECKLINK_VIDEOOUTPUT_SVIDEO + 1
    } 	DECKLINK_VIDEOOUTPUT;


DEFINE_GUID(LIBID_DecklinkPublicLib,0x1469D378,0x8829,0x4ff0,0x9B,0x3B,0x07,0xDD,0x5B,0x16,0xF3,0xCB);

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter,0x44A8B5C7,0x13B6,0x4211,0xBD,0x40,0x35,0xB6,0x29,0xD9,0xE6,0xDF);

#ifdef __cplusplus

class DECLSPEC_UUID("44A8B5C7-13B6-4211-BD40-35B629D9E6DF")
DecklinkVideoCaptureFilter;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureProperties,0x50D29FCF,0x70ED,0x4155,0x9B,0x2A,0x91,0xF2,0xCE,0x9A,0x86,0xBA);

#ifdef __cplusplus

class DECLSPEC_UUID("50D29FCF-70ED-4155-9B2A-91F2CE9A86BA")
DecklinkVideoCaptureProperties;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureProperties2,0x6296A3EB,0x08FF,0x421e,0xB5,0xAC,0x6B,0xC8,0x34,0xCF,0x4D,0xB6);

#ifdef __cplusplus

class DECLSPEC_UUID("6296A3EB-08FF-421e-B5AC-6BC834CF4DB6")
DecklinkVideoCaptureProperties2;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter,0xAAA22F7E,0x5AA0,0x49d9,0x8C,0x8D,0xB5,0x2B,0x1A,0xA9,0x2E,0xB7);

#ifdef __cplusplus

class DECLSPEC_UUID("AAA22F7E-5AA0-49d9-8C8D-B52B1AA92EB7")
DecklinkAudioCaptureFilter;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureProperties,0xED4418E7,0x582D,0x4759,0xAE,0x07,0x8C,0xA7,0xF7,0x71,0x42,0x7F);

#ifdef __cplusplus

class DECLSPEC_UUID("ED4418E7-582D-4759-AE07-8CA7F771427F")
DecklinkAudioCaptureProperties;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureProperties2,0x8869832C,0xFDE3,0x468e,0xB0,0xD2,0x53,0xBF,0x2D,0x59,0xC1,0x7A);

#ifdef __cplusplus

class DECLSPEC_UUID("8869832C-FDE3-468e-B0D2-53BF2D59C17A")
DecklinkAudioCaptureProperties2;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter,0xCEB13CC8,0x3591,0x45a5,0xBA,0x0F,0x20,0xE9,0xA1,0xD7,0x2F,0x76);

#ifdef __cplusplus

class DECLSPEC_UUID("CEB13CC8-3591-45a5-BA0F-20E9A1D72F76")
DecklinkVideoRenderFilter;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderProperties,0x98C36C7C,0x5985,0x46c4,0x90,0x9C,0x0E,0xB7,0xBD,0x0C,0x60,0xF7);

#ifdef __cplusplus

class DECLSPEC_UUID("98C36C7C-5985-46c4-909C-0EB7BD0C60F7")
DecklinkVideoRenderProperties;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter,0x19FA8CC3,0x56CE,0x46ab,0x82,0x5D,0x5C,0xE1,0xA3,0x9B,0x13,0x7A);

#ifdef __cplusplus

class DECLSPEC_UUID("19FA8CC3-56CE-46ab-825D-5CE1A39B137A")
DecklinkAudioRenderFilter;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderProperties,0x222A4295,0xE98B,0x4af2,0x90,0x63,0x34,0x0E,0x91,0xBE,0x7E,0x68);

#ifdef __cplusplus

class DECLSPEC_UUID("222A4295-E98B-4af2-9063-340E91BE7E68")
DecklinkAudioRenderProperties;
#endif

DEFINE_GUID(CLSID_DecklinkCaptureFilter,0x472BB322,0x7639,0x412e,0xAF,0x90,0xF8,0x6F,0x1A,0xD6,0xA2,0x2F);

#ifdef __cplusplus

class DECLSPEC_UUID("472BB322-7639-412e-AF90-F86F1AD6A22F")
DecklinkCaptureFilter;
#endif

DEFINE_GUID(CLSID_DecklinkRenderFilter,0x189B7800,0x82A0,0x4e92,0xA2,0xE9,0x2C,0x8E,0x4A,0x15,0xC3,0xE3);

#ifdef __cplusplus

class DECLSPEC_UUID("189B7800-82A0-4e92-A2E9-2C8E4A15C3E3")
DecklinkRenderFilter;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter2,0xCE3FF814,0x04C1,0x4827,0x9F,0x18,0x42,0x62,0x03,0xE9,0xB1,0xB3);

#ifdef __cplusplus

class DECLSPEC_UUID("CE3FF814-04C1-4827-9F18-426203E9B1B3")
DecklinkVideoCaptureFilter2;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter3,0x20722FC4,0x9EBC,0x47b9,0x80,0xB4,0x6A,0x2E,0xD4,0xD2,0x7E,0xCF);

#ifdef __cplusplus

class DECLSPEC_UUID("20722FC4-9EBC-47b9-80B4-6A2ED4D27ECF")
DecklinkVideoCaptureFilter3;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter4,0xB3980D18,0x10D4,0x4045,0x9A,0xF7,0x91,0xEF,0x33,0x0A,0xEB,0xF2);

#ifdef __cplusplus

class DECLSPEC_UUID("B3980D18-10D4-4045-9AF7-91EF330AEBF2")
DecklinkVideoCaptureFilter4;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter5,0x929CE8E6,0x96DB,0x4fe0,0x98,0x0A,0x83,0xDA,0xB2,0xD2,0xAF,0x31);

#ifdef __cplusplus

class DECLSPEC_UUID("929CE8E6-96DB-4fe0-980A-83DAB2D2AF31")
DecklinkVideoCaptureFilter5;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter6,0x681439FF,0xEB76,0x45dd,0xBF,0x51,0x80,0xD7,0xC6,0x0F,0x57,0x27);

#ifdef __cplusplus

class DECLSPEC_UUID("681439FF-EB76-45dd-BF51-80D7C60F5727")
DecklinkVideoCaptureFilter6;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter7,0xDE5D8755,0x421A,0x43f2,0x88,0x47,0xE5,0xA9,0xAC,0xB4,0x4D,0x04);

#ifdef __cplusplus

class DECLSPEC_UUID("DE5D8755-421A-43f2-8847-E5A9ACB44D04")
DecklinkVideoCaptureFilter7;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter8,0x976AC924,0xE89A,0x4a20,0xB6,0x92,0x48,0x23,0x46,0xE2,0x4C,0x71);

#ifdef __cplusplus

class DECLSPEC_UUID("976AC924-E89A-4a20-B692-482346E24C71")
DecklinkVideoCaptureFilter8;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter9,0x43D9805A,0x5EA9,0x4f81,0x97,0xB1,0xC7,0x18,0x89,0x15,0x4A,0x75);

#ifdef __cplusplus

class DECLSPEC_UUID("43D9805A-5EA9-4f81-97B1-C71889154A75")
DecklinkVideoCaptureFilter9;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter10,0x651A64B6,0x4675,0x4220,0x9D,0xC2,0x9E,0x5F,0x84,0x83,0x20,0x36);

#ifdef __cplusplus

class DECLSPEC_UUID("651A64B6-4675-4220-9DC2-9E5F84832036")
DecklinkVideoCaptureFilter10;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter11,0x6AF011C1,0x6576,0x40b6,0x80,0x70,0xF6,0xB6,0x5C,0x42,0xE2,0x91);

#ifdef __cplusplus

class DECLSPEC_UUID("6AF011C1-6576-40b6-8070-F6B65C42E291")
DecklinkVideoCaptureFilter11;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter12,0x8A599218,0xFBF6,0x40b5,0x90,0x9D,0x5D,0x14,0xF7,0x0E,0x88,0xE3);

#ifdef __cplusplus

class DECLSPEC_UUID("8A599218-FBF6-40b5-909D-5D14F70E88E3")
DecklinkVideoCaptureFilter12;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter13,0x8AE58702,0x3ADF,0x430d,0x8A,0xB3,0xC9,0x78,0xB2,0x32,0x77,0x22);

#ifdef __cplusplus

class DECLSPEC_UUID("8AE58702-3ADF-430d-8AB3-C978B2327722")
DecklinkVideoCaptureFilter13;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter14,0x9AE1A80D,0x7265,0x47f7,0xA3,0x1C,0x79,0x1C,0xBA,0x43,0x9C,0xD4);

#ifdef __cplusplus

class DECLSPEC_UUID("9AE1A80D-7265-47f7-A31C-791CBA439CD4")
DecklinkVideoCaptureFilter14;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter15,0xA8A62D5F,0x9CEA,0x484a,0x8E,0x8D,0x46,0xF8,0x49,0x9D,0x65,0xBF);

#ifdef __cplusplus

class DECLSPEC_UUID("A8A62D5F-9CEA-484a-8E8D-46F8499D65BF")
DecklinkVideoCaptureFilter15;
#endif

DEFINE_GUID(CLSID_DecklinkVideoCaptureFilter16,0xB47B720F,0x6F80,0x404f,0xA0,0x29,0xF3,0x1F,0x16,0xD9,0x24,0x66);

#ifdef __cplusplus

class DECLSPEC_UUID("B47B720F-6F80-404f-A029-F31F16D92466")
DecklinkVideoCaptureFilter16;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter2,0x1BCC3EF4,0x724F,0x4a45,0xB6,0x1D,0x8D,0x4B,0xBF,0x32,0xC5,0xBF);

#ifdef __cplusplus

class DECLSPEC_UUID("1BCC3EF4-724F-4a45-B61D-8D4BBF32C5BF")
DecklinkAudioCaptureFilter2;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter3,0xBC90EE8C,0xF8DC,0x4776,0x8D,0xCF,0x24,0x92,0x9C,0x13,0xF9,0xD2);

#ifdef __cplusplus

class DECLSPEC_UUID("BC90EE8C-F8DC-4776-8DCF-24929C13F9D2")
DecklinkAudioCaptureFilter3;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter4,0x1EF51542,0xB849,0x4337,0xB7,0xAE,0xC9,0x80,0xC1,0x3F,0x86,0xBF);

#ifdef __cplusplus

class DECLSPEC_UUID("1EF51542-B849-4337-B7AE-C980C13F86BF")
DecklinkAudioCaptureFilter4;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter5,0xDE6DB48D,0x66EE,0x477a,0xBE,0x4B,0x52,0x2B,0x22,0x53,0xCD,0x95);

#ifdef __cplusplus

class DECLSPEC_UUID("DE6DB48D-66EE-477a-BE4B-522B2253CD95")
DecklinkAudioCaptureFilter5;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter6,0xB8E0C8A1,0x777D,0x4727,0xA5,0x42,0x6D,0xF0,0xDF,0x1E,0x1D,0x1C);

#ifdef __cplusplus

class DECLSPEC_UUID("B8E0C8A1-777D-4727-A542-6DF0DF1E1D1C")
DecklinkAudioCaptureFilter6;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter7,0xED1441F5,0xA132,0x44e7,0x90,0x27,0x14,0xDB,0x56,0x74,0x14,0x9B);

#ifdef __cplusplus

class DECLSPEC_UUID("ED1441F5-A132-44e7-9027-14DB5674149B")
DecklinkAudioCaptureFilter7;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter8,0x37BD18AA,0xF5BD,0x434c,0xB0,0xC5,0x7A,0xE5,0x70,0xC3,0x77,0xA5);

#ifdef __cplusplus

class DECLSPEC_UUID("37BD18AA-F5BD-434c-B0C5-7AE570C377A5")
DecklinkAudioCaptureFilter8;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter9,0x04D8F1C7,0x96B5,0x4991,0xA9,0xE1,0x1F,0x07,0xD8,0xE8,0xBE,0x6F);

#ifdef __cplusplus

class DECLSPEC_UUID("04D8F1C7-96B5-4991-A9E1-1F07D8E8BE6F")
DecklinkAudioCaptureFilter9;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter10,0x12BA1627,0xB2CF,0x47b4,0xBA,0x5F,0x04,0xF2,0x90,0x0A,0x84,0x9C);

#ifdef __cplusplus

class DECLSPEC_UUID("12BA1627-B2CF-47b4-BA5F-04F2900A849C")
DecklinkAudioCaptureFilter10;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter11,0xCB71FDBC,0x6304,0x463d,0x8B,0x7F,0x96,0xF8,0xBE,0xDA,0x6F,0x7A);

#ifdef __cplusplus

class DECLSPEC_UUID("CB71FDBC-6304-463d-8B7F-96F8BEDA6F7A")
DecklinkAudioCaptureFilter11;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter12,0xD092C151,0xA35A,0x4995,0x97,0x41,0xCA,0x3E,0x0B,0x06,0xA0,0xB2);

#ifdef __cplusplus

class DECLSPEC_UUID("D092C151-A35A-4995-9741-CA3E0B06A0B2")
DecklinkAudioCaptureFilter12;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter13,0xD8034EE1,0x6A0D,0x4bed,0x9A,0xA9,0x2E,0xEF,0x27,0x13,0x82,0x3E);

#ifdef __cplusplus

class DECLSPEC_UUID("D8034EE1-6A0D-4bed-9AA9-2EEF2713823E")
DecklinkAudioCaptureFilter13;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter14,0xEECE0424,0xB1E1,0x4037,0x81,0xC4,0xAD,0xCD,0x9C,0x36,0xA1,0x0A);

#ifdef __cplusplus

class DECLSPEC_UUID("EECE0424-B1E1-4037-81C4-ADCD9C36A10A")
DecklinkAudioCaptureFilter14;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter15,0xF2C0ECE2,0x96CA,0x49d5,0xA7,0x23,0xCD,0xA8,0x00,0x3A,0x73,0x27);

#ifdef __cplusplus

class DECLSPEC_UUID("F2C0ECE2-96CA-49d5-A723-CDA8003A7327")
DecklinkAudioCaptureFilter15;
#endif

DEFINE_GUID(CLSID_DecklinkAudioCaptureFilter16,0xF5FFFBDC,0xBFC7,0x4fc9,0x9E,0x0D,0x83,0x63,0x28,0x6D,0xA9,0x00);

#ifdef __cplusplus

class DECLSPEC_UUID("F5FFFBDC-BFC7-4fc9-9E0D-8363286DA900")
DecklinkAudioCaptureFilter16;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter2,0x16A2E3A5,0x0C3E,0x4484,0x9E,0x78,0x3A,0xBF,0x2F,0xBE,0x3A,0xCE);

#ifdef __cplusplus

class DECLSPEC_UUID("16A2E3A5-0C3E-4484-9E78-3ABF2FBE3ACE")
DecklinkVideoRenderFilter2;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter3,0x4354ED19,0xBDE1,0x4083,0x9B,0xE7,0x99,0x1A,0xF1,0xF0,0xB5,0x27);

#ifdef __cplusplus

class DECLSPEC_UUID("4354ED19-BDE1-4083-9BE7-991AF1F0B527")
DecklinkVideoRenderFilter3;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter4,0x4546201B,0xE2B2,0x4e78,0x9B,0x1C,0xDE,0x64,0x06,0xC3,0xBE,0xFA);

#ifdef __cplusplus

class DECLSPEC_UUID("4546201B-E2B2-4e78-9B1C-DE6406C3BEFA")
DecklinkVideoRenderFilter4;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter5,0x4A5FCAED,0xCAA7,0x456e,0xB8,0xEA,0x60,0x8F,0x35,0xA6,0x8A,0x0D);

#ifdef __cplusplus

class DECLSPEC_UUID("4A5FCAED-CAA7-456e-B8EA-608F35A68A0D")
DecklinkVideoRenderFilter5;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter6,0x8128230E,0x8FC1,0x4af6,0xBB,0xF1,0x6C,0x6B,0x6E,0x7C,0x1F,0x16);

#ifdef __cplusplus

class DECLSPEC_UUID("8128230E-8FC1-4af6-BBF1-6C6B6E7C1F16")
DecklinkVideoRenderFilter6;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter7,0x6919722B,0x7329,0x4c5f,0x9F,0x68,0xBA,0x2F,0xE3,0xCF,0x1C,0x77);

#ifdef __cplusplus

class DECLSPEC_UUID("6919722B-7329-4c5f-9F68-BA2FE3CF1C77")
DecklinkVideoRenderFilter7;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter8,0x4C17A259,0x854D,0x433f,0xB0,0x87,0x9A,0xC8,0x92,0x38,0x18,0x0A);

#ifdef __cplusplus

class DECLSPEC_UUID("4C17A259-854D-433f-B087-9AC89238180A")
DecklinkVideoRenderFilter8;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter9,0x43B49DF4,0x3DF5,0x444c,0x86,0xB6,0x13,0xC2,0x96,0x0A,0x25,0x9C);

#ifdef __cplusplus

class DECLSPEC_UUID("43B49DF4-3DF5-444c-86B6-13C2960A259C")
DecklinkVideoRenderFilter9;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter10,0x4A47FF79,0x276D,0x4fa4,0xB1,0x19,0x14,0xBE,0x27,0x10,0xF6,0x84);

#ifdef __cplusplus

class DECLSPEC_UUID("4A47FF79-276D-4fa4-B119-14BE2710F684")
DecklinkVideoRenderFilter10;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter11,0x5399AC37,0x821C,0x4cd6,0x98,0x2F,0xD9,0xBE,0x96,0xA3,0x3E,0xBE);

#ifdef __cplusplus

class DECLSPEC_UUID("5399AC37-821C-4cd6-982F-D9BE96A33EBE")
DecklinkVideoRenderFilter11;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter12,0x9886854D,0x6852,0x4f72,0x81,0x19,0xA0,0x1C,0xEE,0x14,0x4C,0x06);

#ifdef __cplusplus

class DECLSPEC_UUID("9886854D-6852-4f72-8119-A01CEE144C06")
DecklinkVideoRenderFilter12;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter13,0xB539D383,0x16C4,0x4bb8,0x88,0x0D,0x38,0xD1,0xFA,0xA3,0x38,0xFD);

#ifdef __cplusplus

class DECLSPEC_UUID("B539D383-16C4-4bb8-880D-38D1FAA338FD")
DecklinkVideoRenderFilter13;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter14,0xB7C90277,0x1BB7,0x4f1d,0xBD,0xD6,0x33,0x51,0xEB,0xA8,0x0D,0x2A);

#ifdef __cplusplus

class DECLSPEC_UUID("B7C90277-1BB7-4f1d-BDD6-3351EBA80D2A")
DecklinkVideoRenderFilter14;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter15,0xBF2E4F80,0x982B,0x4ea2,0x87,0x79,0x5D,0x0B,0x5C,0xDD,0x86,0xA3);

#ifdef __cplusplus

class DECLSPEC_UUID("BF2E4F80-982B-4ea2-8779-5D0B5CDD86A3")
DecklinkVideoRenderFilter15;
#endif

DEFINE_GUID(CLSID_DecklinkVideoRenderFilter16,0xC6047434,0x6C0B,0x45b6,0xA7,0xAD,0x08,0x53,0x49,0xC5,0x44,0xA2);

#ifdef __cplusplus

class DECLSPEC_UUID("C6047434-6C0B-45b6-A7AD-085349C544A2")
DecklinkVideoRenderFilter16;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter2,0x8D09D460,0xD361,0x40bd,0xA2,0xD0,0x7E,0x09,0x4B,0x4D,0x56,0xFA);

#ifdef __cplusplus

class DECLSPEC_UUID("8D09D460-D361-40bd-A2D0-7E094B4D56FA")
DecklinkAudioRenderFilter2;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter3,0xF34B54D3,0x15B2,0x4779,0x89,0x13,0x64,0xD6,0xE6,0xC6,0x78,0x73);

#ifdef __cplusplus

class DECLSPEC_UUID("F34B54D3-15B2-4779-8913-64D6E6C67873")
DecklinkAudioRenderFilter3;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter4,0x98FC338D,0x9524,0x457c,0x91,0x6A,0x14,0x01,0x6A,0xC4,0x83,0xA8);

#ifdef __cplusplus

class DECLSPEC_UUID("98FC338D-9524-457c-916A-14016AC483A8")
DecklinkAudioRenderFilter4;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter5,0x1A06C310,0xDCD3,0x4bc3,0x8B,0xA3,0x47,0xF8,0x27,0x3A,0x50,0x9C);

#ifdef __cplusplus

class DECLSPEC_UUID("1A06C310-DCD3-4bc3-8BA3-47F8273A509C")
DecklinkAudioRenderFilter5;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter6,0x2C7D2EF4,0x2054,0x485b,0x83,0x10,0x5E,0xE8,0x30,0x59,0x55,0xC9);

#ifdef __cplusplus

class DECLSPEC_UUID("2C7D2EF4-2054-485b-8310-5EE8305955C9")
DecklinkAudioRenderFilter6;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter7,0xEF87B072,0xBCD3,0x4f4e,0xA1,0x7C,0x23,0x4C,0x73,0x59,0x26,0x31);

#ifdef __cplusplus

class DECLSPEC_UUID("EF87B072-BCD3-4f4e-A17C-234C73592631")
DecklinkAudioRenderFilter7;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter8,0xF8CFB51B,0xADE0,0x4fae,0xB9,0xA6,0x38,0xE9,0xF0,0xBB,0x29,0x19);

#ifdef __cplusplus

class DECLSPEC_UUID("F8CFB51B-ADE0-4fae-B9A6-38E9F0BB2919")
DecklinkAudioRenderFilter8;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter9,0x0986D25A,0x92A3,0x4f82,0x98,0x43,0xFB,0x34,0x40,0x46,0xDA,0x81);

#ifdef __cplusplus

class DECLSPEC_UUID("0986D25A-92A3-4f82-9843-FB344046DA81")
DecklinkAudioRenderFilter9;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter10,0x4E00C0A7,0xE5E8,0x4770,0xA6,0xCC,0xBE,0xC9,0xAA,0xFE,0x22,0xDE);

#ifdef __cplusplus

class DECLSPEC_UUID("4E00C0A7-E5E8-4770-A6CC-BEC9AAFE22DE")
DecklinkAudioRenderFilter10;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter11,0x5B988FAA,0xFD10,0x4c8b,0xB4,0x91,0x7E,0x13,0xCD,0x42,0xB6,0x4E);

#ifdef __cplusplus

class DECLSPEC_UUID("5B988FAA-FD10-4c8b-B491-7E13CD42B64E")
DecklinkAudioRenderFilter11;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter12,0x62B20A82,0x7F0B,0x4e82,0x91,0x4D,0x74,0xDC,0x22,0x9C,0x19,0x36);

#ifdef __cplusplus

class DECLSPEC_UUID("62B20A82-7F0B-4e82-914D-74DC229C1936")
DecklinkAudioRenderFilter12;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter13,0xB102C29D,0x8A9B,0x43e6,0xB9,0x2D,0xBA,0x52,0x47,0x3D,0xD2,0x11);

#ifdef __cplusplus

class DECLSPEC_UUID("B102C29D-8A9B-43e6-B92D-BA52473DD211")
DecklinkAudioRenderFilter13;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter14,0xBBBFE701,0xFE8A,0x4e6c,0xB6,0xE0,0x3C,0xD1,0xF3,0x1B,0x62,0xBD);

#ifdef __cplusplus

class DECLSPEC_UUID("BBBFE701-FE8A-4e6c-B6E0-3CD1F31B62BD")
DecklinkAudioRenderFilter14;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter15,0xD3E541A5,0x0929,0x418b,0x80,0x53,0xA1,0x64,0x67,0xAD,0xD9,0xDB);

#ifdef __cplusplus

class DECLSPEC_UUID("D3E541A5-0929-418b-8053-A16467ADD9DB")
DecklinkAudioRenderFilter15;
#endif

DEFINE_GUID(CLSID_DecklinkAudioRenderFilter16,0xD7305937,0xFC9B,0x409e,0x85,0x10,0x92,0x96,0x8D,0xEA,0x8F,0x14);

#ifdef __cplusplus

class DECLSPEC_UUID("D7305937-FC9B-409e-8510-92968DEA8F14")
DecklinkAudioRenderFilter16;
#endif

DEFINE_GUID(CLSID_DecklinkUpsampleFilter,0xF5C45F6D,0xE4DD,0x469d,0xB3,0x97,0x73,0x41,0xD6,0x02,0xC4,0x03);

#ifdef __cplusplus

class DECLSPEC_UUID("F5C45F6D-E4DD-469d-B397-7341D602C403")
DecklinkUpsampleFilter;
#endif

DEFINE_GUID(CLSID_DecklinkEffectsFilter,0xBFA26F43,0xFB18,0x40d9,0xBD,0x58,0x5A,0x6C,0xE0,0xF4,0x24,0x69);

#ifdef __cplusplus

class DECLSPEC_UUID("BFA26F43-FB18-40d9-BD58-5A6CE0F42469")
DecklinkEffectsFilter;
#endif

DEFINE_GUID(CLSID_DecklinkEffectsProperties,0xEA131320,0x64CC,0x4f3f,0xB7,0x9D,0x41,0xA3,0x83,0xA6,0x5E,0xDE);

#ifdef __cplusplus

class DECLSPEC_UUID("EA131320-64CC-4f3f-B79D-41A383A65EDE")
DecklinkEffectsProperties;
#endif

DEFINE_GUID(CLSID_DecklinkMJPEGEncoderFilter,0x1E003B41,0xB606,0x4ae4,0xB2,0xBB,0xC3,0x5E,0x13,0x35,0x75,0xA5);

#ifdef __cplusplus

class DECLSPEC_UUID("1E003B41-B606-4ae4-B2BB-C35E133575A5")
DecklinkMJPEGEncoderFilter;
#endif

DEFINE_GUID(CLSID_DecklinkMJPEGEncoderProperties,0xB21009AE,0x27A7,0x4e32,0xB6,0xB8,0x39,0x72,0x3F,0xD5,0xD3,0x5D);

#ifdef __cplusplus

class DECLSPEC_UUID("B21009AE-27A7-4e32-B6B8-39723FD5D35D")
DecklinkMJPEGEncoderProperties;
#endif

DEFINE_GUID(CLSID_DecklinkMJPEGDecoderFilter,0x979520BE,0x4C52,0x4ba7,0xA5,0x34,0xB1,0x45,0xED,0xCF,0xDF,0x21);

#ifdef __cplusplus

class DECLSPEC_UUID("979520BE-4C52-4ba7-A534-B145EDCFDF21")
DecklinkMJPEGDecoderFilter;
#endif

DEFINE_GUID(CLSID_DecklinkMJPEGDecoderProperties,0xEFAD70C1,0x0CA9,0x4754,0xA3,0x6B,0xFE,0x2E,0xC6,0x34,0xE1,0x40);

#ifdef __cplusplus

class DECLSPEC_UUID("EFAD70C1-0CA9-4754-A36B-FE2EC634E140")
DecklinkMJPEGDecoderProperties;
#endif

DEFINE_GUID(CLSID_DecklinkStillSequenceSourceFilter,0xC3BF8648,0xC4F7,0x4CE2,0xAA,0x00,0xC3,0xF5,0x49,0x84,0x08,0x6A);

#ifdef __cplusplus

class DECLSPEC_UUID("C3BF8648-C4F7-4CE2-AA00-C3F54984086A")
DecklinkStillSequenceSourceFilter;
#endif

DEFINE_GUID(CLSID_DecklinkStillSequenceSinkFilter,0xD72825C3,0x2221,0x4ec8,0x9E,0xBF,0xD3,0xF6,0x78,0x07,0x9E,0xEE);

#ifdef __cplusplus

class DECLSPEC_UUID("D72825C3-2221-4ec8-9EBF-D3F678079EEE")
DecklinkStillSequenceSinkFilter;
#endif

#ifndef __MEDIASUBTYPE_V210_INTERFACE_DEFINED__
#define __MEDIASUBTYPE_V210_INTERFACE_DEFINED__

/* interface MEDIASUBTYPE_V210 */
/* [auto_handle][version][uuid] */ 


DEFINE_GUID(IID_MEDIASUBTYPE_V210,0x30313276,0xB0B0,0x4dd3,0x8E,0x8C,0x57,0x26,0x92,0xD5,0x26,0xF6);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30313276-B0B0-4dd3-8E8C-572692D526F6")
    MEDIASUBTYPE_V210
    {
    public:
        BEGIN_INTERFACE
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct MEDIASUBTYPE_V210Vtbl
    {
        BEGIN_INTERFACE
        
        END_INTERFACE
    } MEDIASUBTYPE_V210Vtbl;

    interface MEDIASUBTYPE_V210
    {
        CONST_VTBL struct MEDIASUBTYPE_V210Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __MEDIASUBTYPE_V210_INTERFACE_DEFINED__ */


#ifndef __MEDIASUBTYPE_v210a_INTERFACE_DEFINED__
#define __MEDIASUBTYPE_v210a_INTERFACE_DEFINED__

/* interface MEDIASUBTYPE_v210a */
/* [auto_handle][version][uuid] */ 


DEFINE_GUID(IID_MEDIASUBTYPE_v210a,0x30313276,0x0000,0x0010,0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30313276-0000-0010-8000-00AA00389B71")
    MEDIASUBTYPE_v210a
    {
    public:
        BEGIN_INTERFACE
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct MEDIASUBTYPE_v210aVtbl
    {
        BEGIN_INTERFACE
        
        END_INTERFACE
    } MEDIASUBTYPE_v210aVtbl;

    interface MEDIASUBTYPE_v210a
    {
        CONST_VTBL struct MEDIASUBTYPE_v210aVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __MEDIASUBTYPE_v210a_INTERFACE_DEFINED__ */


#ifndef __MEDIASUBTYPE_r210_INTERFACE_DEFINED__
#define __MEDIASUBTYPE_r210_INTERFACE_DEFINED__

/* interface MEDIASUBTYPE_r210 */
/* [auto_handle][version][uuid] */ 


DEFINE_GUID(IID_MEDIASUBTYPE_r210,0x30313272,0x0000,0x0010,0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("30313272-0000-0010-8000-00AA00389B71")
    MEDIASUBTYPE_r210
    {
    public:
        BEGIN_INTERFACE
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct MEDIASUBTYPE_r210Vtbl
    {
        BEGIN_INTERFACE
        
        END_INTERFACE
    } MEDIASUBTYPE_r210Vtbl;

    interface MEDIASUBTYPE_r210
    {
        CONST_VTBL struct MEDIASUBTYPE_r210Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __MEDIASUBTYPE_r210_INTERFACE_DEFINED__ */


#ifndef __MEDIASUBTYPE_HDYC_INTERFACE_DEFINED__
#define __MEDIASUBTYPE_HDYC_INTERFACE_DEFINED__

/* interface MEDIASUBTYPE_HDYC */
/* [auto_handle][version][uuid] */ 


DEFINE_GUID(IID_MEDIASUBTYPE_HDYC,0x43594448,0x0000,0x0010,0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43594448-0000-0010-8000-00AA00389B71")
    MEDIASUBTYPE_HDYC
    {
    public:
        BEGIN_INTERFACE
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct MEDIASUBTYPE_HDYCVtbl
    {
        BEGIN_INTERFACE
        
        END_INTERFACE
    } MEDIASUBTYPE_HDYCVtbl;

    interface MEDIASUBTYPE_HDYC
    {
        CONST_VTBL struct MEDIASUBTYPE_HDYCVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __MEDIASUBTYPE_HDYC_INTERFACE_DEFINED__ */


#ifndef __IDecklinkKeyer_INTERFACE_DEFINED__
#define __IDecklinkKeyer_INTERFACE_DEFINED__

/* interface IDecklinkKeyer */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkKeyer,0x9D63ADFC,0x8D1A,0x451D,0x95,0x8E,0x12,0xFA,0x4B,0x1E,0xFD,0x2F);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9D63ADFC-8D1A-451D-958E-12FA4B1EFD2F")
    IDecklinkKeyer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE set_AlphaBlendModeOn( 
            /* [in] */ UINT isExternalKey) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE set_AlphaBlendModeOff( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE set_AlphaLevel( 
            /* [in] */ UINT alphaLevel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE set_AlphaAutoBlendSettings( 
            /* [in] */ UINT rampFrames,
            /* [in] */ UINT onFrames,
            /* [in] */ UINT offFrames,
            /* [in] */ UINT blendProcessRepeats) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE do_AlphaRampOn( 
            /* [in] */ UINT framesDuration) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE do_AlphaRampOff( 
            /* [in] */ UINT framesDuration) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_DeviceSupportsKeying( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE get_DeviceSupportsExternalKeying( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE set_DefaultTimebase( 
            /* [in] */ long Timebase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkKeyerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkKeyer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkKeyer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkKeyer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaBlendModeOn )( 
            IDecklinkKeyer * This,
            /* [in] */ UINT isExternalKey);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaBlendModeOff )( 
            IDecklinkKeyer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaLevel )( 
            IDecklinkKeyer * This,
            /* [in] */ UINT alphaLevel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaAutoBlendSettings )( 
            IDecklinkKeyer * This,
            /* [in] */ UINT rampFrames,
            /* [in] */ UINT onFrames,
            /* [in] */ UINT offFrames,
            /* [in] */ UINT blendProcessRepeats);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *do_AlphaRampOn )( 
            IDecklinkKeyer * This,
            /* [in] */ UINT framesDuration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *do_AlphaRampOff )( 
            IDecklinkKeyer * This,
            /* [in] */ UINT framesDuration);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSupportsKeying )( 
            IDecklinkKeyer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSupportsExternalKeying )( 
            IDecklinkKeyer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *set_DefaultTimebase )( 
            IDecklinkKeyer * This,
            /* [in] */ long Timebase);
        
        END_INTERFACE
    } IDecklinkKeyerVtbl;

    interface IDecklinkKeyer
    {
        CONST_VTBL struct IDecklinkKeyerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkKeyer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkKeyer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkKeyer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkKeyer_set_AlphaBlendModeOn(This,isExternalKey)	\
    (This)->lpVtbl -> set_AlphaBlendModeOn(This,isExternalKey)

#define IDecklinkKeyer_set_AlphaBlendModeOff(This)	\
    (This)->lpVtbl -> set_AlphaBlendModeOff(This)

#define IDecklinkKeyer_set_AlphaLevel(This,alphaLevel)	\
    (This)->lpVtbl -> set_AlphaLevel(This,alphaLevel)

#define IDecklinkKeyer_set_AlphaAutoBlendSettings(This,rampFrames,onFrames,offFrames,blendProcessRepeats)	\
    (This)->lpVtbl -> set_AlphaAutoBlendSettings(This,rampFrames,onFrames,offFrames,blendProcessRepeats)

#define IDecklinkKeyer_do_AlphaRampOn(This,framesDuration)	\
    (This)->lpVtbl -> do_AlphaRampOn(This,framesDuration)

#define IDecklinkKeyer_do_AlphaRampOff(This,framesDuration)	\
    (This)->lpVtbl -> do_AlphaRampOff(This,framesDuration)

#define IDecklinkKeyer_get_DeviceSupportsKeying(This)	\
    (This)->lpVtbl -> get_DeviceSupportsKeying(This)

#define IDecklinkKeyer_get_DeviceSupportsExternalKeying(This)	\
    (This)->lpVtbl -> get_DeviceSupportsExternalKeying(This)

#define IDecklinkKeyer_set_DefaultTimebase(This,Timebase)	\
    (This)->lpVtbl -> set_DefaultTimebase(This,Timebase)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_set_AlphaBlendModeOn_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ UINT isExternalKey);


void __RPC_STUB IDecklinkKeyer_set_AlphaBlendModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_set_AlphaBlendModeOff_Proxy( 
    IDecklinkKeyer * This);


void __RPC_STUB IDecklinkKeyer_set_AlphaBlendModeOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_set_AlphaLevel_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ UINT alphaLevel);


void __RPC_STUB IDecklinkKeyer_set_AlphaLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_set_AlphaAutoBlendSettings_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ UINT rampFrames,
    /* [in] */ UINT onFrames,
    /* [in] */ UINT offFrames,
    /* [in] */ UINT blendProcessRepeats);


void __RPC_STUB IDecklinkKeyer_set_AlphaAutoBlendSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_do_AlphaRampOn_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ UINT framesDuration);


void __RPC_STUB IDecklinkKeyer_do_AlphaRampOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_do_AlphaRampOff_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ UINT framesDuration);


void __RPC_STUB IDecklinkKeyer_do_AlphaRampOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_get_DeviceSupportsKeying_Proxy( 
    IDecklinkKeyer * This);


void __RPC_STUB IDecklinkKeyer_get_DeviceSupportsKeying_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_get_DeviceSupportsExternalKeying_Proxy( 
    IDecklinkKeyer * This);


void __RPC_STUB IDecklinkKeyer_get_DeviceSupportsExternalKeying_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkKeyer_set_DefaultTimebase_Proxy( 
    IDecklinkKeyer * This,
    /* [in] */ long Timebase);


void __RPC_STUB IDecklinkKeyer_set_DefaultTimebase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkKeyer_INTERFACE_DEFINED__ */


#ifndef __IADecklinkKeyer_INTERFACE_DEFINED__
#define __IADecklinkKeyer_INTERFACE_DEFINED__

/* interface IADecklinkKeyer */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkKeyer,0x4DB4A578,0x7353,0x46e3,0xA6,0x07,0x75,0xF2,0xE3,0xB5,0xE5,0x39);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4DB4A578-7353-46e3-A607-75F2E3B5E539")
    IADecklinkKeyer : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE set_AlphaBlendModeOn( 
            /* [in] */ UINT isExternalKey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE set_AlphaBlendModeOff( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE set_AlphaLevel( 
            /* [in] */ UINT alphaLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE set_AlphaAutoBlendSettings( 
            /* [in] */ UINT rampFrames,
            /* [in] */ UINT onFrames,
            /* [in] */ UINT offFrames,
            /* [in] */ UINT blendProcessRepeats) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE do_AlphaRampOn( 
            /* [in] */ UINT framesDuration) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE do_AlphaRampOff( 
            /* [in] */ UINT framesDuration) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_DeviceSupportsKeying( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE get_DeviceSupportsExternalKeying( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE set_DefaultTimebase( 
            /* [in] */ long Timebase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkKeyerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkKeyer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkKeyer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkKeyer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkKeyer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkKeyer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkKeyer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaBlendModeOn )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT isExternalKey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaBlendModeOff )( 
            IADecklinkKeyer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaLevel )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT alphaLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *set_AlphaAutoBlendSettings )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT rampFrames,
            /* [in] */ UINT onFrames,
            /* [in] */ UINT offFrames,
            /* [in] */ UINT blendProcessRepeats);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *do_AlphaRampOn )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT framesDuration);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *do_AlphaRampOff )( 
            IADecklinkKeyer * This,
            /* [in] */ UINT framesDuration);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSupportsKeying )( 
            IADecklinkKeyer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *get_DeviceSupportsExternalKeying )( 
            IADecklinkKeyer * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *set_DefaultTimebase )( 
            IADecklinkKeyer * This,
            /* [in] */ long Timebase);
        
        END_INTERFACE
    } IADecklinkKeyerVtbl;

    interface IADecklinkKeyer
    {
        CONST_VTBL struct IADecklinkKeyerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkKeyer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkKeyer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkKeyer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkKeyer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkKeyer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkKeyer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkKeyer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkKeyer_set_AlphaBlendModeOn(This,isExternalKey)	\
    (This)->lpVtbl -> set_AlphaBlendModeOn(This,isExternalKey)

#define IADecklinkKeyer_set_AlphaBlendModeOff(This)	\
    (This)->lpVtbl -> set_AlphaBlendModeOff(This)

#define IADecklinkKeyer_set_AlphaLevel(This,alphaLevel)	\
    (This)->lpVtbl -> set_AlphaLevel(This,alphaLevel)

#define IADecklinkKeyer_set_AlphaAutoBlendSettings(This,rampFrames,onFrames,offFrames,blendProcessRepeats)	\
    (This)->lpVtbl -> set_AlphaAutoBlendSettings(This,rampFrames,onFrames,offFrames,blendProcessRepeats)

#define IADecklinkKeyer_do_AlphaRampOn(This,framesDuration)	\
    (This)->lpVtbl -> do_AlphaRampOn(This,framesDuration)

#define IADecklinkKeyer_do_AlphaRampOff(This,framesDuration)	\
    (This)->lpVtbl -> do_AlphaRampOff(This,framesDuration)

#define IADecklinkKeyer_get_DeviceSupportsKeying(This)	\
    (This)->lpVtbl -> get_DeviceSupportsKeying(This)

#define IADecklinkKeyer_get_DeviceSupportsExternalKeying(This)	\
    (This)->lpVtbl -> get_DeviceSupportsExternalKeying(This)

#define IADecklinkKeyer_set_DefaultTimebase(This,Timebase)	\
    (This)->lpVtbl -> set_DefaultTimebase(This,Timebase)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_set_AlphaBlendModeOn_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ UINT isExternalKey);


void __RPC_STUB IADecklinkKeyer_set_AlphaBlendModeOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_set_AlphaBlendModeOff_Proxy( 
    IADecklinkKeyer * This);


void __RPC_STUB IADecklinkKeyer_set_AlphaBlendModeOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_set_AlphaLevel_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ UINT alphaLevel);


void __RPC_STUB IADecklinkKeyer_set_AlphaLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_set_AlphaAutoBlendSettings_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ UINT rampFrames,
    /* [in] */ UINT onFrames,
    /* [in] */ UINT offFrames,
    /* [in] */ UINT blendProcessRepeats);


void __RPC_STUB IADecklinkKeyer_set_AlphaAutoBlendSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_do_AlphaRampOn_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ UINT framesDuration);


void __RPC_STUB IADecklinkKeyer_do_AlphaRampOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_do_AlphaRampOff_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ UINT framesDuration);


void __RPC_STUB IADecklinkKeyer_do_AlphaRampOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_get_DeviceSupportsKeying_Proxy( 
    IADecklinkKeyer * This);


void __RPC_STUB IADecklinkKeyer_get_DeviceSupportsKeying_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_get_DeviceSupportsExternalKeying_Proxy( 
    IADecklinkKeyer * This);


void __RPC_STUB IADecklinkKeyer_get_DeviceSupportsExternalKeying_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkKeyer_set_DefaultTimebase_Proxy( 
    IADecklinkKeyer * This,
    /* [in] */ long Timebase);


void __RPC_STUB IADecklinkKeyer_set_DefaultTimebase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkKeyer_INTERFACE_DEFINED__ */


#ifndef __IDecklinkRawDeviceControl_INTERFACE_DEFINED__
#define __IDecklinkRawDeviceControl_INTERFACE_DEFINED__

/* interface IDecklinkRawDeviceControl */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkRawDeviceControl,0x72D62DE6,0x010F,0x48e6,0xA2,0x51,0x78,0xCA,0x28,0x5B,0xDF,0xE0);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72D62DE6-010F-48e6-A251-78CA285BDFE0")
    IDecklinkRawDeviceControl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendRawCommandSync( 
            /* [in] */ const byte *command,
            /* [in] */ UINT lenCommand,
            /* [out][in] */ byte *response,
            /* [out][in] */ UINT *lenResponse) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SendRawCommandAsync( 
            /* [out][in] */ struct DecklinkRawCommandAsync *args) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkRawDeviceControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkRawDeviceControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkRawDeviceControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkRawDeviceControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendRawCommandSync )( 
            IDecklinkRawDeviceControl * This,
            /* [in] */ const byte *command,
            /* [in] */ UINT lenCommand,
            /* [out][in] */ byte *response,
            /* [out][in] */ UINT *lenResponse);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SendRawCommandAsync )( 
            IDecklinkRawDeviceControl * This,
            /* [out][in] */ struct DecklinkRawCommandAsync *args);
        
        END_INTERFACE
    } IDecklinkRawDeviceControlVtbl;

    interface IDecklinkRawDeviceControl
    {
        CONST_VTBL struct IDecklinkRawDeviceControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkRawDeviceControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkRawDeviceControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkRawDeviceControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkRawDeviceControl_SendRawCommandSync(This,command,lenCommand,response,lenResponse)	\
    (This)->lpVtbl -> SendRawCommandSync(This,command,lenCommand,response,lenResponse)

#define IDecklinkRawDeviceControl_SendRawCommandAsync(This,args)	\
    (This)->lpVtbl -> SendRawCommandAsync(This,args)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkRawDeviceControl_SendRawCommandSync_Proxy( 
    IDecklinkRawDeviceControl * This,
    /* [in] */ const byte *command,
    /* [in] */ UINT lenCommand,
    /* [out][in] */ byte *response,
    /* [out][in] */ UINT *lenResponse);


void __RPC_STUB IDecklinkRawDeviceControl_SendRawCommandSync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkRawDeviceControl_SendRawCommandAsync_Proxy( 
    IDecklinkRawDeviceControl * This,
    /* [out][in] */ struct DecklinkRawCommandAsync *args);


void __RPC_STUB IDecklinkRawDeviceControl_SendRawCommandAsync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkRawDeviceControl_INTERFACE_DEFINED__ */


#ifndef __IADecklinkRawDeviceControl_INTERFACE_DEFINED__
#define __IADecklinkRawDeviceControl_INTERFACE_DEFINED__

/* interface IADecklinkRawDeviceControl */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkRawDeviceControl,0xAF2662C6,0x3ABE,0x498e,0xAD,0xE9,0x25,0x40,0xB6,0xE3,0x06,0x08);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF2662C6-3ABE-498e-ADE9-2540B6E30608")
    IADecklinkRawDeviceControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendRawCommandSync( 
            /* [in] */ const byte *command,
            /* [in] */ UINT lenCommand,
            /* [out][in] */ byte *response,
            /* [out][in] */ UINT *lenResponse) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendRawCommandAsync2( 
            /* [out][in] */ VARIANT *rawCommand,
            /* [in] */ UINT cRawCommand) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkRawDeviceControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkRawDeviceControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkRawDeviceControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkRawDeviceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkRawDeviceControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkRawDeviceControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkRawDeviceControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkRawDeviceControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendRawCommandSync )( 
            IADecklinkRawDeviceControl * This,
            /* [in] */ const byte *command,
            /* [in] */ UINT lenCommand,
            /* [out][in] */ byte *response,
            /* [out][in] */ UINT *lenResponse);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendRawCommandAsync2 )( 
            IADecklinkRawDeviceControl * This,
            /* [out][in] */ VARIANT *rawCommand,
            /* [in] */ UINT cRawCommand);
        
        END_INTERFACE
    } IADecklinkRawDeviceControlVtbl;

    interface IADecklinkRawDeviceControl
    {
        CONST_VTBL struct IADecklinkRawDeviceControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkRawDeviceControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkRawDeviceControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkRawDeviceControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkRawDeviceControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkRawDeviceControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkRawDeviceControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkRawDeviceControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkRawDeviceControl_SendRawCommandSync(This,command,lenCommand,response,lenResponse)	\
    (This)->lpVtbl -> SendRawCommandSync(This,command,lenCommand,response,lenResponse)

#define IADecklinkRawDeviceControl_SendRawCommandAsync2(This,rawCommand,cRawCommand)	\
    (This)->lpVtbl -> SendRawCommandAsync2(This,rawCommand,cRawCommand)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkRawDeviceControl_SendRawCommandSync_Proxy( 
    IADecklinkRawDeviceControl * This,
    /* [in] */ const byte *command,
    /* [in] */ UINT lenCommand,
    /* [out][in] */ byte *response,
    /* [out][in] */ UINT *lenResponse);


void __RPC_STUB IADecklinkRawDeviceControl_SendRawCommandSync_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkRawDeviceControl_SendRawCommandAsync2_Proxy( 
    IADecklinkRawDeviceControl * This,
    /* [out][in] */ VARIANT *rawCommand,
    /* [in] */ UINT cRawCommand);


void __RPC_STUB IADecklinkRawDeviceControl_SendRawCommandAsync2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkRawDeviceControl_INTERFACE_DEFINED__ */


#ifndef __IDecklinkStatus_INTERFACE_DEFINED__
#define __IDecklinkStatus_INTERFACE_DEFINED__

/* interface IDecklinkStatus */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkStatus,0x15BE165D,0xBFF5,0x47f8,0x8E,0x71,0xDE,0x46,0x57,0xAB,0xEB,0xE5);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("15BE165D-BFF5-47f8-8E71-DE4657ABEBE5")
    IDecklinkStatus : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVideoInputStatus( 
            /* [out] */ int *videoStatus,
            /* [out] */ int *genlockStatus) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterVideoStatusChangeEvent( 
            /* [in] */ unsigned long event) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkStatus * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkStatus * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVideoInputStatus )( 
            IDecklinkStatus * This,
            /* [out] */ int *videoStatus,
            /* [out] */ int *genlockStatus);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *RegisterVideoStatusChangeEvent )( 
            IDecklinkStatus * This,
            /* [in] */ unsigned long event);
        
        END_INTERFACE
    } IDecklinkStatusVtbl;

    interface IDecklinkStatus
    {
        CONST_VTBL struct IDecklinkStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkStatus_GetVideoInputStatus(This,videoStatus,genlockStatus)	\
    (This)->lpVtbl -> GetVideoInputStatus(This,videoStatus,genlockStatus)

#define IDecklinkStatus_RegisterVideoStatusChangeEvent(This,event)	\
    (This)->lpVtbl -> RegisterVideoStatusChangeEvent(This,event)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkStatus_GetVideoInputStatus_Proxy( 
    IDecklinkStatus * This,
    /* [out] */ int *videoStatus,
    /* [out] */ int *genlockStatus);


void __RPC_STUB IDecklinkStatus_GetVideoInputStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkStatus_RegisterVideoStatusChangeEvent_Proxy( 
    IDecklinkStatus * This,
    /* [in] */ unsigned long event);


void __RPC_STUB IDecklinkStatus_RegisterVideoStatusChangeEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkStatus_INTERFACE_DEFINED__ */


#ifndef __IADecklinkStatus_INTERFACE_DEFINED__
#define __IADecklinkStatus_INTERFACE_DEFINED__

/* interface IADecklinkStatus */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkStatus,0x8E530B1C,0x8276,0x4bfa,0xB8,0xBA,0x4B,0xD3,0x60,0xC7,0x9F,0xA7);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E530B1C-8276-4bfa-B8BA-4BD360C79FA7")
    IADecklinkStatus : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVideoInputStatus( 
            /* [out] */ int *videoStatus,
            /* [out] */ int *genlockStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RegisterVideoStatusChangeEvent( 
            /* [in] */ unsigned long event) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkStatus * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkStatus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkStatus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkStatus * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVideoInputStatus )( 
            IADecklinkStatus * This,
            /* [out] */ int *videoStatus,
            /* [out] */ int *genlockStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RegisterVideoStatusChangeEvent )( 
            IADecklinkStatus * This,
            /* [in] */ unsigned long event);
        
        END_INTERFACE
    } IADecklinkStatusVtbl;

    interface IADecklinkStatus
    {
        CONST_VTBL struct IADecklinkStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkStatus_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkStatus_GetVideoInputStatus(This,videoStatus,genlockStatus)	\
    (This)->lpVtbl -> GetVideoInputStatus(This,videoStatus,genlockStatus)

#define IADecklinkStatus_RegisterVideoStatusChangeEvent(This,event)	\
    (This)->lpVtbl -> RegisterVideoStatusChangeEvent(This,event)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkStatus_GetVideoInputStatus_Proxy( 
    IADecklinkStatus * This,
    /* [out] */ int *videoStatus,
    /* [out] */ int *genlockStatus);


void __RPC_STUB IADecklinkStatus_GetVideoInputStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkStatus_RegisterVideoStatusChangeEvent_Proxy( 
    IADecklinkStatus * This,
    /* [in] */ unsigned long event);


void __RPC_STUB IADecklinkStatus_RegisterVideoStatusChangeEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkStatus_INTERFACE_DEFINED__ */


#ifndef __IDecklinkCaptureBanner_INTERFACE_DEFINED__
#define __IDecklinkCaptureBanner_INTERFACE_DEFINED__

/* interface IDecklinkCaptureBanner */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkCaptureBanner,0x26D02C91,0xB25F,0x40ff,0x9B,0x39,0x63,0xB3,0xFA,0xBC,0xC5,0x18);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("26D02C91-B25F-40ff-9B39-63B3FABCC518")
    IDecklinkCaptureBanner : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNoInputFrame( 
            /* [out] */ byte **frame) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BlackVideo( 
            /* [in] */ byte *bmih,
            /* [in] */ byte *frame) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkCaptureBannerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkCaptureBanner * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkCaptureBanner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkCaptureBanner * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetNoInputFrame )( 
            IDecklinkCaptureBanner * This,
            /* [out] */ byte **frame);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *BlackVideo )( 
            IDecklinkCaptureBanner * This,
            /* [in] */ byte *bmih,
            /* [in] */ byte *frame);
        
        END_INTERFACE
    } IDecklinkCaptureBannerVtbl;

    interface IDecklinkCaptureBanner
    {
        CONST_VTBL struct IDecklinkCaptureBannerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkCaptureBanner_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkCaptureBanner_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkCaptureBanner_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkCaptureBanner_GetNoInputFrame(This,frame)	\
    (This)->lpVtbl -> GetNoInputFrame(This,frame)

#define IDecklinkCaptureBanner_BlackVideo(This,bmih,frame)	\
    (This)->lpVtbl -> BlackVideo(This,bmih,frame)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkCaptureBanner_GetNoInputFrame_Proxy( 
    IDecklinkCaptureBanner * This,
    /* [out] */ byte **frame);


void __RPC_STUB IDecklinkCaptureBanner_GetNoInputFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkCaptureBanner_BlackVideo_Proxy( 
    IDecklinkCaptureBanner * This,
    /* [in] */ byte *bmih,
    /* [in] */ byte *frame);


void __RPC_STUB IDecklinkCaptureBanner_BlackVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkCaptureBanner_INTERFACE_DEFINED__ */


#ifndef __IADecklinkCaptureBanner_INTERFACE_DEFINED__
#define __IADecklinkCaptureBanner_INTERFACE_DEFINED__

/* interface IADecklinkCaptureBanner */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkCaptureBanner,0x9B434A6C,0x768E,0x4f55,0x8E,0xB2,0xD2,0x19,0xEB,0xA8,0x51,0x93);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B434A6C-768E-4f55-8EB2-D219EBA85193")
    IADecklinkCaptureBanner : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNoInputFrame( 
            /* [out] */ byte **frame) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BlackVideo( 
            /* [in] */ byte *bmih,
            /* [in] */ byte *frame) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkCaptureBannerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkCaptureBanner * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkCaptureBanner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkCaptureBanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkCaptureBanner * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkCaptureBanner * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkCaptureBanner * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkCaptureBanner * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNoInputFrame )( 
            IADecklinkCaptureBanner * This,
            /* [out] */ byte **frame);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BlackVideo )( 
            IADecklinkCaptureBanner * This,
            /* [in] */ byte *bmih,
            /* [in] */ byte *frame);
        
        END_INTERFACE
    } IADecklinkCaptureBannerVtbl;

    interface IADecklinkCaptureBanner
    {
        CONST_VTBL struct IADecklinkCaptureBannerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkCaptureBanner_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkCaptureBanner_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkCaptureBanner_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkCaptureBanner_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkCaptureBanner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkCaptureBanner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkCaptureBanner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkCaptureBanner_GetNoInputFrame(This,frame)	\
    (This)->lpVtbl -> GetNoInputFrame(This,frame)

#define IADecklinkCaptureBanner_BlackVideo(This,bmih,frame)	\
    (This)->lpVtbl -> BlackVideo(This,bmih,frame)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkCaptureBanner_GetNoInputFrame_Proxy( 
    IADecklinkCaptureBanner * This,
    /* [out] */ byte **frame);


void __RPC_STUB IADecklinkCaptureBanner_GetNoInputFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkCaptureBanner_BlackVideo_Proxy( 
    IADecklinkCaptureBanner * This,
    /* [in] */ byte *bmih,
    /* [in] */ byte *frame);


void __RPC_STUB IADecklinkCaptureBanner_BlackVideo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkCaptureBanner_INTERFACE_DEFINED__ */


#ifndef __IDecklinkIOControl_INTERFACE_DEFINED__
#define __IDecklinkIOControl_INTERFACE_DEFINED__

/* interface IDecklinkIOControl */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkIOControl,0x60F58A81,0xA387,0x4922,0xAA,0xAC,0x99,0x8B,0xD9,0xFB,0xE1,0xAA);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60F58A81-A387-4922-AAAC-998BD9FBE1AA")
    IDecklinkIOControl : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIOFeatures( 
            /* [out] */ unsigned long *features) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAnalogueOutput( 
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVideoInput( 
            /* [in] */ BOOL inputIsDigital,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDualLinkOutput( 
            /* [in] */ BOOL enableDualLinkOutput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSingleFieldOutputForSynchronousFrames( 
            /* [in] */ BOOL singleFieldOutput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHDTVPulldownOnOutput( 
            /* [in] */ BOOL enableHDTV32PulldownOnOutput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetBlackToDeckInCapture( 
            /* [in] */ unsigned long blackToDeckSetting) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAFrameReference( 
            /* [in] */ unsigned long aFrameReference) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCaptureVANCLines( 
            /* [in] */ unsigned long vancLine1,
            /* [in] */ unsigned long vancLine2,
            /* [in] */ unsigned long vancLine3) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVideoOutputDownconversionMode( 
            /* [in] */ unsigned long downconversionMode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAudioInputSource( 
            /* [in] */ unsigned long audioInputSource) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetGenlockTiming( 
            /* [in] */ int timingOffset) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVideoOutputDownconversionMode2( 
            /* [in] */ unsigned long downconversionMode,
            /* [in] */ unsigned long downconvertToAnalogOutput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCaptureTimecodeSource( 
            /* [in] */ unsigned long timecodeSource) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetVideoInput2( 
            /* [in] */ unsigned long videoSource,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAnalogueOutput2( 
            /* [in] */ unsigned long videoOutput,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkIOControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkIOControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkIOControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkIOControl * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetIOFeatures )( 
            IDecklinkIOControl * This,
            /* [out] */ unsigned long *features);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAnalogueOutput )( 
            IDecklinkIOControl * This,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVideoInput )( 
            IDecklinkIOControl * This,
            /* [in] */ BOOL inputIsDigital,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetDualLinkOutput )( 
            IDecklinkIOControl * This,
            /* [in] */ BOOL enableDualLinkOutput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetSingleFieldOutputForSynchronousFrames )( 
            IDecklinkIOControl * This,
            /* [in] */ BOOL singleFieldOutput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetHDTVPulldownOnOutput )( 
            IDecklinkIOControl * This,
            /* [in] */ BOOL enableHDTV32PulldownOnOutput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetBlackToDeckInCapture )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long blackToDeckSetting);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAFrameReference )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long aFrameReference);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureVANCLines )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long vancLine1,
            /* [in] */ unsigned long vancLine2,
            /* [in] */ unsigned long vancLine3);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVideoOutputDownconversionMode )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long downconversionMode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAudioInputSource )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long audioInputSource);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetGenlockTiming )( 
            IDecklinkIOControl * This,
            /* [in] */ int timingOffset);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVideoOutputDownconversionMode2 )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long downconversionMode,
            /* [in] */ unsigned long downconvertToAnalogOutput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureTimecodeSource )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long timecodeSource);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetVideoInput2 )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long videoSource,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetAnalogueOutput2 )( 
            IDecklinkIOControl * This,
            /* [in] */ unsigned long videoOutput,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE);
        
        END_INTERFACE
    } IDecklinkIOControlVtbl;

    interface IDecklinkIOControl
    {
        CONST_VTBL struct IDecklinkIOControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkIOControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkIOControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkIOControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkIOControl_GetIOFeatures(This,features)	\
    (This)->lpVtbl -> GetIOFeatures(This,features)

#define IDecklinkIOControl_SetAnalogueOutput(This,isComponent,setupIs75)	\
    (This)->lpVtbl -> SetAnalogueOutput(This,isComponent,setupIs75)

#define IDecklinkIOControl_SetVideoInput(This,inputIsDigital,isComponent,setupIs75)	\
    (This)->lpVtbl -> SetVideoInput(This,inputIsDigital,isComponent,setupIs75)

#define IDecklinkIOControl_SetDualLinkOutput(This,enableDualLinkOutput)	\
    (This)->lpVtbl -> SetDualLinkOutput(This,enableDualLinkOutput)

#define IDecklinkIOControl_SetSingleFieldOutputForSynchronousFrames(This,singleFieldOutput)	\
    (This)->lpVtbl -> SetSingleFieldOutputForSynchronousFrames(This,singleFieldOutput)

#define IDecklinkIOControl_SetHDTVPulldownOnOutput(This,enableHDTV32PulldownOnOutput)	\
    (This)->lpVtbl -> SetHDTVPulldownOnOutput(This,enableHDTV32PulldownOnOutput)

#define IDecklinkIOControl_SetBlackToDeckInCapture(This,blackToDeckSetting)	\
    (This)->lpVtbl -> SetBlackToDeckInCapture(This,blackToDeckSetting)

#define IDecklinkIOControl_SetAFrameReference(This,aFrameReference)	\
    (This)->lpVtbl -> SetAFrameReference(This,aFrameReference)

#define IDecklinkIOControl_SetCaptureVANCLines(This,vancLine1,vancLine2,vancLine3)	\
    (This)->lpVtbl -> SetCaptureVANCLines(This,vancLine1,vancLine2,vancLine3)

#define IDecklinkIOControl_SetVideoOutputDownconversionMode(This,downconversionMode)	\
    (This)->lpVtbl -> SetVideoOutputDownconversionMode(This,downconversionMode)

#define IDecklinkIOControl_SetAudioInputSource(This,audioInputSource)	\
    (This)->lpVtbl -> SetAudioInputSource(This,audioInputSource)

#define IDecklinkIOControl_SetGenlockTiming(This,timingOffset)	\
    (This)->lpVtbl -> SetGenlockTiming(This,timingOffset)

#define IDecklinkIOControl_SetVideoOutputDownconversionMode2(This,downconversionMode,downconvertToAnalogOutput)	\
    (This)->lpVtbl -> SetVideoOutputDownconversionMode2(This,downconversionMode,downconvertToAnalogOutput)

#define IDecklinkIOControl_SetCaptureTimecodeSource(This,timecodeSource)	\
    (This)->lpVtbl -> SetCaptureTimecodeSource(This,timecodeSource)

#define IDecklinkIOControl_SetVideoInput2(This,videoSource,setupIs75,componentLevelsSMPTE)	\
    (This)->lpVtbl -> SetVideoInput2(This,videoSource,setupIs75,componentLevelsSMPTE)

#define IDecklinkIOControl_SetAnalogueOutput2(This,videoOutput,setupIs75,componentLevelsSMPTE)	\
    (This)->lpVtbl -> SetAnalogueOutput2(This,videoOutput,setupIs75,componentLevelsSMPTE)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_GetIOFeatures_Proxy( 
    IDecklinkIOControl * This,
    /* [out] */ unsigned long *features);


void __RPC_STUB IDecklinkIOControl_GetIOFeatures_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetAnalogueOutput_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ BOOL isComponent,
    /* [in] */ BOOL setupIs75);


void __RPC_STUB IDecklinkIOControl_SetAnalogueOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetVideoInput_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ BOOL inputIsDigital,
    /* [in] */ BOOL isComponent,
    /* [in] */ BOOL setupIs75);


void __RPC_STUB IDecklinkIOControl_SetVideoInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetDualLinkOutput_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ BOOL enableDualLinkOutput);


void __RPC_STUB IDecklinkIOControl_SetDualLinkOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetSingleFieldOutputForSynchronousFrames_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ BOOL singleFieldOutput);


void __RPC_STUB IDecklinkIOControl_SetSingleFieldOutputForSynchronousFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetHDTVPulldownOnOutput_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ BOOL enableHDTV32PulldownOnOutput);


void __RPC_STUB IDecklinkIOControl_SetHDTVPulldownOnOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetBlackToDeckInCapture_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long blackToDeckSetting);


void __RPC_STUB IDecklinkIOControl_SetBlackToDeckInCapture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetAFrameReference_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long aFrameReference);


void __RPC_STUB IDecklinkIOControl_SetAFrameReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetCaptureVANCLines_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long vancLine1,
    /* [in] */ unsigned long vancLine2,
    /* [in] */ unsigned long vancLine3);


void __RPC_STUB IDecklinkIOControl_SetCaptureVANCLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetVideoOutputDownconversionMode_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long downconversionMode);


void __RPC_STUB IDecklinkIOControl_SetVideoOutputDownconversionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetAudioInputSource_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long audioInputSource);


void __RPC_STUB IDecklinkIOControl_SetAudioInputSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetGenlockTiming_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ int timingOffset);


void __RPC_STUB IDecklinkIOControl_SetGenlockTiming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetVideoOutputDownconversionMode2_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long downconversionMode,
    /* [in] */ unsigned long downconvertToAnalogOutput);


void __RPC_STUB IDecklinkIOControl_SetVideoOutputDownconversionMode2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetCaptureTimecodeSource_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long timecodeSource);


void __RPC_STUB IDecklinkIOControl_SetCaptureTimecodeSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetVideoInput2_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long videoSource,
    /* [in] */ BOOL setupIs75,
    /* [in] */ BOOL componentLevelsSMPTE);


void __RPC_STUB IDecklinkIOControl_SetVideoInput2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkIOControl_SetAnalogueOutput2_Proxy( 
    IDecklinkIOControl * This,
    /* [in] */ unsigned long videoOutput,
    /* [in] */ BOOL setupIs75,
    /* [in] */ BOOL componentLevelsSMPTE);


void __RPC_STUB IDecklinkIOControl_SetAnalogueOutput2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkIOControl_INTERFACE_DEFINED__ */


#ifndef __IADecklinkIOControl_INTERFACE_DEFINED__
#define __IADecklinkIOControl_INTERFACE_DEFINED__

/* interface IADecklinkIOControl */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkIOControl,0xEF0EE278,0xDFC0,0x432f,0xAD,0x84,0xE7,0x80,0x83,0x5B,0x45,0xB3);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF0EE278-DFC0-432f-AD84-E780835B45B3")
    IADecklinkIOControl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIOFeatures( 
            /* [out] */ unsigned long *features) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAnalogueOutput( 
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVideoInput( 
            /* [in] */ BOOL inputIsDigital,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDualLinkOutput( 
            /* [in] */ BOOL enableDualLinkOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSingleFieldOutputForSynchronousFrames( 
            /* [in] */ BOOL singleFieldOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHDTVPulldownOnOutput( 
            /* [in] */ BOOL enableHDTV32PulldownOnOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBlackToDeckInCapture( 
            /* [in] */ unsigned long blackToDeckSetting) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAFrameReference( 
            /* [in] */ unsigned long aFrameReference) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaptureVANCLines( 
            /* [in] */ unsigned long vancLine1,
            /* [in] */ unsigned long vancLine2,
            /* [in] */ unsigned long vancLine3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVideoOutputDownconversionMode( 
            /* [in] */ unsigned long downconversionMode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAudioInputSource( 
            /* [in] */ unsigned long audioInputSource) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGenlockTiming( 
            /* [in] */ int timingOffset) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVideoOutputDownconversionMode2( 
            /* [in] */ unsigned long downconversionMode,
            /* [in] */ unsigned long downconvertToAnalogOutput) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaptureTimecodeSource( 
            /* [in] */ unsigned long timecodeSource) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVideoInput2( 
            /* [in] */ unsigned long videoSource,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAnalogueOutput2( 
            /* [in] */ unsigned long videoOutput,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkIOControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkIOControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkIOControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkIOControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkIOControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkIOControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkIOControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkIOControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIOFeatures )( 
            IADecklinkIOControl * This,
            /* [out] */ unsigned long *features);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAnalogueOutput )( 
            IADecklinkIOControl * This,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVideoInput )( 
            IADecklinkIOControl * This,
            /* [in] */ BOOL inputIsDigital,
            /* [in] */ BOOL isComponent,
            /* [in] */ BOOL setupIs75);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDualLinkOutput )( 
            IADecklinkIOControl * This,
            /* [in] */ BOOL enableDualLinkOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSingleFieldOutputForSynchronousFrames )( 
            IADecklinkIOControl * This,
            /* [in] */ BOOL singleFieldOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHDTVPulldownOnOutput )( 
            IADecklinkIOControl * This,
            /* [in] */ BOOL enableHDTV32PulldownOnOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBlackToDeckInCapture )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long blackToDeckSetting);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAFrameReference )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long aFrameReference);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureVANCLines )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long vancLine1,
            /* [in] */ unsigned long vancLine2,
            /* [in] */ unsigned long vancLine3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVideoOutputDownconversionMode )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long downconversionMode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAudioInputSource )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long audioInputSource);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGenlockTiming )( 
            IADecklinkIOControl * This,
            /* [in] */ int timingOffset);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVideoOutputDownconversionMode2 )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long downconversionMode,
            /* [in] */ unsigned long downconvertToAnalogOutput);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCaptureTimecodeSource )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long timecodeSource);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVideoInput2 )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long videoSource,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAnalogueOutput2 )( 
            IADecklinkIOControl * This,
            /* [in] */ unsigned long videoOutput,
            /* [in] */ BOOL setupIs75,
            /* [in] */ BOOL componentLevelsSMPTE);
        
        END_INTERFACE
    } IADecklinkIOControlVtbl;

    interface IADecklinkIOControl
    {
        CONST_VTBL struct IADecklinkIOControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkIOControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkIOControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkIOControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkIOControl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkIOControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkIOControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkIOControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkIOControl_GetIOFeatures(This,features)	\
    (This)->lpVtbl -> GetIOFeatures(This,features)

#define IADecklinkIOControl_SetAnalogueOutput(This,isComponent,setupIs75)	\
    (This)->lpVtbl -> SetAnalogueOutput(This,isComponent,setupIs75)

#define IADecklinkIOControl_SetVideoInput(This,inputIsDigital,isComponent,setupIs75)	\
    (This)->lpVtbl -> SetVideoInput(This,inputIsDigital,isComponent,setupIs75)

#define IADecklinkIOControl_SetDualLinkOutput(This,enableDualLinkOutput)	\
    (This)->lpVtbl -> SetDualLinkOutput(This,enableDualLinkOutput)

#define IADecklinkIOControl_SetSingleFieldOutputForSynchronousFrames(This,singleFieldOutput)	\
    (This)->lpVtbl -> SetSingleFieldOutputForSynchronousFrames(This,singleFieldOutput)

#define IADecklinkIOControl_SetHDTVPulldownOnOutput(This,enableHDTV32PulldownOnOutput)	\
    (This)->lpVtbl -> SetHDTVPulldownOnOutput(This,enableHDTV32PulldownOnOutput)

#define IADecklinkIOControl_SetBlackToDeckInCapture(This,blackToDeckSetting)	\
    (This)->lpVtbl -> SetBlackToDeckInCapture(This,blackToDeckSetting)

#define IADecklinkIOControl_SetAFrameReference(This,aFrameReference)	\
    (This)->lpVtbl -> SetAFrameReference(This,aFrameReference)

#define IADecklinkIOControl_SetCaptureVANCLines(This,vancLine1,vancLine2,vancLine3)	\
    (This)->lpVtbl -> SetCaptureVANCLines(This,vancLine1,vancLine2,vancLine3)

#define IADecklinkIOControl_SetVideoOutputDownconversionMode(This,downconversionMode)	\
    (This)->lpVtbl -> SetVideoOutputDownconversionMode(This,downconversionMode)

#define IADecklinkIOControl_SetAudioInputSource(This,audioInputSource)	\
    (This)->lpVtbl -> SetAudioInputSource(This,audioInputSource)

#define IADecklinkIOControl_SetGenlockTiming(This,timingOffset)	\
    (This)->lpVtbl -> SetGenlockTiming(This,timingOffset)

#define IADecklinkIOControl_SetVideoOutputDownconversionMode2(This,downconversionMode,downconvertToAnalogOutput)	\
    (This)->lpVtbl -> SetVideoOutputDownconversionMode2(This,downconversionMode,downconvertToAnalogOutput)

#define IADecklinkIOControl_SetCaptureTimecodeSource(This,timecodeSource)	\
    (This)->lpVtbl -> SetCaptureTimecodeSource(This,timecodeSource)

#define IADecklinkIOControl_SetVideoInput2(This,videoSource,setupIs75,componentLevelsSMPTE)	\
    (This)->lpVtbl -> SetVideoInput2(This,videoSource,setupIs75,componentLevelsSMPTE)

#define IADecklinkIOControl_SetAnalogueOutput2(This,videoOutput,setupIs75,componentLevelsSMPTE)	\
    (This)->lpVtbl -> SetAnalogueOutput2(This,videoOutput,setupIs75,componentLevelsSMPTE)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_GetIOFeatures_Proxy( 
    IADecklinkIOControl * This,
    /* [out] */ unsigned long *features);


void __RPC_STUB IADecklinkIOControl_GetIOFeatures_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetAnalogueOutput_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ BOOL isComponent,
    /* [in] */ BOOL setupIs75);


void __RPC_STUB IADecklinkIOControl_SetAnalogueOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetVideoInput_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ BOOL inputIsDigital,
    /* [in] */ BOOL isComponent,
    /* [in] */ BOOL setupIs75);


void __RPC_STUB IADecklinkIOControl_SetVideoInput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetDualLinkOutput_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ BOOL enableDualLinkOutput);


void __RPC_STUB IADecklinkIOControl_SetDualLinkOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetSingleFieldOutputForSynchronousFrames_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ BOOL singleFieldOutput);


void __RPC_STUB IADecklinkIOControl_SetSingleFieldOutputForSynchronousFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetHDTVPulldownOnOutput_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ BOOL enableHDTV32PulldownOnOutput);


void __RPC_STUB IADecklinkIOControl_SetHDTVPulldownOnOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetBlackToDeckInCapture_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long blackToDeckSetting);


void __RPC_STUB IADecklinkIOControl_SetBlackToDeckInCapture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetAFrameReference_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long aFrameReference);


void __RPC_STUB IADecklinkIOControl_SetAFrameReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetCaptureVANCLines_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long vancLine1,
    /* [in] */ unsigned long vancLine2,
    /* [in] */ unsigned long vancLine3);


void __RPC_STUB IADecklinkIOControl_SetCaptureVANCLines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetVideoOutputDownconversionMode_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long downconversionMode);


void __RPC_STUB IADecklinkIOControl_SetVideoOutputDownconversionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetAudioInputSource_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long audioInputSource);


void __RPC_STUB IADecklinkIOControl_SetAudioInputSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetGenlockTiming_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ int timingOffset);


void __RPC_STUB IADecklinkIOControl_SetGenlockTiming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetVideoOutputDownconversionMode2_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long downconversionMode,
    /* [in] */ unsigned long downconvertToAnalogOutput);


void __RPC_STUB IADecklinkIOControl_SetVideoOutputDownconversionMode2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetCaptureTimecodeSource_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long timecodeSource);


void __RPC_STUB IADecklinkIOControl_SetCaptureTimecodeSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetVideoInput2_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long videoSource,
    /* [in] */ BOOL setupIs75,
    /* [in] */ BOOL componentLevelsSMPTE);


void __RPC_STUB IADecklinkIOControl_SetVideoInput2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkIOControl_SetAnalogueOutput2_Proxy( 
    IADecklinkIOControl * This,
    /* [in] */ unsigned long videoOutput,
    /* [in] */ BOOL setupIs75,
    /* [in] */ BOOL componentLevelsSMPTE);


void __RPC_STUB IADecklinkIOControl_SetAnalogueOutput2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkIOControl_INTERFACE_DEFINED__ */


#ifndef __IDecklinkMediaSample_INTERFACE_DEFINED__
#define __IDecklinkMediaSample_INTERFACE_DEFINED__

/* interface IDecklinkMediaSample */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkMediaSample,0x4CAEF6E0,0x714A,0x4b4c,0x90,0x2D,0xBC,0x53,0xAA,0xB2,0xC4,0x23);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4CAEF6E0-714A-4b4c-902D-BC53AAB2C423")
    IDecklinkMediaSample : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVANCBuffer( 
            /* [out] */ byte **ppBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkMediaSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkMediaSample * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkMediaSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkMediaSample * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetVANCBuffer )( 
            IDecklinkMediaSample * This,
            /* [out] */ byte **ppBuffer);
        
        END_INTERFACE
    } IDecklinkMediaSampleVtbl;

    interface IDecklinkMediaSample
    {
        CONST_VTBL struct IDecklinkMediaSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkMediaSample_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkMediaSample_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkMediaSample_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkMediaSample_GetVANCBuffer(This,ppBuffer)	\
    (This)->lpVtbl -> GetVANCBuffer(This,ppBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDecklinkMediaSample_GetVANCBuffer_Proxy( 
    IDecklinkMediaSample * This,
    /* [out] */ byte **ppBuffer);


void __RPC_STUB IDecklinkMediaSample_GetVANCBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkMediaSample_INTERFACE_DEFINED__ */


#ifndef __IADecklinkMediaSample_INTERFACE_DEFINED__
#define __IADecklinkMediaSample_INTERFACE_DEFINED__

/* interface IADecklinkMediaSample */
/* [unique][helpstring][dual][uuid][object] */ 


DEFINE_GUID(IID_IADecklinkMediaSample,0x5BD0A576,0xD366,0x4dfa,0x96,0xAE,0x52,0x92,0x97,0x1A,0x49,0x99);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5BD0A576-D366-4dfa-96AE-5292971A4999")
    IADecklinkMediaSample : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVANCBuffer( 
            /* [out] */ byte **ppBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IADecklinkMediaSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IADecklinkMediaSample * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IADecklinkMediaSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IADecklinkMediaSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IADecklinkMediaSample * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IADecklinkMediaSample * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IADecklinkMediaSample * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IADecklinkMediaSample * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVANCBuffer )( 
            IADecklinkMediaSample * This,
            /* [out] */ byte **ppBuffer);
        
        END_INTERFACE
    } IADecklinkMediaSampleVtbl;

    interface IADecklinkMediaSample
    {
        CONST_VTBL struct IADecklinkMediaSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IADecklinkMediaSample_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IADecklinkMediaSample_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IADecklinkMediaSample_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IADecklinkMediaSample_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IADecklinkMediaSample_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IADecklinkMediaSample_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IADecklinkMediaSample_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IADecklinkMediaSample_GetVANCBuffer(This,ppBuffer)	\
    (This)->lpVtbl -> GetVANCBuffer(This,ppBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IADecklinkMediaSample_GetVANCBuffer_Proxy( 
    IADecklinkMediaSample * This,
    /* [out] */ byte **ppBuffer);


void __RPC_STUB IADecklinkMediaSample_GetVANCBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IADecklinkMediaSample_INTERFACE_DEFINED__ */


#ifndef __IDecklinkSampleGrabberCB_INTERFACE_DEFINED__
#define __IDecklinkSampleGrabberCB_INTERFACE_DEFINED__

/* interface IDecklinkSampleGrabberCB */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkSampleGrabberCB,0xC23F9F44,0x2BC3,0x425a,0x8F,0x56,0xCD,0xAD,0xA8,0xFC,0xC9,0xE9);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C23F9F44-2BC3-425a-8F56-CDADA8FCC9E9")
    IDecklinkSampleGrabberCB : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SampleCB( 
            /* [in] */ double SampleTime,
            /* [in] */ IMediaSample *pSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BufferCB( 
            /* [in] */ double SampleTime,
            /* [in] */ BYTE *pBuffer,
            /* [in] */ long BufferLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkSampleGrabberCBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkSampleGrabberCB * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkSampleGrabberCB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkSampleGrabberCB * This);
        
        HRESULT ( STDMETHODCALLTYPE *SampleCB )( 
            IDecklinkSampleGrabberCB * This,
            /* [in] */ double SampleTime,
            /* [in] */ IMediaSample *pSample);
        
        HRESULT ( STDMETHODCALLTYPE *BufferCB )( 
            IDecklinkSampleGrabberCB * This,
            /* [in] */ double SampleTime,
            /* [in] */ BYTE *pBuffer,
            /* [in] */ long BufferLen);
        
        END_INTERFACE
    } IDecklinkSampleGrabberCBVtbl;

    interface IDecklinkSampleGrabberCB
    {
        CONST_VTBL struct IDecklinkSampleGrabberCBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkSampleGrabberCB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkSampleGrabberCB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkSampleGrabberCB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkSampleGrabberCB_SampleCB(This,SampleTime,pSample)	\
    (This)->lpVtbl -> SampleCB(This,SampleTime,pSample)

#define IDecklinkSampleGrabberCB_BufferCB(This,SampleTime,pBuffer,BufferLen)	\
    (This)->lpVtbl -> BufferCB(This,SampleTime,pBuffer,BufferLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabberCB_SampleCB_Proxy( 
    IDecklinkSampleGrabberCB * This,
    /* [in] */ double SampleTime,
    /* [in] */ IMediaSample *pSample);


void __RPC_STUB IDecklinkSampleGrabberCB_SampleCB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabberCB_BufferCB_Proxy( 
    IDecklinkSampleGrabberCB * This,
    /* [in] */ double SampleTime,
    /* [in] */ BYTE *pBuffer,
    /* [in] */ long BufferLen);


void __RPC_STUB IDecklinkSampleGrabberCB_BufferCB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkSampleGrabberCB_INTERFACE_DEFINED__ */


#ifndef __IDecklinkSampleGrabber_INTERFACE_DEFINED__
#define __IDecklinkSampleGrabber_INTERFACE_DEFINED__

/* interface IDecklinkSampleGrabber */
/* [helpstring][uuid][object] */ 


DEFINE_GUID(IID_IDecklinkSampleGrabber,0xCAFA3E5A,0x16E0,0x42ce,0xB0,0x64,0x78,0xDE,0x6C,0x30,0x68,0xF8);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAFA3E5A-16E0-42ce-B064-78DE6C3068F8")
    IDecklinkSampleGrabber : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetOneShot( 
            /* [in] */ BOOL OneShot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaType( 
            /* [in] */ const AM_MEDIA_TYPE *pamt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConnectedMediaType( 
            /* [out] */ AM_MEDIA_TYPE *pamt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferSamples( 
            /* [in] */ BOOL BufferThem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentBuffer( 
            /* [out] */ long *pBufferSize,
            /* [out] */ long *pBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentSample( 
            /* [out] */ IMediaSample **ppSample) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCallback( 
            /* [in] */ IDecklinkSampleGrabberCB *pCallback,
            /* [in] */ long WhichMethodToCallback) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDecklinkSampleGrabberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDecklinkSampleGrabber * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDecklinkSampleGrabber * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDecklinkSampleGrabber * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOneShot )( 
            IDecklinkSampleGrabber * This,
            /* [in] */ BOOL OneShot);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaType )( 
            IDecklinkSampleGrabber * This,
            /* [in] */ const AM_MEDIA_TYPE *pamt);
        
        HRESULT ( STDMETHODCALLTYPE *GetConnectedMediaType )( 
            IDecklinkSampleGrabber * This,
            /* [out] */ AM_MEDIA_TYPE *pamt);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferSamples )( 
            IDecklinkSampleGrabber * This,
            /* [in] */ BOOL BufferThem);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentBuffer )( 
            IDecklinkSampleGrabber * This,
            /* [out] */ long *pBufferSize,
            /* [out] */ long *pBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentSample )( 
            IDecklinkSampleGrabber * This,
            /* [out] */ IMediaSample **ppSample);
        
        HRESULT ( STDMETHODCALLTYPE *SetCallback )( 
            IDecklinkSampleGrabber * This,
            /* [in] */ IDecklinkSampleGrabberCB *pCallback,
            /* [in] */ long WhichMethodToCallback);
        
        END_INTERFACE
    } IDecklinkSampleGrabberVtbl;

    interface IDecklinkSampleGrabber
    {
        CONST_VTBL struct IDecklinkSampleGrabberVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDecklinkSampleGrabber_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDecklinkSampleGrabber_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDecklinkSampleGrabber_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDecklinkSampleGrabber_SetOneShot(This,OneShot)	\
    (This)->lpVtbl -> SetOneShot(This,OneShot)

#define IDecklinkSampleGrabber_SetMediaType(This,pamt)	\
    (This)->lpVtbl -> SetMediaType(This,pamt)

#define IDecklinkSampleGrabber_GetConnectedMediaType(This,pamt)	\
    (This)->lpVtbl -> GetConnectedMediaType(This,pamt)

#define IDecklinkSampleGrabber_SetBufferSamples(This,BufferThem)	\
    (This)->lpVtbl -> SetBufferSamples(This,BufferThem)

#define IDecklinkSampleGrabber_GetCurrentBuffer(This,pBufferSize,pBuffer)	\
    (This)->lpVtbl -> GetCurrentBuffer(This,pBufferSize,pBuffer)

#define IDecklinkSampleGrabber_GetCurrentSample(This,ppSample)	\
    (This)->lpVtbl -> GetCurrentSample(This,ppSample)

#define IDecklinkSampleGrabber_SetCallback(This,pCallback,WhichMethodToCallback)	\
    (This)->lpVtbl -> SetCallback(This,pCallback,WhichMethodToCallback)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_SetOneShot_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [in] */ BOOL OneShot);


void __RPC_STUB IDecklinkSampleGrabber_SetOneShot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_SetMediaType_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [in] */ const AM_MEDIA_TYPE *pamt);


void __RPC_STUB IDecklinkSampleGrabber_SetMediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_GetConnectedMediaType_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [out] */ AM_MEDIA_TYPE *pamt);


void __RPC_STUB IDecklinkSampleGrabber_GetConnectedMediaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_SetBufferSamples_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [in] */ BOOL BufferThem);


void __RPC_STUB IDecklinkSampleGrabber_SetBufferSamples_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_GetCurrentBuffer_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [out] */ long *pBufferSize,
    /* [out] */ long *pBuffer);


void __RPC_STUB IDecklinkSampleGrabber_GetCurrentBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_GetCurrentSample_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [out] */ IMediaSample **ppSample);


void __RPC_STUB IDecklinkSampleGrabber_GetCurrentSample_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDecklinkSampleGrabber_SetCallback_Proxy( 
    IDecklinkSampleGrabber * This,
    /* [in] */ IDecklinkSampleGrabberCB *pCallback,
    /* [in] */ long WhichMethodToCallback);


void __RPC_STUB IDecklinkSampleGrabber_SetCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDecklinkSampleGrabber_INTERFACE_DEFINED__ */

#endif /* __DecklinkPublicLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


