#include "Application.h"

#include "../Platform/PAL.h"
#include "../Core/Event/Event.h"

namespace DollsEngine
{
	void Application::Create()
	{
		m_platform = std::make_unique<NativePlatform>();
		m_platform->Initialize();
	}

	void Application::Tick()
	{
		m_platform->PumpMessages();
	}

	Window* Application::CreateWindow(const WindowCreateInfo& createInfo)
	{
		std::unique_ptr<Window> window = std::make_unique<NativeWindow>();
		window->Create(createInfo);
		window->SetEventCallback([this](Event& event) {
			this->OnEvent(event);
		});
		Window* windowPtr = window.get();
		m_windows.push_back(std::move(window));
		return windowPtr;
	}

	void Application::OnEvent(Event& event)
	{
		if (event.GetEventTypeId() == GetEventTypeId<WindowCloseEvent>())
		{
			WindowCloseEvent& windowCloseEvent = static_cast<WindowCloseEvent&>(event);
			OnWindowClose(windowCloseEvent);
		}
	}
}