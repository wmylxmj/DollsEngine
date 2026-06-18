# CMakeList.txt: DollsEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

add_subdirectory(../External/volk ${CMAKE_CURRENT_BINARY_DIR}/volk)
add_subdirectory(../External/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)

# 将源代码添加到此项目的可执行文件。
add_executable (
    DollsEngine 
     
    
    "Platform/Windows/WindowsWindow.h"
    "Platform/Windows/WindowsWindow.cpp"
    
    
    "Core/Core.h"
    
    "Engine/Engine.h" 
    "Application/Application.h"
    "Application/Application.cpp"
    "main.cpp"
  "Core/Event/Event.h"   "Engine/Engine.cpp" "Core/Window.h" "Core/Event/Events/WindowEvents.h" "Platform/Platform.h" "Core/Platform.h" "Platform/Windows/WindowsPlatform.h")

target_compile_definitions(DollsEngine PRIVATE
    $<$<PLATFORM_ID:Windows>:DOLLS_PLATFORM_WINDOWS>
)


# 添加Vulkan平台宏定义
target_compile_definitions(DollsEngine PRIVATE
    $<$<PLATFORM_ID:Windows>:VK_USE_PLATFORM_WIN32_KHR>
    $<$<PLATFORM_ID:Linux>:VK_USE_PLATFORM_XLIB_KHR>
    $<$<PLATFORM_ID:Darwin>:VK_USE_PLATFORM_MACOS_MVK>
)
target_link_libraries(DollsEngine PRIVATE volk)

target_compile_definitions(DollsEngine PRIVATE GLFW_INCLUDE_NONE)
target_link_libraries(DollsEngine PRIVATE glfw)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DollsEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
