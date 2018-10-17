#include "sdw_string.h"

void SetLocale()
{
#if SDW_PLATFORM == SDW_PLATFORM_MACOS
	setlocale(LC_ALL, "en_US.UTF-8");
#else
	setlocale(LC_ALL, "");
#endif
}
