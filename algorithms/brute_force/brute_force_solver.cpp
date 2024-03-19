#include "brute_force_solver.hpp"
#include <algorithm>
#include <limits>
#include <numeric>

Route BruteForceSolver::solve(const std::vector<City>& cities) {
    Route bestRoute;
    double minDistance = std::numeric_limits<double>::max();
    std::vector<int> indices(cities.size());
    std::iota(indices.begin(), indices.end(), 0); // Fill with 0, 1, 2, ..., n-1

    do {
        Route route;
        for (int index : indices) {
            route.addCity(cities[index]);
        }
        // Add starting city as the last city
        route.addCity(cities[0]);
        double distance = route.totalDistance() - cities.back().distanceTo(cities.front());
        if (distance < minDistance) {
            minDistance = distance;
            bestRoute = route;
        }
    } while (std::next_permutation(indices.begin() + 1, indices.end())); // Start from second city

    return bestRoute;
}

