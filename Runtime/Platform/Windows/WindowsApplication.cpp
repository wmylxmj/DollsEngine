#include "WindowsApplication.h"

#include "../GenericWindowEvent.h"

namespace DollsEngine
{
	std::shared_ptr<GenericWindow> WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::unique_ptr<WindowsWindow> window = std::make_unique<WindowsWindow>();
		window->Create(createInfo);
		window->SetEventCallback([this](Event& event) {
			this->OnEvent(event);
		});

		m_windows.push_back(std::move(window));
		return window;
	}

	void WindowsApplication::OnEvent(Event& event)
	{
		if (event.GetEventTypeId() == GetEventTypeId<GenericWindowCloseEvent>())
		{
			GenericWindowCloseEvent& windowCloseEvent = static_cast<GenericWindowCloseEvent&>(event);
			m_messageHandler->OnWindowClose(windowCloseEvent.GetWindow());
		}
	}
}