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

		static std::shared_ptr<WindowsWindow> Create();

		void Initialize(WindowsApplication* application, const GenericWindowCreateInfo& createInfo);
		virtual void Show() override;
		virtual void* GetOSWindowHandle() const override;
		WindowsApplication* GetOwningApplication() const;

	private:
		WindowsWindow();

		WindowsApplication* m_owningApplication;
		GLFWwindow* m_window;
	};
}