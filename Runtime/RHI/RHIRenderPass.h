#pragma once

#include "RHITexture.h"

#include <cstdint>
#include <vector>

namespace DollsEngine
{
    enum class RHIAttachmentLoadOp {
        Load,
        Clear,
        DontCare,
    };


    struct RHIRenderingColorAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;
        float clearColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    };

    // 深度模板
    struct RHIRenderingDepthStencilAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;
        float clearDepth = 1.0f;
        uint32_t clearStencil = 0;
    };

    class RHIRenderPassBeginInfo {
    public:
    };
}
