cmake_minimum_required(VERSION 3.13)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)
set(-Wall -Wextra -pedantic -std=c++14)

add_executable(GeneticAlgorithm main.cpp City.cpp Tour.hpp Tour.cpp GeneticAlgorithm.hpp GeneticAlgorithm.cpp)