#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    /* RenderPass来源：1.BeginRenderPass 2.Pipeline */
    class VulkanRenderPassDescription {
    };

    class VulkanRenderPass {
    public:
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VkRenderPass m_renderPass;
    };
}