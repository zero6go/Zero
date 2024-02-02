#include "zpch.h"
#include "Zero/Renderer/GraphicsContext.h"

#include "Zero/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Zero {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    ZERO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		ZERO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}