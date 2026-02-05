#pragma once
#include <vector>
#include <queue>
#include <utility>

enum class CellType {
    Empty,
    Obstacle
};

struct Node {
    int x, y; // Current Position
    Node* parent; // Parent node for path reconstruction 

    Node(int x, int y, Node* parent = nullptr)
        : x(x), y(y), parent(parent) {}
};

class Map {
public:
    Map(int width, int height);
    void setObstacle(int x, int y);
    bool isFree(int x, int y) const;
    void print() const;

    // BFS pathfinding function
    std::vector<std::pair<int, int>> findPath(int startX, int startY, int goalX, int goalY);

private:
    int width;
    int height;
    std::vector<std::vector<CellType>> grid;
    bool inBounds(int x, int y) const;
};
