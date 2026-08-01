#pragma once

#include "VulkanAPI.h"
#include "VulkanQueue.h"

namespace DollsEngine
{
	class VulkanDevice
	{
	private:
		bool CreateDevice();

		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice;

		VulkanQueue m_graphicsQueue;
	};
}