#include "VulkanWindowsPlatform.h"

#include "../../../../Core/Windows/WindowsAPI.h"

namespace DollsEngine
{
	VkResult VulkanWindowsPlatform::CreateSurface(VkInstance instance, void* windowHandle, VkSurfaceKHR* outSurface)
	{
		VkWin32SurfaceCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
		createInfo.hinstance = GetModuleHandle(NULL);
		createInfo.hwnd = (HWND)windowHandle;
		return vkCreateWin32SurfaceKHR(instance, &createInfo, nullptr, outSurface);
	}

	void VulkanWindowsPlatform::CollectInstanceExtensions(VulkanInstanceExtensionsCollector &collector)
	{

	}

}