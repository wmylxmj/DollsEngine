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
        }
    }


}