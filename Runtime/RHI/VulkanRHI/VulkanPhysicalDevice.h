#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanPhysicalDevice {
    public:
    	void Initialize(VkPhysicalDevice physicalDevice);
    	VkPhysicalDevice GetHandle() const { return m_physicalDevice; }

    	const VkPhysicalDeviceProperties& GetProperties() const { return m_physicalDeviceProperties; }
    	const VkPhysicalDeviceIDPropertiesKHR& GetIDProperties() const { return m_physicalDeviceIDProperties; }
    	const VkPhysicalDeviceSubgroupProperties& GetSubgroupProperties() const { return m_physicalDeviceSubgroupProperties; }

    private:
 		VkPhysicalDevice m_physicalDevice;

		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;
    	VkPhysicalDeviceSubgroupProperties m_physicalDeviceSubgroupProperties;

    };
}