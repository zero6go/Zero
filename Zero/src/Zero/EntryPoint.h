#pragma once

#ifdef ZERO_PLATFORM_WINDOWS

extern Zero::Application* Zero::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Zero::CreateApplication();
	app->Run();
	delete app;
}

#endif 