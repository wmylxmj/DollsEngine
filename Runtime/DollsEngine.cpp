// DollsEngine.cpp: 定义应用程序的入口点。
//

#include "DollsEngine.h"
#include "Application/Application.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "volk.h"

class MyApplication : public DollsEngine::Application
{
public:
	void OnWindowClose() override {
	}
};

MyApplication* application = nullptr;

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);      // 禁用默认的 OpenGL 上下文
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);        // 暂时禁止窗口大小调整
	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);

	VkResult result = volkInitialize();

	if (result != VK_SUCCESS) {
		printf("volk 初始化失败！请检查系统是否安装了 Vulkan 驱动。\n");
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents(); // 处理键盘、鼠标等窗口输入事件

		// TODO: 在此处添加 Vulkan 的渲染逻辑（如提交指令缓冲区、呈现图像等）
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}