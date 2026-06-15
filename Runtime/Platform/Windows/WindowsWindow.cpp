#include "WindowsWindow.h"

#include "../GenericWindowEvent.h"

namespace DollsEngine
{
	WindowsWindow::WindowsWindow() : m_window(nullptr) {}


	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::Create(const GenericWindowCreateInfo& createInfo)
	{
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, this);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowsWindow* windowsWindow = (WindowsWindow*)(glfwGetWindowUserPointer(window));
			GenericWindowCloseEvent event(windowsWindow);
			windowsWindow->m_eventCallback(event);
		});
	}

	void WindowsWindow::Show()
	{
		glfwShowWindow(m_window);
	}

	void* WindowsWindow::GetOsWindowHandle() const
	{
		return m_window;
	}
}