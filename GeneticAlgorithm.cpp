//
// Created by larry on 2019-03-26.
//


#include "GeneticAlgorithm.hpp"


// returns the elite tour.
Tour GeneticAlgorithm::getElite(const vector<Tour>& population) {
    return population[0];
}

//finds the fittest tour and moves it to the top
void GeneticAlgorithm::moveEliteTop(vector<Tour>& population) {

    int index = 0;
    double value = population[0].getFitness();
    for (int i = 1; i < population.size(); i++) {
        if (population[i].getFitness() < value) {
            value = population[i].getFitness();
            index = i;
        }
    }

    iter_swap(population.begin(), population.begin() + index);
}

// randomly choose parents of parent pool subset
Tour GeneticAlgorithm::chooseParents(vector<Tour> population) {
    vector<Tour> parentSubset;

    for (int i = 0; i < PARENT_POOL_SIZE; i++) {
        int index = rand() % population.size();
        parentSubset.push_back(population[index]);
        population.erase(population.begin() + index);
    }

    int index = 0;
    double value = parentSubset[0].getFitness();
    for (int i = 1; i < parentSubset.size(); i++) {
        if (parentSubset[i].getFitness() < value) {
            value = parentSubset[i].getFitness();
            index = i;
        }
    }

    return parentSubset[index];
}

// Creating cross list. Crossing multiple parent tours to make a child tours
vector<Tour> GeneticAlgorithm::createCrossList(const vector<Tour>& population) {
    vector<Tour> crossedList;

    for (int i = 0; i < population.size() - 1; i++) {
        vector<Tour> parentTours;
        for (int j = 0; j < NUMBER_OF_PARENTS; j++) {
            Tour tour = chooseParents(population);
            parentTours.push_back(tour);
        }

        vector<int> random_indexes;
        for (int k = 0; k < NUMBER_OF_PARENTS - 1; k++) {
            int index = rand() % CITIES_IN_TOUR;
            random_indexes.push_back(index);
        }
        random_indexes.push_back(CITIES_IN_TOUR - 1);
        sort(random_indexes.begin(), random_indexes.end());

        Tour childTour;
        for (int z = 0; z < parentTours.size(); z++) {
            for (int h = 0; h <= random_indexes[z]; h++) {
                if (!childTour.isContainCity(parentTours[z].getCity(h))) {
                    childTour.addCity(parentTours[z].getCity(h));
                }
            }
        }
//        childTour.printSize();
        crossedList.push_back(childTour);
    }

    return crossedList;
}

// create a crossList of tours and merge it with the population list
void GeneticAlgorithm::updatePopulation(vector<Tour> &population) {
    vector<Tour> crossedList = createCrossList(population);
    for (int i = 1; i < population.size(); i++) {
        population[i] = crossedList[i - 1];
    }
}

//smudge around some of the cities in each tour and evaluate the fitness for the new list of tours
void GeneticAlgorithm::mutatePopulation(vector<Tour> &population) {
    for (int i = 1; i < population.size(); i++) {
        population[i].mutate(MUTATION_RATE);
    }
}
