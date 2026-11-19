#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanFramebuffer {
    public:
        explicit VulkanFramebuffer(VulkanDevice& device);
        VkFramebuffer GetHandle() const { return m_framebuffer; }

    private:
        VulkanDevice& m_device;

        VkFramebuffer m_framebuffer = VK_NULL_HANDLE;


    };
}