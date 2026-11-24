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
            if (viewType != other.viewType) return false;
            if (format != other.format) return false;
            if (components.r != other.components.r) return false;
            if (components.g != other.components.g) return false;
            if (components.b != other.components.b) return false;
            if (components.a != other.components.a) return false;
            if (aspectMask != other.aspectMask) return false;
            if (baseMipLevel != other.baseMipLevel) return false;
            if (mipLevelCount != other.mipLevelCount) return false;
            if (baseArrayLayer != other.baseArrayLayer) return false;
            if (arrayLayerCount != other.arrayLayerCount) return false;

            return true;
        }
    };

    template<>
    struct Hash<VulkanTextureViewDescription> {
        size_t operator()(const VulkanTextureViewDescription& description) const
        {
            size_t seed = 0;
            HashCombine(seed, description.viewType);
            HashCombine(seed, description.format);
            HashCombine(seed, description.components.r);
            HashCombine(seed, description.components.g);
            HashCombine(seed, description.components.b);
            HashCombine(seed, description.components.a);
            HashCombine(seed, description.aspectMask);
            HashCombine(seed, description.baseMipLevel);
            HashCombine(seed, description.mipLevelCount);
            HashCombine(seed, description.baseArrayLayer);
            HashCombine(seed, description.arrayLayerCount);
            return seed;
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
