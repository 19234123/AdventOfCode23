#include "Functions.h"
#include "Galaxy.h"

string filePath = R"(C:\Dev\Text_files\input.txt)";
int expansionFactor = 999999;


void createNodes(const vector<string>& rawInput);

int main() {
    createNodes(readFile(filePath));

    long long totalLength = 0;
    for (auto& node1: Galaxy::galaxyList) {
        for (auto& node2: Galaxy::galaxyList) {
            totalLength += node1->distanceBetween(node2);
        }
    }
    cout << totalLength;
    return 0;
}

void createNodes(const vector<string>& rawInput) {
    vector<long long> columnIndexes;
    for (int column=0; column<rawInput[0].size(); column++) {
        string currentCol;
        for (auto & line : rawInput) {
            currentCol += line[column];
        }
        if (currentCol.find_first_not_of(currentCol[0]) == string::npos) {
            columnIndexes.push_back(column);
        }
    }

    vector<int> rowIndexes;
    for (int i=0; i<rawInput.size(); i++) {
        string currentLine = rawInput[i];
        if (currentLine.find_first_not_of(currentLine[0]) == string::npos) {
            rowIndexes.push_back(i);
        }
    }

    for (int row=0; row<rawInput.size(); row++) {
        for (int column=0; column<rawInput[0].size(); column++) {
            if (rawInput[row][column] != '.') {
                // x = col
                // y = row
                int rowMultiplier = 0;
                int columnMultiplier = 0;
                for (const auto& rowIndex: rowIndexes) {
                    if (row>rowIndex) {
                        rowMultiplier++;
                    }
                }
                for (const auto& columnIndex: columnIndexes) {
                    if (column>columnIndex) {
                        columnMultiplier++;
                    }
                }
                int galaxyColumn = column + (expansionFactor * columnMultiplier);
                int galaxyRow = row + (expansionFactor * rowMultiplier);
                new Galaxy(galaxyColumn, galaxyRow);
            }
        }
    }
}