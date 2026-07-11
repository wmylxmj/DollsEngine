#pragma once


#include "../VulkanPlatform.h"

namespace DollsEngine
{
	class VulkanWindowsPlatform : public VulkanPlatform {
		virtual VkResult CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface) override;
	};
}
