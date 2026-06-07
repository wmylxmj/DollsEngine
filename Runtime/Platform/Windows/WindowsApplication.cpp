#include "WindowsApplication.h"

namespace DollsEngine
{
	void WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::shared_ptr<WindowsWindow> window = std::make_shared<WindowsWindow>();
		window->Create(this, createInfo);

		glfwSetWindowCloseCallback((GLFWwindow*)window->GetOSWindowHandle(), [](GLFWwindow* window) {
			WindowsWindow& windowsWindow = *(WindowsWindow*)glfwGetWindowUserPointer(window);
			windowsWindow.GetOwningApplication()->m_messageHandler->OnWindowClose(windowsWindow.shared_from_this());
		});

		m_windows.push_back(window);
	}
}