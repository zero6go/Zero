#pragma once

#include "Zero/Core/Base.h"
#include "Zero/Core/Log.h"
#include <filesystem>

#ifdef ZERO_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define ZERO_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ZERO##type##ERROR(msg, __VA_ARGS__); ZERO_DEBUGBREAK(); } }
#define ZERO_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ZERO_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define ZERO_INTERNAL_ASSERT_NO_MSG(type, check) ZERO_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ZERO_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define ZERO_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define ZERO_INTERNAL_ASSERT_GET_MACRO(...) ZERO_EXPAND_MACRO( ZERO_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ZERO_INTERNAL_ASSERT_WITH_MSG, ZERO_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define ZERO_ASSERT(...) ZERO_EXPAND_MACRO( ZERO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define ZERO_CORE_ASSERT(...) ZERO_EXPAND_MACRO( ZERO_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define ZERO_ASSERT(...)
#define ZERO_CORE_ASSERT(...)
#endif