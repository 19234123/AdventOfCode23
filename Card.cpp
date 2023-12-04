//
// Created by Steven on 04/12/2023.
//

#include "Card.h"

vector<Card*> Card::allCards;
vector<Card*> Card::cardsToProcess;
int Card::playedCards;

Card::Card(const int &cardNumber, const string &rawNumbers) {
    this->cardNumber = cardNumber;
    setupNumberLists(rawNumbers);
    allCards.push_back(this);
}

void Card::setupNumberLists(const string &rawNumbers) {
    vector<string> rawNumberSplit = splitLineToString(rawNumbers, ':');
    vector<string> gameNumbers = splitLineToString(rawNumberSplit.at(1), '|');
    inputNumbers = splitLineToInt(gameNumbers.at(0), ' ');
    validationNumbers = splitLineToInt(gameNumbers.at(1), ' ');
    validationNumbers = quickSort(validationNumbers);
}

vector<int> Card::splitLineToInt(const string& line, const char& delimiter){
    vector<int> splitString;

    std::stringstream stream(line);

    string currentLine;
    while (stream.good()) {
        std::getline(stream, currentLine, delimiter);
        if (!currentLine.empty()) {
            splitString.push_back(std::stoi(currentLine));
        }
    }

    return splitString;
}

vector<string> Card::splitLineToString(const string& line, const char& delimiter){
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

string Card::trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

vector<int> Card::quickSort(vector<int> numbers) {
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