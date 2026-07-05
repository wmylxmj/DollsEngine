#pragma once

#include "../RHI/RHI.h"
#include "VulkanAPI.h"

namespace DollsEngine
{
	class VulkanRHI : public RHI
	{
	public:
		virtual bool Initialize() override;

	protected:
		bool CreateInstance();

		VkInstance m_instance;
	};
}