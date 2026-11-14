//
// Created by 13973 on 26-10-18.
//

#include "VulkanTexture.h"

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


}