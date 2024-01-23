#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Zero {
	class ZERO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define ZERO_CORE_TRACE(...)    ::Zero::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ZERO_CORE_INFO(...)     ::Zero::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ZERO_CORE_WARN(...)     ::Zero::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ZERO_CORE_ERROR(...)    ::Zero::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ZERO_CORE_FATAL(...)    ::Zero::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define ZERO_TRACE(...)		  ::Zero::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ZERO_INFO(...)		  ::Zero::Log::GetClientLogger()->info(__VA_ARGS__)
#define ZERO_WARN(...)		  ::Zero::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ZERO_ERROR(...)		  ::Zero::Log::GetClientLogger()->error(__VA_ARGS__)
#define ZERO_FATAL(...)		  ::Zero::Log::GetClientLogger()->fatal(__VA_ARGS__)