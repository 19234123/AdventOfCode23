#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "EnginePart.h"
#include "Gear.h"
#include <algorithm>
#include <list>
#include "Card.h"

using std::vector;
using std::list;
using std::string;
using std::cout;
using std::endl;


string filePath = R"(C:\Dev\Text_files\input.txt)";
vector<string> readFile();
vector<string> splitLineToString(const string& line, const char& delimiter);
vector<int> splitLineToInt(const string& line, const char& delimiter);
bool binarySearch(const std::vector<int>& sortedArray, int target);
vector<int> quickSort(vector<int> numbers);
string trim(const string& str);
int getMaxIndex(const string& currentCard);


int main() {
    vector<string> rawInput = readFile();


    for (int i=0; i<rawInput.size(); i++) {
        new Card(i+1, rawInput.at(i));
    }

    int maxIndex;
    for (int i=0; i<Card::allCards.size(); i++){
        auto *currentCard = Card::allCards.at(i);

        maxIndex = 0;
        for (const auto& numberToCheck: currentCard->inputNumbers){
            if (binarySearch(currentCard->validationNumbers, numberToCheck)){
                maxIndex++;
            }
        }

        for (int j=i+1; j<=i+maxIndex; j++){
            Card::cardsToProcess.push_back(Card::allCards.at(j));
        }

        Card::playedCards++;
    }

    int index;
    while (!Card::cardsToProcess.empty()) {
        int cardListSize = Card::cardsToProcess.size();
        if (cardListSize % 10000 == 0) {
            cout << cardListSize << endl;
        }
        auto *currentCard = Card::cardsToProcess.at(0);

        maxIndex = 0;
        for (const auto &numberToCheck: currentCard->inputNumbers) {
            if (binarySearch(currentCard->validationNumbers, numberToCheck)) {
                maxIndex++;
            }
        }

        index = currentCard->cardNumber-1;
        for (int j=index+1; j<=index+maxIndex; j++) {
            Card::cardsToProcess.push_back(Card::allCards.at(j));
        }

        Card::cardsToProcess.erase(Card::cardsToProcess.begin());
        Card::playedCards++;
    }



    cout << Card::playedCards;
    return 0;
}

bool binarySearch(const std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

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

vector<int> quickSort(vector<int> numbers){
    int listSize = (int)numbers.size();

    vector<int> currentList;
    if (listSize > 1){
        int pivotIndex = listSize/2;
        int pivot = numbers.at(pivotIndex);
        vector<int> lessThanEqual;
        vector<int> greaterThan;

        for (int i=0; i<listSize; i++){
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