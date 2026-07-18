#include "Engine/Engine.h"
#include "Application/Application.h"

#include <iostream>

class MyApplication : public DollsEngine::Application
{
public:
	virtual void OnWindowClose(DollsEngine::WindowCloseEvent& event) override
	{
		m_shouldExit = true;
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

	while (!engine.ShouldExit())
	{
		engine.Tick();
	}

	return 0;
}