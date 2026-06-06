#include "GenericWindow.h"

namespace DollsEngine
{
	void GenericWindow::Init(const GenericWindowDesc& desc)
	{
		m_window = glfwCreateWindow(desc.clientWidth, desc.clientHeight, desc.title, nullptr, nullptr);
	}

	void GenericWindow::Show()
	{
		glfwShowWindow(m_window);
	}
}