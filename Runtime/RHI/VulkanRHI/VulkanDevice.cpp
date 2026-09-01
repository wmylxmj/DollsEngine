#include "VulkanDevice.h"

namespace DollsEngine
{
    bool VulkanDevice::Create(VulkanPhysicalDevice physicalDevice)
    {
        m_physicalDevice = physicalDevice;

        return true;
    }

    void VulkanDevice::FlagExtensionsSupported(const char *layerName) {
        uint32_t extensionCount;
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetHandle(), layerName, &extensionCount, nullptr);

        std::vector<VkExtensionProperties> availableExtensions(extensionCount);
        vkEnumerateDeviceExtensionProperties(m_physicalDevice.GetHandle(), layerName, &extensionCount, availableExtensions.data());

        for (const char *requiredExtension : m_requiredExtensions) {
            bool hasExtension = false;
            for (const VkExtensionProperties &availableExtension : availableExtensions) {
                if (strcmp(requiredExtension, availableExtension.extensionName) == 0) {
                    hasExtension = true;
    }


}