#include "Population.h"
#include "Individual.h"

#include <iostream>

int Population::population_size = 100;

Population::Population() {
}


Population::~Population() {
}

void Population::populate(const char* target) {
	for (int i = 0; i < Population::population_size; i++) {
		individuals.push_back(new Individual(target));
	}
}

Individual* Population::getHead() {
	return individuals[0];
}