#pragma once

#include "../RHI.h"
#include "Platforms/VulkanNativePlatform.h"
#include "VulkanLayer.h"
#include "VulkanExtension.h"

#include <memory>

namespace DollsEngine
{
	class VulkanRHI : public RHI
	{
	public:
		virtual bool Initialize() override;

	protected:
		bool CreateInstance();
		bool CreateDebugMessenger();

		std::unique_ptr<VulkanPlatform> m_vulkanPlatform;

		VkInstance m_instance;
		VulkanInstanceLayersCollector m_instanceLayersCollector;
		VulkanInstanceExtensionsCollector m_instanceExtensionsCollector;

		VkDebugUtilsMessengerEXT m_debugMessenger;
	};
}