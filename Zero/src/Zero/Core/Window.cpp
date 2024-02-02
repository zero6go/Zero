#include "zpch.h"
#include "Zero/Core/Window.h"

#ifdef ZERO_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Zero
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef ZERO_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		ZERO_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}