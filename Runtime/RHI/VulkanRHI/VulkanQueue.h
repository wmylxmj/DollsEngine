#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanQueue {
    private:
        VkQueue m_queue;
        uint32_t m_queueFamilyIndex;
        uint32_t m_queueIndex;

    };
}


