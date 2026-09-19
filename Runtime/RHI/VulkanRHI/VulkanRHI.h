#pragma once

#include "../RHI.h"
#include "Platforms/VulkanNativePlatform.h"
#include "VulkanInstance.h"
#include "VulkanDevice.h"

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
		bool CreateDevice();

		std::unique_ptr<VulkanPlatform> m_vulkanPlatform;

		VulkanInstance m_instance;

		VkDebugUtilsMessengerEXT m_debugMessenger;
		VulkanDevice m_device;
	};
}