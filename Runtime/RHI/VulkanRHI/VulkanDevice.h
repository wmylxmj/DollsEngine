#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
	class VulkanDevice
	{
	private:
		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice;
	};
}