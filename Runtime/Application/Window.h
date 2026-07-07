#pragma once

#include <functional>
#include <cstdint>

namespace DollsEngine
{
	class Event;

	struct WindowCreateInfo
	{
		const char* title;
		uint32_t clientWidth;
		uint32_t clientHeight;
	};

	class Window
	{
	public:
		virtual bool Create(const WindowCreateInfo& createInfo) = 0;
		virtual void Show() = 0;
		virtual void* GetOsWindowHandle() const = 0;

		void SetEventCallback(const std::function<void(Event&)>& callback) { m_eventCallback = callback; }

	protected:
		std::function<void(Event&)> m_eventCallback;
	};
}