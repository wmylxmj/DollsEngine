#pragma once

#include "VulkanAPI.h"
#include "VulkanCommandBuffer.h"

#include <mutex>

namespace DollsEngine
{
    class VulkanCommandPool {
    public:
        VkCommandPool GetHandle() const { return m_commandPool; }

    private:
        VkCommandPool m_commandPool;
    };
}