#pragma once

#include "../GenericWindow.h"

#include "GLFW/glfw3.h"

class WindowsApplication;

namespace DollsEngine
{
	class WindowsWindow : public GenericWindow
	{
	public:
		void Create(WindowsApplication* application, GenericWindowCreateInfo& createInfo);
		void Show() override;

	protected:
		WindowsApplication* m_application;
		GLFWwindow* m_window;
	};
}