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

    enum class RHIAttachmentStoreOp {
        Store,
        DontCare,
    };

    struct RHIRenderingColorAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;

        RHIAttachmentLoadOp loadOp = RHIAttachmentLoadOp::DontCare;

        float clearColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    };

    // 深度模板
    struct RHIRenderingDepthStencilAttachmentInfo {
        RHITexture* pTexture = nullptr;
        RHITexture* pResolveTexture = nullptr;

        RHIAttachmentLoadOp depthLoadOp = RHIAttachmentLoadOp::DontCare;
        RHIAttachmentStoreOp depthStoreOp = RHIAttachmentStoreOp::DontCare;
        RHIAttachmentLoadOp stencilLoadOp = RHIAttachmentLoadOp::DontCare;
        RHIAttachmentStoreOp stencilStoreOp = RHIAttachmentStoreOp::DontCare;

        float clearDepth = 1.0f;
        uint32_t clearStencil = 0;
    };

    class RHIRenderPassBeginInfo {
    public:
        // 颜色附件信息
        RHIRenderingDepthStencilAttachmentInfo depthStencilAttachmentInfo;
    };
}
