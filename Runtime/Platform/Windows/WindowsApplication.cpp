#include "WindowsApplication.h"

#include "WindowsWindowEvent.h"

namespace DollsEngine
{
	std::shared_ptr<GenericWindow> WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::shared_ptr<WindowsWindow> window = std::make_shared<WindowsWindow>();
		window->Create(this, createInfo);
		window->SetEventCallback([](Event& event) {
			if (event.GetEventTypeId() == GetEventTypeId<WindowsWindowCloseEvent>())
			{
				static_cast<WindowsWindowCloseEvent&>(event).GetWindow()->GetOwningApplication()->OnEvent(event);
			}
		});

		m_windows.push_back(window);
		return window;
	}

	void WindowsApplication::OnEvent(Event& event)
	{
		if (event.GetEventTypeId() == GetEventTypeId<WindowsWindowCloseEvent>())
		{
			WindowsWindowCloseEvent& windowCloseEvent = static_cast<WindowsWindowCloseEvent&>(event);
			m_messageHandler->OnWindowClose(*windowCloseEvent.GetWindow());
		}
	}
}