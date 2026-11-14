#pragma once

#include "VulkanAPI.h"
#include "../RHIRenderPass.h"

#include <vector>

namespace DollsEngine
{
    /* RenderPass来源：1.BeginRenderPass 2.Pipeline */
    class VulkanRenderPassDescription {
    public:
        void Initialize(const RHIRenderPassBeginInfo& renderPassBeginInfo);

    private:
        std::vector<VkAttachmentDescription> m_attachmentDescriptions;

        std::vector<VkAttachmentReference> m_colorAttachmentReferences;
        std::vector<VkAttachmentReference> m_colorResolveAttachmentReferences;
        VkAttachmentReference m_depthStencilAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
        VkAttachmentReference m_depthStencilResolveAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
    };

    class VulkanRenderPass {
    public:
        bool Create(const VulkanRenderPassDescription& description);
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VkRenderPass m_renderPass;
    };
}