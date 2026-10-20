#pragma once

#include "VulkanAPI.h"

namespace  DollsEngine
{
    class VulkanDevice;
    class VulkanCommandPool;

    class VulkanCommandBuffer {
    public:
        VulkanCommandBuffer(VulkanDevice& device, VulkanCommandPool& commandPool);

        bool Create();

    private:
        VulkanDevice& m_device;
        VulkanCommandPool& m_commandPool;

        VkCommandBuffer m_commandBuffer;

    };
}

