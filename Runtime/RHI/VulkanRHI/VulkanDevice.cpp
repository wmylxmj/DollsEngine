#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanDevice::Initialize(VkPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;
    }


}