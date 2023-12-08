#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
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

    // add named nodes to map
    std::map<string, Node> nodeMap;
    std::map<string, Node*> startNodes;
    Node* currentNodePtr;
    for (const auto& line: rawInput) {
        string nodeName = splitLineToString(line, ' ')[0];

        Node currentNode = Node();
        currentNode.name = nodeName;
        nodeMap[nodeName] = currentNode;

        if (nodeName[2] == 'A') {
            currentNodePtr = &nodeMap[nodeName];
            startNodes[nodeName] = currentNodePtr;
        }
    }

    // set up left and right nodes
    for (const auto& line: rawInput) {
        vector<string> lineSplit = splitLineToString(line, ' ');
        string nodeName = lineSplit[0];
        string leftNode = stripCharacters(lineSplit[2], {'(', ','});
        string rightNode = stripCharacters(lineSplit[3], {')'});

        Node& currentNode = nodeMap[nodeName];
        currentNode.left = &nodeMap[leftNode];
        currentNode.right = &nodeMap[rightNode];
    }

    // find end node
    Node* currentNode;
    string currentNodeName;
    vector<long long> pathLengths;
    for (const auto& node: startNodes) {
        currentNode = node.second;
        pathLengths.push_back(pathLength(instructions, currentNode));
    }

    long long steps = lcmOfSet(pathLengths);
    cout << steps;
    return 0;
}