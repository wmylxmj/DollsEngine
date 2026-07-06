#pragma once

#include "../ApplicationPlatform.h"
#include "WindowsAPI.h"

namespace DollsEngine
{
	class ApplicationWindowsPlatform : public ApplicationPlatform
	{
	public:
		virtual bool Initialize() override;
		virtual void PumpMessages() override;
	};
}