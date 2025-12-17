#pragma once

#include <string>
#include <sstream>

namespace sr {
	template <typename T>
	inline std::string to_string_any(const T& value) {
		std::ostringstream out;
		out << value;

		return out.str();
	}

	inline void format_impl(std::string& out, const std::string& fmt) {
		out += fmt;
	}

	template <typename... Args>
	inline std::string format(const std::string& fmt, Args&&... args) {

	}
};