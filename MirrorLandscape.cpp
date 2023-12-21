#include "MirrorLandscape.h"

MirrorLandscape::MirrorLandscape(vector<string> &grid) {
    this->gridRows = grid;

    generateColumns();
    calculateGridValue();
}

void MirrorLandscape::generateColumns() {
    for (int column = 0; column<gridRows[0].size(); column++) {
        string currentRow;
        for (auto & row: gridRows) {
            currentRow += row[column];
        }
        gridColumns.push_back(currentRow);
    }
}

void MirrorLandscape::processList(const vector<string> &list, bool rows) {
    bool mirrorFound = false;
    for (int listIndex = 0; listIndex<list.size() - 1; listIndex++) {
        string currentRow = list[listIndex];
        string nextRow = list[listIndex + 1];

        if (mirrorFound) {
            break;
        }

        if (currentRow == nextRow) {
            if (rows) {
                rowMatches++;
                rowMirrorIndex = listIndex + 1;
            } else {
                columnMirrorIndex = listIndex + 1;
                columnMatches++;
            }

            int firstIndex = listIndex - 1;
            for (int secondIndex = listIndex + 2; secondIndex<list.size(); secondIndex++) {

                if (firstIndex<0) {
                    break;
                } else {
                    currentRow = list[firstIndex];
                    nextRow = list[secondIndex];

                    if (currentRow == nextRow) {
                        if (rows) {
                            rowMatches++;
                            mirrorFound = true;
                        } else {
                            columnMatches++;
                            mirrorFound = true;
                        }
                        firstIndex--;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

void MirrorLandscape::calculateGridValue() {
    processList(gridRows, true);
    processList(gridColumns, false);

    if (columnMatches != 0 || rowMatches != 0) {
        if (rowMatches > columnMatches) {
            gridValue = rowMirrorIndex * 100;
        } else if (columnMatches > rowMatches) {
            gridValue = columnMirrorIndex;
        } else {
            cout << "AAA" << endl;
            if (rowMirrorIndex > columnMirrorIndex) {
                gridValue = rowMirrorIndex * 100;
            } else {
                gridValue = columnMirrorIndex;
            }
            cout << "BBB" << endl;
        }
    } else {
        if (columnMirrorIndex != -1 || rowMirrorIndex != -1) {
            if (rowMirrorIndex > columnMirrorIndex) {
                gridValue = rowMirrorIndex * 100;
            } else {
                gridValue = columnMirrorIndex;
            }

//            if (columnMirrorIndex != -1 && rowMirrorIndex != -1) {
//                gridValue = rowMirrorIndex * 100;
//            } else if (rowMirrorIndex != -1) {
//                gridValue = rowMirrorIndex * 100;
//            } else {
//                gridValue = columnMirrorIndex;
//            }
        }
        cout << "CCC" << endl;
    }
}





//void MirrorLandscape::calculateGridValue() {
//    // Check rows
//    for (int i=0; i<gridRows.size() - 1; i++) {
//        string currentRow = gridRows[i];
//        string nextRow = gridRows[i + 1];
//
//        if (currentRow == nextRow) {
//            gridValue = (i + 1) * 100;
//        }
//    }
//
//    // Check columns
//    if (gridValue == 0) {
//        vector<long long> columnIndexes;
//        for (int column = 0; column<gridRows[0].size() - 1; column++) {
//            string currentColumn, nextColumn;
//            for (int row = 0; row<gridRows.size(); row++) {
//                currentColumn += gridRows[row][column];
//                nextColumn += gridRows[row][column + 1];;
//
//                if (currentColumn == nextColumn) {
//                    gridValue = row + 1;
//                }
//            }
//        }
//    }
//}