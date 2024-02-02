#pragma once

#include "Zero.h"

class Sandbox2D : public Zero::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Zero::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Zero::Event& e) override;
private:
	Zero::OrthographicCameraController m_CameraController;

	// Temp
	Zero::Ref<Zero::VertexArray> m_SquareVA;
	Zero::Ref<Zero::Shader> m_FlatColorShader;

	Zero::Ref<Zero::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};