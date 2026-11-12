#pragma once

#include "RHITexture.h"

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
        RHITexture* pTexture;
        RHITexture* pResolveTexture;
        RHIAttachmentLoadOp loadOp;
        RHIAttachmentStoreOp storeOp;
        float clearColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    };

    // 深度模板
    struct RHIRenderingDepthStencilAttachmentInfo {
        RHITexture* pTexture;
        RHITexture* pResolveTexture;
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
