#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/VulkanWindowsPlatform.h"
#endif

namespace DollsEngine
{
	inline VkResult VulkanPlatformCreateSurface(VkInstance instance, HWND windowHandle, VkSurfaceKHR* outSurface)
	{
#ifdef DOLLS_PLATFORM_WINDOWS
		return VulkanWindowsPlatformCreateSurface(instance, windowHandle, outSurface);
#endif
	}
}