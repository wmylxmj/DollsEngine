#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {
        VkImageViewType viewType = VK_IMAGE_VIEW_TYPE_MAX_ENUM;
        VkFormat format = VK_FORMAT_UNDEFINED;
        VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_NONE;

    };

    struct VulkanTextureView {
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
