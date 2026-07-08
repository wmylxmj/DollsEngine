#pragma once

#include "Window.h"
#include "PlatformService.h"
#include "WindowEvents.h"

#include <memory>

namespace DollsEngine
{
	class Application
	{
	public:
		void Create();
		void Tick();

		Window* CreateWindow(const WindowCreateInfo& createInfo);
		bool ShouldExit() { return m_shouldExit; }


	protected:
		void OnEvent(Event& event);

		virtual void OnWindowClose(WindowCloseEvent& event) {}

		bool m_shouldExit = false;
		std::unique_ptr<PlatformService> m_platform;
		std::vector<std::unique_ptr<Window>> m_windows;
	};
}