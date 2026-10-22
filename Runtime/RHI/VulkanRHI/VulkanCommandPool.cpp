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

    }


    VulkanCommandBuffer *VulkanCommandPool::AcquireCommandBuffer(VkCommandBufferLevel commandBufferLevel)
    {

    }


}