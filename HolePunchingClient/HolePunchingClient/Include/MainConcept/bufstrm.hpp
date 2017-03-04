//------------------------------------------------------------------------------
// File: Bufstrm.hpp
//
// Desc: Buffered stream stuff
//
// Copyright (c) 2000-2002, MainConcept AG.  All rights reserved.
//--------------------------------------------------------------------------
//
// $Id: bufstrm.hpp,v 1.2 2004/01/16 03:09:37 serge Exp $
// 
//------------------------------------------------------------------------------

#ifndef _BUFSTRM_HPP_
#define _BUFSTRM_HPP_


#define BS_OK       (0)
#define BS_IO_ERROR (1)
#define BS_ERROR    (0xFFFFFFFF)


#define BS_FLAGS_DST 0x00000001 // owns AuxInfo channel
#define BS_FLAGS_ACT 0x00000002 // owns Drive channel
// i.e. part calling HT-channel to drive information


typedef struct bufstream bufstream_tt;

struct bufstream
{

// how many bytes can be put_into/read_from buffer
// used if "request"-call fails
// fifo_w_empty/fifo_r_filled
  unsigned long  (*usable_bytes)(bufstream_tt *bs);

//request the buffer with at least numbytes-bytes
// fifo_w_sampbuf/fifo_r_sampbuf
  unsigned char *(*request)(bufstream_tt *bs, unsigned long numbytes);

//confirm numbytes-bytes filled in in requested after last "request"-call
// fifo_w_commit/fifo_r_remove
  unsigned long  (*confirm)(bufstream_tt *bs, unsigned long numbytes);

//put/get numbytes-bytes into/from bufsteam
// fifo_w_sampput/fifo_r_sampget
  unsigned long  (*copybytes)(bufstream_tt *bs, unsigned char *ptr, unsigned long numSamples);

// maximal chunk-size in buffer-mode (i.e. for "request"-call)
  unsigned long  (*chunksize)(bufstream_tt *bs);
  

//inform bufstream about some additional info - for example
// to inform MUXer about encoding-units
//
// offs: offset from last request-call (if called after
// confirm/copybyte means next copybyte-chunk, i.e.
// we need to call auxinfo() before copybyte() or confirm()
// if offs != 0). AcessUnit-auxinfo is alway called with offs=0
// after confirm()/copybyte()-call!
// Other aux-info can be putted earlier then stream arrive.
//
// Can one asssume that area 0...offs-1 (after last request-call)
// is filled with valid part of stream? Do we need it?
//
  unsigned long (*auxinfo)(bufstream_tt *bs, unsigned long offs, unsigned long info_ID, void *info_ptr, unsigned long info_size);

// allow to split output-stream {if(split!=NULL) - splittable}
// return 0 = OK
  unsigned long (*split) (bufstream_tt *bs);
  void  (*done)  (bufstream_tt *bs, int Abort);
  void  (*free)  (bufstream_tt *bs);

// used to drive io-pipe, undefined = NULL, currently unused
  struct drive_struct *drive_ptr;
  unsigned long  (*drive) (bufstream_tt *bs, unsigned long info_ID, void *info_ptr, unsigned char info_size);

  unsigned long flags; //currently unused, setted once on create/initialisation time
  unsigned long (*state) (bufstream_tt *bs); //currently unused

  struct impl_stream* Buf_IO_struct;
  void* lpUserData;
};


// close_bufstream is generic done and destroy makro
//
#define close_bufstream(bs, abort) \
do { bs->done(bs, abort); bs->free(bs); bs = NULL; } while(0)
//
// bs = NULL; is very important!
//
// It force usage of close_bufstream()-macro
// on pointer-variables and produce Compiler-error
// on static/stack/part_of_struct allocated objects


#endif /* _BUFSTRM_HPP_ */
