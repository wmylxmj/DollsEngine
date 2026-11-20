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
        VulkanPresenter(VulkanInstance& instance, VulkanDevice& device, VulkanPlatform& platform);

    protected:
        VulkanInstance& m_instance;
        VulkanDevice& m_device;
        VulkanPlatform& m_platform;

        void* windowHandle = nullptr;
        VkSurfaceKHR m_surface = VK_NULL_HANDLE;

    };
}
