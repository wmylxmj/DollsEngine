#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {
        VkImageViewType imageViewType = VK_IMAGE_VIEW_TYPE_MAX_ENUM;

    };
    class VulkanTextureView {
    public:
        VkImageView GetHandle() const { return m_imageView; }

    protected:
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
