//
// Created by 13973 on 26-7-18.
//

#include "VulkanLayer.h"

namespace DollsEngine
{
    void VulkanInstanceLayersCollector::AddLayer(const char *layerName)
    {
        m_preferredLayers.emplace_back(layerName);
    }


}