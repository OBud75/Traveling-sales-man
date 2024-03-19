#include "greedy_solver.hpp"
#include <algorithm>
#include <limits>

Route GreedySolver::solve(const std::vector<City>& cities) {
    Route route;
    std::vector<bool> visited(cities.size(), false);
    int currentCityIndex = 0;
    route.addCity(cities[currentCityIndex]);
    visited[currentCityIndex] = true;

    for (size_t i = 0; i < cities.size() - 1; ++i) {
        double minDistance = std::numeric_limits<double>::max();
        int nextCityIndex = -1;
        for (size_t j = 0; j < cities.size(); ++j) {
            if (!visited[j]) {
                double distance = cities[currentCityIndex].distanceTo(cities[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextCityIndex = j;
                }
            }
        }
        route.addCity(cities[nextCityIndex]);
        visited[nextCityIndex] = true;
        currentCityIndex = nextCityIndex;
    }

    // Return to the starting city to complete the tour
    route.addCity(cities[0]);

    return route;
}
