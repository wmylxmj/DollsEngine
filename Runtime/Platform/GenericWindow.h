#pragma once

#include <stdint.h>

#include "GLFW/glfw3.h"

namespace DollsEngine
{
	class Application;

	struct GenericWindowCreateInfo
	{
		const char* title;
		uint32_t clientWidth;
		uint32_t clientHeight;
	};

	class GenericWindow
	{
	public:
		void Create(const GenericWindowCreateInfo& createInfo);
		void Show();

	private:
		GLFWwindow* m_window;
	};
}