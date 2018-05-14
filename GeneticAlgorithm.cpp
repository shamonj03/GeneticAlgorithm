#include <vector>
#include <algorithm>
#include <iostream>

#include "GeneticAlgorithm.h"
#include "Population.h"
#include "Individual.h"
#include "Util.h"

float GeneticAlgorithm::crossover_rate = 0.70f;
float GeneticAlgorithm::mutation_rate = 1.0f;

GeneticAlgorithm::GeneticAlgorithm(const char* target_, Population* population_) : target(target_), population(population_) {

}


GeneticAlgorithm::~GeneticAlgorithm() {
}

bool compare(const Individual* l, const Individual* r) //(2)
{
	return r->fitness < l->fitness;
}

void GeneticAlgorithm::simulate() {
	population->populate(target);

int generation = 0;
	Individual* head = population->getHead();
	while(head->fitness < Individual::gene_length) {
		std::sort(population->individuals.begin(), population->individuals.end(), compare);
		head = population->getHead();

		std::cout << "Generation: " << generation;
		std::cout << ", Fittest: " << head->fitness;
		std::cout << ", Genes: " << head->toString();
		std::cout << std::endl;

		generation++;
		evolve();
	}

	std::cout << "Generation: " << generation;
	std::cout << ", Fittest: " << head->fitness;
	std::cout << ", Genes: " << head->toString();
	std::cout << std::endl;

	while (true);
}


Individual* GeneticAlgorithm::crossOver(Individual* mother, Individual* father) {
	Individual* individual = new Individual(target);

	for (int i = 0; i < Individual::gene_length; i++) {
		float r = Util::randf(0, 1);

		if (r < crossover_rate) {
			individual->genes[i] = mother->genes[i];
		} else {
			individual->genes[i] = father->genes[i];
		}
	}
	return individual;
}


void GeneticAlgorithm::evolve() {
	int half_size = (int)std::ceil(Population::population_size * 0.50f);
	for (int i = 1; i < Population::population_size; i++) {
		int mother_index = rand() % half_size;

		int father_index = rand() % half_size;
		while (father_index != 0) {
			father_index = rand() % half_size;
		}

		Individual* mother = population->individuals[0];
		Individual* father = population->individuals[father_index];

		Individual* offspring = crossOver(mother, father);
		population->individuals[i]->genes = offspring->genes;
	}

	for (int i = 1; i < Population::population_size; i++) {
		float r = Util::randf(0, 1);
		if (r < mutation_rate) {
			int r_g = std::rand() % Individual::gene_length;
			population->individuals[i]->genes[r_g] = Individual::mutation();
		}
		population->individuals[i]->evaluateFitness(target);
	}
}