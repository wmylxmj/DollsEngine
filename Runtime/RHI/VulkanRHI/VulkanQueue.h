#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanQueue {
    public:
        VulkanQueue(VulkanDevice& device);

        VkQueue GetQueue() const { return m_queue; }

    private:
        VkQueue m_queue;
        uint32_t m_queueFamilyIndex;
        uint32_t m_queueIndex;

    };
}


