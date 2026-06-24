#pragma once

namespace DollsEngine
{
	class Platform
	{
	public:
		virtual bool Initialize() = 0;
		virtual void PumpMessages() = 0;
	};
}