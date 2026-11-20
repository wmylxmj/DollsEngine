//
// Created by 13973 on 26-11-8.
//

#include "RHIPresenter.h"

#include "VulkanRHI/VulkanPresenter.h"

namespace DollsEngine
{
    VulkanPresenter::VulkanPresenter(VulkanInstance &instance, VulkanDevice &device, VulkanPlatform &platform) :
        m_instance(instance),
        m_device(device),
        m_platform(platform)
    {

    }


}
