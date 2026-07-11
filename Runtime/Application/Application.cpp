#include "Application.h"

#include "Platforms/NativeWindow.h"
#include "Platforms/NativePlatformService.h"
#include "../Core/Event/Event.h"

namespace DollsEngine
{
	void Application::Create()
	{
		m_platformService = std::make_unique<NativePlatformService>();
		m_platformService->Initialize();
	}

	void Application::Tick()
	{
		m_platformService->PumpMessages();
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