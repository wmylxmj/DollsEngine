#pragma once

#include "../../Core/Event/Event.h"

namespace DollsEngine
{
	class Window;

	class WindowEvent : public Event
	{
	public:
		Window* GetWindow() const { return m_window; }

	protected:
		WindowEvent(Window* window) : m_window(window) {}
		Window* m_window;
	};

	class WindowCloseEvent : public WindowEvent
	{
	public:
		WindowCloseEvent(Window* window) : WindowEvent(window) {}
		virtual size_t GetEventTypeId() const override { return DollsEngine::GetEventTypeId<WindowCloseEvent>(); }
	};
}