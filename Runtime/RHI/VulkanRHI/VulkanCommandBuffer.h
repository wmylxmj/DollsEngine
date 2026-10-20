#pragma once

#include "VulkanAPI.h"

namespace  DollsEngine
{
    class VulkanDevice;
    class VulkanCommandPool;

    class VulkanCommandBuffer {
    public:
        VkCommandBuffer GetHandle() const { return m_commandBuffer; }

    private:
        VkCommandBuffer m_commandBuffer;

    };
}

