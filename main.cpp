#include <iostream>
#include <vector>
#include <list>
#include "Functions.h"
#include "Hand.h"

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input2.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    vector<Hand*> gameHands;
    for (const auto& line: rawInput) {
        vector<string> splitLine = splitLineToString(line, ' ');
        gameHands.push_back(new Hand(splitLine[0], std::stoi(splitLine[1])));

    }


    return 0;
}