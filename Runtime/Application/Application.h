#pragma once

#include "../Core/Window.h"
#include "../Core/Platform.h"
#include "../Core/Event/Events/WindowEvents.h"

#include <memory>

namespace DollsEngine
{
	class Application
	{
	public:
		void Create();
		void Tick();

		Window* CreateWindow(const WindowCreateInfo& createInfo);

	protected:
		void OnEvent(Event& event);

		virtual void OnWindowClose(WindowCloseEvent& event) {}

		std::unique_ptr<Platform> m_platform;
		std::vector<std::unique_ptr<Window>> m_windows;
	};
}