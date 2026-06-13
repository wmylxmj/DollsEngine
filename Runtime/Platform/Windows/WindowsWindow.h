#pragma once

#include "../GenericWindow.h"
#include "WindowsWindowEvent.h"

#include "GLFW/glfw3.h"

#include <memory>

namespace DollsEngine
{
	class WindowsApplication;

	class WindowsWindow : public GenericWindow
	{
	public:
		WindowsWindow();
		~WindowsWindow();

		void Create(WindowsApplication* owningApplication, const GenericWindowCreateInfo& createInfo);

		virtual void Show() override;
		virtual void* GetOSWindowHandle() const override;

		WindowsApplication* GetOwningApplication() const;

	private:
		WindowsApplication* m_owningApplication;
		GLFWwindow* m_window;
	};
}