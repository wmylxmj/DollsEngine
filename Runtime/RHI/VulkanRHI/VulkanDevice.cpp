#include "VulkanDevice.h"

#include <cstring>

namespace DollsEngine
{
    bool VulkanDevice::Create(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;

        return true;
    }

    void VulkanDevice::FlagExtensionsSupported(const char *layerName) {
        uint32_t extensionCount;
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetPhysicalDevice(), layerName, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> availableExtensions(extensionCount);
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetPhysicalDevice(), layerName, &extensionCount, availableExtensions.data());

        for (auto& preferredExtension : m_preferredExtensions) {
            if (preferredExtension.first) {
                continue;
            }
            for (const auto& availableExtension : availableExtensions) {
                if (strcmp(preferredExtension.second, availableExtension.extensionName) == 0) {
                    preferredExtension.first = true;
                    break;
                }
            }
        }
    }


}