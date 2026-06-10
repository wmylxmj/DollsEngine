#pragma once

#include "../GenericApplication.h"
#include "WindowsWindow.h"

#include <vector>

namespace DollsEngine
{
	class WindowsApplication : public GenericApplication
	{
	public:
		virtual std::shared_ptr<GenericWindow> CreateWindow(const GenericWindowCreateInfo& createInfo) override;

	private:
		std::vector<std::shared_ptr<WindowsWindow>> m_windows;
	};
}