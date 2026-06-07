#pragma once

#include "../GenericApplication.h"
#include "WindowsWindow.h"

#include <vector>

namespace DollsEngine
{
	class WindowsApplication : public GenericApplication
	{
	public:
		static void Initialize();
		virtual void CreateWindow(GenericWindowCreateInfo& createInfo) override;

	private:
		std::vector<WindowsWindow*> m_windows;
	};
}