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

    class RHIRenderingColorAttachmentInfo {
    public:
        RHITexture* pTexture;
        RHITexture* pResolveTexture;
        RHIAttachmentLoadOp loadOp;
        RHIAttachmentStoreOp storeOp;

    };

    // 深度模板

    class RHIRenderPass {

    };
}
