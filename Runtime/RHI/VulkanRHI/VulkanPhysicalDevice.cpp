#include "VulkanPhysicalDevice.h"

namespace DollsEngine
{
    void VulkanPhysicalDevice::Initialize(VkPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;

        m_physicalDeviceIDProperties = {};
        m_physicalDeviceIDProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR;
        m_physicalDeviceSubgroupProperties = {};
        m_physicalDeviceSubgroupProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;

        VkPhysicalDeviceProperties2KHR physicalDeviceProperties2 = {};
        physicalDeviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR;
        physicalDeviceProperties2.pNext = &m_physicalDeviceIDProperties;
        m_physicalDeviceIDProperties.pNext = &m_physicalDeviceSubgroupProperties;

        vkGetPhysicalDeviceProperties2KHR(m_physicalDevice, &physicalDeviceProperties2);
        m_physicalDeviceProperties = physicalDeviceProperties2.properties;
    }

}