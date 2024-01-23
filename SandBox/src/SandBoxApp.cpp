#include <Zero.h>

class ExampleLayer : public Zero::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ZERO_INFO("ExampleLayer::Update");
	}

	void OnEvent(Zero::Event& event) override
	{
		ZERO_TRACE("{0}", event);
	}

};

class SandBox : public Zero::Application {
public:

	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Zero::ImGuiLayer());
	}

	~SandBox()
	{

	}

};

Zero::Application* Zero::CreateApplication() 
{
	return new SandBox();
}