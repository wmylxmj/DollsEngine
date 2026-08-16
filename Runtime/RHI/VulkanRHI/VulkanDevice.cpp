#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanDevice::Initialize(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;
    }

}