#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "Functions.h"
#include "Hand.h"

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    vector<Hand*> gameHands;
    std::map<string, vector<Hand*>> handMap;
    for (const auto& line: rawInput) {
        vector<string> splitLine = splitLineToString(line, ' ');
        Hand *currentHand = new Hand(splitLine[0], std::stoi(splitLine[1]));
        handMap[currentHand->handType].push_back(currentHand);
        gameHands.push_back(currentHand);
    }

    string handTypes[] = {"High card", "One pair", "Two pair","Three of a kind",
                          "Full house","Four of a kind","Five of a kind"};
    int rank = 1;
    int totalWinnings = 0;
    for (const auto& type: handTypes) {
        vector<Hand*> handsToRank = handMap[type];

        while (!handsToRank.empty()) {
            Hand* weakestHand = Hand::getWeakestHand(handsToRank);
            totalWinnings += (rank * weakestHand->bidAmount);
            rank++;
            handsToRank.erase(std::find(handsToRank.begin(), handsToRank.end(), weakestHand));
        }
    }

    cout << "Total winnings: " << totalWinnings;
    return 0;
}