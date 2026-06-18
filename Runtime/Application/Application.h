#pragma once

#include "../Core/Window.h"
#include "../Core/Platform.h"
#include <memory>

namespace DollsEngine
{
	class Application
	{
	public:
		void Create();
		void Tick();

	protected:
		std::unique_ptr<Platform> m_platform;
		std::vector<std::unique_ptr<Window>> m_windows;
	};
}