#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "EnginePart.h"

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
    for (auto& part: EnginePart::partList){
        if (part.checkIfValid(rawInput)){
            valueSum += part.value;
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