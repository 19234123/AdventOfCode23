#include <iostream>
#include <vector>
#include <list>
#include "Functions.h"

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    vector<string> roundData;

    for (auto& line: rawInput) {
        auto lineData = splitLineToString(line, ' ');
        string roundDataString;
        for (int i=1; i<lineData.size(); i++){
            roundDataString += lineData[i];
        }
        roundData.push_back(roundDataString);
    }

    long long totalCount = 1;
    long long maxTime = std::stoi(roundData[0]);
    long long maxDistance = std::stoll(roundData[1]);
    long long distanceTravelled;
    long long roundCount = 0;

    for (int secondsHeld=1; secondsHeld<=maxTime/2; secondsHeld++) {
        distanceTravelled = secondsHeld * (maxTime-secondsHeld);
        if (distanceTravelled > maxDistance) {
            roundCount++;
        }
    }

    if (maxTime % 2 != 0){
        totalCount *= 2 * roundCount;
    } else {
        totalCount *= (2 * roundCount) - 1;
    }

    cout << totalCount;
    return 0;
}