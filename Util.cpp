#include "Util.h"

#include <cstdlib>

int Util::randi(int start, int end) {
	int range = (end - start) + 1;
	int random_int = start + (std::rand() % range);
	return random_int;
}

float Util::randf(int start, int end) {
	return start + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (end - start)));
}