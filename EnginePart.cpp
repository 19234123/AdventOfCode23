#include "EnginePart.h"

std::list<EnginePart> EnginePart::partList;
std::list<std::string> EnginePart::gearCoordinates;

EnginePart::EnginePart(int row, int value, int startCol) {
    this->row = row;
    this->value = value;
    this->startCol = startCol;
    this->endCol = startCol + std::to_string(value).length()-1;

    partList.push_back(*this);
}

void EnginePart::getGearCoordinates(const std::vector<std::string> &grid){
    int numberOfRows = grid.size();
    int numberOfColumns = grid.at(0).size();

    // start col
    if (row != 0){
        if (grid.at(row-1).at(startCol) == '*'){
            gearCoordinates.push_back(std::to_string(row-1) + std::to_string(startCol) + "-" + std::to_string(value));
        }
        if (startCol != 0){
            if (grid.at(row-1).at(startCol-1) == '*') {
                gearCoordinates.push_back(std::to_string(row-1) + std::to_string(startCol-1) + "-" + std::to_string(value));
            }
        }
    }
    if (row != numberOfRows-1){
        if (grid.at(row+1).at(startCol) == '*'){
            gearCoordinates.push_back(std::to_string(row+1) + std::to_string(startCol) + "-" + std::to_string(value));
        }
        if (startCol != 0){
            if (grid.at(row+1).at(startCol-1) == '*'){
                gearCoordinates.push_back(std::to_string(row+1) + std::to_string(startCol-1) + "-" + std::to_string(value));
            }
        }
    }
    if (startCol != 0){
        if (grid.at(row).at(startCol-1) == '*'){
            gearCoordinates.push_back(std::to_string(row) + std::to_string(startCol-1) + "-" + std::to_string(value));
        }
    }

    // middle col
    if (endCol == startCol+2) {
        int middleCol = startCol + 1;
        if (row != 0){
            if (grid.at(row-1).at(middleCol) == '*'){
                gearCoordinates.push_back(std::to_string(row-1) + std::to_string(middleCol) + "-" + std::to_string(value));
            }
        }
        if (row != numberOfRows-1){
            if (grid.at(row+1).at(middleCol) == '*'){
                gearCoordinates.push_back(std::to_string(row+1) + std::to_string(middleCol) + "-" + std::to_string(value));
            }
        }
    }

    // end col
    if (endCol != numberOfColumns-1){
        if (grid.at(row).at(endCol+1) == '*'){
            gearCoordinates.push_back(std::to_string(row) + std::to_string(endCol+1) + "-" + std::to_string(value));
        }
        if (row != 0){
            if (grid.at(row-1).at(endCol+1) == '*'){
                gearCoordinates.push_back(std::to_string(row-1) + std::to_string(endCol+1) + "-" + std::to_string(value));
            }
        }
        if (row != numberOfRows-1){
            if (grid.at(row+1).at(endCol+1) == '*'){
                gearCoordinates.push_back(std::to_string(row+1) + std::to_string(endCol+1) + "-" + std::to_string(value));
            }
        }
    }
    if (row != 0){
        if (grid.at(row-1).at(endCol) == '*'){
            gearCoordinates.push_back(std::to_string(row-1) + std::to_string(endCol) + "-" + std::to_string(value));
        }
    }
    if (row != numberOfRows-1){
        if (grid.at(row+1).at(endCol) == '*'){
            gearCoordinates.push_back(std::to_string(row+1) + std::to_string(endCol) + "-" + std::to_string(value));
        }
    }
}

bool EnginePart::checkIfValid(const std::vector<std::string> &grid) {

    int numberOfRows = grid.size();
    int numberOfColumns = grid.at(0).size();

    std::list<char> gridSquaresToCheck;

    // start col
    if (row != 0){
        gridSquaresToCheck.push_back(grid.at(row-1).at(startCol)); // 1
        if (startCol != 0){
            gridSquaresToCheck.push_back(grid.at(row-1).at(startCol-1)); // 7
        }
    }
    if (row != numberOfRows-1){
        gridSquaresToCheck.push_back(grid.at(row+1).at(startCol)); // 2
        if (startCol != 0){
            gridSquaresToCheck.push_back(grid.at(row+1).at(startCol-1)); // 6
        }
    }
    if (startCol != 0){
        gridSquaresToCheck.push_back(grid.at(row).at(startCol-1)); // 3
    }

    // middle col
    if (endCol == startCol+2) {
        int middleCol = startCol + 1;
        if (row != 0){
            gridSquaresToCheck.push_back(grid.at(row - 1).at(middleCol)); // 1
        }
        if (row != numberOfRows-1){
            gridSquaresToCheck.push_back(grid.at(row + 1).at(middleCol)); // 2
        }
    }

    // end col
    if (endCol != numberOfColumns-1){
        gridSquaresToCheck.push_back(grid.at(row).at(endCol+1)); // 4
        if (row != 0){
            gridSquaresToCheck.push_back(grid.at(row-1).at(endCol+1)); // 8
        }
        if (row != numberOfRows-1){
            gridSquaresToCheck.push_back(grid.at(row+1).at(endCol+1)); // 5
        }
    }
    if (row != 0){
        gridSquaresToCheck.push_back(grid.at(row-1).at(endCol)); // 1
    }
    if (row != numberOfRows-1){
        gridSquaresToCheck.push_back(grid.at(row+1).at(endCol)); // 2
    }



    for (const auto& square: gridSquaresToCheck){
        if (!isdigit(square)){
            if (square != '.'){
                return true;
            }
        }
    }

    return false;
}

