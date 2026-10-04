//
// Created by 13973 on 26-9-29.
//

#include "VulkanSwapchain.h"

#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanSwapchain::Create(VkSurfaceKHR surface, uint32_t width, uint32_t height, bool vsync, VkSwapchainKHR oldSwapchain)
    {
        m_surface = surface;

        uint32_t availablePresentModeCount = 0;
        vkGetPhysicalDeviceSurfacePresentModesKHR(m_device.GetPhysicalDevice().GetHandle(), m_surface, &availablePresentModeCount, nullptr);
        std::vector<VkPresentModeKHR> availablePresentModes(availablePresentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(m_device.GetPhysicalDevice().GetHandle(), m_surface, &availablePresentModeCount, availablePresentModes.data());

        VkPresentModeKHR presentMode = VK_PRESENT_MODE_FIFO_KHR;
        for (const auto& availablePresentMode : availablePresentModes) {
            if (availablePresentMode == VK_PRESENT_MODE_IMMEDIATE_KHR && !vsync) {
                presentMode = availablePresentMode;
                break;
            }
            if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
                presentMode = availablePresentMode;
            }
        }

        VkSurfaceCapabilitiesKHR surfaceCapabilities;
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_device.GetPhysicalDevice().GetHandle(), m_surface, &surfaceCapabilities);
        VkCompositeAlphaFlagBitsKHR compositeAlpha = VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR;
        if (surfaceCapabilities.supportedCompositeAlpha & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR) {
            compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        }

        VkSwapchainCreateInfoKHR swapchainCreateInfo = {};
        swapchainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        swapchainCreateInfo.surface = m_surface;
        swapchainCreateInfo.minImageCount = 3;
        swapchainCreateInfo.imageFormat = VK_FORMAT_B8G8R8A8_UNORM;
        swapchainCreateInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        swapchainCreateInfo.imageExtent.width = width;
        swapchainCreateInfo.imageExtent.height = height;
        swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
        swapchainCreateInfo.preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
        swapchainCreateInfo.imageArrayLayers = 1;
        swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        swapchainCreateInfo.presentMode = presentMode;
        swapchainCreateInfo.oldSwapchain = oldSwapchain;
        swapchainCreateInfo.clipped = VK_TRUE;
        swapchainCreateInfo.compositeAlpha = compositeAlpha;

        if (vkCreateSwapchainKHR(m_device.GetHandle(), &swapchainCreateInfo, nullptr, &m_swapchain) != VK_SUCCESS) {
            return false;
        }
    }


}
