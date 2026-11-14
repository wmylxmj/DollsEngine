//
// Created by 13973 on 26-11-14.
//

#include "VulkanRHIUtils.h"

namespace DollsEngine
{
    VkFormat ConvertToVkFormat(const RHIPixelFormat format)
    {
        switch (format) {
            case RHIPixelFormat::R8G8B8A8_UNORM:
                return VK_FORMAT_R8G8B8A8_UNORM;
            case RHIPixelFormat::D24_UNORM_S8_UINT:
                return VK_FORMAT_D24_UNORM_S8_UINT;
            default:
                return VK_FORMAT_UNDEFINED;
        }
    }



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
        switch (storeOp) {
            case RHIAttachmentStoreOp::Store:
                return VK_ATTACHMENT_STORE_OP_STORE;
            default:
                return VK_ATTACHMENT_STORE_OP_DONT_CARE;
        }
    }
}