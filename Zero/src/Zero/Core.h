#pragma once

#ifdef ZERO_PLATFORM_WINDOWS
	#ifdef ZERO_BUILD_DLL
		#define ZERO_API __declspec(dllexport)
	#else
		#define ZERO_API __declspec(dllimport)
	#endif 
#else
	#error Zero only support Windows!
#endif 

#ifdef ZERO_ENABLE_ASSERTS
	#define ZERO_ASSERT(x, ...) { if(!(x)) { ZERO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ZERO_CORE_ASSERT(x, ...) { if(!(x)) { ZERO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ZERO_ASSERT(x, ...)
	#define ZERO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)