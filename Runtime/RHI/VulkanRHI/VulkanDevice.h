#pragma once

#include "VulkanAPI.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"

#include <vector>
#include <utility>

namespace DollsEngine
{
	class VulkanDevice
	{
	public:
        void AddPreferredExtension(const char* extensionName) { m_preferredExtensions.emplace_back(false, extensionName); }


		bool Create(VulkanPhysicalDevice physicalDevice);

	private:
		void FlagExtensionsSupported(const char* layerName = nullptr);

		std::vector<std::pair<bool, const char*>> m_preferredExtensions;

		VkDevice m_device;

		VulkanPhysicalDevice m_physicalDevice;

		VulkanQueue m_graphicsQueue;
	};
}
