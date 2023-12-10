#include "AoC_Graph.h"

void AoC_Graph::PathTraveller::moveToNextNode() {
    for (const auto& pair: currentNode->neighbours) {
        nextNode = pair.first;
        if (nextNode->asciiStateString == "S") {
            visitedNodes.push_back(currentNode->id);
            endFound = true;
            steps++;
            return;
        }
        auto it = std::find(visitedNodes.begin(), visitedNodes.end(), nextNode->id);
        if (it == visitedNodes.end()) {
            visitedNodes.push_back(currentNode->id);
            currentNode = nextNode;
            steps++;
            break;
        } else if (it == visitedNodes.begin()) {
            visitedNodes.push_back(nextNode->id);
            endFound = true;
        }
    }
}

void AoC_Graph::PathTraveller::setStartNode(Node* node) {
    this->currentNode = node;

}


void AoC_Graph::generateEdges() {
    for (auto &node: nodeList) {
        if (node->asciiStateString == ".") {
            continue;
        }
        for (auto &otherNode: nodeList) {
            if (otherNode->asciiStateString == ".") {
                continue;
            }
            int currentX = node->x;
            int currentY = node->y;
            int otherX = otherNode->x;
            int otherY = otherNode->y;

            vector<string> otherValidSymbols;
            vector<string> currentValidSymbols;
            // North neighbour
            if ((currentX == otherX) && (currentY-1 == otherY)) {
                otherValidSymbols = {"S", "|", "7", "F"};
                currentValidSymbols = {"S", "|", "L", "J"};
            // South neighbour
            } else if ((currentX == otherX) && (currentY+1 == otherY)) {
                otherValidSymbols = {"S", "|", "L", "J"};
                currentValidSymbols = {"S", "|", "7", "F"};
            // East neighbour
            } else if ((currentY == otherY) && (currentX+1 == otherX)) {
                otherValidSymbols = {"S", "-", "J", "7"};
                currentValidSymbols = {"S", "-", "L", "F"};
            // West neighbour
            } else if ((currentY == otherY) && (currentX-1 == otherX)) {
                otherValidSymbols = {"S", "-", "L", "F"};
                currentValidSymbols = {"S", "-", "J", "7"};
            }

            if (!otherValidSymbols.empty()) {
                if (validNeighbour(otherValidSymbols, otherNode)) {
                    if (validNeighbour(currentValidSymbols, node)) {
                        addEdge(node, otherNode);
                    }
                }
            }
        }
    }
}

bool AoC_Graph::validNeighbour(const vector<string>& symbols, Node* node2) {
    for (const auto &symbol: symbols) {
        if (node2->asciiStateString == symbol) {
            return true;
        }
    }
    return false;
}

void AoC_Graph::displayGraphAsString() {
    for (const auto& node: nodeList) {
        if (node->asciiStateString != ".") {
            cout << node->asciiStateString << " (" << node->x << "," << node->y << ")" << endl;
            cout << "Neighbours: ";
            for (const auto &pair: node->neighbours) {
                cout << pair.first->asciiStateString + ", ";
            }
            cout << endl << endl;
        }
    }
    cout << endl;
}

vector<string> AoC_Graph::getNodeNames() {
    vector<string> nodes;
    for (const auto& node: nodeList) {
        if (node->asciiStateString != ".") {
            nodes.push_back(node->asciiStateString);
        }
    }
    return nodes;
}

vector<Graph::Node*> AoC_Graph::getStartingNodes() {
    vector<Node*> nodes;
    for (auto& node: nodeList) {
        if (node->asciiStateString == "S") {
            nodes.push_back(node);
            for (auto& neighbour: node->neighbours) {
                nodes.push_back(neighbour.first);
            }
        }

    }
    return nodes;
}


