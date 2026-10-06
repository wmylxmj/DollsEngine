#include "VulkanSemaphore.h"

#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanSemaphore::Create()
    {
        VkSemaphoreCreateInfo semaphoreCreateInfo = {};
        semaphoreCreateInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

        if (vkCreateSemaphore(m_device.GetHandle(), &semaphoreCreateInfo, nullptr, &m_semaphore) != VK_SUCCESS) {
            return false;
        }
        return true;
    }


}
