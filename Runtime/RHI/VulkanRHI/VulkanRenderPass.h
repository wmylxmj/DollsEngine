#pragma once

#include "VulkanAPI.h"
#include "../RHIRenderPass.h"
#include "../../Core/Hash/Hash.h"

#include <vector>

namespace DollsEngine
{
    class VulkanDevice;

    /**
     * RenderPass来源：1.BeginRenderPass 2.Pipeline
     */
    class VulkanRenderPassDescription {
    public:
        void Initialize(const RHIRenderPassBeginInfo& renderPassBeginInfo);

        const std::vector<VkAttachmentDescription>& GetAttachmentDescriptions() const { return m_attachmentDescriptions; }
        const std::vector<VkAttachmentReference>& GetColorAttachmentReferences() const { return m_colorAttachmentReferences; }
        const std::vector<VkAttachmentReference>& GetColorResolveAttachmentReferences() const { return m_colorResolveAttachmentReferences; }
        const VkAttachmentReference& GetDepthStencilAttachmentReference() const { return m_depthStencilAttachmentReference; }
        const VkAttachmentReference& GetDepthStencilResolveAttachmentReference() const { return m_depthStencilResolveAttachmentReference; }

        bool HasColorResolveAttachments() const { return m_hasColorResolveAttachments; }
        bool HasDepthStencilAttachment() const { return m_depthStencilAttachmentReference.attachment != VK_ATTACHMENT_UNUSED; }
        bool HasDepthStencilResolveAttachment() const { return m_depthStencilResolveAttachmentReference.attachment != VK_ATTACHMENT_UNUSED; }

    private:
        std::vector<VkAttachmentDescription> m_attachmentDescriptions;

        std::vector<VkAttachmentReference> m_colorAttachmentReferences;
        std::vector<VkAttachmentReference> m_colorResolveAttachmentReferences;
        VkAttachmentReference m_depthStencilAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
        VkAttachmentReference m_depthStencilResolveAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };

        bool m_hasColorResolveAttachments = false;
    };

    /**
     * VkRenderPass compatibility key.
     *
     * Used for framebuffer cache bucketing. Do NOT use this alone as the cache
     * key for VkRenderPass objects, because load/store ops and layouts are
     * intentionally excluded.
     */
    class VulkanRenderPassCompatibilityDescription {
    public:
        void Initialize(const VulkanRenderPassDescription& description);

        bool operator==(const VulkanRenderPassCompatibilityDescription& other) const;

        uint32_t GetAttachmentCount() const { return static_cast<uint32_t>(m_attachmentFormat.size()); }
        uint32_t GetColorAttachmentCount() const { return static_cast<uint32_t>(m_colorAttachmentIndices.size()); }
        bool HasColorResolveAttachments() const { for (uint32_t attachment : m_colorResolveAttachmentIndices) { if (attachment != VK_ATTACHMENT_UNUSED) return true; } return false; }
        bool HasDepthStencilAttachment() const { return m_depthStencilAttachmentIndex != VK_ATTACHMENT_UNUSED; }
        bool HasDepthStencilResolveAttachment() const { return m_depthStencilResolveAttachmentIndex != VK_ATTACHMENT_UNUSED; }

        const std::vector<VkFormat>& GetAttachmentFormat() const { return m_attachmentFormat; }
        const std::vector<VkSampleCountFlagBits>& GetAttachmentSamples() const { return m_attachmentSamples; }
        const std::vector<VkAttachmentDescriptionFlags>& GetAttachmentFlags() const { return m_attachmentFlags; }
        const std::vector<uint32_t>& GetColorAttachmentIndices() const { return m_colorAttachmentIndices; }
        const std::vector<uint32_t>& GetColorResolveAttachmentIndices() const { return m_colorResolveAttachmentIndices; }
        uint32_t GetDepthStencilAttachmentIndex() const { return m_depthStencilAttachmentIndex; }
        uint32_t GetDepthStencilResolveAttachmentIndex() const { return m_depthStencilResolveAttachmentIndex; }

    private:
        std::vector<VkFormat> m_attachmentFormat;
        std::vector<VkSampleCountFlagBits> m_attachmentSamples;
        std::vector<VkAttachmentDescriptionFlags> m_attachmentFlags;

        std::vector<uint32_t> m_colorAttachmentIndices;
        std::vector<uint32_t> m_colorResolveAttachmentIndices;

        uint32_t m_depthStencilAttachmentIndex = VK_ATTACHMENT_UNUSED;
        uint32_t m_depthStencilResolveAttachmentIndex = VK_ATTACHMENT_UNUSED;
    };

    template<>
    struct Hash<VulkanRenderPassCompatibilityDescription> {
        size_t operator()(const VulkanRenderPassCompatibilityDescription& description) const
        {
            size_t seed = 0;

            HashCombine(seed, description.GetAttachmentCount());
            HashCombine(seed, description.GetDepthStencilAttachmentIndex());
            HashCombine(seed, description.GetDepthStencilResolveAttachmentIndex());

            for (VkFormat format : description.GetAttachmentFormat()) {
                HashCombine(seed, format);
            }
            for (VkSampleCountFlagBits samples : description.GetAttachmentSamples()) {
                HashCombine(seed, samples);
            }
            for (VkAttachmentDescriptionFlags flags : description.GetAttachmentFlags()) {
                HashCombine(seed, flags);
            }
            for (uint32_t index : description.GetColorAttachmentIndices()) {
                HashCombine(seed, index);
            }
            for (uint32_t index : description.GetColorResolveAttachmentIndices()) {
                HashCombine(seed, index);
            }

            return seed;
        }
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