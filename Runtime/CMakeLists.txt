# CMakeList.txt: DollsEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 添加Vulkan平台宏定义
set(VOLK_STATIC_DEFINES
        $<$<PLATFORM_ID:Windows>:VK_USE_PLATFORM_WIN32_KHR>
        $<$<PLATFORM_ID:Linux>:VK_USE_PLATFORM_XLIB_KHR>
        $<$<PLATFORM_ID:Darwin>:VK_USE_PLATFORM_MACOS_MVK>
)
add_subdirectory(../External/volk ${CMAKE_CURRENT_BINARY_DIR}/volk)
add_subdirectory(../External/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)

# 将源代码添加到此项目的可执行文件。
add_executable(DollsEngine
        "Core/Core.h"
        "Core/Event/Event.h"
        "RHI/RHI/RHI.h"
        "RHI/RHI/RHIResource.h"
        "RHI/VulkanRHI/VulkanAPI.h"
        "RHI/VulkanRHI/VulkanPlatform.h"
        "RHI/VulkanRHI/VulkanRHI.h"
        "RHI/VulkanRHI/VulkanRHI.cpp"
        "RHI/VulkanRHI/VulkanDevice.h"
        "Engine/Engine.h"
        "Engine/Engine.cpp"
        "Application/Application.h"
        "Application/Application.cpp"
        "Application/Window.h"
        "Application/PlatformService.h"
        "Application/Platform/NativeWindow.h"
        "Application/WindowEvents.h"
        "Application/ApplicationPlatform.h"
        "Application/Platform/ApplicationNativePlatform.h"
        "main.cpp"
)

if (WIN32)
    target_sources(DollsEngine PRIVATE
            "Core/Windows/WindowsAPI.h"
            "Application/Platform/Windows/ApplicationWindowsPlatform.cpp"
            "Application/Platform/Windows/ApplicationWindowsPlatform.h"
            "Application/Platform/Windows/WindowsWindow.cpp"
            "Application/Platform/Windows/WindowsWindow.h"
            "Application/Platform/Windows/WindowsPlatformService.h"
            "Application/Platform/Windows/WindowsPlatformService.cpp"
            "RHI/VulkanRHI/Windows/VulkanWindowsPlatform.h"
            "RHI/VulkanRHI/Windows/VulkanWindowsPlatform.cpp"
    )
endif()
    
target_compile_definitions(DollsEngine PRIVATE
        $<$<PLATFORM_ID:Windows>:DOLLS_PLATFORM_WINDOWS>
)

target_link_libraries(DollsEngine PRIVATE volk)

target_compile_definitions(DollsEngine PRIVATE GLFW_INCLUDE_NONE)
target_link_libraries(DollsEngine PRIVATE glfw)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET DollsEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
