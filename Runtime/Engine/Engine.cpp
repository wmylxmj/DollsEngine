#include "Engine.h"

#include "../Application/Application.h"

namespace DollsEngine
{
	int Engine::Init()
	{
		return 0;
	}

	void Engine::Tick()
	{
		m_application->Tick();
	}

	bool Engine::ShouldExit() {
		return m_application->ShouldExit();
	}
}