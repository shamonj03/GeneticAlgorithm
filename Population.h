#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

class Population {

public:
	static int population_size;
	std::vector<class Individual*> individuals;

	Population();
	~Population();

	void populate(const char* target);

	Individual* getHead();
};

#endif // !POPULATION_H