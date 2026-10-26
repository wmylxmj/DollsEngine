#pragma once

#include "VulkanAPI.h"

namespace  DollsEngine
{
    class VulkanDevice;
    class VulkanCommandPool;

    class VulkanCommandBuffer {
    public:
        VulkanCommandBuffer(VulkanDevice& device, VulkanCommandPool& commandPool);

        bool Create(VkCommandBufferLevel commandBufferLevel);
        VkCommandBuffer GetHandle() const { return m_commandBuffer; }

        VkCommandBufferLevel GetCommandBufferLevel() const { return m_commandBufferLevel; }

    private:
        VulkanDevice& m_device;
        VulkanCommandPool& m_commandPool;

        VkCommandBuffer m_commandBuffer;
        VkCommandBufferLevel m_commandBufferLevel;


    };
}

