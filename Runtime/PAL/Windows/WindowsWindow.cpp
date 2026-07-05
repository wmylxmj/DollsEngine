#include "WindowsWindow.h"

#include "../../core/Event/Events/WindowEvents.h"
#include <tchar.h>

namespace DollsEngine
{
	bool WindowsWindow::Create(const WindowCreateInfo& createInfo)
	{
		RECT rect = { 0 };
		rect.right = createInfo.clientWidth;
		rect.bottom = createInfo.clientHeight;
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		m_hwnd = CreateWindowEx(
			0,
			TEXT("DOLLS"),
			TEXT(createInfo.title),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top,
			NULL, NULL, GetModuleHandle(NULL), this
		);

		if (!m_hwnd)
		{
			return false;
		}

		return true;
	}

	void WindowsWindow::Show()
	{
		ShowWindow(m_hwnd, SW_SHOW);
		UpdateWindow(m_hwnd);
	}

	void* WindowsWindow::GetOsWindowHandle() const
	{
		return m_hwnd;
	}

	LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_NCCREATE: {
			CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(cs->lpCreateParams));
			break;
		}

		case WM_CLOSE:
			WindowsWindow* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			WindowCloseEvent event(window);
			window->m_eventCallback(event);
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}