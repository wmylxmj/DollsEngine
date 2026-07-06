#pragma once

#include "../ApplicationPlatform.h"
#include "../../Core/Windows/WindowsAPI.h"

namespace DollsEngine
{
	class ApplicationWindowsPlatform : public ApplicationPlatform
	{
	public:
		virtual bool Initialize() override;
		virtual void PumpMessages() override;
	};
}