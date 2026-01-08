#pragma once

#include "sink.h"
#include <ostream>

namespace sr {
class ConsoleSink final : public Sink {
  private:
	std::ostream &out_;

  public:
	explicit ConsoleSink(std::ostream &out) : out_(out) {}
	void write(std::string_view message) override { out_ << message << "\n"; }
};
} // namespace sr