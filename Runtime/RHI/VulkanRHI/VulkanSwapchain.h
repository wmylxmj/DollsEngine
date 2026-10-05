#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanSwapchain {
    public:
        VulkanSwapchain(VulkanDevice& device) : m_device(device) {}

        bool Create(VkSurfaceKHR surface, uint32_t width, uint32_t height, bool vsync, VkSwapchainKHR oldSwapchain = VK_NULL_HANDLE);

        VkSurfaceKHR GetSurface() const { return m_surface; }
        VkSwapchainKHR GetHandle() const { return m_swapchain; }

    protected:
        VulkanDevice& m_device;

        VkSurfaceKHR m_surface;
        VkSwapchainKHR m_swapchain;

    };
}


