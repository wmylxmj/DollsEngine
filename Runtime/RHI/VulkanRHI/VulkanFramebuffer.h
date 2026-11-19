#pragma once

#include "VulkanAPI.h"

namespace DollsEngine
{
    class VulkanFramebuffer {
    public:
        VkFramebuffer GetHandle() const { return m_framebuffer; }

    private:
        VkFramebuffer m_framebuffer = VK_NULL_HANDLE;


    };
}