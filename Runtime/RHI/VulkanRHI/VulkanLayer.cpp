//
// Created by 13973 on 26-7-18.
//

#include "VulkanLayer.h"

#include <cstring>

namespace DollsEngine
{
    void VulkanInstanceLayersCollector::AddLayer(const char *layerName)
    {
        m_preferredLayers.emplace_back(layerName);
    }

    void VulkanInstanceLayersCollector::FlagLayersSupported()
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

    std::vector<const char*> VulkanInstanceLayersCollector::GetSupportedLayers() const
    {
        std::vector<const char*> supportedLayers;
        for (const auto& preferredLayer : m_preferredLayers) {
            if (preferredLayer.IsSupported()) {
                supportedLayers.push_back(preferredLayer.GetLayerName());
            }
        }
        return supportedLayers;
    }
}