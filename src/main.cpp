#include <iostream>
#include "../include/log.h"

int main() {
	std::cout << "Sirius Logger." << std::endl;
	
	sr::log_info("Hello {}. This is a test for log info. Number 1: {}. Double: {}. Float: {}. Boolean: {}.", "Tapendra", 24, 2.4, 2.4f, true);
	
	return 0;
}