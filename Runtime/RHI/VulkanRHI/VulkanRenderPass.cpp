#include "VulkanRenderPass.h"

#include "VulkanRHIUtils.h"
#include "VulkanTexture.h"

namespace DollsEngine
{
    void VulkanRenderPassDescription::Initialize(const RHIRenderPassBeginInfo &renderPassBeginInfo)
    {
        for (int i = 0; i < renderPassBeginInfo.colorAttachmentInfos.size(); i++) {
            VkAttachmentDescription attachmentDescription = {};
            attachmentDescription.format = ConvertToVkFormat(renderPassBeginInfo.colorAttachmentInfos[i].pTexture->GetPixelFormat());
            attachmentDescription.samples = VK_SAMPLE_COUNT_1_BIT;
            attachmentDescription.loadOp = ConvertToVkAttachmentLoadOp(renderPassBeginInfo.colorAttachmentInfos[i].loadOp);
            attachmentDescription.storeOp = ConvertToVkAttachmentStoreOp(renderPassBeginInfo.colorAttachmentInfos[i].storeOp);
            attachmentDescription.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
            attachmentDescription.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        }
    }


}