#pragma once

#include "GenericApplicationMessageHandler.h"

namespace DollsEngine
{
	class GenericApplication
	{
	public:
		void SetMessageHandler(GenericApplicationMessageHandler* messageHandler) { m_messageHandler = messageHandler; }

	protected:
		GenericApplicationMessageHandler* m_messageHandler;
	};
}
