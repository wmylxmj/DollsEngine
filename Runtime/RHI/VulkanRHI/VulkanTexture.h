#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanTexture {
    public:

    protected:
        VkImage m_image;
        VmaAllocation m_allocation;
    };
}