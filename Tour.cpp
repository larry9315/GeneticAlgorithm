//
// Created by larry on 2019-03-23.
//



#include "Tour.hpp"

Tour::Tour() {

}

Tour::Tour(vector<City>& cities) {
    //initialization
    for (int i = 0; i < cities.size(); i++) {
        City* ptr = &cities[i];
        cityVec.push_back(ptr);
    }

    randomize();

    //fitness calculation
    assignFitness();

}

//randomly shuffles the city vectors
void Tour::randomize() {
    random_shuffle(cityVec.begin(), cityVec.end());
}

// uses pythagorean theorem to calculate the distance
double Tour::calculateDistance(const City& cityStart, const City& cityEnd) {
    double xDistance = abs(cityStart.getX() - cityEnd.getX());
    double yDistance = abs(cityStart.getY() - cityEnd.getY());

    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

// calculates the fitness of the tour
void Tour::assignFitness() {
    int i;
    fitness = 0;
    for (i = 0; i < cityVec.size() - 1; i++) {
        fitness += calculateDistance(*cityVec[i], *cityVec[i + 1]);
    }
    fitness += calculateDistance(*cityVec[i], *cityVec[0]);
}

double Tour::getFitness() {
    return fitness;
}

City* Tour::getCity(int index) {
    return cityVec[index];
}

void Tour::addCity(City* city) {
    cityVec.push_back(city);
}

//print the route
void Tour::printRoute() {
    for (City* city : cityVec) {
        cout << "City: " << city->getName() << " -> ";
    }
}

// check if the city with the same name is in the list of the tour
bool Tour::isContainCity(City *city) {
    for (int i = 0; i < cityVec.size(); i++) {
        if (cityVec[i]->getName() == city->getName()) {
            return true;
        }
    }
    return false;
}

// smudge some cities around depending on mutation rate and evaluate the fitness
void Tour::mutate(double mutationRate) {
    for (int i = 0; i < cityVec.size() - 1; i++) {
        double r = ((double) rand() / (RAND_MAX));
        if (r < mutationRate) {
            iter_swap(cityVec.begin() + i, cityVec.begin() + i + 1);
        }
    }
    assignFitness();
}

void Tour::printSize() {
    cout << cityVec.size() << endl;
}
