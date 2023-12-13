#include "SequenceProcessor.h"

map<string, long> SequenceProcessor::arrangementMap;

SequenceProcessor::SequenceProcessor(const string &sequence, const vector<int>& groupsInSequence) {
    this->sequence = sequence;
    this->groupsInSequence = groupsInSequence;

    for (const auto& i: groupsInSequence) {
        totalBrokenSprings += i;
    }
    calculateArrangements();
}

void SequenceProcessor::calculateArrangements() {
    int unknownSpringCount = 0;

    // Count the number of unknown springs
    for (const auto& c: sequence) {
        if (c == '?') {
            unknownSpringCount++;
        }
    }

    // 2^unknownSpringCount
    int possibilities = 1 << unknownSpringCount;

    // Iterate through all possibilities
    for (int i=0; i<possibilities; i++) {
        string arrangement = sequence;
        // Replace '?' based on the binary representation
        for (int j=0; j<unknownSpringCount; j++) {
            char replacement = ((i >> j) & 1) ? '#' : '.';
            size_t index = arrangement.find('?');
            arrangement[index] = replacement;
        }

        // Check if correct number of springs in arrangement
        int brokenCount = 0;
        for (char c: arrangement) {
            if (c == '#') {
                brokenCount++;
            }
        }

        if (brokenCount != totalBrokenSprings) {
            continue;
        }

        // Check if the arrangement satisfies the damaged groups condition
        bool valid = false;
        size_t currentIndex = arrangement.find('#');

        for (int groupSize: groupsInSequence) {
            if (currentIndex >= arrangement.size()) {
                valid = false;
                continue;
            }

            auto nextSubstring = arrangement.substr(currentIndex, groupSize);
            if (nextSubstring.find_first_not_of('#') != string::npos) {
                valid = false;
                break;
            }

            size_t damagedIndex = nextSubstring.find('#');
            if (damagedIndex != string::npos && nextSubstring.size() == groupSize) {
                bool endIndex = currentIndex > arrangement.size()-groupSize;

                char previousChar = 'X';
                char nextChar = 'X';
                if (currentIndex != 0) {
                    previousChar = arrangement[currentIndex - 1];
                }
                if (!endIndex) {
                    nextChar = arrangement[currentIndex + groupSize];
                }

                if (previousChar != '#' && nextChar != '#') {
                    valid = true;
                } else {
                    valid = false;
                    break;
                }
            } else {
                valid = false;
                break;
            }
            currentIndex = arrangement.find('#', currentIndex + groupSize + 1);
        }

        if (valid) {
            arrangements++;
        }
    }
}