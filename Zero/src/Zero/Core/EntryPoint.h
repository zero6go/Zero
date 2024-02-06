#pragma once
#include "Zero/Core/Base.h"
#include "Zero/Core/Application.h"

#ifdef ZERO_PLATFORM_WINDOWS

extern Zero::Application* Zero::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Zero::Log::Init();

	ZERO_PROFILE_BEGIN_SESSION("Startup", "ZeroProfile-Startup.json");
	auto app = Zero::CreateApplication({ argc, argv });
	ZERO_PROFILE_END_SESSION();

	ZERO_PROFILE_BEGIN_SESSION("Runtime", "ZeroProfile-Runtime.json");
	app->Run();
	ZERO_PROFILE_END_SESSION();

	ZERO_PROFILE_BEGIN_SESSION("Shutdown", "ZeroProfile-Shutdown.json");
	delete app;
	ZERO_PROFILE_END_SESSION();
}

#endif 