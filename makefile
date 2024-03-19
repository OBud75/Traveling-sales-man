CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC_DIR = .
BUILD_DIR = build
EXECUTABLE = tsp_solver
SRCS = city/city.cpp route/route.cpp algorithms/brute_force/brute_force_solver.cpp algorithms/greedy/greedy_solver.cpp algorithms/two_opt/two_opt_solver.cpp main.cpp
OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)
