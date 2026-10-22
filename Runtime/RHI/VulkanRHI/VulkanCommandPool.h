#pragma once

#include "VulkanAPI.h"
#include "VulkanCommandBuffer.h"

#include <mutex>
#include <vector>
#include <memory>
#include <utility>

namespace DollsEngine
{
    class VulkanCommandPool {
    public:
        VkCommandPool GetHandle() const { return m_commandPool; }

        VulkanCommandBuffer* AcquireCommandBuffer(VkCommandBufferLevel commandBufferLevel);

    private:
        VkCommandPool m_commandPool;

        std::mutex m_mutex;
        std::pair<VkCommandBufferLevel, std::vector<std::unique_ptr<VulkanCommandBuffer>>> m_commandBuffers;
        std::pair<VkCommandBufferLevel, std::vector<VulkanCommandBuffer*>>
    };
}