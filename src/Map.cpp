#include "Map.h"
#include <iostream>
#include <algorithm>
#include <set>

Map::Map(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<CellType>(width, CellType::Empty)); // 0 = free
}

bool Map::inBounds(int x, int y) const{
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Map::setObstacle(int x, int y) {
    if (inBounds(x, y)) {
        grid[y][x] = CellType::Obstacle; 
    }
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

// BFS Pathfinding Implementation
std::vector<std::pair<int, int>> Map::findPath(int startX, int startY, int goalX, int goalY){
    if (!isFree(startX, startY) || !isFree(goalX, goalY)) {
        return {}; //Return empty path if start or goal is blocked 
    }

    //Direction arrays for 4-directional movement (N,E,S,W)
    const int dx[] = {0,1,0,-1};
    const int dy[] = {-1,0,1,0};

    // Visited grid to track explored cells
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    //Queue for BFS frontier 
    std::queue<Node*> frontier;

    //Initialize with start position
    frontier.push(new Node(startX, startY, nullptr));
    visited[startY][startX] = true;

    //Variable to store goal node when found 
    Node* goalNode = nullptr;

    //BFS Main Loop
    while (!frontier.empty()) {
        //Get next node from queue
        Node* current = frontier.front();
        frontier.pop();

        //Check if we reached the goal 
        if (current->x == goalX && current->y == goalY) {
            goalNode = current;
            break; // Exit early, we found the goal
        }

        //Explore all 4 neighbors
        for (int i= 0; i < 4; i++) {
            int nx = current->x +dx[i]; // Neighbor x
            int ny = current->y + dy[i]; //Neighbor y 

            if (isFree(nx,ny) && !visited[ny][nx]) {
                visited[ny][nx] = true; // mark as visited immediately
                frontier.push(new Node(nx, ny, current)); // Add neighbor to frontier with current as parent
            } 
        }
    }

    //Path Reconstruction
    std::vector<std::pair<int, int>> path;

    if (goalNode!= nullptr) {
        // Walk backwards from goal to start using parent pointers
        Node* current = goalNode;
        while (current != nullptr) {
            path.push_back({current->x, current->y});
            current = current->parent;
        }

        // Reverse to get path from start to goal
        std::reverse(path.begin(), path.end());
    }

    //Memory Cleanup - Delete all allocated nodes
    std::set<Node*> toDelete;
    
    // Collect nodes still in frontier
    while (!frontier.empty()) {
        toDelete.insert(frontier.front());
        frontier.pop();
    }
    
    // Collect nodes from the path (if path was found)
    if (goalNode != nullptr) {
        Node* current = goalNode;
        while (current != nullptr) {
            toDelete.insert(current);
            current = current->parent;
        }
    }
    
    // Delete all unique nodes
    for (Node* node : toDelete) {
        delete node;
    }
    
    return path;
}