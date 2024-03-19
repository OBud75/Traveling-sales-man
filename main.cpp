#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <thread>
#include "./city/city.hpp"
#include "./route/route.hpp"
#include "./algorithms/brute_force/brute_force_solver.hpp"
#include "./algorithms/greedy/greedy_solver.hpp"
#include "./algorithms/two_opt/two_opt_solver.hpp"

// Function to read cities from a file and return a vector of City objects
std::vector<City> readCitiesFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::vector<City> cities;
    int id;
    double x, y;
    // Read city data from the file and create City objects
    while (file >> id >> x >> y)
    {
        cities.emplace_back(id, x, y);
    }
    return cities;
}

// Function to write the route to a file
void writeRouteToFile(const Route &route, const std::string &filename)
{
    std::filesystem::create_directory("output"); // Create "output" directory if it doesn't exist
    std::ofstream file("output/" + filename);    // output results in a file
    // Write city IDs in the route to the file
    for (const City &city : route.getCities())
    {
        file << city.getId() << " ";
    }
    file << std::endl;
    // calculate and write total distance of the route to the file
    file << "Total distance: " << route.totalDistance() << std::endl;
}

int main()
{
    // Read cities from input file
    std::vector<City> cities = readCitiesFromFile("input.txt");

    // Create threads, each executing a different algorithm
    std::thread bruteForceThread([&]()
                                 {
        
        Route bruteForceRoute = BruteForceSolver::solve(cities);
        writeRouteToFile(bruteForceRoute, "brute_force_output.txt"); });

    std::thread greedyThread([&]()
                             {
        
        Route greedyRoute = GreedySolver::solve(cities);
        
        writeRouteToFile(greedyRoute, "greedy_output.txt");

        // Improve greedy solution using 2-opt algorithm
        Route improvedRoute = TwoOptSolver::solve(greedyRoute);
        
        writeRouteToFile(improvedRoute, "greedy_output_improved.txt"); });

    // Wait for threads to finish
    bruteForceThread.join();
    greedyThread.join();

    return 0;
}