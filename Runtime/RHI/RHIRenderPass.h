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

    };

    // 深度模板
    struct RHIRenderingDepthStencilAttachmentInfo {
        RHITexture* pTexture;
        RHITexture* pResolveTexture;
        RHIAttachmentLoadOp depthLoadOp;
        RHIAttachmentStoreOp depthStoreOp;
        RHIAttachmentLoadOp stencilLoadOp;
        RHIAttachmentStoreOp stencilStoreOp;
    };

    class RHIRenderPassBeginInfo {
    public:
    };
}
