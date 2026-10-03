//
// Created by 13973 on 26-9-29.
//

#include "VulkanSwapchain.h"

namespace DollsEngine
{
    bool VulkanSwapchain::Create(VkSurfaceKHR surface, uint32_t width, uint32_t height, bool vsync, VkSwapchainKHR oldSwapchain)
    {
        m_surface = surface;
    }


}