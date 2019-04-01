#pragma once

#include <string>
#include <iostream>


using namespace std;

class City {
private:
    string name;
    int x;
    int y;
public:
    City(string cityName);

    City(string cityName, int xCoordinate, int yCoordinate);

    string print();

    int getX() const;

    int getY() const;

    string getName() const;
//    friend bool operator==(const City& lhs, const City& rhs);
};