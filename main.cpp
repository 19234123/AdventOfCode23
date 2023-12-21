#include "Functions.h"
#include "MirrorLandscape.h"

string filePath = R"(C:\Dev\Text_files\input.txt)";

int main() {
    vector<string> rawInput = readFile(filePath);

    vector<MirrorLandscape*> gridsToProcess;
    vector<string> currentGrid;
    for (const auto& line: rawInput) {
        if (!line.empty()) {
            currentGrid.push_back(line);
        } else {
            gridsToProcess.push_back(new MirrorLandscape(currentGrid));
            currentGrid.clear();
        }
    }


    int total = 0;
    for (auto& x: gridsToProcess) {
        total += x->gridValue;
    }

    cout << total;

 return 0;
}