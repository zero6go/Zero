#include "zpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Zero {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ZERO_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		ZERO_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ZERO_CORE_ASSERT(status, "Failed to initialize Glad!");

		ZERO_CORE_INFO("OpenGL Info:");
		ZERO_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		ZERO_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		ZERO_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		ZERO_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		ZERO_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}