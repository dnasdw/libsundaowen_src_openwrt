#ifndef LIBSUNDAOWEN_SDW_TYPE_H_
#define LIBSUNDAOWEN_SDW_TYPE_H_

#include "sdw_platform.h"

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#if defined(SDW_MAIN)
#include <shellapi.h>
#endif
#endif

#include <clocale>
#if SDW_COMPILER != SDW_COMPILER_MSC || (SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION >= 1600)
#include <cstdint>
#else
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#endif
#include <cstdio>
#if SDW_COMPILER == SDW_COMPILER_CLANG || (SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION >= 1600) || (SDW_COMPILER == SDW_COMPILER_GNUC && SDW_COMPILER_VERSION >= 50400)
#include <codecvt>
#endif
#include <regex>
#include <string>

using namespace std;

typedef int8_t n8;
typedef int16_t n16;
typedef int32_t n32;
typedef int64_t n64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#if SDW_COMPILER == SDW_COMPILER_MSC
#if SDW_COMPILER_VERSION < 1600
#define nullptr NULL
#endif
#endif
typedef wchar_t UChar;
typedef wstring UString;
typedef wregex URegex;
#else
typedef char UChar;
typedef string UString;
typedef regex URegex;
#endif

#endif	// LIBSUNDAOWEN_SDW_TYPE_H_
