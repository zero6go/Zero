#pragma once

#ifdef ZERO_PLATFORM_WINDOWS

extern Zero::Application* Zero::CreateApplication();

void main(int argc, char** argv)
{
	Zero::Log::Init();
	ZERO_CORE_WARN("Initialized Log!");
	int a = 5;
	ZERO_INFO("Hello! Var={0}",a);

	auto app = Zero::CreateApplication();
	app->Run();
	delete app;
}

#endif 