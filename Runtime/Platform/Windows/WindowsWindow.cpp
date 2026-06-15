#include "WindowsWindow.h"

#include "../GenericWindowEvent.h"

namespace DollsEngine
{
	static uint32_t s_numWindows = 0;

	WindowsWindow::WindowsWindow() : m_window(nullptr) {}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_window);
		s_numWindows--;
		if (s_numWindows == 0)
		{
            glfwTerminate();
		}
	}

	void WindowsWindow::Create(const GenericWindowCreateInfo& createInfo)
	{
		if (s_numWindows == 0) 
		{ 
			glfwInit();
		}
		s_numWindows += 1;

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