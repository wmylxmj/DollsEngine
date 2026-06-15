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

	void Application::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		m_platformApplication->CreateWindow(createInfo);
	}
}