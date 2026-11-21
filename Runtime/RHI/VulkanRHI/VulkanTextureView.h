#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    struct VulkanTextureViewDescription
    {

    };
    class VulkanTextureView {
    public:
        VkImageView GetHandle() const { return m_imageView; }

    protected:
        VkImageView m_imageView = VK_NULL_HANDLE;
    };
}
