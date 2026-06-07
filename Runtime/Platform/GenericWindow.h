#pragma once

#include <stdint.h>

namespace DollsEngine
{
	struct GenericWindowCreateInfo
	{
		const char* title;
		uint32_t clientWidth;
		uint32_t clientHeight;
	};

	class GenericWindow
	{
	public:
		virtual void Show() = 0;
		virtual void* GetOSWindowHandle() const = 0;
	};
}