#ifndef ADVENTOFCODE23_CARD_H
#define ADVENTOFCODE23_CARD_H

#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class Card {
public:
    int cardNumber;
    vector<int> inputNumbers;
    vector<int> validationNumbers;
    static vector<Card*> allCards;
    static vector<Card*> cardsToProcess;
    static int playedCards;

    Card(const int& cardNumber, const string& rawNumbers);
    void setupNumberLists(const string& rawNumbers);
    static vector<int> splitLineToInt(const string& line, const char& delimiter);
    static vector<string> splitLineToString(const string& line, const char& delimiter);
    static string trim(const string& str);
    static vector<int> quickSort(vector<int> numbers);
};


#endif //ADVENTOFCODE23_CARD_H
