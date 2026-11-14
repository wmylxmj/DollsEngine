#pragma once

namespace DollsEngine
{
    enum class RHIPixelFormat {
        Undefined,
        R8G8B8A8_UNORM,
    };

    class RHITexture {
    protected:
        RHIPixelFormat m_pixelFormat = RHIPixelFormat::Undefined;
    };
}
