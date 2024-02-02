#include <Zero.h>
#include <Zero/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class SandBox : public Zero::Application {
public:

	SandBox()
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~SandBox()
	{
	}
};

Zero::Application* Zero::CreateApplication() 
{
	return new SandBox();
}