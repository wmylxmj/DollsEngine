#pragma once

#include "VulkanAPI.h"

#include <vector>
#include <utility>

namespace DollsEngine
{
    class VulkanInstance
    {
    public:
        void AddPreferredLayer(const char* layerName) { m_preferredLayers.emplace_back(false, layerName); }
        void AddPreferredExtension(const char* extensionName) { m_preferredExtensions.emplace_back(false, extensionName); }

        bool Create(VkApplicationInfo applicationInfo);
        VkInstance GetInstance() const { return m_instance; }

    private:
        void FlagLayersSupported();
        void FlagExtensionsSupported(const char* layerName = nullptr);

        VkInstance m_instance;

        std::vector<std::pair<bool, const char*>> m_preferredLayers;
        std::vector<const char*> m_supportedLayers;

        std::vector<std::pair<bool, const char*>> m_preferredExtensions;
        std::vector<const char*> m_supportedExtensions;
    };
}
