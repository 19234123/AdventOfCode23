#ifndef ADVENTOFCODE23_GALAXY_H
#define ADVENTOFCODE23_GALAXY_H
#include <vector>
#include <cstdlib>
#include <algorithm>

using std::vector;


class Galaxy {
public:
    int x, y;
    vector<Galaxy*> visited {};

    static vector<Galaxy*> galaxyList;

    Galaxy(int x, int y);
    int distanceBetween(Galaxy* otherGalaxy);
    int manhattanDistance(int otherX, int otherY) const;

};


#endif //ADVENTOFCODE23_GALAXY_H
