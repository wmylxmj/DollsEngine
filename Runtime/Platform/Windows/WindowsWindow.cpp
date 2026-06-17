#include "WindowsWindow.h"

#include "../../core/Event/Events/WindowEvents.h"
#include <tchar.h>

namespace DollsEngine
{
	static bool s_wndClassRegistered = false;

	bool WindowsWindow::Create(const WindowCreateInfo& createInfo)
	{
		if (!s_wndClassRegistered)
		{
			WNDCLASSEX wc = {};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.style = CS_DBLCLKS;
			wc.cbClsExtra = 0;
			wc.cbWndExtra = 0;
			wc.hInstance = GetModuleHandle(NULL);
			wc.hIcon = nullptr;
			wc.hCursor = nullptr;
			wc.hbrBackground = nullptr;
			wc.lpszMenuName = nullptr;
			wc.lpszClassName = TEXT("DOLLS");
			wc.hIconSm = nullptr;

			if (!RegisterClassEx(&wc))
			{
				MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
				return false;
			}
			s_wndClassRegistered = true;
		}

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
}