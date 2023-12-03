#ifndef ADVENTOFCODE23_ENGINEPART_H
#define ADVENTOFCODE23_ENGINEPART_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

class EnginePart {
public:
    int row;
    int startCol;
    int endCol;
    int value;

    static std::list<EnginePart> partList;
    static std::list<std::string> gearCoordinates;

    EnginePart(int row, int value, int startCol);
    bool checkIfValid(const std::vector<std::string>& grid);
    void getGearCoordinates(const std::vector<std::string> &grid);

};


#endif //ADVENTOFCODE23_ENGINEPART_H
