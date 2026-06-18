#pragma once

#ifdef DOLLS_PLATFORM_WINDOWS
#include "Windows/WindowsWindow.h"
#include "Windows/WindowsPlatform.h"
namespace DollsEngine
{
	using NativeWindow = WindowsWindow;
	using NativePlatform = WindowsPlatform;
}
#endif