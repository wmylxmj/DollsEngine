#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/WindowsWindow.h"
namespace DollsEngine
{
	using NativeWindow = WindowsWindow;
}
#endif