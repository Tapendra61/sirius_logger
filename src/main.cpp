#include <iostream>
#include "../include/formatter.h"

int main() {
	std::cout << "Sirius Logger." << std::endl;
	
	std::string res = sr::format("Hello {}", "Tapendra");
	std::cout << res << std::endl;
	
	return 0;
}