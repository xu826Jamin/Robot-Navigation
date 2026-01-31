#pragma once
#include <vector>

class Map {
public:
    Map(int width, int height);
    void setObstacle(int x, int y);
    bool isFree(int x, int y) const;
    void print() const;

private:
    int width;
    int height;
    std::vector<std::vector<int>> grid;
};
