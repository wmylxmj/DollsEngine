#pragma once

#include "../GenericWindow.h"

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

		void Create(const GenericWindowCreateInfo& createInfo);

		virtual void Show() override;
		virtual void* GetOsWindowHandle() const override;


	private:
		GLFWwindow* m_window;
	};
}