//
// Created by Steven on 03/12/2023.
//

#ifndef ADVENTOFCODE23_GEAR_H
#define ADVENTOFCODE23_GEAR_H
#include <list>
#include <string>

class Gear {
public:
    int id;
    std::list<int> neighbours;
    static std::list<Gear*> gearList;

    Gear(int id);

};


#endif //ADVENTOFCODE23_GEAR_H
