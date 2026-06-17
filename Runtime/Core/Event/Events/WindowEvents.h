#pragma once

#include "../Event.h"

namespace DollsEngine
{
    class IWindow;

    class WindowEvent : public Event
    {
    };

    class WindowCloseEvent : public WindowEvent
    {
    };
}