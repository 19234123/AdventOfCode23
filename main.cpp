#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "EnginePart.h"
#include "Gear.h"
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;

string filePath = R"(C:\Dev\Text_files\input.txt)";
vector<string> readFile();
vector<string> splitLine(const string& line, const char& delimiter);
string trim(const string& str);


int main() {
    vector<string> rawInput = readFile();

    // Create part list
    int row = 0;
    for (const auto& line: rawInput) {
        string value;
        for (int col=0; col<=line.length(); col++){
            char currentChar = line[col];

            if (col != line.length()) {
                if (isdigit(currentChar)) {
                    value += currentChar;
                } else {
                    if (!value.empty()) {
                        int startCol = col - value.length();
                        new EnginePart(row, std::stoi(value), startCol);
                        value.clear();
                    }
                }
            } else {
                if (!value.empty()) {
                    int startCol = col - value.length();
                    new EnginePart(row, std::stoi(value), startCol);
                    value.clear();
                }
            }
        }
        row++;
    }

    // add valid part values to list
    int valueSum = 0;
    for (auto& part: EnginePart::partList) {
        part.getGearCoordinates(rawInput);
    }

    std::list<string> gearList;
    int currentGearNeighbour;
    for (const auto& currentGear: EnginePart::gearCoordinates) {
        vector<string> gearDataSplit = splitLine(currentGear, '-');
        string currentGearId = gearDataSplit[0];
        currentGearNeighbour = std::stoi(gearDataSplit[1]);
        Gear *currentGearObj = new Gear(std::stoi(currentGearId));

        if (std::find(gearList.begin(), gearList.end(), currentGearId) == gearList.end()){
            gearList.push_back(currentGearId);
            currentGearObj->neighbours.push_back(currentGearNeighbour);
        } else {
            for (const auto& gear: Gear::gearList){
                if (gear->id == std::stoi(currentGearId)){
                    if (std::find(gear->neighbours.begin(), gear->neighbours.end(), currentGearNeighbour) == gear->neighbours.end()) {
                        gear->neighbours.push_back(currentGearNeighbour);
                    }

                }
            }
        }
    }

    for (auto& gear: Gear::gearList){
        if (gear->neighbours.size() == 2){
            int currentSum = 1;
            for (const auto& neighbour: gear->neighbours){
                currentSum *= neighbour;
            }
            valueSum += currentSum;
        }
    }

    cout << valueSum;
    return 0;
}

vector<string> splitLine(const string& line, const char& delimiter){
    vector<string> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(trim(currentLine));
        }
    }

    return splitString;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}


vector<string> readFile(){
    vector<string> rawInput;

    std::ifstream file(filePath);

    if (file.is_open()) {
        string line;
        while(std::getline(file, line)) {
            rawInput.push_back(line);
        }
    } else {
        std::cout << "Unable to open file";
    }
    return rawInput;
}