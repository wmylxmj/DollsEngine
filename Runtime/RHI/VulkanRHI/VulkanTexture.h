#pragma once

#include "../RHITexture.h"
#include "VulkanTextureView.h"

#include <memory>

namespace DollsEngine
{
    class VulkanTexture : public RHITexture {
    protected:
        VkImage m_image;
        // 拥有图片
        bool m_isImageOwner;

    };
}
