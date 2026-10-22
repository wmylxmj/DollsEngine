#pragma once

#include "VulkanAPI.h"
#include "VulkanCommandBuffer.h"

#include <mutex>
#include <vector>
#include <memory>

namespace DollsEngine
{
    class VulkanCommandPool {
    public:
        VkCommandPool GetHandle() const { return m_commandPool; }

    private:
        VkCommandPool m_commandPool;

        std::vector<std::unique_ptr<VulkanCommandBuffer>> m_commandBuffers;
    };
}