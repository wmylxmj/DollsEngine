//
// Created by 13973 on 26-10-26.
//

#include "RHITexture.h"

namespace DollsEngine
{
    RHITexture::RHITexture(const RHITextureCreateInfo& createInfo)
        : m_pixelFormat(createInfo.pixelFormat)
        , m_width(createInfo.width)
        , m_height(createInfo.height)
        , m_sampleCount(createInfo.sampleCount)
    {
    }
}
