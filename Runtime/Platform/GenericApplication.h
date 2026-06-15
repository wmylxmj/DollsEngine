#pragma once

#include "GenericApplicationMessageHandler.h"
#include "GenericWindow.h"

#include <memory>

namespace DollsEngine
{
	class GenericApplication
	{
	public:
		GenericApplication() : m_messageHandler(nullptr) {}
		void SetMessageHandler(GenericApplicationMessageHandler* messageHandler) { m_messageHandler = messageHandler; }

		virtual GenericWindow* CreateWindow(const GenericWindowCreateInfo& createInfo) = 0;
		virtual void PumpMessages() = 0;

	protected:
		GenericApplicationMessageHandler* m_messageHandler;
	};
}
