#pragma once

#include "VulkanAPI.h"
#include "VulkanCommandBuffer.h"

#include <mutex>
#include <vector>
#include <memory>
#include <queue>
#include <unordered_map>

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanCommandPool {
    public:
        VulkanCommandPool(VulkanDevice& device);
        bool Create(uint32_t queueFamilyIndex);
        VkCommandPool GetHandle() const { return m_commandPool; }

        VulkanCommandBuffer* AcquireCommandBuffer(VkCommandBufferLevel commandBufferLevel);

    private:
        VulkanDevice& m_device;
        VkCommandPool m_commandPool;

        std::mutex m_mutex;
        std::unordered_map<VkCommandBufferLevel, std::vector<std::unique_ptr<VulkanCommandBuffer>>> m_commandBuffers;
        std::unordered_map<VkCommandBufferLevel, std::queue<VulkanCommandBuffer*>> m_availableCommandBuffers;
    };
}