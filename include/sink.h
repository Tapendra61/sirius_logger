#pragma once

#include <string_view>

namespace sr {
class Sink {
  public:
	virtual ~Sink() = default;

	virtual void write(std::string_view message) = 0;
};
} // namespace sr