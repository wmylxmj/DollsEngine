//
// Created by 13973 on 26-10-6.
//

#include "VulkanPresenter.h"


namespace DollsEngine
{
    VulkanPresenter::VulkanPresenter(VulkanInstance &instance, VulkanDevice &device, VulkanPlatform &platform) :
        m_instance(instance),
        m_device(device),
        m_platform(platform)
    {

    }
}
