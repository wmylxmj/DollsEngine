#pragma once

#include "VulkanAPI.h"
#include "VulkanSemaphore.h"

#include <vector>

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanSwapchain {
    public:
        VulkanSwapchain(VulkanDevice& device) : m_device(device) {}

        bool Create(VkSurfaceKHR surface, uint32_t width, uint32_t height, bool vsync, VkSwapchainKHR oldSwapchain = VK_NULL_HANDLE);

        bool AcquireNextImage(uint32_t& outImageIndex, VulkanSemaphore*& pOutSemaphore);


        VkSurfaceKHR GetSurface() const { return m_surface; }
        VkSwapchainKHR GetHandle() const { return m_swapchain; }

        const std::vector<VkImage>& GetImages() const { return m_images; }

    protected:
        VulkanDevice& m_device;

        VkSurfaceKHR m_surface;
        VkSwapchainKHR m_swapchain;

        std::vector<VkImage> m_images;

        std::vector<VulkanSemaphore> m_readyToRenderSemaphores;
        // 当前信号量索引
        uint32_t m_currentSemaphoreIndex = 0;


    };
}


