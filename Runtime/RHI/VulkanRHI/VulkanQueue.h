#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanQueue {
    public:
        VulkanQueue(VulkanDevice& device);

        VkQueue GetHandle() const { return m_queue; }
        uint32_t GetQueueFamilyIndex() const { return m_queueFamilyIndex; }

    private:
        VkQueue m_queue;
        uint32_t m_queueFamilyIndex;
        uint32_t m_queueIndex;

    };
}


