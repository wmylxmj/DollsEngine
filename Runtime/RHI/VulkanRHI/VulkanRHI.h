#pragma once

#include "../RHI.h"
#include "VulkanApi.h"

namespace DollsEngine
{
	class VulkanRHI : public RHI
	{
	public:
		virtual bool Initialize() override;

	protected:
		VkInstance m_instance;
	};
}