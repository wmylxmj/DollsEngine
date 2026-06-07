#pragma once

#include "../GenericWindow.h"

#include "GLFW/glfw3.h"

namespace DollsEngine
{
	class WindowsApplication;

	class WindowsWindow : public GenericWindow
	{
	public:
		void Create(WindowsApplication* application, const GenericWindowCreateInfo& createInfo);
		virtual void Show() override;
		virtual void* GetOSWindowHandle() const override;

	protected:
		WindowsApplication* m_application;
		GLFWwindow* m_window;
	};
}