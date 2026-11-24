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

    VulkanTextureView *VulkanTexture:
    {
        if (m_image == VK_NULL_HANDLE) {
            return nullptr;
        }

        {
            std::shared_lock lock(m_textureViewCachesMutex);
            if (auto it = m_textureViewCaches.find(description); it != m_textureViewCaches.end()) {
                return it->second.get();
            }
        }

        std::unique_lock lock(m_textureViewCachesMutex);
        if (auto it = m_textureViewCaches.find(description); it != m_textureViewCaches.end()) {
            return it->second.get();
        }

        auto view = std::make_unique<VulkanTextureView>(m_device);
        if (!view->Create(m_image, description)) {
            return nullptr;
        }

        return m_textureViewCaches.emplace(description, std::move(view)).first->second.get();
    }
}
