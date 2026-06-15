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
		bool useOpenGL;
	};

	class GenericWindow
	{
	public:
		void SetEventCallback(const std::function<void(Event&)>& callback) { m_eventCallback = callback; }

		virtual void Show() = 0;
		virtual void* GetOsWindowHandle() const = 0;

	protected:
		std::function<void(Event&)> m_eventCallback;
	};
}