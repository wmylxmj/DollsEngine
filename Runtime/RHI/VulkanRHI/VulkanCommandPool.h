#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanCommandPool {
    public:
        VkCommandPool GetHandle() const { return m_commandPool; }

    private:
        VkCommandPool m_commandPool;
    };
}