#ifndef INDIVIDUAL_H
#define INDIVIDUAL_h
#include <string>

class Individual {

public:
	static int gene_length;
	char* genes;
	int fitness;

	Individual(const char* target);
	~Individual();

	void evaluateFitness(const char* target);

	static char mutation();

	std::string toString();

	bool operator<(const  Individual & other) {
		return fitness < other.fitness;
	}
};

#endif // !INDIVIDUAL_H
