#include "VulkanRenderPass.h"

#include "VulkanRHIUtils.h"
#include "VulkanTexture.h"

namespace DollsEngine
{
    void VulkanRenderPassDescription::Initialize(const RHIRenderPassBeginInfo &renderPassBeginInfo)
    {
        m_attachmentDescriptions.clear();
        for (const auto & colorAttachmentInfo : renderPassBeginInfo.colorAttachmentInfos) {
            VkAttachmentDescription attachmentDescription = {};
            attachmentDescription.format = ConvertToVkFormat(colorAttachmentInfo.pTexture->GetPixelFormat());
            attachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
            attachmentDescription.loadOp = ConvertToVkAttachmentLoadOp(colorAttachmentInfo.loadOp);
            attachmentDescription.storeOp = ConvertToVkAttachmentStoreOp(colorAttachmentInfo.storeOp);
            attachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
            attachmentDescription.initialLayout = attachmentDescription.loadOp == VK_ATTACHMENT_LOAD_OP_CLEAR ? VK_IMAGE_LAYOUT_UNDEFINED : VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            attachmentDescription.finalLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

            m_attachmentDescriptions.push_back(attachmentDescription);
        }
    }


}