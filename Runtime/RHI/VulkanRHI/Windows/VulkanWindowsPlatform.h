#pragma once

#include "../VulkanApi.h"

namespace DollsEngine
{
	VkResult VulkanWindowsPlatformCreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface);
}
