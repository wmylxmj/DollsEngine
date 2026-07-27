#include "VulkanRHI.h"

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
		m_instanceLayersCollector.AddLayer("VK_LAYER_KHRONOS_validation");
#endif
		m_instanceLayersCollector.FlagLayersSupported();
		std::vector<const char*> supportedLayers = m_instanceLayersCollector.GetSupportedLayers();

#ifdef DOLLS_DEBUG
		m_instanceExtensionsCollector.AddExtension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif
		m_instanceExtensionsCollector.AddExtension(VK_KHR_SURFACE_EXTENSION_NAME);
		m_vulkanPlatform->CollectInstanceExtensions(m_instanceExtensionsCollector);
		m_instanceExtensionsCollector.FlagExtensionsSupported(nullptr);
		for (const auto& layerName : supportedLayers) {
			m_instanceExtensionsCollector.FlagExtensionsSupported(layerName);
		}
		std::vector<const char*> supportedExtensions = m_instanceExtensionsCollector.GetSupportedExtensions();

		VkInstanceCreateInfo instanceCreateInfo = {};
		instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceCreateInfo.pApplicationInfo = &appInfo;
		instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(supportedLayers.size());
		instanceCreateInfo.ppEnabledLayerNames = supportedLayers.data();
		instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(supportedExtensions.size());
		instanceCreateInfo.ppEnabledExtensionNames = supportedExtensions.data();

		if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			return false;
		}

		return true;
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

		if (vkCreateDebugUtilsMessengerEXT(m_instance, &createInfo, nullptr, &m_debugMessenger) != VK_SUCCESS) {
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

		VkPhysicalDevice selectedDevice = VK_NULL_HANDLE;

	}

	bool VulkanRHI::CreateDevice()
	{
		return true;
	}


}