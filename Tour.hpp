//
// Created by larry on 2019-03-23.
//

#pragma once

#include <vector>
#include "City.hpp"
#include <algorithm>
#include <math.h>

class Tour {
private:
    vector<City*> cityVec;
    double fitness = 0;
public:
    Tour();

    Tour(vector<City>& cities);

    void randomize();

    double calculateDistance(const City& cityStart, const City& cityEnd);

    void printRoute();

    void assignFitness();

    double getFitness();

    City* getCity(int index);

    void addCity(City* city);

    bool isContainCity(City* city);

    void mutate();


};