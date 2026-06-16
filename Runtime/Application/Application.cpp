#include "Application.h"

#include "../Platform/Windows/WindowsApplication.h"

namespace DollsEngine
{
	void Application::Create()
	{
#ifdef DOLLS_PLATFORM_WINDOWS
		m_platformApplication = std::make_unique<WindowsApplication>();
		m_platformApplication->SetMessageHandler(this);
#endif
	}

	void Application::Tick()
	{
		m_platformApplication->PumpMessages();
	}

	Window* Application::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::unique_ptr<Window> window = std::make_unique<Window>();
		window->SetNativeWindow(m_platformApplication->CreateWindow(createInfo));
		Window* windowPtr = window.get();
		m_windows.push_back(std::move(window));
		return windowPtr;
	}
}