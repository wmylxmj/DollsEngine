//
// Created by 13973 on 26-10-18.
//

#include "VulkanTexture.h"

namespace DollsEngine
{
    VkFormat ConvertToVkFormat(RHIPixelFormat format)
    {
        switch (format) {
            case RHIPixelFormat::R8G8B8A8_UNORM:
                return VK_FORMAT_R8G8B8A8_UNORM;
            default:
                return VK_FORMAT_UNDEFINED;
        }
    }


}