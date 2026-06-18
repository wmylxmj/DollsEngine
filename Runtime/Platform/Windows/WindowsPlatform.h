#pragma once

#include "../../Core/Platform.h"

#include <Windows.h>

namespace DollsEngine
{
	class WindowsPlatform : public Platform
	{
	public:
		virtual void PumpMessages() override;
	};
}