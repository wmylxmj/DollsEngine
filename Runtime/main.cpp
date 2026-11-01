#include "Engine/Engine.h"
#include "Application/Application.h"

#include <iostream>

class MyApplication : public DollsEngine::Application
{
public:
	virtual void OnInit() override
	{
		DollsEngine::WindowCreateInfo windowCreateInfo = {};
		windowCreateInfo.clientWidth = 800;
		windowCreateInfo.clientHeight = 600;
		windowCreateInfo.title = "Test Window";

		CreateWindow(windowCreateInfo)->Show();
	}

	virtual void OnWindowClose(DollsEngine::WindowCloseEvent& event) override
	{
		m_shouldExit = true;
	}
};

int main()
{
	DollsEngine::Engine engine;

	MyApplication myApplication;
	engine.SetApplication(&myApplication);

	engine.Init();

	while (!engine.ShouldExit())
	{
		engine.Tick();
	}

	return 0;
}