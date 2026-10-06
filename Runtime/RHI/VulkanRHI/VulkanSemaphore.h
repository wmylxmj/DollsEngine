#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanSemaphore {
    public:
        VulkanSemaphore(VulkanDevice& device) : m_device(device) {}

        VkSemaphore GetHandle() const { return m_semaphore; }

    protected:
        VulkanDevice& m_device;

        VkSemaphore m_semaphore = VK_NULL_HANDLE;


    };
}
