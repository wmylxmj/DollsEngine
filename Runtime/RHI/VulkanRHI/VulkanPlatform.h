#pragma once

#include "VulkanAPI.h"
#include "VulkanInstance.h"
#include "VulkanExtension.h"


namespace DollsEngine
{
	class VulkanPlatform {
	public:
		virtual void AddPreferredPlatformSpecificInstanceExtensions(VulkanInstance& instance) = 0;

		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) = 0;

		virtual void CollectInstanceExtensions(VulkanInstanceExtensionsCollector& collector) = 0;
	};
}