#pragma once

#include "../Core/Event/Event.h"

#include <stdint.h>
#include <memory>
#include <functional>

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
		void SetEventCallback(std::function<void(Event&)> callback) { m_eventCallback = callback; }

	protected:
		std::function<void(Event&)> m_eventCallback;
	};
}