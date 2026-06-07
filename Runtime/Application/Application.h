#pragma once

#include "../Platform/GenericApplicationMessageHandler.h"
#include "../Platform/GenericApplication.h"

namespace DollsEngine
{
	class Application : public GenericApplicationMessageHandler
	{
	public:
		void Create(GenericApplication* platformApplication);

		void CreateWindow(GenericWindowCreateInfo createInfo);

	protected:
		GenericApplication* m_platformApplication;
	};
}