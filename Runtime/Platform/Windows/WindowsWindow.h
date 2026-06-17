#pragma once

#include "../../Core/Window.h"
#include "../GenericWindow.h"

#include "GLFW/glfw3.h"

#include <memory>

namespace DollsEngine
{
	class WindowsWindow : public Window
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