#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    class VulkanExtension
    {
    public:
        explicit VulkanExtension(const char* extensionName) : m_extensionName(extensionName) {}
        const char* GetExtensionName() const { return m_extensionName; }
        void SetSupported() { m_isSupported = true; }
        [[nodiscard]] bool IsSupported() const { return m_isSupported; }


    protected:
        const char* m_extensionName;
        bool m_isSupported = false;
    };

    // 实例拓展
    class VulkanInstanceExtension : public VulkanExtension
    {
    public:
        explicit VulkanInstanceExtension(const char* extensionName) : VulkanExtension(extensionName) {}

    };

    class VulkanInstanceExtensionsCollector
    {
    public:
        void AddExtension(const char* extensionName);
        void FlagExtensionsSupported(const char* layerName = nullptr);
        std::vector<const char*> GetSupportedExtensions();

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
