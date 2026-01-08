#pragma once

#include "formatter.h"
#include "sink.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <memory>
#include <mutex>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace sr {
enum class LogLevel { Trace, Info, Warning, Error, Fatal };

struct LogColors {
	static constexpr const char *red = "\x1b[31m";
	static constexpr const char *bright_red = "\x1b[1;31m";
	static constexpr const char *yellow = "\x1b[33m";
	static constexpr const char *gray = "\x1b[90m";
	static constexpr const char *reset = "\x1b[0m";
};

class Logger {
  private:
	std::vector<std::unique_ptr<Sink>> sinks_;
	LogLevel level_ = LogLevel::Trace;
	std::mutex mtx_;

  public:

	void set_level(LogLevel level) { level_ = level; }

	template <typename... Args>
	void log(LogLevel level, const std::string &fmt, Args &&...args) {
		if (level < level_)
			return;

		std::lock_guard<std::mutex> lock(mtx_);

		std::string message = "[" + get_current_timestamp() + "]" + "[" +
							  level_to_string(level) + "]" +
							  format(fmt, std::forward<Args>(args)...);
									
		for(auto& sink: sinks_) {
			sink->write(message);
		}
	}

	void add_sink(std::unique_ptr<Sink> sink) {
		sinks_.push_back(std::move(sink));
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

	static std::string get_current_timestamp() {
		std::ostringstream oss;

		std::chrono::time_point<std::chrono::system_clock> now =
			std::chrono::system_clock::now();
		std::time_t c_time_now = std::chrono::system_clock::to_time_t(now);
		std::tm local_tm;
		localtime_s(&local_tm, &c_time_now);
		oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");

		return oss.str();
	}

	const char *get_log_color(LogLevel level) {
		switch (level) {
		case LogLevel::Fatal:
			return LogColors::bright_red;
		case LogLevel::Error:
			return LogColors::red;
		case LogLevel::Warning:
			return LogColors::yellow;
		case LogLevel::Info:
			return LogColors::reset;
		case LogLevel::Trace:
			return LogColors::gray;
		}
		return LogColors::reset;
	}
};
} // namespace sr