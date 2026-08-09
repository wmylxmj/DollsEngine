//
// Created by 13973 on 26-8-5.
//

#include "VulkanInstance.h"

#include <cstring>

namespace DollsEngine
{
    bool VulkanInstance::Create(VkApplicationInfo applicationInfo)
    {
        FlagLayersSupported();
        m_supportedLayers.clear();
        for (const auto& preferredLayer : m_preferredLayers) {
            if (preferredLayer.IsSupported()) {
                m_supportedLayers.push_back(preferredLayer.GetLayerName());
            }
        }

        FlagExtensionsSupported(nullptr);
		for (const auto& layerName : m_supportedLayers) {
			FlagExtensionsSupported(layerName);
		}
        m_supportedExtensions.clear();
        for (const auto& preferredExtension : m_preferredExtensions) {
        }



    }

    void VulkanInstance::FlagLayersSupported()
    {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for (auto& preferredLayer : m_preferredLayers) {
            if (preferredLayer.IsSupported()) {
                continue;
            }
            for (const auto& availableLayer : availableLayers) {
                if (strcmp(preferredLayer.GetLayerName(), availableLayer.layerName) == 0) {
                    preferredLayer.SetSupported();
                    break;
                }
            }
        }
    }

    void VulkanInstance::FlagExtensionsSupported(const char *layerName)
    {
        uint32_t extensionCount;
        vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> extensionProperties(extensionCount);
        vkEnumerateInstanceExtensionProperties(layerName, &extensionCount, extensionProperties.data());

        for (auto& preferredExtension : m_preferredExtensions) {
            if (preferredExtension.IsSupported()) {
                continue;
            }
            for (const auto& extensionProperty : extensionProperties) {
                if (strcmp(preferredExtension.GetExtensionName(), extensionProperty.extensionName) == 0) {
                    preferredExtension.SetSupported();
                    break;
                }
            }
        }
    }




}