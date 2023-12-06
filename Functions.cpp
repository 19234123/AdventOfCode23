#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include "Functions.h"
#include <omp.h>



void setRange(const vector<string>& rangeData, std::map<long long, long long>& map) {
    vector<long long> currentRange;
    for (int i=1; i<rangeData.size(); i++) {
        currentRange = splitLineToLongLong(rangeData[i], ' ');
        long long key   = currentRange[1];
        long long value = currentRange[0];
        long long range = currentRange[2];
        std::cout << currentRange[0] << " " << currentRange[1] << " " << currentRange[2] << std::endl;

        for (long long ii=0; ii<range; ii++) {
            map[key+ii] = value+ii;
        }
        std::cout << currentRange[0] << " " << currentRange[1] << " " << currentRange[2] << std::endl;
    }
}

vector<long long> splitLineToLongLong(const string& line, const char& delimiter) {
    vector<long long> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(std::stoll(trim(currentLine)));
        }
    }

    return splitString;
}

vector<int> splitLineToInt(const string& line, const char& delimiter){
    vector<int> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(std::stoi(trim(currentLine)));
        }
    }

    return splitString;
}

vector<string> splitLineToString(const string& line, const char& delimiter){
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

string strip(const string& input, const std::unordered_set<char>& charsToRemove) {
    string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), [&charsToRemove](char c) {
        return charsToRemove.find(c) != charsToRemove.end();
    }), result.end());
    return result;
}

string trim(const string& input) {
    size_t first = input.find_first_not_of(' ');
    size_t last = input.find_last_not_of(' ');
    return input.substr(first, (last - first + 1));
}


vector<string> readFile(const string& filePath){
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
