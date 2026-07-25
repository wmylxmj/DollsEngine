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

		if (vkCreateInstance(&instanceCreateInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			return false;
		}

		return true;
	}
}