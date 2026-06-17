#pragma once

#include "../../Core/Window.h"

#include <Windows.h>

namespace DollsEngine
{
	struct WindowCreateInfo;

	class WindowsWindow : public Window
	{
	public:
		virtual bool Create(const WindowCreateInfo& createInfo) override;
		virtual void Show() override;
		virtual void* GetOsWindowHandle() const override;

	private:
		friend LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		HWND m_hwnd;
	};
}