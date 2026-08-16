#pragma once

#include "VulkanAPI.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"

namespace DollsEngine
{
	class VulkanDevice
	{
	public:
		bool Initialize(VulkanPhysicalDevice physicalDevice);
	private:
		bool CreateDevice();

		VkDevice m_device;

		VulkanPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;

		VulkanQueue m_graphicsQueue;
	};
}