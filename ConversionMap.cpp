#include <map>
#include "ConversionMap.h"
#include "Functions.h"


ConversionMap::ConversionMap(vector<string> ranges) {
    vector<long long> currentRange;
    for (int i=1; i<ranges.size(); i++) {
        currentRange = splitLineToLongLong(ranges[i], ' ');
        long long mapValue = currentRange[0];
        long long minValue = currentRange[1];
        int range = (int) currentRange[2];
        mapRanges.push_back(new Range(mapValue, minValue, range));
    }
}


ConversionMap::Range::Range(long long int mapValue, long long int minValue, int range) {
    this->mapValueStart = mapValue;
    this->minValue = minValue;
    this->maxValue = minValue+(range-1);
    this->range = range;
}

long long ConversionMap::Range::getMapValue(long long input) const {
    long long distanceFromStart = input - minValue;
    return mapValueStart + distanceFromStart;
}

long long ConversionMap::Range::valueInRange(long long int input) const {
    return (input >= minValue && input <= maxValue);
}


long long ConversionMap::getMapValue(long long int input) {
    long long mapValue = -1;
    for (const auto range: mapRanges) {
        if (range->valueInRange(input)){
            mapValue = range->getMapValue(input);
        }
    }

    if (mapValue == -1) {
        return input;
    } else {
        return mapValue;
    }
}