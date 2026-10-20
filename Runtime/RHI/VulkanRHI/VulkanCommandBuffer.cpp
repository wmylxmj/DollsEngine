//
// Created by 13973 on 26-10-11.
//

#include "VulkanCommandBuffer.h"

#include "VulkanCommandPool.h"

namespace DollsEngine
{
    VulkanCommandBuffer::VulkanCommandBuffer(VulkanDevice &device, VulkanCommandPool &commandPool) :
        m_device(device),
        m_commandPool(commandPool)
    {

    }

    bool VulkanCommandBuffer::Create()
    {
        VkCommandBufferAllocateInfo allocateInfo = {};
        allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocateInfo.commandPool = m_commandPool.GetHandle();
        allocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocateInfo.commandBufferCount = 1;

        if (vkAllocateCommandBuffers(m_device.GetHandle(), &allocateInfo, &m_commandBuffer) != VK_SUCCESS)
        {
            return false;
        }

        return true;
    }


}
