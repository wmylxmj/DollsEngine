#include "VulkanWindowsPlatform.h"

#include "../../../Platform/Windows/WindowsApi.h"

namespace DollsEngine
{
	VkSurfaceKHR VulkanWindowsPlatformCreateSurface(VkInstance instance, void* windowHandle)
	{
		VkWin32SurfaceCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		createInfo.hinstance = GetModuleHandle(NULL);
		createInfo.hwnd = (HWND)windowHandle;

		return VkSurfaceKHR();
	}
}