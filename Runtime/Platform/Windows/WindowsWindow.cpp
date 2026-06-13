#include "WindowsWindow.h"

namespace DollsEngine
{
	WindowsWindow::WindowsWindow() :
		m_window(nullptr),
		m_owningApplication(nullptr)
	{
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::Create(WindowsApplication* owningApplication, const GenericWindowCreateInfo& createInfo)
	{
		m_owningApplication = owningApplication;
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, this);

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
			WindowsWindow* windowsWindow = (WindowsWindow*)(glfwGetWindowUserPointer(window));
			WindowsWindowCloseEvent event(windowsWindow);
			windowsWindow->m_eventCallback(event);
		});
	}

	void WindowsWindow::Show()
	{
		glfwShowWindow(m_window);
	}

	void* WindowsWindow::GetOSWindowHandle() const
	{
		return m_window;
	}

	WindowsApplication* WindowsWindow::GetOwningApplication() const
	{
		return m_owningApplication;
	}
}