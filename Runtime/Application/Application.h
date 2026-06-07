#pragma once

#include "../Platform/GenericApplicationMessageHandler.h"
#include "../Platform/GenericApplication.h"

namespace DollsEngine
{
	class Application : public GenericApplicationMessageHandler, public std::enable_shared_from_this<Application>
	{
	public:
		void Create(std::shared_ptr<GenericApplication> platformApplication);

		void CreateWindow(const GenericWindowCreateInfo& createInfo);

	protected:
		std::shared_ptr<GenericApplication> m_platformApplication;
	};
}