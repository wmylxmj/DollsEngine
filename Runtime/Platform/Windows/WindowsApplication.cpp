#include "WindowsApplication.h"

#include "../GenericWindowEvent.h"

namespace DollsEngine
{
	GenericWindow* WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::unique_ptr<WindowsWindow> window = std::make_unique<WindowsWindow>();
		window->Create(createInfo);
		window->SetEventCallback([this](Event& event) {
			this->OnEvent(event);
		});

		GenericWindow* windowPtr = window.get();
		m_windows.push_back(std::move(window));
		return windowPtr;
	}

	void WindowsApplication::PumpMessages()
	{
		if (m_windows.size() > 0) {
			glfwPollEvents();
		}
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