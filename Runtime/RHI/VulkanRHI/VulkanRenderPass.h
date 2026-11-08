#pragma once

#include "VulkanAPI.h"

#include <vector>

namespace DollsEngine
{
    /* RenderPass来源：1.BeginRenderPass 2.Pipeline */
    class VulkanRenderPassDescription {
    private:
        std::vector<VkAttachmentDescription> m_attachmentDescriptions;

        std::vector<VkAttachmentReference> m_colorAttachmentReferences;
        // 深度模板
        VkAttachmentReference m_depthStencilAttachmentReference;
    };

    class VulkanRenderPass {
    public:
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VkRenderPass m_renderPass;
    };
}