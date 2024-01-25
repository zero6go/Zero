#pragma once

#include "Zero/Layer.h"

#include "Zero/Events/ApplicationEvent.h"
#include "Zero/Events/KeyEvent.h"
#include "Zero/Events/MouseEvent.h"

namespace Zero {

	class ZERO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}