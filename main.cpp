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

    // Setup round data list
    vector<vector<int>> roundDataList;
    auto dataSize = splitLineToString(rawInput[0], ' ').size();
    for (int i=0; i<dataSize-1; i++) {
        roundDataList.emplace_back();
    }

    for (auto& line: rawInput) {
        auto lineData = splitLineToString(line, ' ');
        for (int i=1; i<lineData.size(); i++){
            roundDataList[i-1].push_back(std::stoi(lineData[i]));
        }
    }

    int totalCount = 1;
    for (const auto& round: roundDataList) {
        int maxTime = round[0];
        int maxDistance = round[1];
        int distanceTravelled;
        int roundCount = 0;

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
    }

    cout << totalCount;
    return 0;
}