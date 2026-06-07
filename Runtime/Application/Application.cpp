#include "Application.h"

namespace DollsEngine
{
	void Application::Create(GenericApplication* platformApplication)
	{
		m_platformApplication = platformApplication;

		m_platformApplication->SetMessageHandler(this);
	}
	void Application::CreateWindow(GenericWindowCreateInfo createInfo)
	{
		m_platformApplication->CreateWindow(createInfo);
	}
}