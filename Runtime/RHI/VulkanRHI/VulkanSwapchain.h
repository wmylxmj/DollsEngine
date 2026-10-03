#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanSwapchain {
    public:
        VkSwapchainKHR GetHandle() const { return m_swapchain; }

    protected:
        VkSurfaceKHR m_surface;
        VkSwapchainKHR m_swapchain;

    };
}


