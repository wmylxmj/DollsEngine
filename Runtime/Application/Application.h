#pragma once

#include "../Platform/GenericApplicationMessageHandler.h"
#include "../Platform/GenericApplication.h"

namespace DollsEngine
{
	class Application : public GenericApplicationMessageHandler
	{
	public:
		void Create();
		void Tick();

		GenericWindow* CreateWindow(const GenericWindowCreateInfo& createInfo);

	protected:
		std::unique_ptr<GenericApplication> m_platformApplication;
	};
}