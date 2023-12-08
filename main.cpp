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

    // add named nodes to map
    std::map<string, Node> nodeMap;
    for (const auto& line: rawInput) {
        string nodeName = splitLineToString(line, ' ')[0];

        Node currentNode = Node();
        currentNode.name = nodeName;

        nodeMap[nodeName] = currentNode;
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
    bool found;
    int steps = 0;
    Node* currentNode = &nodeMap["AAA"];
    string currentNodeName;
    while (!found) {
        for (auto const& direction: instructions) {
            steps++;
            currentNodeName = currentNode->name;
            currentNode = &nodeMap[currentNodeName];
            Node* nextNode;

            if (direction == 'L') {
                nextNode = currentNode->left;
            } else {
                nextNode = currentNode->right;
            }

            if (nextNode->name == "ZZZ") {
                found = true;
                break;
            } else {
                currentNode = nextNode;
            }
        }
    }

    cout << steps;
    return 0;
}