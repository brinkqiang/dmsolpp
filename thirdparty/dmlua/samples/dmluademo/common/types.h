#ifndef __TYPES_H__
#define __TYPES_H__

// tolua_begin

typedef unsigned char UINT8;
typedef short INT16;
typedef unsigned short UINT16;
typedef int INT32;
typedef unsigned int UINT32;

#ifdef WIN32
typedef long long int INT64;
typedef unsigned long long int UINT64;
#else
typedef long long int INT64;
typedef unsigned long long int UINT64;
#endif

#ifdef WIN32
#define FMT_I64 "%I64d"
#define FMT_U64 "%I64u"
#define FMT_64X "%I64x"
#else
#define FMT_I64 "%lld"
#define FMT_U64 "%llu"
#define FMT_64X "%llx"
#endif

// tolua_end

#endif

