//
// Created by 13973 on 26-7-12.
//

#include "VulkanExtension.h"

#include <cstring>

namespace DollsEngine
{
    void VulkanInstanceExtensionsCollector::AddExtension(const char *extensionName)
    {
        m_preferredExtensions.emplace_back(extensionName);
    }

    void VulkanInstanceExtensionsCollector::FlagExtensionsSupported(const char *layerName)
    {
        uint32_t extensionCount;
        vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensionProperties(extensionCount);
        vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, extensionProperties.data());

        for (auto& preferredExtension : m_preferredExtensions) {
            for (const auto& extensionProperty : extensionProperties) {
                if (strcmp(preferredExtension.GetExtensionName(), extensionProperty.extensionName) == 0) {
                    preferredExtension.SetSupported();
                }
            }
        }
    }



}