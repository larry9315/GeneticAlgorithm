//
// Created by larry on 2019-03-26.
//


#include "GeneticAlgorithm.hpp"


Tour GeneticAlgorithm::getElite(const vector<Tour>& population) {
    return population[0];
}

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

Tour GeneticAlgorithm::chooseParents(vector<Tour> population) {
    vector<Tour> parentSubset;

    for (int i = 0; i < 5; i++) {
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

Tour GeneticAlgorithm::mergeTour(Tour tour1, Tour tour2) {
    int index = rand() % 32;
    Tour childTour;
    for (int i = 0; i <= index; i++) {
        childTour.addCity(tour1.getCity(i));
    }

    for (int i = 0; i < 32; i++) {
        if (!childTour.isContainCity(tour2.getCity(i))) {
            childTour.addCity(tour2.getCity(i));
        }
    }



    return childTour;
}

vector<Tour> GeneticAlgorithm::createCrossList(const vector<Tour>& population) {
    vector<Tour> crossedList;
    for (int i = 0; i < population.size() - 1; i++) {
        Tour tour1 = chooseParents(population);
        Tour tour2 = chooseParents(population);
        Tour merged = mergeTour(tour1, tour2);
        crossedList.push_back(merged);
    }

    return crossedList;
}

void GeneticAlgorithm::updatePopulation(vector<Tour> &population) {
    vector<Tour> crossedList = createCrossList(population);
    for (int i = 1; i < population.size(); i++) {
        population[i] = crossedList[i - 1];
    }
}

void GeneticAlgorithm::mutatePopulation(vector<Tour> &population) {
    for (int i = 1; i < population.size(); i++) {
        population[i].mutate();
    }
}
