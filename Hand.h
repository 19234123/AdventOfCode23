#ifndef ADVENTOFCODE23_HAND_H
#define ADVENTOFCODE23_HAND_H
#include "Functions.h"


class Hand {
private:
    void initialiseCardsAndOccurrences();
    void processHighestValueArrangement();
    void calculateHandValue();
    void setHandType(const string& handType);
    static int getCardValue(const char& card);
public:
        string initialArrangement;
        string sortedHand;
        int bidAmount;
        string handType {};
        string highestValueArrangement {};
        std::map<char, int> cardOccurrences {};
        int handValue = 0;

        Hand(const string& initialArrangement, int bidAmount);
};


#endif //ADVENTOFCODE23_HAND_H
