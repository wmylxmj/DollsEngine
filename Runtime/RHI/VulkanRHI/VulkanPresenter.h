#pragma once

#include "VulkanSwapchain.h"
#include "../RHIPresenter.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanPresenter : public RHIPresenter {
    protected:
        VulkanDevice& m_device;

    };
}
