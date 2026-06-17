#pragma once

#include "../../Core/Window.h"

#include <Windows.h>

namespace DollsEngine
{
	struct WindowCreateInfo;

	class WindowsWindow : public Window
	{
	public:
		virtual void Create(const WindowCreateInfo& createInfo) override;
		virtual void Show() override;
		virtual void* GetOsWindowHandle() const override;

	private:
		HWND m_hwnd;
	};
}