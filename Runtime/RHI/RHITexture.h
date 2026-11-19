#pragma once

#include <cstdint>

namespace DollsEngine
{
    enum class RHIPixelFormat {
        Undefined,
        B8G8R8A8_UNORM,
        D24_UNORM_S8_UINT,
    };

    struct RHITextureCreateInfo {
    };

    class RHITexture {
    public:
        RHIPixelFormat GetPixelFormat() const { return m_pixelFormat; }
        uint32_t GetWidth() const { return m_width; }
        uint32_t GetHeight() const { return m_height; }
        uint32_t GetSampleCount() const { return m_sampleCount; }

    protected:
        RHIPixelFormat m_pixelFormat = RHIPixelFormat::Undefined;
        uint32_t m_width = 0;
        uint32_t m_height = 0;
        uint32_t m_sampleCount = 1;
    };
}
