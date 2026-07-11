#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
	class VulkanPlatform {
		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) = 0;

	};
}