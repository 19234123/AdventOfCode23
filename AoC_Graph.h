#ifndef ADVENTOFCODE23_AOC_GRAPH_H
#define ADVENTOFCODE23_AOC_GRAPH_H
#include "Graph.h"


class AoC_Graph : public Graph {
public:
    class PathTraveller {
    public:
        vector<int> visitedNodes {};
        Node* currentNode = nullptr;
        Node* nextNode = nullptr;
        bool endFound;
        int steps;

        void setStartNode(Node* node);
        void moveToNextNode();

    };
    vector<vector<Node>> nodeGrid {};

    vector<Node*> getStartingNodes();
    void generateEdges();
    static bool validNeighbour(const vector<string>& symbols, Node* node2);
    void displayGraphAsString() override;
    vector<string> getNodeNames();

};


#endif //ADVENTOFCODE23_AOC_GRAPH_H
