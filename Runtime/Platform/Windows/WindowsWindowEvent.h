#pragma once

#include "../../Core/Event/Event.h"

namespace DollsEngine
{
	class WindowsWindow;

	class WindowsWindowEvent : public Event
	{
	public:
		WindowsWindow* GetWindow() const { return m_window; }

	public:
		WindowsWindowEvent(WindowsWindow* window) : m_window(window) {}
		WindowsWindow* m_window;
	};

	class WindowsWindowCloseEvent : public WindowsWindowEvent
	{
	public:
		WindowsWindowCloseEvent(WindowsWindow* window) : WindowsWindowEvent(window) {}

		virtual size_t GetEventTypeId() const override { return DollsEngine::GetEventTypeId<WindowsWindowCloseEvent>(); }
	};
}