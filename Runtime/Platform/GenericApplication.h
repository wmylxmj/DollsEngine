#pragma once

#include "GenericApplicationMessageHandler.h"
#include "GenericWindow.h"

#include <memory>

namespace DollsEngine
{
	class GenericApplication
	{
	public:
		virtual void CreateWindow(const GenericWindowCreateInfo& createInfo) = 0;
		void SetMessageHandler(const std::shared_ptr<GenericApplicationMessageHandler> messageHandler) { m_messageHandler = messageHandler; }

	protected:
		std::shared_ptr<GenericApplicationMessageHandler> m_messageHandler;
	};
}
