#ifndef ADVENTOFCODE23_CONVERSIONMAP_H
#define ADVENTOFCODE23_CONVERSIONMAP_H
#include <vector>
#include <string>

using std::vector;
using std::string;

class ConversionMap {
private:
    class Range {
    public:
        long long mapValueStart;
        long long minValue;
        long long maxValue;
        int range;

        Range(long long mapValue, long long int minValue, int range);
        long long getMapValue(long long input) const;
        long long valueInRange(long long input) const;
    };

public:
    vector<Range*> mapRanges;

    explicit ConversionMap(vector<string> ranges);
    long long getMapValue(long long input);
};


#endif //ADVENTOFCODE23_CONVERSIONMAP_H
