#pragma once

#include "sink.h"
#include <fstream>
#include <string_view>

namespace sr {
class FileSink final : public Sink {
  private:
	std::ofstream file_;

  public:
	explicit FileSink(const std::string &path)
		: file_(path, std::ios::out | std::ios::app) {}

	void write(std::string_view message) override {
		file_ << message << "\n";
		file_.flush();
	}
};
} // namespace sr