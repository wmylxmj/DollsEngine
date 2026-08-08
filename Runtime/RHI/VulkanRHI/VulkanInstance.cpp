//
// Created by 13973 on 26-8-5.
//

#include "VulkanInstance.h"

#include <cstring>

namespace DollsEngine
{
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


}