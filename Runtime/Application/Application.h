#pragma once

#include "../Platform/GenericApplicationMessageHandler.h"
#include "../Platform/GenericApplication.h"
#include "Window.h"

namespace DollsEngine
{
	class Application : public GenericApplicationMessageHandler
	{
	public:
		void Create();
		void Tick();

		Window* CreateWindow(const GenericWindowCreateInfo& createInfo);

	protected:
		std::unique_ptr<GenericApplication> m_platformApplication;
		std::vector<std::unique_ptr<Window>> m_windows;
	};
}