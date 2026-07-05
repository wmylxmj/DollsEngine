#pragma once

#include "../PAL/Platform.h"
#include "WindowsAPI.h"

namespace DollsEngine
{
	class WindowsPlatform : public Platform
	{
	public:
		virtual bool Initialize() override;
		virtual void PumpMessages() override;
	};
}