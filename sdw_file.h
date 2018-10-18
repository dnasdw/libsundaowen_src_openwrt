#ifndef LIBSUNDAOWEN_SDW_FILE_H_
#define LIBSUNDAOWEN_SDW_FILE_H_

#include "sdw_platform.h"
#include "sdw_type.h"

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#define UFopen FopenW
#define Fseek _fseeki64
#define Ftell _ftelli64
#else
#define UFopen Fopen
#define Fseek fseeko
#define Ftell ftello
#endif

FILE* Fopen(const char* a_pFileName, const char* a_pMode, bool a_bVerbose = true);

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
FILE* FopenW(const wchar_t* a_pFileName, const wchar_t* a_pMode, bool a_bVerbose = true);
#endif

#endif	// LIBSUNDAOWEN_SDW_FILE_H_
