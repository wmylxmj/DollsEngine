#pragma once

#include "../RHITexture.h"
#include "VulkanAPI.h"

namespace DollsEngine
{
    VkFormat ConvertToVkFormat(RHIPixelFormat format);

    class VulkanTexture : public RHITexture {
    protected:
        VkImage m_image;

    };
}
