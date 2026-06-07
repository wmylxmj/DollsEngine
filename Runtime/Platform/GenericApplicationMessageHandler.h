#pragma once

#include <memory>

namespace DollsEngine
{
	class GenericWindow;

	class GenericApplicationMessageHandler
	{
	public:
		virtual void OnWindowClose(const std::shared_ptr<GenericWindow>& window) {}
	};
}