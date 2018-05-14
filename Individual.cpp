#include "Individual.h"
#include "FitnessEvaluator.h"
#include <iostream>

int Individual::gene_length = 12;

Individual::Individual(const char* target) : fitness(0), genes(new char[gene_length]) {
	for (int i = 0; i < Individual::gene_length; i++) {
		genes[i] = Individual::mutation();
	}
	evaluateFitness(target);
}

Individual::~Individual() {
}

void Individual::evaluateFitness(const char* target) {
	fitness = FitnessEvaluator::calculateFitness(genes, target);
}

char Individual::mutation() {
	int index = std::rand() % std::strlen(FitnessEvaluator::GENOME);
	return FitnessEvaluator::GENOME[index];
}


std::string Individual::toString() {
	std::string test;
	for (int i2 = 0; i2 < Individual::gene_length; i2++) {
		test += genes[i2];
	}
	return test;
}
