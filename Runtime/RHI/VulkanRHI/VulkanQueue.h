#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanQueue {
    public:
        VulkanQueue(VulkanDevice& device);

    private:
        VkQueue m_queue;
        uint32_t m_queueFamilyIndex;
        uint32_t m_queueIndex;

    };
}


