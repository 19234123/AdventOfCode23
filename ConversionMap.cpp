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

        // 50 98 2
    }
}

ConversionMap::Range::Range(long long int mapValue, long long int minValue, int range) {
    this->mapValueStart = mapValue;
    this->minValue = minValue;
    this->maxValue = minValue+(range-1);
    this->range = range;
}

long long ConversionMap::Range::getMapValue(long long input) const {
    return mapValueStart + (input-minValue);
}

long long ConversionMap::Range::getReverseMapValue(long long input) const {
    return minValue + (input-mapValueStart);
}

long long ConversionMap::Range::keyInRange(long long int input) const {
    return (input >= mapValueStart && input <= (mapValueStart+range));
}

long long ConversionMap::Range::valueInRange(long long int input) const {
    return (input >= minValue && input <= maxValue);
}

long long ConversionMap::getReverseMapValue(long long int input) {
    for (const auto range: mapRanges) {
        if (range->keyInRange(input)){
            return range->getReverseMapValue(input);
        }
    }
    return input;
}

long long ConversionMap::getMapValue(long long int input) {
    for (const auto range: mapRanges) {
        if (range->valueInRange(input)){
            return range->getMapValue(input);
        }
    }
    return input;
}