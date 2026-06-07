#pragma once

#include "../GenericWindow.h"

#include "GLFW/glfw3.h"

#include <memory>

namespace DollsEngine
{
	class WindowsApplication;

	class WindowsWindow : public GenericWindow, public std::enable_shared_from_this<WindowsWindow>
	{
	public:
		~WindowsWindow();
		void Create(WindowsApplication* application, const GenericWindowCreateInfo& createInfo);
		virtual void Show() override;
		virtual void* GetOSWindowHandle() const override;
		WindowsApplication* GetOwningApplication() const;

	protected:
		WindowsApplication* m_application;
		GLFWwindow* m_window;
	};
}