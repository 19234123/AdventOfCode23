#ifndef ADVENTOFCODE23_SEQUENCEPROCESSOR_H
#define ADVENTOFCODE23_SEQUENCEPROCESSOR_H
#include "Functions.h"
#include <bitset>
#include <cmath>

class SequenceProcessor {
public:
    string sequence {};
    vector<int> groupsInSequence;
    int totalBrokenSprings = 0;
    long arrangements = 0;

    static map<string, long> arrangementMap;

    SequenceProcessor(const string& sequence, const vector<int>& groupsInSequence);
    void calculateArrangements();

};

#endif //ADVENTOFCODE23_SEQUENCEPROCESSOR_H