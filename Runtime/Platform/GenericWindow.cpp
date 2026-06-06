#include "GenericWindow.h"

namespace DollsEngine
{
	void GenericWindow::Create(const GenericWindowCreateInfo& createInfo)
	{
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);

		glfwSetWindowUserPointer(m_window, this);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			GenericWindow& genericWindow = *static_cast<GenericWindow*>(glfwGetWindowUserPointer(window));
		});
	}

	void GenericWindow::Show()
	{
		glfwShowWindow(m_window);
	}
}