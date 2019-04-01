//
// Created by larry on 2019-03-22.
//

#include <string>
#include "City.hpp"


using namespace std;


City::City(string cityName) {
    name = cityName;
    x = rand() % 1001;
    y = rand() % 1001;
}

City::City(string cityName, int xCoordinate, int yCoordinate) {
    name = cityName;
    x = xCoordinate;
    y = yCoordinate;
}

string City::print() {
    string str = "";
    str += "City " + name + ": " + to_string(x) + " " + to_string(y);
    return str;
}

int City::getX() const {
    return x;
}

int City::getY() const {
    return y;
}

string City::getName() const {
    return name;
}

//bool operator==(const City& lhs, const City& rhs) {
//    if (lhs.name == rhs.name) {
//        cout << "true detected" << endl;
//        return true;
//    } else {
//        cout << "false detected" << endl;
//        return false;
//    }
//}