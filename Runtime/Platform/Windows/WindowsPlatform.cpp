#include "WindowsPlatform.h"

#include "WindowsWindow.h"
#include "../../Core/Event/Events/WindowEvents.h"

namespace DollsEngine
{
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