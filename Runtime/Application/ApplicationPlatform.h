#pragma once

namespace DollsEngine
{
	class ApplicationPlatform
	{
	public:
		virtual bool Initialize() = 0;
		virtual void PumpMessages() = 0;
	};
}