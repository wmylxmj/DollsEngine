#pragma once

#include "VulkanAPI.h"

namespace  DollsEngine
{
    class VulkanCommandBuffer {
    public:
        VkCommandBuffer GetHandle() const { return m_commandBuffer; }

    private:
        VkCommandBuffer m_commandBuffer;

    };
}

