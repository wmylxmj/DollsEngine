// DollsEngine.cpp: 定义应用程序的入口点。
//

#include "Engine/Engine.h"
#include "Application/Application.h"

#include "GLFW/glfw3.h"

#include <iostream>

bool g_exit = false;

class MyApplication : public DollsEngine::Application
{
public:
	virtual void OnWindowClose(DollsEngine::WindowCloseEvent& event) override
	{
		g_exit = true;
	}
};

int main()
{
	DollsEngine::Engine engine;

	MyApplication myApplication;
	myApplication.Create();

	engine.SetApplication(&myApplication);

	DollsEngine::WindowCreateInfo windowCreateInfo;
	windowCreateInfo.clientWidth = 800;
	windowCreateInfo.clientHeight = 600;
	windowCreateInfo.title = "Test Window";

	myApplication.CreateWindow(windowCreateInfo)->Show();

	while (!g_exit) {
		engine.Tick();
	}

	return 0;
}