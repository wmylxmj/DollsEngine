#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanPhysicalDevice {
    public:
    	void Initialize(VkPhysicalDevice physicalDevice);
    	const VkPhysicalDevice& GetPhysicalDevice() const { return m_physicalDevice; }

    	const VkPhysicalDeviceProperties& GetProperties() const { return m_physicalDeviceProperties; }

    private:
 		VkPhysicalDevice m_physicalDevice;

		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;
    	VkPhysicalDeviceSubgroupProperties m_physicalDeviceSubgroupProperties;

    };
}