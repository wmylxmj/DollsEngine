#include "Engine.h"

#include "../Application/Application.h"
#include "../RHI/RHIRuntime.h"

namespace DollsEngine
{
	int Engine::Init()
	{
		if (!InitializeRHI()) return -1;
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