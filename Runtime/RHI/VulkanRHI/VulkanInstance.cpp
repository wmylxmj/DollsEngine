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
            if (preferredLayer.first) {
                m_supportedLayers.push_back(preferredLayer.GetLayerName());
            }
        }

        FlagExtensionsSupported(nullptr);
        for (const auto& layerName : m_supportedLayers) {
            FlagExtensionsSupported(layerName);
        }
        m_supportedExtensions.clear();
        for (const auto& preferredExtension : m_preferredExtensions) {
            if (preferredExtension.first) {
                m_supportedExtensions.push_back(preferredExtension.GetExtensionName());
            }
        }

        VkInstanceCreateInfo instanceCreateInfo = {};
        instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceCreateInfo.pApplicationInfo = &applicationInfo;
        instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(m_supportedLayers.size());
        instanceCreateInfo.ppEnabledLayerNames = m_supportedLayers.data();
        instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(m_supportedExtensions.size());
        instanceCreateInfo.ppEnabledExtensionNames = m_supportedExtensions.data();

        if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance) != VK_SUCCESS)
        {
            return false;
        }

        return true;
    }

    void VulkanInstance::FlagLayersSupported()
    {
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

        for (auto& preferredLayer : m_preferredLayers) {
            if (preferredLayer.first) {
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
            if (preferredExtension.first) {
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
