#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanSwapchain {
    public:
        VkSwapchainKHR GetHandle() const { return m_swapchain; }

    protected:
        VulkanDevice& m_device;

        VkSurfaceKHR m_surface;
        VkSwapchainKHR m_swapchain;

    };
}


