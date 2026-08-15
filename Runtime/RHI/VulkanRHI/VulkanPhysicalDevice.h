#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanPhysicalDevice {
    private:
 		VkPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;


    };
}