# RobotNavigator

A C++ pathfinding and navigation system implementing the Breadth-First Search (BFS) algorithm for 2D grid-based environments.

## Overview

RobotNavigator is a pathfinding simulation project that demonstrates autonomous navigation through obstacle-filled environments. The system uses BFS to find optimal paths from start to goal positions while avoiding obstacles.

## Features

- **BFS Pathfinding Algorithm**: Implements breadth-first search to guarantee shortest path in unweighted grids
- **2D Grid-Based Map System**: Flexible map creation with customizable dimensions
- **Obstacle Management**: Dynamic obstacle placement and collision detection
- **Path Visualization**: Visual representation of maps, obstacles, and computed paths
- **Comprehensive Testing**: Built-in test suite covering various navigation scenarios

## Core Components

### Map System
- **Grid Representation**: 2D grid with configurable width and height
- **Cell Types**: Empty cells (`.`) and obstacles (`#`)
- **Boundary Checking**: Automatic validation of coordinates
- **Path Finding**: BFS implementation returning optimal step-by-step paths

### Path Finding Features
- **4-Directional Movement**: North, East, South, West navigation
- **Optimal Path Guarantee**: BFS ensures shortest path in terms of steps
- **Path Reconstruction**: Full path from start to goal with coordinates
- **Memory Management**: Proper cleanup of dynamically allocated nodes

## Test Scenarios

The project includes 5 comprehensive test cases:

1. **Simple Straight Path**: Basic horizontal navigation without obstacles
2. **Path Around Obstacle**: Navigation around a vertical wall barrier
3. **No Path Available**: Handling completely blocked scenarios
4. **Complex Maze**: Multi-obstacle navigation through intricate layouts
5. **Start Equals Goal**: Edge case where start and destination are identical

## Building the Project

### Requirements
- CMake 3.10 or higher
- C++11 compatible compiler
- Make or equivalent build system

### Build Instructions

```bash
# Navigate to project directory
cd RobotNavigator

# Create and enter build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile the project
make

# Run the executable
./RobotNavigator
```

## Project Structure

```
RobotNavigator/
├── CMakeLists.txt          # Build configuration
├── include/                # Header files
│   ├── Map.h              # Map class definition
│   ├── Robot.h            # Robot class definition
│   └── Simulator.h        # Simulator class definition
├── src/                   # Source files
│   ├── main.cpp           # Test suite and entry point
│   ├── Map.cpp            # Map implementation with BFS
│   ├── Robot.cpp          # Robot logic
│   └── Simulator.cpp      # Simulation control
└── build/                 # Compiled binaries (generated)
```

## Usage Example

```cpp
#include "Map.h"

// Create a 10x5 grid map
Map map(10, 5);

// Add obstacles
map.setObstacle(5, 0);
map.setObstacle(5, 1);
map.setObstacle(5, 2);

// Find path from (0,0) to (9,0)
auto path = map.findPath(0, 0, 9, 0);

// Display the path
if (!path.empty()) {
    for (const auto& pos : path) {
        std::cout << "(" << pos.first << ", " << pos.second << ")\n";
    }
}
```

## Algorithm Details

### BFS Implementation
- **Queue-based exploration**: Guarantees level-by-level traversal
- **Visited tracking**: Prevents revisiting cells
- **Parent pointers**: Enables path reconstruction
- **Early termination**: Stops when goal is reached

### Time Complexity
- **BFS**: O(width × height) in worst case
- **Path Reconstruction**: O(path length)

### Space Complexity
- **Grid storage**: O(width × height)
- **Visited array**: O(width × height)
- **Queue/Frontier**: O(width × height) worst case

## Output

The program outputs:
- Visual map representation with obstacles marked as `#`
- Path coordinates for each successful navigation
- Step count for each path
- Test results for all scenarios

## Future Enhancements

Potential improvements could include:
- A* pathfinding for weighted grids
- Diagonal movement support (8-directional)
- Dynamic obstacle updates during navigation
- Multi-robot coordination
- Real-time visualization
- Different terrain costs

## License

This project is for educational purposes demonstrating pathfinding algorithms.