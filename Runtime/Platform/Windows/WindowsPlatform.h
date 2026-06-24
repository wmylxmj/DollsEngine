#pragma once

#include "../../Core/Platform.h"
#include "WindowsApi.h"

namespace DollsEngine
{
	class WindowsPlatform : public Platform
	{
	public:

		virtual void PumpMessages() override;
	};
}