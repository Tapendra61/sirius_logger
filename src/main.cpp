#include "../include/log.h"
#include "logger.h"

int main() {
	
	sr::init_logger(sr::LogLevel::Trace, "log.txt");
	
	sr::log_fatal("Something went wrong id: {}", 1);
	sr::log_error("Something went wrong id: {}", 1);
	sr::log_warn("Something went wrong id: {}", 1);
	sr::log_info("Something went wrong id: {}", 1);
	sr::log_trace("Something went wrong id: {}", 1);
	return 0;
}