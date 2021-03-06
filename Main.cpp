// GeneticAlgorithm.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <iostream>

#include "Population.h"
#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "FitnessEvaluator.h"

int main() {
	srand(time(NULL));

	const char* target = "Hello world";
	Individual::gene_length = std::strlen(target);

	Population* population = new Population();
	GeneticAlgorithm algorithm(target, population);
	algorithm.simulate();

	//while (true);
    return 0;
}

