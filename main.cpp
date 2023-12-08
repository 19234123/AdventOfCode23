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

    string instructions = rawInput[0];
    rawInput.erase(rawInput.begin(), rawInput.begin()+2);

    std::map<string, Node> nodeList;

    for (const auto& line: rawInput) {
        vector<string> lineSplit = splitLineToString(line, ' ');
        string nodeName = lineSplit[0];
        string left = stripCharacters(lineSplit[2], {'(', ','});
        string right = stripCharacters(lineSplit[3], {')'});


        string x;
    }

    return 0;
}