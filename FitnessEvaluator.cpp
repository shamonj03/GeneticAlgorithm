#include "FitnessEvaluator.h"
#include <string>


const char* FitnessEvaluator::GENOME = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

int FitnessEvaluator::calculateFitness(char* genes, const char* target) {
	int fitness = 0;
	for (int i = 0; i < std::strlen(target); i++) {
		fitness += (genes[i] == target[i]);
	}
	return fitness;
}