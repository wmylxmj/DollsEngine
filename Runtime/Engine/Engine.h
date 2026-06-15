#pragma once

namespace DollsEngine
{
	class Application;

	class Engine
	{
	public:
		int Init();
		void Tick();

		void SetApplication(Application* application) { m_application = application; }

	private:
		Application* m_application;
	};
}