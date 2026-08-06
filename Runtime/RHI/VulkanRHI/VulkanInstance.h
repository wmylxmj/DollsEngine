#pragma once

#include "VulkanAPI.h"
#include <vector>

namespace DollsEngine
{
    class VulkanInstanceLayer
    {
    public:
        explicit VulkanInstanceLayer(const char* layerName) : m_layerName(layerName) {}
        const char* GetLayerName() const { return m_layerName; }
        void SetSupported() { m_isSupported = true; }
        bool IsSupported() const { return m_isSupported; }

    protected:
        const char* m_layerName;
        bool m_isSupported = false;
    };

    class VulkanInstanceExtension
    {
    public:
        explicit VulkanInstanceExtension(const char* extensionName) : m_extensionName(extensionName) {}
        const char* GetExtensionName() const { return m_extensionName; }
        void SetSupported() { m_isSupported = true; }
        [[nodiscard]] bool IsSupported() const { return m_isSupported; }

    protected:
        const char* m_extensionName;
        bool m_isSupported = false;
    };

    class VulkanInstance {

    private:
        std::vector<VulkanInstanceLayer> m_preferredLayers;
        std::vector<const char*> m_supportedLayers;
        std::vector<VulkanInstanceExtension> m_preferredExtensions;

        std::vector<const char*> m_supportedExtensions;
    };

}


