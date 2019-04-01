//
// Created by larry on 2019-03-26.
//

#include "Tour.hpp"

const int CITIES_IN_TOUR = 32;
const int POPULATION_SIZE = 32;
const int ITERATIONS = 1000;
const int PARENT_POOL_SIZE = 5;
const double MUTATION_RATE = .15;
const int NUMBER_OF_PARENTS = 2;

class GeneticAlgorithm {
private:

    static Tour chooseParents(vector<Tour> population);

public:

    static vector<Tour> createCrossList(const vector<Tour>& population);

    static void updatePopulation(vector<Tour>& population);

    static void mutatePopulation(vector<Tour>& population);

    static void moveEliteTop(vector<Tour>& population);

    static Tour getElite(const vector<Tour>& population);
};