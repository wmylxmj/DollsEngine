#pragma once

#include "GenericApplicationMessageHandler.h"
#include "GenericWindow.h"

#include <memory>

namespace DollsEngine
{
	class GenericApplication
	{
	public:
		virtual GenericWindow* CreateWindow(const GenericWindowCreateInfo& createInfo) = 0;
		void SetMessageHandler(GenericApplicationMessageHandler* messageHandler) { m_messageHandler = messageHandler; }

	protected:
		GenericApplicationMessageHandler* m_messageHandler;
	};
}
