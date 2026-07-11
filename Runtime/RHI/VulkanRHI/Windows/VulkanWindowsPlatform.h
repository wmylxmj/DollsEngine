#pragma once

#include "../VulkanAPI.h"
#include "../VulkanPlatform.h"

namespace DollsEngine
{
	class VulkanWindowsPlatform : public VulkanPlatform {
		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) override;
	};
}
