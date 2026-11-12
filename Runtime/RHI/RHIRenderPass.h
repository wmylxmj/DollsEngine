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

    enum class RHIAccessFlags {
        None = 0,
        IndirectCommandRead = 1 << 0,
        VertexAttributeRead = 1 << 1,
        UniformRead = 1 << 2,
        ShaderRead = 1 << 3,
        ShaderWrite = 1 << 4,
        ColorAttachmentRead = 1 << 5,
        ColorAttachmentWrite = 1 << 6,
        DepthStencilAttachmentRead = 1 << 7,
        DepthStencilAttachmentWrite = 1 <<

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
