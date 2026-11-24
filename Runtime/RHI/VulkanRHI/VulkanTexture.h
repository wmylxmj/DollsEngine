#pragma once

#include "../RHITexture.h"
#include "VulkanTextureView.h"

#include <unordered_map>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanTexture : public RHITexture {
    public:
        explicit VulkanTexture(VulkanDevice& device);
        ~VulkanTexture();

        // 外部 VkImage 路径：只包装，不拥有 image
        bool Create(VkImage image, const RHITextureCreateInfo& createInfo);

        VulkanTextureView* GetOrCreateView(const VulkanTextureViewDescription& description);

        VkImage GetImage() const { return m_image; }
        bool IsImageOwner() const { return m_isImageOwner; }

    protected:
        VulkanDevice& m_device;
        VkImage m_image = VK_NULL_HANDLE;
        bool m_isImageOwner = false;
        // 纹理视图缓存
        std::shared_mutex m_textureViewCachesMutex;
        std::unordered_map<VulkanTextureViewDescription, std::unique_ptr<VulkanTextureView>, Hash<VulkanTextureViewDescription>> m_textureViewCaches;
    };
}
