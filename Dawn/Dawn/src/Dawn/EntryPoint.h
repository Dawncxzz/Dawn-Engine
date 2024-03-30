#pragma once

#ifdef DAWN_PLATFORM_WINDOWS

extern Dawn::Application* Dawn::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Dawn::CreateApplication();
	app->Run();
	delete app;
}
#endif
