#pragma once

#include "../Core/Window.h"
#include <memory>

namespace DollsEngine
{
	class Application
	{
	public:
		void Create();
		void Tick();

	protected:
		std::vector<std::unique_ptr<Window>> m_windows;
	};
}