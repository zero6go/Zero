#pragma once

#include "Zero/Core/Base.h"

#include "Zero/Core/Window.h"
#include "Zero/Core/LayerStack.h"
#include "Zero/Events/Event.h"
#include "Zero/Events/ApplicationEvent.h"

#include "Zero/Core/Timestep.h"

#include "Zero/ImGui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Zero {

	class Application
	{
	public:
		Application(const std::string& name = "Zero App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	//在客户端中定义
	Application* CreateApplication();

}
