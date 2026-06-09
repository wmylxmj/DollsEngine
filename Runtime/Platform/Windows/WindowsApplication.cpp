#include "WindowsApplication.h"

namespace DollsEngine
{
	void WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::shared_ptr<WindowsWindow> window = WindowsWindow::Create(createInfo);
		window->SetOwningApplication(this);

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
	}
}