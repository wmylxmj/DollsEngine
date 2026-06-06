#include "GenericWindow.h"

namespace DollsEngine
{
	void GenericWindow::Init(const GenericWindowDesc& desc)
	{
		m_window = glfwCreateWindow(desc.clientWidth, desc.clientHeight, desc.title, nullptr, nullptr);

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