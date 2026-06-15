#pragma once

#include "../GenericApplication.h"
#include "WindowsWindow.h"

#include <vector>

namespace DollsEngine
{
	class WindowsApplication : public GenericApplication
	{
	public:
		virtual GenericWindow* CreateWindow(const GenericWindowCreateInfo& createInfo) override;
		virtual void PumpMessages() override;
		void OnEvent(Event& event);

	private:
		std::vector<std::unique_ptr<WindowsWindow>> m_windows;
	};
}