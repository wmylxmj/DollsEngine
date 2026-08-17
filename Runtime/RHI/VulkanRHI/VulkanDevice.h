#pragma once

#include "VulkanAPI.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"

#include <vector>

namespace DollsEngine
{
	// 设备拓展
	class VulkanDeviceExtension
	{
	public:
		explicit VulkanDeviceExtension(const char* extensionName) : m_extensionName(extensionName) {}
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
		bool Create(VulkanPhysicalDevice physicalDevice);

	private:
        void FlagExtensionsSupported(const char* layerName = nullptr);


		std::vector<VulkanDeviceExtension> m_preferredExtensions;


		VkDevice m_device;

		VulkanPhysicalDevice m_physicalDevice;

		VulkanQueue m_graphicsQueue;
	};
}