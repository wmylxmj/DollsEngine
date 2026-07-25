#pragma once

#include "../RHI.h"
#include "Platforms/VulkanNativePlatform.h"
#include "VulkanLayer.h"
#include "VulkanExtension.h"

namespace DollsEngine
{
	class VulkanRHI : public RHI
	{
	public:
		virtual bool Initialize() override;

	protected:
		bool CreateInstance();

		VkInstance m_instance;
		VulkanInstanceLayersCollector m_instanceLayersCollector;
		VulkanInstanceExtensionsCollector m_instanceExtensionsCollector;
	};
}