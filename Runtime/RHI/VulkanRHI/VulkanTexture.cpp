//
// Created by 13973 on 26-10-18.
//

#include "VulkanTexture.h"

#include "VulkanRHIUtils.h"

namespace DollsEngine
{
    VulkanTexture::VulkanTexture(VulkanDevice& device)
        : m_device(device)
    {
    }

    VulkanTexture::~VulkanTexture()
    {
        // 外部 VkImage 不属于当前纹理，这里不销毁
        // VkImageView 相关逻辑后面再补
    }

    bool VulkanTexture::Create(VkImage image, const RHITextureCreateInfo& createInfo)
    {
        if (m_image != VK_NULL_HANDLE ||
            image == VK_NULL_HANDLE ||
            createInfo.width == 0 ||
            createInfo.height == 0 ||
            createInfo.sampleCount == 0 ||
            ConvertToVkFormat(createInfo.pixelFormat) == VK_FORMAT_UNDEFINED) {
            return false;
        }

        m_pixelFormat = createInfo.pixelFormat;
        m_width = createInfo.width;
        m_height = createInfo.height;
        m_sampleCount = createInfo.sampleCount;

        m_image = image;
        m_isImageOwner = false;
        return true;
    }

}
