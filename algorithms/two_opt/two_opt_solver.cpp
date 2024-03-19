#include "two_opt_solver.hpp"

Route TwoOptSolver::solve(const Route& initialRoute) {
    Route bestRoute = initialRoute;
    bool improvement = true;

    while (improvement) {
        improvement = false;
        for (auto i = 1; i < bestRoute.getCities().size() - 1; ++i) {
            for (auto j = i + 1; j < bestRoute.getCities().size(); ++j) {
                Route newRoute = bestRoute.twoOptSwap(i, j);
                if (newRoute.totalDistance() < bestRoute.totalDistance()) {
                    bestRoute = newRoute;
                    improvement = true;
                }
            }
        }
    }

    return bestRoute;
}
