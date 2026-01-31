#include <iostream>
#include "Map.h"

int main() {
    Map map(10, 10);
    map.setObstacle(3, 4);
    map.setObstacle(5, 6);
    map.print();
    return 0;
}
