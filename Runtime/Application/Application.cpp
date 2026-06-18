#include "Application.h"

#include "../platform/Platform.h"

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
}