#include "WindowsWindow.h"

namespace DollsEngine
{
	void WindowsWindow::Create(WindowsApplication* application, const GenericWindowCreateInfo& createInfo)
	{
		m_application = application;
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);

		glfwSetWindowUserPointer(m_window, m_application);
	}

	void WindowsWindow::Show()
	{
		glfwShowWindow(m_window);
	}
	void* WindowsWindow::GetOSWindowHandle() const
	{
		return m_window;
	}
}