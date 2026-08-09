#include "VulkanRHI.h"

#include <tuple>
#include <map>

namespace DollsEngine
{
	bool VulkanRHI::Initialize()
	{
		return true;
	}

	bool VulkanRHI::CreateInstance()
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "DollsEngine";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "DollsEngine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);

#ifdef DOLLS_DEBUG
		m_instance.AddPreferredLayer("VK_LAYER_KHRONOS_validation");
		m_instance.AddPreferredExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME)
#endif
		m_instance.AddPreferredExtension(VK_KHR_SURFACE_EXTENSION_NAME);

		m_vulkanPlatform->AddPreferredPlatformSpecificInstanceExtensions(m_instance);
		return m_instance.Create(appInfo);
	}

	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugMessageCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData)
	{
		return VK_FALSE;
	}

	bool VulkanRHI::CreateDebugMessenger()
	{
		VkDebugUtilsMessengerCreateInfoEXT createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
									 VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
									 VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
							     VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		createInfo.pfnUserCallback = DebugMessageCallback;
		createInfo.pUserData = nullptr; // Optional

		if (vkCreateDebugUtilsMessengerEXT(m_instance.GetInstance(), &createInfo, nullptr, &m_debugMessenger) != VK_SUCCESS) {
			return false;
		}

		return true;
	}

	// 函数
	static VkPhysicalDevice SelectPhysicalDevice(VkInstance instance)
	{
		uint32_t physicalDeviceCount = 0;
		if (vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, nullptr) != VK_SUCCESS ||
			physicalDeviceCount == 0) {
			return VK_NULL_HANDLE;
		};

		std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
		vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices.data());

		using Performance = std::tuple<uint32_t>;
		std::multimap<Performance, VkPhysicalDevice, std::greater<>> candidates;

		for (const auto& physicalDevice : physicalDevices) {
			Performance performance = std::make_tuple(0);

			VkPhysicalDeviceProperties2 physicalDeviceProperties2 = {};
			physicalDeviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;

			vkGetPhysicalDeviceProperties2(physicalDevice, &physicalDeviceProperties2);

			if (physicalDeviceProperties2.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
				std::get<0>(performance) = 4;
			}
			else if (physicalDeviceProperties2.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) {
				std::get<0>(performance) = 3;
			}

			candidates.insert({ performance, physicalDevice });
		}

		return candidates.begin()->second;
	}

	bool VulkanRHI::CreateDevice()
	{
		return true;
	}


}