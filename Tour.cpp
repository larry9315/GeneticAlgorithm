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

void Tour::randomize() {
    random_shuffle(cityVec.begin(), cityVec.end());
}

double Tour::calculateDistance(const City& cityStart, const City& cityEnd) {
    double xDistance = abs(cityStart.getX() - cityEnd.getX());
    double yDistance = abs(cityStart.getY() - cityEnd.getY());

    return sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
}

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

void Tour::printRoute() {
    for (City* city : cityVec) {
        cout << "City: " << city->getName() << " -> ";
    }
//    cout << "fitness: " << fitness << endl;
}

bool Tour::isContainCity(City *city) {
    for (int i = 0; i < cityVec.size(); i++) {
        if (cityVec[i]->getName() == city->getName()) {
            return true;
        }
    }
    return false;
}

void Tour::mutate() {
    for (int i = 0; i < cityVec.size() - 1; i++) {
        double r = ((double) rand() / (RAND_MAX));
        if (r < 0.15) {
            iter_swap(cityVec.begin() + i, cityVec.begin() + i + 1);
        }
    }
    assignFitness();
}
