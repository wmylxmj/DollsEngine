#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanLayer {
    public:
        explicit VulkanLayer(const char* layerName) : m_layerName(layerName) {}
        const char* GetLayerName() const { return m_layerName; }
        void SetSupported() { m_isSupported = true; }
        bool IsSupported() const { return m_isSupported; }


    protected:
        const char* m_layerName;
        bool m_isSupported = false;
    };

    // 实例层
    class VulkanInstanceLayer : public VulkanLayer
    {
    public:
        explicit VulkanInstanceLayer(const char* layerName) : VulkanLayer(layerName) {}
    };

    class VulkanInstanceLayersCollector
    {
    public:
    };
}


