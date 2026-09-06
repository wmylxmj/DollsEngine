//
// Created by 13973 on 26-8-1.
//

#include "VulkanQueue.h"

#include "VulkanDevice.h"

namespace DollsEngine
{
    void VulkanQueue::Initialize(uint32_t queueFamilyIndex, uint32_t queueIndex)
    {
        m_queueFamilyIndex = queueFamilyIndex;
        m_queueIndex = queueIndex;

        vkGetDeviceQueue(m_device.GetHandle(), m_queueFamilyIndex, m_queueIndex, &m_queue);
    }

}
