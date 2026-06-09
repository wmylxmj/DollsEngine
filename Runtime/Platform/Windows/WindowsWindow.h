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
		static std::shared_ptr<WindowsWindow> Create(const GenericWindowCreateInfo& createInfo);

		~WindowsWindow();

		virtual void Show() override;
		virtual void* GetOSWindowHandle() const override;

		void SetOwningApplication(WindowsApplication* owningApplication) { m_owningApplication = owningApplication; }
		WindowsApplication* GetOwningApplication() const;

	private:
		WindowsWindow(const GenericWindowCreateInfo& createInfo);

		WindowsApplication* m_owningApplication;
		GLFWwindow* m_window;
	};
}