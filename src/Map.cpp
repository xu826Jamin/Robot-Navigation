#include "Map.h"
#include <iostream>

Map::Map(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<CellType>(width, CellType::Empty)); // 0 = free
}

bool Map::inBounds(int x, int y) const{
    return x >= 0 && y>= 0 && y < height;
}

void Map::setObstacle(int x, int y) {
    grid[y][x] = CellType::Obstacle; 
}

bool Map::isFree(int x, int y) const {
    if(!inBounds(x,y)) return false;
    return grid[y][x] == CellType::Empty;
}

void Map::print() const {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch(grid[y][x]) {
                case CellType::Empty: std::cout << ". "; break;
                case CellType::Obstacle: std::cout << "# "; break;
            }
        }
        std::cout << std::endl;
    }
}
