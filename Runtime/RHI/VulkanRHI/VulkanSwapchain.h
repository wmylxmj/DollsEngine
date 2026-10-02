#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanSwapchain {
    protected:
        VkSurfaceKHR m_surface;
        VkSwapchainKHR m_swapchain;

    };
}


