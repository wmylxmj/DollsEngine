// DollsEngine.cpp: 定义应用程序的入口点。
//

#include "DollsEngine.h"
#include "Engine/Engine.h"
#include "volk.h"

using namespace std;

int main()
{
	VkResult result = volkInitialize();

	if (result != VK_SUCCESS) {
		printf("volk 初始化失败！请检查系统是否安装了 Vulkan 驱动。\n");
		return -1;
	}

	printf("volk 已成功加载 Vulkan 驱动！\n");
	cout << "Hello CMake!" << endl;
	return 0;
}