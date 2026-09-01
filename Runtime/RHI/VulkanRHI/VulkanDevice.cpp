#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanDevice::Create(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;

        return true;
    }

    void VulkanDevice::FlagExtensionsSupported(const char *layerName) {

    }


}