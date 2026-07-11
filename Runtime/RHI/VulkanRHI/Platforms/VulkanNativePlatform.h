#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/VulkanWindowsPlatform.h"
namespace DollsEngine {
    using VulkanNativePlatform = VulkanWindowsPlatform;
}
#endif
