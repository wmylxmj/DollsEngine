#pragma once

#define VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHX

#include "../VulkanApi.h"

namespace DollsEngine
{
	VkSurfaceKHR VulkanWindowsPlatformCreateSurface(VkInstance instance, void* windowHandle);
}
