#pragma once

#include "VulkanAPI.h"
#include "VulkanExtension.h"


namespace DollsEngine
{
	class VulkanPlatform {
		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) = 0;
		virtual void CollectInstanceExtensions(VulkanInstanceExtensionsCollector& collector) = 0;
	};
}