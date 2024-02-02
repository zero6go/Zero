#include "zpch.h"
#include "Zero/Renderer/VertexArray.h"

#include "Zero/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Zero {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    ZERO_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		ZERO_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}