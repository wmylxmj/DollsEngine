#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {
        VkImageViewType imageViewType = VK_IMAGE_VIEW_TYPE_MAX_ENUM;
        VkFormat format = VK_FORMAT_UNDEFINED;

    };

    struct VulkanTextureView {
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
