#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    class VulkanExtension
    {
    public:
        inline bool IsEnabled() const { return m_isEnabled; }
        inline bool IsSupported() const { return m_isSupported; }

    protected:
        bool m_isEnabled = false;
        bool m_isSupported = false;
    };

    // 实例拓展
    class VulkanInstanceExtension : public VulkanExtension
    {

    };

    class VulkanInstanceExtensionsCollector
    {
    public:
        void FlagExtensionsSupported(const char* pLayerName = nullptr);

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
