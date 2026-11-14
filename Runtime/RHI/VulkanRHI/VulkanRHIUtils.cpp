//
// Created by 13973 on 26-11-14.
//

#include "VulkanRHIUtils.h"

namespace DollsEngine
{
    VkAttachmentLoadOp ConvertToVkAttachmentLoadOp(RHIAttachmentLoadOp loadOp)
    {
        switch (loadOp) {
            case RHIAttachmentLoadOp::Load:
                return VK_ATTACHMENT_LOAD_OP_LOAD;
            case RHIAttachmentLoadOp::Clear:
                return VK_ATTACHMENT_LOAD_OP_CLEAR;
            default:
                return VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        }
    }

    VkAttachmentStoreOp ConvertToVkAttachmentStoreOp(RHIAttachmentStoreOp storeOp)
    {

    }

}