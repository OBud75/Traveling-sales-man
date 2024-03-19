#pragma once

#include "../../route/route.hpp"

// Class declaration for the GreedySolver class, responsible for solving TSP using a greedy algorithm
class GreedySolver
{
public:
    // Static method to solve TSP using a greedy algorithm
    static Route solve(const std::vector<City> &cities);
};
