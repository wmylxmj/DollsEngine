#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanQueue {
    public:
        VulkanQueue(VulkanDevice& device) : m_device(device) {}

        void Initialize(uint32_t queueFamilyIndex, uint32_t queueIndex);

        VkQueue GetHandle() const { return m_queue; }
        uint32_t GetQueueFamilyIndex() const { return m_queueFamilyIndex; }
        uint32_t GetQueueIndex() const { return m_queueIndex; }

    private:
        VkQueue m_queue;
        uint32_t m_queueFamilyIndex;
        uint32_t m_queueIndex;

        VulkanDevice& m_device;
    };
}


