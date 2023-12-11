#include "Galaxy.h"

vector<Galaxy*> Galaxy::galaxyList;

Galaxy::Galaxy(long long x, long long y) {
    this->x = x;
    this->y = y;
    visited.push_back(this);
    galaxyList.push_back(this);
}

long long Galaxy::manhattanDistance(long long otherX, long long otherY) const {
    return std::abs(this->x - otherX) + std::abs(this->y - otherY);
}

long long Galaxy::distanceBetween(Galaxy* otherGalaxy) {
    if (std::find(visited.begin(), visited.end(), otherGalaxy) == visited.end()) {
        otherGalaxy->visited.push_back(this);
        return manhattanDistance(otherGalaxy->x, otherGalaxy->y);
    }
    return 0;
}


