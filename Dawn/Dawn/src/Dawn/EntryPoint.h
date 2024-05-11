#pragma once

#ifdef DAWN_PLATFORM_WINDOWS

extern Dawn::Application* Dawn::CreateApplication();

int main(int argc, char** argv)
{
	Dawn::Log::Init();
	DAWN_CORE_WARN("Initialized Log!");
	int a = 5;
	DAWN_INFO("Hello! Var={0}", a);

	auto app = Dawn::CreateApplication();
	app->Run();
	delete app;
}
#endif