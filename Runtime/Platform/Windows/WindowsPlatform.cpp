#include "WindowsPlatform.h"

namespace DollsEngine
{
	bool WindowsPlatform::Initialize()
	{
		return false;
	}

	void WindowsPlatform::PumpMessages()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}