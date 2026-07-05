#pragma once

#include "../VulkanAPI.h"

namespace DollsEngine
{
	VkResult VulkanWindowsPlatformCreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface);
}
