#pragma once

#include <vector>
#include "../city/city.hpp"

// Class representing a route containing a sequence of cities
class Route
{
private:
    std::vector<City> cities; // Vector to store cities in the route

public:
    // Default constructor
    Route();

    // Method to add a city to the route
    void addCity(const City &city);

    // Method to calculate the total distance of the route
    double totalDistance() const;

    // Method to retrieve the vector of cities in the route
    std::vector<City> getCities() const;

    // Method to perform a 2-opt swap operation on the route
    Route twoOptSwap(int i, int j) const; // Perform 2-opt swap operation
};