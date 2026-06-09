#include "WindowsWindow.h"

namespace DollsEngine
{
	std::shared_ptr<WindowsWindow> WindowsWindow::Create(const GenericWindowCreateInfo& createInfo)
	{
		return std::shared_ptr<WindowsWindow>(new WindowsWindow(createInfo));
	}

	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_window);
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

	WindowsWindow::WindowsWindow(const GenericWindowCreateInfo& createInfo) : m_owningApplication(nullptr)
	{
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);

		glfwSetWindowUserPointer(m_window, this);
	}
}