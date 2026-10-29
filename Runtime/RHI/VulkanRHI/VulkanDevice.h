#pragma once

#include "VulkanAPI.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"
#include "VulkanCommandPool.h"

#include <vector>
#include <utility>
#include <mutex>
#include <unordered_map>
#include <queue>

namespace DollsEngine
{
	class VulkanDevice
	{
	public:
		VulkanDevice();

        void AddPreferredExtension(const char* extensionName) { m_preferredExtensions.emplace_back(false, extensionName); }

		bool Create(VulkanPhysicalDevice physicalDevice);
		VkDevice GetHandle() const { return m_device; }

		VulkanPhysicalDevice GetPhysicalDevice() const { return m_physicalDevice; }

		VulkanCommandPool* AcquireCommandPool(uint32_t queueFamilyIndex);

	private:
		void FlagExtensionsSupported(const char* layerName = nullptr);

		std::vector<std::pair<bool, const char*>> m_preferredExtensions;
		std::vector<const char*> m_supportedExtensions;

		VkDevice m_device;

		VulkanPhysicalDevice m_physicalDevice;

		VulkanQueue m_graphicsQueue;
		VulkanQueue m_computeQueue;

		std::mutex m_commandPoolMutex;
		std::unordered_map<uint32_t, std::vector<std::unique_ptr<VulkanCommandPool>>> m_commandPools;
		std::unordered_map<uint32_t, std::queue<VulkanCommandPool*>> m_availableCommandPools;
	};
}
