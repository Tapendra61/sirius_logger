#pragma once

#include "formatter.h"
#include <ostream>

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

		output_ << "[" << level_to_string(level) << "]"
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
};
} // namespace sr