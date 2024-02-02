#include "zpch.h"
#include "Zero/Renderer/RenderCommand.h"

namespace Zero {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}