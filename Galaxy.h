#ifndef ADVENTOFCODE23_GALAXY_H
#define ADVENTOFCODE23_GALAXY_H
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;

class Galaxy {
public:
    long long x, y;
    vector<Galaxy*> visited {};

    static vector<Galaxy*> galaxyList;

    Galaxy(long long x, long long y);
    long long distanceBetween(Galaxy* otherGalaxy);
    [[nodiscard]] long long manhattanDistance(long long otherX, long long otherY) const;

};


#endif //ADVENTOFCODE23_GALAXY_H
