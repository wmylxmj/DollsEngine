#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

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
        // 输入：设备引用
        explicit VulkanTextureView(VulkanDevice& device);

        VulkanTextureView(const VulkanTextureView&) = delete;
        VulkanTextureView& operator=(const VulkanTextureView&) = delete;
        VulkanTextureView(VulkanTextureView&&) = delete;
        VulkanTextureView& operator=(VulkanTextureView&&) = delete;

        bool Create(VkImage image, const VulkanTextureViewDescription& description);
        VkImageView GetHandle() const { return m_imageView; }

        VkImage GetImage() const { return m_image; }

    protected:
        VulkanDevice& m_device;

        VkImage m_image = VK_NULL_HANDLE;
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
