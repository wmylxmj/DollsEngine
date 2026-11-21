#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {
        VkFormat format = VK_FORMAT_UNDEFINED;
        VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_NONE;

        uint32_t baseMipLevel = 0;
        uint32_t mipLevelCount = VK_REMAINING_MIP_LEVELS;
        uint32_t baseArrayLayer = 0;
        uint32_t arrayLayerCount = VK_REMAINING_ARRAY_LAYERS;
    };

    struct VulkanTextureView {
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
