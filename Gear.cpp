
#include <algorithm>
#include "Gear.h"

std::list<Gear*> Gear::gearList;

Gear::Gear(int id) {
    this->id = id;
    bool exists;
    if (!gearList.empty()) {
        exists = false;
        for (const auto &gear: gearList) {
            if (gear->id == id) {
                exists = true;
            }
        }
    } else {
        Gear::gearList.push_back(this);
        exists = true;
    }

    if (!exists) {
        Gear::gearList.push_back(this);
    }


}
