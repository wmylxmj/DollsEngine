#pragma once

#include "../RHITexture.h"
#include "VulkanTextureView.h"

namespace DollsEngine
{
    class VulkanTexture : public RHITexture {
    protected:
        VkImage m_image;

    };
}
