#include "Application.h"

namespace DollsEngine
{
	void Application::Create(std::shared_ptr<GenericApplication> platformApplication)
	{
		m_platformApplication = platformApplication;

		m_platformApplication->SetMessageHandler(this->shared_from_this());
	}

	void Application::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		m_platformApplication->CreateWindow(createInfo);
	}
}