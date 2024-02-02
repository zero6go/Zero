#pragma once

#include "Zero.h"

class ExampleLayer : public Zero::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Zero::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Zero::Event& e) override;
private:
	Zero::ShaderLibrary m_ShaderLibrary;
	Zero::Ref<Zero::Shader> m_Shader;
	Zero::Ref<Zero::VertexArray> m_VertexArray;

	Zero::Ref<Zero::Shader> m_FlatColorShader;
	Zero::Ref<Zero::VertexArray> m_SquareVA;

	Zero::Ref<Zero::Texture2D> m_Texture, m_ChernoLogoTexture;

	Zero::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};
