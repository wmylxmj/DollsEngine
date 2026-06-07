#include "WindowsApplication.h"

namespace DollsEngine
{
	void WindowsApplication::Initialize()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);      // 禁用默认的 OpenGL 上下文
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);        // 暂时禁止窗口大小调整
	}

	void WindowsApplication::CreateWindow(const GenericWindowCreateInfo& createInfo)
	{
		std::shared_ptr<WindowsWindow> window = std::make_shared<WindowsWindow>();
		window->Create(this, createInfo);

		glfwSetWindowCloseCallback((GLFWwindow*)window->GetOSWindowHandle(), [](GLFWwindow* window) {
			WindowsApplication& application = *(WindowsApplication*)glfwGetWindowUserPointer(window);
			application.m_messageHandler->OnWindowClose();
		});

		m_windows.push_back(window);
	}
}