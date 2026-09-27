//
// Created by 13973 on 26-9-19.
//

#include "RHIRuntime.h"

#include "VulkanRHI/VulkanRHI.h"

namespace DollsEngine
{
    static RHI* s_globalRHI = nullptr;

    bool InitializeRHI()
    {
        s_globalRHI = new VulkanRHI();
        return s_globalRHI->Initialize();
    }


}