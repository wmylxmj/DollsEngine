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
        VkAttachmentReference m_depthStencilAttachmentReference;
        VkAttachmentReference m_depthStencilResolveAttachmentReference;
    };

    class VulkanRenderPass {
    public:
        bool Create(const VulkanRenderPassDescription& description);
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VkRenderPass m_renderPass;
    };
}