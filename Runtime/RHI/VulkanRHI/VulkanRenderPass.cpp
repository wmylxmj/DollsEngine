#include "VulkanRenderPass.h"

#include "VulkanTexture.h"

namespace DollsEngine
{
    void VulkanRenderPassDescription::Initialize(const RHIRenderPassBeginInfo &renderPassBeginInfo)
    {
        for (int i = 0; i < renderPassBeginInfo.colorAttachmentInfos.size(); i++) {
            VkAttachmentDescription attachmentDescription = {};
        }
    }


}