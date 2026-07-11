#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/WindowsPlatformService.h"
namespace DollsEngine
{
    using NativePlatformService = WindowsPlatformService;
}
#endif