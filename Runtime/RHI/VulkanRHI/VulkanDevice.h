#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
	class VulkanDevice
	{
	private:
		bool CreateDevice();

		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice;
	};
}