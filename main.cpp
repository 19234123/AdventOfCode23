#include "Functions.h"
#include "Galaxy.h"

string filePath = R"(C:\Dev\Text_files\input2.txt)";


int main() {
    vector<string> rawInput = readFile(filePath);

    // Duplicate columns as needed
    vector<int> columnIndexes;
    for (int column=0; column<rawInput.size(); column++) {
        string currentCol;
        for (auto & line : rawInput) {
            currentCol += line[column];
        }
        if (currentCol.find_first_not_of(currentCol[0]) == string::npos) {
            columnIndexes.push_back(column+columnIndexes.size()); // taking into account inserting at previous index
        }
    }

    for (int i=0; i<rawInput.size(); i++) {
        string& currentRow = rawInput[i];
        for (const auto& index: columnIndexes) {
            currentRow.insert(index, 1, '.');
        }
    }

    // Duplicate rows as needed
    vector<string> gridLines;
    for (const auto& line: rawInput) {
        gridLines.push_back(line);
        if (line.find_first_not_of(line[0]) == string::npos) {
            gridLines.push_back(line);
        }
    }


    for (int row=0; row<gridLines.size(); row++) {
        for (int column=0; column<gridLines[0].size(); column++) {
            if (gridLines[row][column] == '#') {
                // x = col
                // y = row
                new Galaxy(column, row);
            }
        }
    }


    int totalLength = 0;
    for (auto& node1: Galaxy::galaxyList) {
        for (auto& node2: Galaxy::galaxyList) {
            totalLength += node1->distanceBetween(node2);
        }
    }

    cout << totalLength;
    return 0;
}