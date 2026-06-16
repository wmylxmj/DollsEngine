#pragma once

#include "../Platform/GenericWindow.h"

namespace DollsEngine
{
	class Window
	{
	public:
		void SetNativeWindow(GenericWindow* nativeWindow) { m_nativeWindow = nativeWindow; }
		void Show() { m_nativeWindow->Show(); }

	private:
		GenericWindow* m_nativeWindow;
	};
}