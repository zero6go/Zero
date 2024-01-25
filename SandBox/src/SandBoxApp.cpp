#include <Zero.h>

#include "imgui/imgui.h"

class ExampleLayer : public Zero::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Zero::Input::IsKeyPressed(ZERO_KEY_TAB))
			ZERO_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Zero::Event& event) override
	{
		if (event.GetEventType() == Zero::EventType::KeyPressed)
		{
			Zero::KeyPressedEvent& e = (Zero::KeyPressedEvent&)event;
			if (e.GetKeyCode() == ZERO_KEY_TAB)
				ZERO_TRACE("Tab key is pressed (event)!");
			ZERO_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class SandBox : public Zero::Application {
public:

	SandBox()
	{
		PushLayer(new ExampleLayer());
	}

	~SandBox()
	{

	}

};

Zero::Application* Zero::CreateApplication() 
{
	return new SandBox();
}