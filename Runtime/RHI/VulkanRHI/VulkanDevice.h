#pragma once

#include "VulkanAPI.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"

namespace DollsEngine
{
	// 设备拓展
	class VulkanDeviceExtension
	{
	public:
		explicit VulkanDeviceExtension(const char* extensionName) : m_extensionName(extensionName), m_isSupported(false) {}
        const char* GetExtensionName() const { return m_extensionName; }
        void SetSupported() { m_isSupported = true; }
        [[nodiscard]] bool IsSupported() const { return m_isSupported; }

    protected:
        const char* m_extensionName;
        bool m_isSupported = false;
    };

	class VulkanDevice
	{
	public:
		bool Initialize(VulkanPhysicalDevice physicalDevice);
	private:
		bool CreateDevice();

		VkDevice m_device;

		VulkanPhysicalDevice m_physicalDevice;
		VkPhysicalDeviceProperties m_physicalDeviceProperties;
		VkPhysicalDeviceIDPropertiesKHR m_physicalDeviceIDProperties;

		VulkanQueue m_graphicsQueue;
	};
}