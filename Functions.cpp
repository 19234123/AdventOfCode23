#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include "Functions.h"

vector<int> getIntegersFromString(string& string) {
    vector<int> integers;
    for (const auto& character: string) {
        if (isdigit(character)) {
            integers.push_back(character);
        }
    }
    return integers;
}

long long greatestCommonMultiple(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lowestCommonMultiple(long long a, long long b) {
    return (a * b) / greatestCommonMultiple(a, b);
}

long long lcmOfSet(const vector<long long>& numbers) {
    long long result = numbers[0];
    for (int i=1; i<numbers.size(); i++) {
        result = lowestCommonMultiple(result, numbers[i]);
    }

    return result;
}

int pathLength(const string& instructions, Node* currentNode) {
    bool endReached = false;

    int length = 0;
    while (!endReached) {
        for (const auto &direction: instructions) {
            length++;
            Node *nextNode;

            if (direction == 'L') {
                nextNode = currentNode->left;
            } else {
                nextNode = currentNode->right;
            }
            if (nextNode->name[2] == 'Z') {
                endReached = true;
                break;
            } else {
                currentNode = nextNode;
            }
        }
    }
    return length;
}

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
            splitString.push_back(std::stoll(trimWhitespace(currentLine)));
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
            splitString.push_back(std::stoi(trimWhitespace(currentLine)));
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
            splitString.push_back(trimWhitespace(currentLine));
        }
    }

    return splitString;
}

string stripCharacters(const string& input, const std::unordered_set<char>& charsToRemove) {
    string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), [&charsToRemove](char c) {
        return charsToRemove.find(c) != charsToRemove.end();
    }), result.end());
    return result;
}

string trimWhitespace(const string& input) {
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

bool binarySearch(const std::vector<long long>& sortedArray, long long target) {
    long long left = 0;
    long long right = sortedArray.size() - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        // Check if target is present at the middle
        if (sortedArray[mid] == target) {
            return true;
        }

            // If target greater, ignore the left half
        else if (sortedArray[mid] < target) {
            left = mid + 1;
        }

            // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If we reach here, then the target was not present
    return false;
}


vector<long long> quickSort(vector<long long> numbers){
    long long listSize = numbers.size();

    vector<long long> currentList;
    if (listSize > 1){
        long long pivotIndex = listSize/2;
        long long pivot = numbers.at(pivotIndex);
        vector<long long> lessThanEqual;
        vector<long long> greaterThan;

        for (long long i=0; i<listSize; i++){
            if (i != pivotIndex) {
                if (numbers.at(i) <= pivot) {
                    lessThanEqual.push_back(numbers.at(i));
                } else {
                    greaterThan.push_back(numbers.at(i));
                }
            }
        }

        lessThanEqual = quickSort(lessThanEqual);
        greaterThan = quickSort(greaterThan);

        currentList.insert(currentList.end(), lessThanEqual.begin(), lessThanEqual.end());
        currentList.push_back(pivot);
        currentList.insert(currentList.end(), greaterThan.begin(), greaterThan.end());
    } else {
        currentList = numbers;
    }
    return currentList;
}
