#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {
        VkImageViewType viewType = VK_IMAGE_VIEW_TYPE_MAX_ENUM;
        VkFormat format = VK_FORMAT_UNDEFINED;
        VkComponentMapping components = {};
        VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_NONE;

        uint32_t baseMipLevel = 0;
        uint32_t mipLevelCount = VK_REMAINING_MIP_LEVELS;
        uint32_t baseArrayLayer = 0;
        uint32_t arrayLayerCount = VK_REMAINING_ARRAY_LAYERS;
    };

    class VulkanTextureView {
    public:
        bool Create(VkImage image, const VulkanTextureViewDescription& description);

    protected:
        VkImage m_image = VK_NULL_HANDLE;
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
