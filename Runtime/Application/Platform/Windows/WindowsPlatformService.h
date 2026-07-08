#pragma once

#include "../../PlatformService.h"

namespace DollsEngine {
    class WindowsPlatformService : public PlatformService {

    public:
        virtual bool Initialize() override;
        virtual void PumpMessages() override;

    };
}


