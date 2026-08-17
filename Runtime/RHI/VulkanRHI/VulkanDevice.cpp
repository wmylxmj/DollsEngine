#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanDevice::Create(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;
    }

}