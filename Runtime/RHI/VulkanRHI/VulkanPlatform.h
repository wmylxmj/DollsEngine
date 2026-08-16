#pragma once

#include "VulkanAPI.h"
#include "VulkanInstance.h"

namespace DollsEngine
{
	class VulkanPlatform
	{
	public:
		virtual void AddPreferredInstanceExtensions(std::vector<const char*>& extensions) = 0;

		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) = 0;
	};
}