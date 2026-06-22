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
		bool ShouldExit();

	private:
		Application* m_application;
	};
}