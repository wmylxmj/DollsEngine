#pragma once

#include "VulkanAPI.h"
#include "VulkanQueue.h"

namespace DollsEngine
{
	class VulkanDevice
	{
	public:
		bool Initialize(VkPhysicalDevice physicalDevice);
	private:
		bool CreateDevice();

		VkDevice m_device;
		VkPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;

		VulkanQueue m_graphicsQueue;
	};
}