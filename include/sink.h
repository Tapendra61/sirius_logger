#pragma once

#include "log_level.h"
#include <string_view>

namespace sr {
class Sink {
  public:
	virtual ~Sink() = default;

	virtual void write(LogLevel &level, std::string_view message) = 0;
};
} // namespace sr