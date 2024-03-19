#pragma once

#include "../../route/route.hpp"

// Class representing a solver for the TSP using brute force approach
class BruteForceSolver
{
public:
    // Static method to solve the TSP using brute force algorithm
    static Route solve(const std::vector<City> &cities);
};
