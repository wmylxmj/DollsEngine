//
// Created by 13973 on 26-11-21.
//

#include "VulkanTextureView.h"

#include "VulkanDevice.h"

namespace DollsEngine
{
    VulkanTextureView::VulkanTextureView(VulkanDevice &device) :
        m_device(device)
    {

    }

    bool VulkanTextureView::Create(VkImage image, const VulkanTextureViewDescription &description)
    {
        if (image == VK_NULL_HANDLE ||
            description.viewType == VK_IMAGE_VIEW_TYPE_MAX_ENUM ||
            description.format == VK_FORMAT_UNDEFINED ||
            description.aspectMask == VK_IMAGE_ASPECT_NONE ||
            m_imageView != VK_NULL_HANDLE) {
            return false;
        }

        VkImageViewCreateInfo imageViewCreateInfo = {};
        imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        imageViewCreateInfo.image = image;
        imageViewCreateInfo.viewType = description.viewType;
        imageViewCreateInfo.format = description.format;
        imageViewCreateInfo.components = description.components;
        imageViewCreateInfo.subresourceRange.aspectMask = description.aspectMask;
        imageViewCreateInfo.subresourceRange.baseMipLevel = description.baseMipLevel;
        imageViewCreateInfo.subresourceRange.levelCount = description.mipLevelCount;
        imageViewCreateInfo.subresourceRange.baseArrayLayer = description.baseArrayLayer;
        imageViewCreateInfo.subresourceRange.layerCount = description.arrayLayerCount;

        VkImageView imageView = VK_NULL_HANDLE;
        if (vkCreateImageView(m_device.GetHandle(), &imageViewCreateInfo, nullptr, &imageView) != VK_SUCCESS) {
            return false;
        }

        m_image = image;
        m_imageView = imageView;
        return true;
    }

}
