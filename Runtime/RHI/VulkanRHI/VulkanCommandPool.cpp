//
// Created by 13973 on 26-10-19.
//

#include "VulkanCommandPool.h"

#include "VulkanDevice.h"

namespace DollsEngine
{
    VulkanCommandPool::VulkanCommandPool(VulkanDevice &device) :
        m_device(device)
    {
        m_commandBuffers[VK_COMMAND_BUFFER_LEVEL_PRIMARY] = std::vector<std::unique_ptr<VulkanCommandBuffer>>();
        m_commandBuffers[VK_COMMAND_BUFFER_LEVEL_SECONDARY] = std::vector<std::unique_ptr<VulkanCommandBuffer>>();
        m_availableCommandBuffers[VK_COMMAND_BUFFER_LEVEL_PRIMARY] = std::queue<VulkanCommandBuffer*>();
        m_availableCommandBuffers[VK_COMMAND_BUFFER_LEVEL_SECONDARY] = std::queue<VulkanCommandBuffer*>();
    }

    bool VulkanCommandPool::Create(uint32_t queueFamilyIndex)
    {
        m_queueFamilyIndex = queueFamilyIndex;

        VkCommandPoolCreateInfo commandPoolCreateInfo = {};
        commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        commandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;
        commandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

        if (vkCreateCommandPool(m_device.GetHandle(), &commandPoolCreateInfo, nullptr, &m_commandPool) != VK_SUCCESS) {
            return false;
        }

        return true;
    }


    VulkanCommandBuffer *VulkanCommandPool::AcquireCommandBuffer(VkCommandBufferLevel commandBufferLevel)
    {
        std::lock_guard<std::mutex> lockGuard(m_mutex);

        VulkanCommandBuffer* pCommandBuffer = nullptr;

        if (!m_availableCommandBuffers[commandBufferLevel].empty()) {
            pCommandBuffer = m_availableCommandBuffers[commandBufferLevel].front();
            m_availableCommandBuffers[commandBufferLevel].pop();
        }

        if (pCommandBuffer == nullptr) {
            std::unique_ptr<VulkanCommandBuffer> pNewCommandBuffer = std::make_unique<VulkanCommandBuffer>(m_device, *this);
            pNewCommandBuffer->Create(commandBufferLevel);
            m_commandBuffers[commandBufferLevel].push_back(std::move(pNewCommandBuffer));
            pCommandBuffer = pNewCommandBuffer.get();
        }

        return pCommandBuffer;
    }
}
