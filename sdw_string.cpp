#include "sdw_string.h"

void SetLocale()
{
#if SDW_PLATFORM == SDW_PLATFORM_MACOS
	setlocale(LC_ALL, "en_US.UTF-8");
#else
	setlocale(LC_ALL, "");
#endif
}

n8 SToN8(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n8>(strtol(a_sString.c_str(), nullptr, a_nRadix));
}

n8 SToN8(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n8>(wcstol(a_sString.c_str(), nullptr, a_nRadix));
}

n16 SToN16(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n16>(strtol(a_sString.c_str(), nullptr, a_nRadix));
}

n16 SToN16(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n16>(wcstol(a_sString.c_str(), nullptr, a_nRadix));
}

n32 SToN32(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n32>(strtol(a_sString.c_str(), nullptr, a_nRadix));
}

n32 SToN32(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<n32>(wcstol(a_sString.c_str(), nullptr, a_nRadix));
}

n64 SToN64(const string& a_sString, int a_nRadix /* = 10 */)
{
	return strtoll(a_sString.c_str(), nullptr, a_nRadix);
}

n64 SToN64(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return wcstoll(a_sString.c_str(), nullptr, a_nRadix);
}

u8 SToU8(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u8>(strtol(a_sString.c_str(), nullptr, a_nRadix));
}

u8 SToU8(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u8>(wcstol(a_sString.c_str(), nullptr, a_nRadix));
}

u16 SToU16(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u16>(strtol(a_sString.c_str(), nullptr, a_nRadix));
}

u16 SToU16(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u16>(wcstol(a_sString.c_str(), nullptr, a_nRadix));
}

u32 SToU32(const string& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u32>(strtoul(a_sString.c_str(), nullptr, a_nRadix));
}

u32 SToU32(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return static_cast<u32>(wcstoul(a_sString.c_str(), nullptr, a_nRadix));
}

u64 SToU64(const string& a_sString, int a_nRadix /* = 10 */)
{
	return strtoull(a_sString.c_str(), nullptr, a_nRadix);
}

u64 SToU64(const wstring& a_sString, int a_nRadix /* = 10 */)
{
	return wcstoull(a_sString.c_str(), nullptr, a_nRadix);
}

f32 SToF32(const string& a_sString)
{
	return static_cast<f32>(strtod(a_sString.c_str(), nullptr));
}

f32 SToF32(const wstring& a_sString)
{
	return static_cast<f32>(wcstod(a_sString.c_str(), nullptr));
}

f64 SToF64(const string& a_sString)
{
	return strtod(a_sString.c_str(), nullptr);
}

f64 SToF64(const wstring& a_sString)
{
	return wcstod(a_sString.c_str(), nullptr);
}

#if (SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION < 1600) || (SDW_PLATFORM == SDW_PLATFORM_WINDOWS && SDW_COMPILER != SDW_COMPILER_MSC)
wstring U8ToW(const string& a_sString)
{
	int nLength = MultiByteToWideChar(CP_UTF8, 0, a_sString.c_str(), -1, nullptr, 0);
	wchar_t* pTemp = new wchar_t[nLength];
	MultiByteToWideChar(CP_UTF8, 0, a_sString.c_str(), -1, pTemp, nLength);
	wstring sString = pTemp;
	delete[] pTemp;
	return sString;
}
#elif (SDW_COMPILER == SDW_COMPILER_GNUC && SDW_COMPILER_VERSION < 50400) || SDW_PLATFORM == SDW_PLATFORM_CYGWIN
wstring U8ToW(const string& a_sString)
{
	return TSToS<string, wstring>(a_sString, "UTF-8", "WCHAR_T");
}
#else
wstring U8ToW(const string& a_sString)
{
	static wstring_convert<codecvt_utf8<wchar_t>> c_cvt_u8;
	return c_cvt_u8.from_bytes(a_sString);
}
#endif

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
wstring AToW(const string& a_sString)
{
	int nLength = MultiByteToWideChar(CP_ACP, 0, a_sString.c_str(), -1, nullptr, 0);
	wchar_t* pTemp = new wchar_t[nLength];
	MultiByteToWideChar(CP_ACP, 0, a_sString.c_str(), -1, pTemp, nLength);
	wstring sString = pTemp;
	delete[] pTemp;
	return sString;
}
#else
wstring AToW(const string& a_sString)
{
	return U8ToW(a_sString);
}
#endif

string FormatV(const char* a_szFormat, va_list a_vaList)
{
	static const int c_nFormatBufferSize = 0x100000;
	static char c_szBuffer[c_nFormatBufferSize] = {};
	vsnprintf(c_szBuffer, c_nFormatBufferSize, a_szFormat, a_vaList);
	return c_szBuffer;
}

wstring FormatV(const wchar_t* a_szFormat, va_list a_vaList)
{
	static const int c_nFormatBufferSize = 0x100000;
	static wchar_t c_szBuffer[c_nFormatBufferSize] = {};
	vswprintf(c_szBuffer, c_nFormatBufferSize, a_szFormat, a_vaList);
	return c_szBuffer;
}

string Format(const char* a_szFormat, ...)
{
	va_list vaList;
	va_start(vaList, a_szFormat);
	string sFormatted = FormatV(a_szFormat, vaList);
	va_end(vaList);
	return sFormatted;
}

wstring Format(const wchar_t* a_szFormat, ...)
{
	va_list vaList;
	va_start(vaList, a_szFormat);
	wstring sFormatted = FormatV(a_szFormat, vaList);
	va_end(vaList);
	return sFormatted;
}
