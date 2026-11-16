#include "VulkanRenderPass.h"

#include "VulkanRHIUtils.h"
#include "VulkanTexture.h"

namespace DollsEngine
{
    void VulkanRenderPassDescription::Initialize(const RHIRenderPassBeginInfo &renderPassBeginInfo)
    {
        m_attachmentDescriptions.clear();

        m_colorAttachmentReferences.clear();
        m_colorResolveAttachmentReferences.clear();
        for (const auto & colorAttachmentInfo : renderPassBeginInfo.colorAttachmentInfos) {
            if (colorAttachmentInfo.pTexture == nullptr) continue;

            const uint32_t sampleCount = colorAttachmentInfo.pTexture->GetSampleCount();

            VkAttachmentDescription attachmentDescription = {};
            attachmentDescription.format = ConvertToVkFormat(colorAttachmentInfo.pTexture->GetPixelFormat());
            attachmentDescription.samples = static_cast<VkSampleCountFlagBits>(sampleCount);
            attachmentDescription.loadOp = ConvertToVkAttachmentLoadOp(colorAttachmentInfo.loadOp);
            attachmentDescription.storeOp = ConvertToVkAttachmentStoreOp(colorAttachmentInfo.storeOp);
            attachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachmentDescription.initialLayout = attachmentDescription.loadOp == VK_ATTACHMENT_LOAD_OP_CLEAR ? VK_IMAGE_LAYOUT_UNDEFINED : VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            m_attachmentDescriptions.push_back(attachmentDescription);

            VkAttachmentReference attachmentReference = {};
            attachmentReference.attachment = static_cast<uint32_t>(m_attachmentDescriptions.size() - 1);
            attachmentReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            m_colorAttachmentReferences.push_back(attachmentReference);

            VkAttachmentReference resolveAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
            if (sampleCount > 1 && colorAttachmentInfo.pResolveTexture != nullptr) {
                VkAttachmentDescription resolveAttachmentDescription = attachmentDescription;
                resolveAttachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
                resolveAttachmentDescription.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                resolveAttachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
                m_attachmentDescriptions.push_back(resolveAttachmentDescription);

                resolveAttachmentReference.attachment = static_cast<uint32_t>(m_attachmentDescriptions.size() - 1);
                resolveAttachmentReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            }
            m_colorResolveAttachmentReferences.push_back(resolveAttachmentReference);
        }

        m_depthStencilAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
        m_depthStencilResolveAttachmentReference = { VK_ATTACHMENT_UNUSED, VK_IMAGE_LAYOUT_UNDEFINED };
        const RHIRenderingDepthStencilAttachmentInfo& depthStencilAttachmentInfo = renderPassBeginInfo.depthStencilAttachmentInfo;
        if (depthStencilAttachmentInfo.pTexture != nullptr) {
            const uint32_t sampleCount = depthStencilAttachmentInfo.pTexture->GetSampleCount();

            VkAttachmentDescription depthStencilAttachmentDescription = {};
            depthStencilAttachmentDescription.format = ConvertToVkFormat(depthStencilAttachmentInfo.pTexture->GetPixelFormat());
            depthStencilAttachmentDescription.samples = static_cast<VkSampleCountFlagBits>(sampleCount);
            depthStencilAttachmentDescription.loadOp = ConvertToVkAttachmentLoadOp(depthStencilAttachmentInfo.depthLoadOp);
            depthStencilAttachmentDescription.storeOp = ConvertToVkAttachmentStoreOp(depthStencilAttachmentInfo.depthStoreOp);
            depthStencilAttachmentDescription.stencilLoadOp = ConvertToVkAttachmentLoadOp(depthStencilAttachmentInfo.stencilLoadOp);
            depthStencilAttachmentDescription.stencilStoreOp = ConvertToVkAttachmentStoreOp(depthStencilAttachmentInfo.stencilStoreOp);

            const bool needsLoad = depthStencilAttachmentDescription.loadOp == VK_ATTACHMENT_LOAD_OP_LOAD || depthStencilAttachmentDescription.stencilLoadOp == VK_ATTACHMENT_LOAD_OP_LOAD;
            depthStencilAttachmentDescription.initialLayout = needsLoad ? VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL : VK_IMAGE_LAYOUT_UNDEFINED;
            depthStencilAttachmentDescription.finalLayout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
            m_attachmentDescriptions.push_back(depthStencilAttachmentDescription);

            m_depthStencilAttachmentReference = {};
            m_depthStencilAttachmentReference.attachment = static_cast<uint32_t>(m_attachmentDescriptions.size() - 1);
            m_depthStencilAttachmentReference.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

            if (sampleCount > 1 && depthStencilAttachmentInfo.pResolveTexture != nullptr) {
                VkAttachmentDescription resolveAttachmentDescription = depthStencilAttachmentDescription;
                resolveAttachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
                resolveAttachmentDescription.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                resolveAttachmentDescription.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
                resolveAttachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
                resolveAttachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
                m_attachmentDescriptions.push_back(resolveAttachmentDescription);

                m_depthStencilResolveAttachmentReference.attachment = static_cast<uint32_t>(m_attachmentDescriptions.size() - 1);
                m_depthStencilResolveAttachmentReference.layout = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
            }
        }
    }

    VulkanRenderPass::VulkanRenderPass(VulkanDevice &device) : m_device(device) {}
    {

    }



}