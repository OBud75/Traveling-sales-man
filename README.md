# Traveling Salesman Problem Solver

#### by: Oussama SALAHOUELHADJ

---

This project provides a solution to the Traveling Salesman Problem (TSP) using various algorithms, including brute force, greedy, and 2-opt algorithms. It allows finding the shortest possible route that visits each city exactly once and returns to the origin city.

## Algorithms

### 1. Brute Force Algorithm

The brute force algorithm calculates the total distance for every possible permutation of cities and returns the one with the shortest distance. While accurate, it is computationally expensive and becomes impractical for larger instances of TSP due to its time complexity.

### 2. Greedy Algorithm

The greedy algorithm starts from a random city and repeatedly selects the nearest unvisited city until all cities are visited. While it's computationally less expensive than brute force, it may not always find the optimal solution.

### 3. 2-opt Algorithm

The 2-opt algorithm is a local search heuristic that improves existing solutions by iteratively swapping pairs of edges to find a shorter tour. It can be applied to improve solutions obtained from other algorithms, such as the greedy algorithm.

## How to Run the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/OussamaSALAHOUELHADJ/Traveling-sales-man.git
   ```

2. Navigate to the project directory:

   ```bash
   cd Traveling-sales-man
   ```

3. Compile the project using the provided Makefile:

   ```bash
    make
   ```

4. Run the executable:

   ```
   ./tsp_solver
   ```

5. The program will read the city data from the input file input.txt, solve the TSP using different algorithms in parallel threads, and output the results to separate text files in the output folder.
