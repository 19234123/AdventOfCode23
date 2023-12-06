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
        [[nodiscard]] long long getMapValue(long long input) const;
        [[nodiscard]] long long valueInRange(long long input) const;
        [[nodiscard]] long long getReverseMapValue(long long input) const;
        [[nodiscard]] long long keyInRange(long long int input) const;
    };

public:
    vector<Range*> mapRanges;

    explicit ConversionMap(vector<string> ranges);
    long long getMapValue(long long input);
    long long getReverseMapValue(long long int input);
};


#endif //ADVENTOFCODE23_CONVERSIONMAP_H
