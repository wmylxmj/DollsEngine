#pragma once

#include "VulkanAPI.h"
#include "../RHIRenderPass.h"

namespace DollsEngine
{
    VkAttachmentLoadOp ConvertToVkAttachmentLoadOp(RHIAttachmentLoadOp loadOp);
}