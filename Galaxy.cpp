#include "Galaxy.h"

vector<Galaxy*> Galaxy::galaxyList;

Galaxy::Galaxy(int x, int y) {
    this->x = x;
    this->y = y;
    visited.push_back(this);
    galaxyList.push_back(this);
}

int Galaxy::manhattanDistance(int otherX, int otherY) const {
    return abs(this->x - otherX) + abs(this->y - otherY);
}

int Galaxy::distanceBetween(Galaxy* otherGalaxy) {
    if (std::find(visited.begin(), visited.end(), otherGalaxy) == visited.end()) {
        otherGalaxy->visited.push_back(this);
        return manhattanDistance(otherGalaxy->x, otherGalaxy->y);
    }
    return 0;
}


