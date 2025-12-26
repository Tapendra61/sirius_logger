#pragma once

#include "formatter.h"
#include <ctime>
#include <iomanip>
#include <ostream>
#include <chrono>
#include <sstream>
#include <string>

namespace sr {
enum class LogLevel { Trace, Info, Warning, Error, Fatal };

class Logger {
  private:
	std::ostream &output_;
	LogLevel level_ = LogLevel::Trace;

  public:
	explicit Logger(std::ostream &output) : output_(output) {}

	void set_level(LogLevel level) { level_ = level; }

	template <typename... Args>
	void log(LogLevel level, const std::string &fmt, Args &&...args) {
		if (level < level_)
			return;

		output_ << "[" << get_current_timestamp() << "]" << "[" << level_to_string(level) << "]"
				<< format(fmt, std::forward<Args>(args)...) << "\n";
	}

  private:
	static const char *level_to_string(LogLevel level) {
		switch (level) {
		case LogLevel::Trace:
			return "Trace";
		case LogLevel::Info:
			return "Info";
		case LogLevel::Warning:
			return "Warning";
		case LogLevel::Error:
			return "Error";
		case LogLevel::Fatal:
			return "Fatal";
		}
		return "Unknown";
	}
	
	std::string get_current_timestamp() {
		std::ostringstream oss;
		
		std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
		std::time_t c_time_now = std::chrono::system_clock::to_time_t(now);
		std::tm local_tm = *std::localtime(&c_time_now);
		oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
		
		return oss.str();
	}
};
} // namespace sr