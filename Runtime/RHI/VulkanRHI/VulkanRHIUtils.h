#pragma once

#include "VulkanAPI.h"
#include "../RHIRenderPass.h"

namespace DollsEngine
{

    VkFormat ConvertToVkFormat(RHIPixelFormat format);


    VkAttachmentLoadOp ConvertToVkAttachmentLoadOp(RHIAttachmentLoadOp loadOp);
    VkAttachmentStoreOp ConvertToVkAttachmentStoreOp(RHIAttachmentStoreOp storeOp);
}