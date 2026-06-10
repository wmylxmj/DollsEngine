#include "WindowsApplication.h"

namespace DollsEngine
{
	std::shared_ptr<GenericWindow> WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::shared_ptr<WindowsWindow> window = std::make_shared<WindowsWindow>();
		window->Create(this, createInfo);

		glfwSetWindowCloseCallback((GLFWwindow*)window->GetOSWindowHandle(), [](GLFWwindow* window) {
			WindowsWindow& windowsWindow = *(WindowsWindow*)glfwGetWindowUserPointer(window);

			for (auto& item : windowsWindow.GetOwningApplication()->m_windows)
			{
				if (item.get() == &windowsWindow)
				{
					windowsWindow.GetOwningApplication()->m_messageHandler->OnWindowClose(item);
				}
			}
		});

		m_windows.push_back(window);
		return window;
	}
}