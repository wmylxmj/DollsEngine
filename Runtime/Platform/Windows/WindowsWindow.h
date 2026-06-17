#pragma once

#include "../../Core/Window.h"

#include <Windows.h>

namespace DollsEngine
{

	class WindowsWindow : public Window
	{
	public:


		virtual void Show() override;
		virtual void* GetOsWindowHandle() const override;

	private:
		HWND m_hwnd;
	};
}