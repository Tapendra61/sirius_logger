#include "logger.h"
#include <iostream>

inline sr::Logger g_logger{std::cout};

namespace sr {
	template<typename... Args>
	inline void log_trace(const std::string& fmt, Args&&... args) {
		g_logger.log(LogLevel::Trace, fmt, std::forward<Args>(args)...);
	}
	
	template<typename... Args>
	inline void log_info(const std::string& fmt, Args&&... args) {
		g_logger.log(LogLevel::Info, fmt, std::forward<Args>(args)...);
	}
	
	template<typename... Args>
	inline void log_warn(const std::string& fmt, Args&&... args) {
		g_logger.log(LogLevel::Warning, fmt, std::forward<Args>(args)...);
	}
	
	template<typename... Args>
	inline void log_error(const std::string& fmt, Args&&... args) {
		g_logger.log(LogLevel::Error, fmt, std::forward<Args>(args)...);
	}
	
	template<typename... Args>
	inline void log_fatal(const std::string& fmt, Args&&... args) {
		g_logger.log(LogLevel::Fatal, fmt, std::forward<Args>(args)...);
	}
};