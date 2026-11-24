#pragma once

#include "VulkanAPI.h"
#include "../../Core/Hash/Hash.h"

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

        bool operator==(const VulkanTextureViewDescription& other) const
        {
            return viewType == other.viewType
                && format == other.format
                && components.r == other.components.r
                && components.g == other.components.g
                && components.b == other.components.b
                && components.a == other.components.a
                && aspectMask == other.aspectMask
                && baseMipLevel == other.baseMipLevel
                && mipLevelCount == other.mipLevelCount
                && baseArrayLayer == other.baseArrayLayer
                && arrayLayerCount == other.arrayLayerCount;
        }
    };

    template<>
    struct Hash<VulkanTextureViewDescription> {
        size_t operator()(const VulkanTextureViewDescription& description) const
        {
        }
    };

    /**
     * 仅管理VkImageView的生命周期
     */
    class VulkanTextureView {
    public:
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
