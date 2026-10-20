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

    }


}
