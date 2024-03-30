#pragma once

#include "Core.h"

namespace Dawn
{
	class DAWN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}

