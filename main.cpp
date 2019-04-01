#include <iostream>

#include "City.hpp"
#include "Tour.hpp"
#include "GeneticAlgorithm.hpp"
#include <vector>

const int CITIES_IN_TOUR = 32;
const int POPULATION_SIZE = 32;
const int ITERATIONS = 1000;


int main() {

    srand (time(0));
    vector<City> masterList;

    for (int i = 0; i < CITIES_IN_TOUR; i++) {
        City city(to_string(i + 1));
        masterList.push_back(city);
    }

    vector<Tour> population;

    for (int i = 0; i < POPULATION_SIZE; i++) {
        Tour tour(masterList);
        population.push_back(tour);
    }

    // starting point, creating elite and getting base distance
    GeneticAlgorithm::moveEliteTop(population);
    Tour baseTour = GeneticAlgorithm::getElite(population);
    double baseDistance = GeneticAlgorithm::getElite(population).getFitness();
    double bestDistance;
    double previousDistance = baseDistance;
    double currentDistance;

    int iteration = 0;
    do {
        cout << "Iteration: " << iteration + 1 << endl;
        //Selection
        GeneticAlgorithm::moveEliteTop(population);
        //Crossover
        GeneticAlgorithm::updatePopulation(population);
        // mutation & evaluation
        GeneticAlgorithm::mutatePopulation(population);

        bestDistance = GeneticAlgorithm::getElite(population).getFitness();
        cout << "New best Distance: " << bestDistance << endl;

        currentDistance = bestDistance;
        iteration++;

        cout << "Improvement rate: " << 100 - (bestDistance / baseDistance) * 100 << "%" << endl;

        cout << "Was improvement made: ";
        if (currentDistance != previousDistance) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        previousDistance = currentDistance;

    } while ((bestDistance / baseDistance) > .70 && iteration < ITERATIONS);

    cout << endl;
    cout << "Report:" << endl;
    cout << "Number of Iterations: " << iteration << endl;
    cout << "Base distance: " << baseDistance << endl;
    cout << "Best distance: " << GeneticAlgorithm::getElite(population).getFitness() << endl;
    cout << "Achieved Improvement Factor: " << 100 - (bestDistance / baseDistance) * 100 << "%" << endl;
    cout << "Base route: ";
    baseTour.printRoute();
    cout << endl;
    cout << "Best route: ";
    GeneticAlgorithm::getElite(population).printRoute();






    return 0;
}