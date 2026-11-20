#pragma once

#include "VulkanSwapchain.h"
#include "../RHIPresenter.h"

namespace DollsEngine
{
    class VulkanInstance;
    class VulkanDevice;
    class VulkanPlatform;

    class VulkanPresenter : public RHIPresenter {
    public:

    protected:
        VulkanInstance& m_instance;
        VulkanDevice& m_device;
        VulkanPlatform& m_platform;

    };
}
