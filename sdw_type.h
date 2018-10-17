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
#include <cstdio>

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
typedef wchar_t UChar;
#else
typedef char UChar;
#endif

#endif	// LIBSUNDAOWEN_SDW_TYPE_H_
