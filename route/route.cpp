#include "route.hpp"
#include <algorithm>

Route::Route() {}

void Route::addCity(const City& city) {
    cities.push_back(city);
}

double Route::totalDistance() const {
    double distance = 0;
    for (size_t i = 0; i < cities.size() - 1; ++i) {
        distance += cities[i].distanceTo(cities[i + 1]);
    }
    // Add distance from last city to first city to complete the loop
    distance += cities.back().distanceTo(cities.front());
    return distance;
}

std::vector<City> Route::getCities() const {
    return cities;
}

Route Route::twoOptSwap(int i, int j) const {
    Route newRoute = *this;
    std::reverse(newRoute.cities.begin() + i, newRoute.cities.begin() + j + 1);
    return newRoute;
}
