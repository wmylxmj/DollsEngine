// DollsEngine.cpp: 定义应用程序的入口点。
//

#include "Application/Application.h"
#include "Platform/Windows/WindowsApplication.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <iostream>

bool g_exit = false;

class MyApplication : public DollsEngine::Application
{
public:
	void OnWindowClose() override {
		g_exit = true;
	}
};

int main()
{
	DollsEngine::WindowsApplication::Initialize();
	std::shared_ptr<DollsEngine::WindowsApplication> windowsApplication = std::make_shared<DollsEngine::WindowsApplication>();

	std::shared_ptr<MyApplication> myApplication = std::make_shared<MyApplication>();
	myApplication->Create(windowsApplication);

	DollsEngine::GenericWindowCreateInfo windowCreateInfo;
	windowCreateInfo.clientWidth = 800;
	windowCreateInfo.clientHeight = 600;
	windowCreateInfo.title = "Test Window";
	myApplication->CreateWindow(windowCreateInfo);

	while (!g_exit) {
		glfwPollEvents(); // 处理键盘、鼠标等窗口输入事件
		// TODO: 在此处添加 Vulkan 的渲染逻辑（如提交指令缓冲区、呈现图像等）
	}

	//glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}