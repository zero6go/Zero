#pragma once

#include <memory>

#include "Zero/Core/PlatformDetection.h"

#ifdef ZERO_DEBUG
	#if defined(ZERO_PLATFORM_WINDOWS)
	#define ZERO_DEBUGBREAK() __debugbreak()
	#elif defined(ZERO_PLATFORM_LINUX)
	#include <signal.h>
	#define ZERO_DEBUGBREAK() raise(SIGTRAP)
	#else
	#error "Platform doesn't support debugbreak yet!"
	#endif
	#define ZERO_ENABLE_ASSERTS
#else
	#define ZERO_DEBUGBREAK()
#endif

#define ZERO_EXPAND_MACRO(x) x
#define ZERO_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ZERO_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Zero {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Zero/Core/Log.h"
#include "Zero/Core/Assert.h"