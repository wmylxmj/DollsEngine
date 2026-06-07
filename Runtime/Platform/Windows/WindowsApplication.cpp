#include "WindowsApplication.h"

namespace DollsEngine
{
	void WindowsApplication::Initialize()
	{
		glfwInit();
	}

	void WindowsApplication::CreateWindow(GenericWindowCreateInfo& createInfo)
	{
		WindowsWindow* window = new WindowsWindow();
		window->Create(this, createInfo);

		glfwSetWindowCloseCallback((GLFWwindow*)window->GetOSWindowHandle(), [](GLFWwindow* window) {
			WindowsApplication& application = *(WindowsApplication*)glfwGetWindowUserPointer(window);
			application.m_messageHandler->OnWindowClose();
		});

		m_windows.push_back(window);
	}
}