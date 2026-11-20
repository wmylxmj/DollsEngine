#pragma once

#include "VulkanInstance.h"
#include "VulkanSwapchain.h"
#include "../RHIPresenter.h"

namespace DollsEngine
{
    class VulkanDevice;

    class VulkanPresenter : public RHIPresenter {
    public:

    protected:
        VulkanInstance& m_instance;
        VulkanDevice& m_device;

    };
}
