#pragma once

#include "RHITexture.h"

#include <cstdint>

namespace DollsEngine
{
    enum class RHIAttachmentLoadOp {
        Load,
        Clear,
        DontCare
    };

    enum class RHIAttachmentStoreOp {
        Store,
        DontCare
    };

    struct RHIRenderingColorAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;
        RHIAttachmentLoadOp loadOp;
        RHIAttachmentStoreOp storeOp;
        float clearColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    };

    // 深度模板
    struct RHIRenderingDepthStencilAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;
        RHIAttachmentLoadOp depthLoadOp;
        RHIAttachmentStoreOp depthStoreOp;
        RHIAttachmentLoadOp stencilLoadOp;
        RHIAttachmentStoreOp stencilStoreOp;
        float clearDepth = 1.0f;
    };

    class RHIRenderPassBeginInfo {
    public:
    };
}
