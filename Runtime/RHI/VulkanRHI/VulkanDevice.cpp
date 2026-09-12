#include "VulkanDevice.h"

#include <cstring>
#include <optional>

namespace DollsEngine
{
    bool VulkanDevice::Create(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;

        VkDeviceCreateInfo deviceCreateInfo = {};
        deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

        VkPhysicalDeviceFeatures physicalDeviceFeatures = {};
        deviceCreateInfo.pEnabledFeatures = &physicalDeviceFeatures;

        deviceCreateInfo.enabledLayerCount = 0;
        deviceCreateInfo.ppEnabledLayerNames = nullptr;

        FlagExtensionsSupported(nullptr);
        m_supportedExtensions.clear();
        for (const auto& preferredExtension : m_preferredExtensions) {
            if (preferredExtension.first) {
                m_supportedExtensions.push_back(preferredExtension.second);
            }
        }
        deviceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(m_supportedExtensions.size());
        deviceCreateInfo.ppEnabledExtensionNames = m_supportedExtensions.data();

        uint32_t queueFamilyCount = 0;
        vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice.GetHandle(), &queueFamilyCount, nullptr);

        std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
        vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice.GetHandle(), &queueFamilyCount, queueFamilies.data());

        std::optional<uint32_t> graphicsQueueFamilyIndex;
        std::optional<uint32_t> computeQueueFamilyIndex;

        for (uint32_t i = 0; i < queueFamilyCount; ++i) {
        }

        std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;





        return true;
    }

    void VulkanDevice::FlagExtensionsSupported(const char *layerName) {
        uint32_t extensionCount;
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetHandle(), layerName, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> availableExtensions(extensionCount);
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetHandle(), layerName, &extensionCount, availableExtensions.data());

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
