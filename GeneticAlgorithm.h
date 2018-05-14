#pragma once
class GeneticAlgorithm {
public:
	static float crossover_rate;
	static float mutation_rate;
	class Population* population;
	const char* target;

	GeneticAlgorithm(const char* target, class Population* population);
	~GeneticAlgorithm();

	void simulate();

	class Individual* crossOver(class Individual* mother, class Individual* father);

	void evolve();
};

