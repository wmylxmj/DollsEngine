#pragma once

#include <stdint.h>

#include "GLFW/glfw3.h"

namespace DollsEngine
{
	class Application;

	struct GenericWindowDesc
	{
		const char* title;
		uint32_t clientWidth;
		uint32_t clientHeight;
	};

	class GenericWindow
	{
	public:
		void Init(const GenericWindowDesc& desc);
		void Show();

	private:
		GLFWwindow* m_window;
	};
}