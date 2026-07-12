#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    class VulkanExtension
    {
    public:
        [[nodiscard]] inline bool IsSupported() const { return m_isSupported; }

    protected:
        bool m_isSupported = false;
    };

    // 实例拓展
    class VulkanInstanceExtension : public VulkanExtension
    {

    };

    class VulkanInstanceExtensionsCollector
    {
    public:
        void AddExtension(const char* extensionName);
        void FlagExtensionsSupported(const char* layerName = nullptr);

    private:
        std::vector<VulkanInstanceExtension> m_preferredExtensions;
    };




    class VulkanDeviceExtension : public VulkanExtension
    {

    };

    class VulkanDeviceExtensionsCollector
    {

    };



}
