#pragma once

#include "VulkanAPI.h"
#include "VulkanInstance.h"

namespace DollsEngine
{
	class VulkanPlatform
	{
	public:
		virtual void AddPreferredPlatformSpecificInstanceExtensions(VulkanInstance& instance) = 0;

		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) = 0;
	};
}