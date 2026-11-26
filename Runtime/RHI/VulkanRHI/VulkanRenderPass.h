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
    class VulkanRenderPassDescription
    {
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
     * 渲染通道兼容性描述
     *
     * 仅保存影响 VkRenderPass 兼容性的字段：附件格式、采样数、附件标志
     * 以及颜色/深度模板附件引用。loadOp、storeOp、initialLayout、finalLayout
     * 等不影响兼容性，因此不在这里保存。
     *
     * 两个描述相等时，对应的 VkRenderPass 一定兼容；不相等时不保证不兼容，
     * 因此适合作为保守的缓存 key。如果要缓存 VkRenderPass 对象本身，还需要
     * 把 load/store/layout 等状态一起纳入 key。
     *
     * 当前引擎固定单 subpass。规范中单 subpass 的 resolve 引用可以忽略，
     * 这里仍然保留，作为更保守的兼容性 key。
     */
    class VulkanRenderPassCompatibilityDescription
    {
    public:
        void Initialize(const VulkanRenderPassDescription& description);

        bool operator==(const VulkanRenderPassCompatibilityDescription& other) const;
        bool operator!=(const VulkanRenderPassCompatibilityDescription& other) const { return !(*this == other); }

        uint32_t GetAttachmentCount() const { return static_cast<uint32_t>(m_attachmentFormats.size()); }
        uint32_t GetColorAttachmentCount() const { return static_cast<uint32_t>(m_colorAttachmentIndices.size()); }

        bool HasColorResolveAttachments() const;
        bool HasDepthStencilAttachment() const { return m_depthStencilAttachmentIndex != VK_ATTACHMENT_UNUSED; }
        bool HasDepthStencilResolveAttachment() const { return m_depthStencilResolveAttachmentIndex != VK_ATTACHMENT_UNUSED; }

        const std::vector<VkFormat>& GetAttachmentFormats() const { return m_attachmentFormats; }
        const std::vector<VkSampleCountFlagBits>& GetAttachmentSamples() const { return m_attachmentSamples; }
        const std::vector<VkAttachmentDescriptionFlags>& GetAttachmentFlags() const { return m_attachmentFlags; }
        const std::vector<uint32_t>& GetColorAttachmentIndices() const { return m_colorAttachmentIndices; }
        const std::vector<uint32_t>& GetColorResolveAttachmentIndices() const { return m_colorResolveAttachmentIndices; }
        uint32_t GetDepthStencilAttachmentIndex() const { return m_depthStencilAttachmentIndex; }
        uint32_t GetDepthStencilResolveAttachmentIndex() const { return m_depthStencilResolveAttachmentIndex; }

    private:
        std::vector<VkFormat> m_attachmentFormats;
        std::vector<VkSampleCountFlagBits> m_attachmentSamples;
        std::vector<VkAttachmentDescriptionFlags> m_attachmentFlags;

        std::vector<uint32_t> m_colorAttachmentIndices;
        std::vector<uint32_t> m_colorResolveAttachmentIndices;

        uint32_t m_depthStencilAttachmentIndex = VK_ATTACHMENT_UNUSED;
        uint32_t m_depthStencilResolveAttachmentIndex = VK_ATTACHMENT_UNUSED;
    };

    template<>
    struct Hash<VulkanRenderPassCompatibilityDescription>
    {
        size_t operator()(const VulkanRenderPassCompatibilityDescription& description) const
        {
            size_t seed = 0;

            HashCombine(seed, description.GetAttachmentCount());
            HashCombine(seed, description.GetColorAttachmentCount());
            HashCombine(seed, description.GetDepthStencilAttachmentIndex());
            HashCombine(seed, description.GetDepthStencilResolveAttachmentIndex());

            for (VkFormat format : description.GetAttachmentFormats()) {
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

    class VulkanRenderPass
    {
    public:
        VulkanRenderPass(VulkanDevice& device);

        bool Create(const VulkanRenderPassDescription& description);
        VkRenderPass GetHandle() const { return m_renderPass; }

    private:
        VulkanDevice& m_device;
        VkRenderPass m_renderPass = VK_NULL_HANDLE;
    };
}