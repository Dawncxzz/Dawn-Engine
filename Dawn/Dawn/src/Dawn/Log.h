#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Dawn {
	class DAWN_API Log
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

// Core log macros
#define DAWN_CORE_ERROR(...)	::Dawn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DAWN_CORE_WARN(...)		::Dawn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DAWN_CORE_INFO(...)		::Dawn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DAWN_CORE_TRACE(...)	::Dawn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DAWN_CORE_CRITICAL(...)	::Dawn::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Core log macros
#define DAWN_ERROR(...)			::Dawn::Log::GetClientLogger()->error(__VA_ARGS__)
#define DAWN_WARN(...)			::Dawn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DAWN_INFO(...)			::Dawn::Log::GetClientLogger()->info(__VA_ARGS__)
#define DAWN_TRACE(...)			::Dawn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DAWN_CRITICAL(...)		::Dawn::Log::GetClientLogger()->critical(__VA_ARGS__)

