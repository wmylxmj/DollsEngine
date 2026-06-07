#include "WindowsWindow.h"

void DollsEngine::WindowsWindow::Create(WindowsApplication* application, GenericWindowCreateInfo& createInfo)
{
	m_application = application;
	m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);

	glfwSetWindowUserPointer(m_window, m_application);

	glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
		GenericWindow& genericWindow = *static_cast<GenericWindow*>(glfwGetWindowUserPointer(window));
	});
}

void DollsEngine::WindowsWindow::Show()
{
	glfwShowWindow(m_window);
}