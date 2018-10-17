#ifndef LIBSUNDAOWEN_SDW_STRING_H_
#define LIBSUNDAOWEN_SDW_STRING_H_

#include "sdw_platform.h"
#include "sdw_type.h"

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#define USTR(x) L##x
#define PRIUS USTR("ls")
#define UCscmp wcscmp
#define UCslen wcslen
#define UPrintf wprintf
#else
#define USTR(x) x
#define PRIUS USTR("s")
#define UCscmp strcmp
#define UCslen strlen
#define UPrintf printf
#endif

void SetLocale();

n8 SToN8(const string& a_sString, int a_nRadix = 10);
n8 SToN8(const wstring& a_sString, int a_nRadix = 10);
n16 SToN16(const string& a_sString, int a_nRadix = 10);
n16 SToN16(const wstring& a_sString, int a_nRadix = 10);
n32 SToN32(const string& a_sString, int a_nRadix = 10);
n32 SToN32(const wstring& a_sString, int a_nRadix = 10);
n64 SToN64(const string& a_sString, int a_nRadix = 10);
n64 SToN64(const wstring& a_sString, int a_nRadix = 10);
u8 SToU8(const string& a_sString, int a_nRadix = 10);
u8 SToU8(const wstring& a_sString, int a_nRadix = 10);
u16 SToU16(const string& a_sString, int a_nRadix = 10);
u16 SToU16(const wstring& a_sString, int a_nRadix = 10);
u32 SToU32(const string& a_sString, int a_nRadix = 10);
u32 SToU32(const wstring& a_sString, int a_nRadix = 10);
u64 SToU64(const string& a_sString, int a_nRadix = 10);
u64 SToU64(const wstring& a_sString, int a_nRadix = 10);
f32 SToF32(const string& a_sString);
f32 SToF32(const wstring& a_sString);
f64 SToF64(const string& a_sString);
f64 SToF64(const wstring& a_sString);

#if (SDW_COMPILER == SDW_COMPILER_GNUC && SDW_COMPILER_VERSION < 50400) || SDW_PLATFORM == SDW_PLATFORM_CYGWIN || (SDW_PLATFORM != SDW_PLATFORM_WINDOWS && defined(SDW_XCONVERT))
template<typename TSrc, typename TDest>
TDest TSToS(const TSrc& a_sString, const string& a_sSrcType, const string& a_sDestType)
{
	TDest sConverted;
	iconv_t cd = iconv_open(a_sDestType.c_str(), a_sSrcType.c_str());
	if (cd == reinterpret_cast<iconv_t>(-1))
	{
		return sConverted;
	}
	size_t uStringLeft = a_sString.size() * sizeof(typename TSrc::value_type);
	static const n32 c_nBufferSize = 1024;
	static const n32 c_nConvertBufferSize = c_nBufferSize - 4;
	char szBuffer[c_nBufferSize];
	typename TSrc::value_type* pString = const_cast<typename TSrc::value_type*>(a_sString.c_str());
	do
	{
		char* pBuffer = szBuffer;
		size_t uBufferLeft = c_nConvertBufferSize;
		n32 nError = iconv(cd, reinterpret_cast<char**>(&pString), &uStringLeft, &pBuffer, &uBufferLeft);
#if SDW_PLATFORM == SDW_PLATFORM_MACOS
		if (nError >= 0 || (nError == static_cast<size_t>(-1) && errno == E2BIG))
#else
		if (nError == 0 || (nError == static_cast<size_t>(-1) && errno == E2BIG))
#endif
		{
			*reinterpret_cast<typename TDest::value_type*>(szBuffer + c_nConvertBufferSize - uBufferLeft) = 0;
			sConverted += reinterpret_cast<typename TDest::value_type*>(szBuffer);
			if (nError == 0)
			{
				break;
			}
		}
		else
		{
			break;
		}
	} while (true);
	iconv_close(cd);
	return sConverted;
}
#endif

wstring U8ToW(const string& a_sString);
wstring AToW(const string& a_sString);

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#define AToU(x) AToW(x)
#else
#define AToU(x) string(x)
#endif

#endif	// LIBSUNDAOWEN_SDW_STRING_H_
