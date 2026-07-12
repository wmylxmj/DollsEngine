#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanExtension
    {
    public:

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

    };




    class VulkanDeviceExtension : public VulkanExtension
    {

    };

    class VulkanDeviceExtensionsCollector
    {

    };



}
