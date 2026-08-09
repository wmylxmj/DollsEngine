#pragma once


#include "../../VulkanPlatform.h"

namespace DollsEngine
{
	class VulkanWindowsPlatform : public VulkanPlatform {
	public:
		virtual void AddPreferredPlatformSpecificInstanceExtensions(VulkanInstance &instance) override;
		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) override;
		virtual void CollectInstanceExtensions(VulkanInstanceExtensionsCollector &collector) override;
	};
}
