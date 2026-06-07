#pragma once

#include "GenericApplicationMessageHandler.h"
#include "GenericWindow.h"

namespace DollsEngine
{
	class GenericApplication
	{
	public:
		virtual void CreateWindow(GenericWindowCreateInfo& createInfo) = 0;
		void SetMessageHandler(GenericApplicationMessageHandler* messageHandler) { m_messageHandler = messageHandler; }

	protected:
		GenericApplicationMessageHandler* m_messageHandler;
	};
}
