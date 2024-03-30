#include <Dawn.h>

class Sandbox : public Dawn::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Dawn::Application* Dawn::CreateApplication()
{
	return new Sandbox();
}