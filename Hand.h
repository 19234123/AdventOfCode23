#ifndef ADVENTOFCODE23_HAND_H
#define ADVENTOFCODE23_HAND_H
#include "Functions.h"


class Hand {
private:
    void initialiseCardsAndOccurrences();
    void calculateHandType();
    static int getCardRank(const char& card);
public:
        string handString;
        int bidAmount;
        string handType {};
        std::map<char, int> cardOccurrences {};

        Hand(const string& initialArrangement, int bidAmount);
        static Hand* getWeakestHand(const vector<Hand*>& handList);
};


#endif //ADVENTOFCODE23_HAND_H
