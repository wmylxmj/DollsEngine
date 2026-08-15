#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanPhysicalDevice {
    public:

    private:
 		VkPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;
    	VkPhysicalDeviceSubgroupProperties m_physicalDeviceSubgroupProperties;

    };
}