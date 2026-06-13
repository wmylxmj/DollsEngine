#pragma once

#include "../Core/Event/Event.h"

namespace DollsEngine
{
    class GenericWindow;

    class GenericWindowEvent : public Event
    {
    public:
        GenericWindow* GetWindow() const { return m_window; }

    protected:
        GenericWindowEvent(GenericWindow* window) : m_window(window) {}
        GenericWindow* m_window;
    };

    class GenericWindowCloseEvent : public GenericWindowEvent
    {
    public:
        GenericWindowCloseEvent(GenericWindow* window) : GenericWindowEvent(window) {}

        virtual size_t GetEventTypeId() const override { return DollsEngine::GetEventTypeId<GenericWindowCloseEvent>(); }
    };


}