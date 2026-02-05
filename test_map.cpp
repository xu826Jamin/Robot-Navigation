#include <iostream>
#include <cstdlib>
#include "Map.h"

int main() {
    try {
        std::cout << "TEST 1: Simple straight path\n";
        std::cout.flush();
        
        Map map1(10, 5);
        map1.print();
        std::cout << "About to find path from (0,0) to (9,0)\n";
        std::cout.flush();
        
        auto path1 = map1.findPath(0, 0, 9, 0);
        
        std::cout << "Path find returned\n";
        std::cout.flush();
        
        if (path1.empty()) {
            std::cout << "No path found!\n";
        } else {
            std::cout << "Path found with " << path1.size() << " steps\n";
        }
        
        std::cout << "TEST 2: Path around obstacle\n";
        std::cout.flush();
        
        Map map2(10, 5);
        
        // Create vertical wall
        for (int y = 0; y < 4; y++) {
            map2.setObstacle(5, y);
        }
        
        map2.print();
        std::cout << "About to find path in map with obstacle\n";
        std::cout.flush();
        
        auto path2 = map2.findPath(2, 2, 8, 2);
        
        std::cout << "Path find returned\n";
        std::cout.flush();
        
        if (path2.empty()) {
            std::cout << "No path found!\n";
        } else {
            std::cout << "Path found with " << path2.size() << " steps\n";
        }
        
        std::cout << "All tests done\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
}
