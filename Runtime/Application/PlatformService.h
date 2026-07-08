#pragma once

namespace DollsEngine {
    class PlatformService {

	public:
		virtual bool Initialize() = 0;
		virtual void PumpMessages() = 0;

    };
}