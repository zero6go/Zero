#pragma once

#include "Zero/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Zero {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

#define ZERO_CORE_TRACE(...)    ::Zero::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZERO_CORE_INFO(...)     ::Zero::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZERO_CORE_WARN(...)     ::Zero::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZERO_CORE_ERROR(...)    ::Zero::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZERO_CORE_CRITICAL(...) ::Zero::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ZERO_TRACE(...)		    ::Zero::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZERO_INFO(...)			::Zero::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZERO_WARN(...)			::Zero::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZERO_ERROR(...)			::Zero::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZERO_CRITICAL(...)      ::Zero::Log::GetClientLogger()->critical(__VA_ARGS__)