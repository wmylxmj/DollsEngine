#include "Application.h"

#include "../platform/Platform.h"
#include "../Core/Event/Event.h"

namespace DollsEngine
{
	void Application::Create()
	{
		m_platform = std::make_unique<NativePlatform>();
	}

	void Application::Tick()
	{
		m_platform->PumpMessages();
	}

	Window* Application::CreateWindow(const WindowCreateInfo& createInfo)
	{
		return nullptr;
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