#include <iostream>
#include "Map.h"

int main() {
    std::cout << "=== BFS Pathfinding Tests ===\n\n";
    std::cout.flush();
    
    // ========================================
    // TEST 1: Simple straight path
    // ========================================
    std::cout << "TEST 1: Simple straight path\n";
    std::cout << "-----------------------------\n";
    std::cout.flush();
    
    Map map1(10, 5);
    map1.print();
    
    auto path1 = map1.findPath(0, 0, 9, 0);
    
    if (path1.empty()) {
        std::cout << "No path found!\n";
    } else {
        std::cout << "Path found with " << path1.size() << " steps:\n";
        for (size_t i = 0; i < path1.size(); i++) {
            std::cout << "  Step " << i << ": (" 
                      << path1[i].first << ", " << path1[i].second << ")\n";
        }
    }
    std::cout << "\n";
    
    // ========================================
    // TEST 2: Path around obstacle
    // ========================================
    std::cout << "TEST 2: Path around obstacle\n";
    std::cout << "-----------------------------\n";
    
    Map map2(10, 5);
    
    // Create vertical wall
    for (int y = 0; y < 4; y++) {
        map2.setObstacle(5, y);
    }
    
    std::cout << "Map (# = obstacle):\n";
    map2.print();
    
    auto path2 = map2.findPath(2, 2, 8, 2);
    
    if (path2.empty()) {
        std::cout << "No path found!\n";
    } else {
        std::cout << "Path found with " << path2.size() << " steps:\n";
        for (const auto& pos : path2) {
            std::cout << "  (" << pos.first << ", " << pos.second << ")\n";
        }
    }
    std::cout << "\n";
    
    // ========================================
    // TEST 3: No path (completely blocked)
    // ========================================
    std::cout << "TEST 3: No path (completely blocked)\n";
    std::cout << "-------------------------------------\n";
    
    Map map3(10, 5);
    
    // Create complete wall
    for (int y = 0; y < 5; y++) {
        map3.setObstacle(5, y);
    }
    
    std::cout << "Map (# = obstacle):\n";
    map3.print();
    
    auto path3 = map3.findPath(2, 2, 8, 2);
    
    if (path3.empty()) {
        std::cout << "No path found! (Expected - wall blocks path)\n";
    } else {
        std::cout << "Path found with " << path3.size() << " steps\n";
    }
    std::cout << "\n";
    
    // ========================================
    // TEST 4: Complex maze
    // ========================================
    std::cout << "TEST 4: Complex maze\n";
    std::cout << "---------------------\n";
    
    Map map4(12, 8);
    
    // Create maze obstacles
    map4.setObstacle(2, 0);
    map4.setObstacle(2, 1);
    map4.setObstacle(2, 2);
    map4.setObstacle(2, 3);
    
    map4.setObstacle(5, 2);
    map4.setObstacle(5, 3);
    map4.setObstacle(5, 4);
    map4.setObstacle(5, 5);
    
    map4.setObstacle(8, 0);
    map4.setObstacle(8, 1);
    map4.setObstacle(8, 2);
    map4.setObstacle(8, 3);
    map4.setObstacle(8, 4);
    
    std::cout << "Map (# = obstacle):\n";
    map4.print();
    
    auto path4 = map4.findPath(0, 0, 11, 7);
    
    if (path4.empty()) {
        std::cout << "No path found!\n";
    } else {
        std::cout << "Path found with " << path4.size() << " steps\n";
        std::cout << "Start: (" << path4.front().first << ", " 
                  << path4.front().second << ")\n";
        std::cout << "Goal:  (" << path4.back().first << ", " 
                  << path4.back().second << ")\n";
    }
    std::cout << "\n";
    
    // ========================================
    // TEST 5: Start equals goal
    // ========================================
    std::cout << "TEST 5: Start equals goal\n";
    std::cout << "--------------------------\n";
    
    Map map5(5, 5);
    auto path5 = map5.findPath(2, 2, 2, 2);
    
    if (path5.empty()) {
        std::cout << "No path found!\n";
    } else {
        std::cout << "Path found with " << path5.size() << " step(s):\n";
        for (const auto& pos : path5) {
            std::cout << "  (" << pos.first << ", " << pos.second << ")\n";
        }
    }
    std::cout << "\n";
    
    std::cout << "=== All tests complete! ===\n";
    
    return 0;
}