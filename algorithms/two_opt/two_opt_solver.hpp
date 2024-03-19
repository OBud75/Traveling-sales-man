#pragma once

#include "../../route/route.hpp"

// Class declaration for the TwoOptSolver class, responsible for solving TSP using the 2-opt algorithm
class TwoOptSolver
{
public:
    // Static method to solve TSP using the 2-opt algorithm
    static Route solve(const Route &initialRoute);
};
