#pragma once

#include "VulkanAPI.h"
#include "../RHIRenderPass.h"

#include <vector>

namespace DollsEngine
{
    class VulkanDevice;

    /* RenderPass来源：1.BeginRenderPass 2.Pipeline */
    class VulkanRenderPassDescription {
    public:
        void Initialize(const RHIRenderPassBeginInfo& renderPassBeginInfo);

        const std::vector<VkAttachmentDescription>& GetAttachmentDescriptions() const { return m_attachmentDescriptions; }

        bool HasColorResolveAttachments() const { return m_hasColorResolveAttachments; }
        bool HasDepthStencilResolveAttachments() const { return m_depthStencilResolveAttachmentReference.attachment != VK_ATTACHMENT_UNUSED; }

    private:
        std::vector<VkAttachmentDescription> m_attachmentDescriptions;

        std::vector<VkAttachmentReference> m_colorAttachmentReferences;
        std::vector<VkAttachmentReference> m_colorResolveAttachmentReferences;
        VkAttachmentReference m_depthStencilAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
        VkAttachmentReference m_depthStencilResolveAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };

        bool m_hasColorResolveAttachments = false;
    };

    class VulkanRenderPass {
    public:
        VulkanRenderPass(VulkanDevice& device);

        bool Create(const VulkanRenderPassDescription& description);
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VulkanDevice& m_device;
        VkRenderPass m_renderPass = VK_NULL_HANDLE;
    };
}