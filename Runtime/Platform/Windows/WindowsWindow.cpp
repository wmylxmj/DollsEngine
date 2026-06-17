#include "WindowsWindow.h"

#include "../../core/Event/Events/WindowEvents.h"

namespace DollsEngine
{
	static uint32_t s_numWindows = 0;




	void WindowsWindow::Show()
	{
		ShowWindow(m_hwnd, SW_SHOW);
		UpdateWindow(m_hwnd);
	}

	void* WindowsWindow::GetOsWindowHandle() const
	{
		return m_hwnd;
	}
}