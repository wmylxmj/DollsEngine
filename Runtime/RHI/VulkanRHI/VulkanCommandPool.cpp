//
// Created by 13973 on 26-10-19.
//

#include "VulkanCommandPool.h"

namespace DollsEngine
{
    VulkanCommandPool::VulkanCommandPool(VulkanDevice &device) :
        m_device(device)
    {

    }

    bool VulkanCommandPool::Create(uint32_t queueFamilyIndex)
    {
        VkCommandPoolCreateInfo commandPoolCreateInfo = {};
        commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        commandPoolCreateInfo.queueFamilyIndex = queueFamilyIndex;
        commandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

        if (vkCreateCommandPool(m_device.GetDevice(), &commandPoolCreateInfo, nullptr, &m_commandPool) != VK_SUCCESS) {
            return false;
        }

        return true;
    }


    VulkanCommandBuffer *VulkanCommandPool::AcquireCommandBuffer(VkCommandBufferLevel commandBufferLevel)
    {

    }


}