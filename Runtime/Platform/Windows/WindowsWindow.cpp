#include "WindowsWindow.h"

namespace DollsEngine
{
	WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(m_window);
	}

	std::shared_ptr<WindowsWindow> WindowsWindow::Create()
	{
		return std::shared_ptr<WindowsWindow>(new WindowsWindow());
	}

	void WindowsWindow::Initialize(WindowsApplication* application, const GenericWindowCreateInfo& createInfo)
	{
		m_owningApplication = application;
		m_window = glfwCreateWindow(createInfo.clientWidth, createInfo.clientHeight, createInfo.title, nullptr, nullptr);

		glfwSetWindowUserPointer(m_window, this);
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

	WindowsWindow::WindowsWindow() : m_window(nullptr), m_owningApplication(nullptr) {}
}