#ifndef FITNESS_EVALUATOR_H
#define FITNESS_EVALUATOR_H

class FitnessEvaluator
{
public:
	static const char* GENOME;
	static int calculateFitness(char* genese, const char* target);
};
#endif // !FITNESS_EVALUATOR_H
