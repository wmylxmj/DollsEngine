#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/ApplicationWindowsPlatform.h"
namespace DollsEngine
{
	using ApplicationNativePlatform = ApplicationWindowsPlatform;
}
#endif