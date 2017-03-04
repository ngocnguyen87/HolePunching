
/**
 * @file vss_common.h
 * Header provides multi-platform support
 * and contains several common functions definition.
 * Supports Linux (gcc), QNX (gcc), Windows (VC++).
 * Copyright (C) 2002-2007 Vanguard Software Solutions, Inc. All rights reserved.
 * Project:	VSS RTP Library
 */

#ifndef	__VSS_COMMON_H_
#define	__VSS_COMMON_H_

/// max size of network command
#define MAX_NETWORK_BUFFER 65536

//------------ system includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef _TMS320C6X
	//these headers work for Windoze & Unix, not for TI:
	#include <signal.h>
	#include <fcntl.h>	//O_BINARY, etc
	#include <sys/types.h>
	#include <sys/stat.h>
#endif
#include <errno.h>
#include <time.h>
#if defined(WIN32) && !defined(GCC)
	#include <winsock2.h>	//<sys/socket.h>, <netinet/in.h>, <netdb.h> replacement
	#include <ws2tcpip.h>	//TCP/IP extensions for winsock2
	#include <io.h>		//open, write, close
	#include <direct.h>	//mkdir
#elif _TMS320C6X
	#include <netmain.h>
	#include <socket.h>
#else
	#include <sys/time.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <unistd.h>	//open, write, close
#endif

//------------ types def
typedef unsigned char vss_byte;
typedef unsigned short vss_ushort;
typedef unsigned int vss_uint;
#define SOCKOPT_TYPE const char*

#if defined(WIN32) && !defined(GCC)
#define _USE_WINSOCK
#endif

#ifdef _USE_WINSOCK
	typedef __int64 vss_i64;
	typedef unsigned __int64 vss_u64;
	typedef __int64 vss_time;	//VC doesnt understand "long long"
  
	#define ETIMEDOUT      100001	//VC has no these constants defined
#ifndef POSIX_ERRORCODES_DEFINED
  #define ENOBUFS	       100002
	#define ENODATA	       100003
	#define EWOULDBLOCK    WSAEWOULDBLOCK
	#define ECONNABORTED   WSAECONNABORTED
	#define ECONNRESET     WSAECONNRESET
  #define EINPROGRESS    WSAEINPROGRESS
  #define ENOTCONN       WSAENOTCONN
  #define EADDRINUSE     WSAEADDRINUSE
  #define EADDRNOTAVAIL  WSAEADDRNOTAVAIL
#endif //POSIX_ERRORCODES_DEFINED

	#define snprintf _snprintf	//VC has only _snprintf() function
	#define vsnprintf _vsnprintf
	#define strdup _strdup
	#define pid_t int
	#define strcasecmp stricmp
	#define INL inline
	#define WRITE_MODE O_RDWR|O_CREAT|O_TRUNC|O_BINARY
	#define READ_MODE O_RDONLY|O_BINARY
	#define PERM_MODE (S_IREAD|S_IWRITE)
	#define FUNC_NAME "function"
	//#define getpid(void) 0
	#define SIGUSR1 10
	#define SIGPIPE 13
	#define DIRSEP "\\"
	#define mkdir(a,b) mkdir(a)
#elif _TMS320C6X
	typedef long vss_time;
	#define MAX_PATH 260
	#define FUNC_NAME "function"
	#define DIRSEP "/"
	#undef SOCKOPT_TYPE
	#define SOCKOPT_TYPE void*
	#define EINTR  10001
	#define EAGAIN 10002
	#define EPIPE  10003
	#define select fdSelect
#else
	typedef long long vss_i64;
	typedef unsigned long long vss_u64;
	typedef long long vss_time;
	#define MAX_PATH 260
	#define INL inline
	#define WRITE_MODE O_RDWR|O_CREAT|O_TRUNC
	#define READ_MODE O_RDONLY
	#define PERM_MODE (S_IRUSR|S_IWUSR | S_IRGRP|S_IWGRP)
	#define stricmp strcasecmp
	#define strcmpi strcasecmp
	#define DIRSEP "/"
	#define closesocket close
#endif
/// useful macros to use inside vss_errout()
#define F FUNC_NAME

/// useful define - size of array, in elements
#ifndef ARRSIZE
#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#endif

//----------- useful vss_gettime, vss_nanosleep constants, microseconds
/// 1 second in ms
#define VSSTIME_SECOND 1000000
#define VSSTIME_MILLI 1000

//----------------- Error codes
#define ERR_OK 0
#define ERR_PARAMS 1

//-------------------------- Functions --------------------
#ifdef __cplusplus
	extern "C" {
#endif

/** @return minimum between two given values */
int vss_min(int i1, int i2);

/** @return maximum between two given values */
int vss_max(int i1, int i2);

/**
 * Current time in microseconds.
 * @return current time in usecs (microseconds)
 */
vss_time vss_gettime(void);

/**
 * Current time in seconds.
 * @return current time in seconds
 */
int vss_gettimesec(void);

/** 
 * Utility to return local time considering daylight saving time
 * @param tt pointer to save result (can be NULL)
 * @return time in sec
 */
time_t vss_dstime(time_t *tt);

/**
 * Incapsulates Unix nanosleep() - for better portability.
 * @param sec - delay in seconds
 * @param usec - delay in usec or microseconds (1/1,000,000 sec)
 * @return 0=OK, -1 if delay was interrupted, see errno in this case
 */
int vss_nanosleep(int sec, int usec);

/**
 * @return current date formatted into string MM/DD/YYYY
 */
char *vss_datestr(char *buffer, int size);

/**
 * @return current time formatted into string HH:MM:SS
 */
char *vss_timestr(char *buffer, int size);

/**
 * @return current date-time formatted into string MM/DD/YYYY HH:MM:SS
 */
char *vss_datetimestr(char *buffer, int size);

/**
 * More reliable version of strncpy().
 * Guarantees that resulting string will have 0 at the end.
 * @param dest destination string
 * @param src source string
 * @param size size of dest string
 * @return pointer to destination string
 */
char *vss_strncpy(char *dest, const char *src, int size);

/**
 * Add [src] to the end of the [dest].
 * @param dest destination string
 * @param src source string
 * @param size size of dest array
 * @return pointer to destination string
 */
char *vss_strncat(char *dest, const char *src, int size);

/**
 * Replace [dest] by [src].
 * @param dest - destination string
 * @param src - source string
 * @param len - number of chars to copy from [src]
 * @param size - max size of dest array
 * @return pointer to destination string
 */
char *vss_strnmove(char *dest, const char *src, int len, int size);

/**
 * Concatenates folder and file name into given buffer,
 * @param buffer - [OUT] buffer to place concatenated name
 * @param bufsize - size of the buffer
 * @param dir - folder name
 * @param filename - file name
 * @return pointer to buffer
 */
char *dir_concat(char *buffer, int bufsize, char *dir, char *filename);

/**
 * Outputs a message to the standard Debug output (VC++ output window on WIN32)
 */
void dbg(char *format, ...);


#if defined(_DEBUG) || defined(DEBUG)
	/// Output text info to the debug console.
	void vss_trace(char *format, ...);
	#define VSS_ASSERT(a,b) if(a) vss_trace("ASSERT: %s \n", b)
#else
	#define VSS_ASSERT(a,b)
	#define vss_trace
#endif


#ifdef __cplusplus
	}
#endif

#endif	// __VSS_COMMON_H_

