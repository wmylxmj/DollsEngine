#include "ApplicationWindowsPlatform.h"

#include "WindowsWindow.h"
#include "../PAL/WindowEvents.h"

namespace DollsEngine
{
	bool ApplicationWindowsPlatform::Initialize()
	{
		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_DBLCLKS;
		wc.lpfnWndProc = WndProc;
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

		return true;
	}

	void ApplicationWindowsPlatform::PumpMessages()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}