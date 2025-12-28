#include "../include/log.h"

int main() {
	sr::log_fatal("Something went wrong id: {}", 1);
	
	return 0;
}