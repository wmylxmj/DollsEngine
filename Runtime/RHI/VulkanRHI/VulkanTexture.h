#pragma once

#include "../RHITexture.h"
#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanTexture : public RHITexture {
    protected:
        VkImage m_image;

    };
}
