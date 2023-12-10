#include "AoC_Graph.h"
#include "Functions.h"

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    auto graph = new AoC_Graph();


    for (int row=0; row<rawInput.size(); row++) {
        for (int column=0; column<rawInput[0].size(); column++) {
            //if (rawInput[row][column] != '.') {
                string currentSymbol = string{rawInput[row][column]};
                graph->addNode(currentSymbol, column, row);
            //}
        }
    }

    cout << "Nodes added" << endl;

    graph->generateEdges();
    //graph->displayGraphAsString();

    cout << "Edges generated" << endl;


    //graph->displayGraphAsString();

    auto r = graph->getStartingNodes();

    auto* t1 = new AoC_Graph::PathTraveller();
    //auto* t2 = new AoC_Graph::PathTraveller();

    t1->setStartNode(r[0]);
    //t2->setStartNode(r[0]);

//    t1->nextNode = r[1];
//    t2->nextNode = r[2];

    bool found = false;
    while (!t1->endFound) {
        t1->moveToNextNode();
        //t2->moveToNextNode();
        auto d = t1->currentNode->id;
        //auto s = t2->currentNode->id;
        //found = (t1->nextNode == t2->nextNode);
    }

    cout << "T1 Location: " << t1->currentNode->asciiStateString << " Steps: " << t1->visitedNodes.size()/2 << endl;
    cout << "Steps++: " << t1->steps << endl;
    //cout << "T2 Steps taken: " << t2->currentNode->asciiStateString << " Steps: " << t2->visitedNodes.size() << endl;

//    cout << "Nodes: " << graph->getNodeNames().size() << endl;
//    while (!nodes.empty()) {
//        auto node = nodes.front();
//        auto results = graph->dijkstraPath("S", node);
//        if (results.size() > maxLength) {
//            maxLength = results.size();
//            cout << "Current max length: " << maxLength << endl;
//        }
//
//        if (count % 10 == 0) {
//            cout << count << ", " << maxLength << endl;
//        }
//
//        count++;
//    }
    return 0;
}