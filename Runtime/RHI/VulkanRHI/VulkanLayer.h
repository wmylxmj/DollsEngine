#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanLayer {
    public:
        explicit VulkanLayer(const char* layerName) : m_layerName(layerName) {}

    protected:
        const char* m_layerName;
    };
}


