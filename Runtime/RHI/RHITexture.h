#pragma once

#include <cstdint>

namespace DollsEngine
{
    enum class RHIPixelFormat {
        Undefined,
        R8G8B8A8_UNORM,
        D24_UNORM_S8_UINT,
    };

    class RHITexture {
    public:
        RHIPixelFormat GetPixelFormat() const { return m_pixelFormat; }

    protected:
        RHIPixelFormat m_pixelFormat = RHIPixelFormat::Undefined;
        // 采样数
    };
}
