#include "Hand.h"
#include <algorithm>


Hand::Hand(const string &initialArrangement, int bidAmount) {
    this->initialArrangement = initialArrangement;
    this->bidAmount = bidAmount;
    this->sortedHand = initialArrangement;
    std::sort(sortedHand.begin(), sortedHand.end());

    initialiseCardsAndOccurrences();
    processHighestValueArrangement();
    calculateHandValue();

}

void Hand::initialiseCardsAndOccurrences() {
    for (const auto& card: initialArrangement){
        cardOccurrences[card]++;
    }
}

void Hand::processHighestValueArrangement() {
    int highestCardCount = 0;
    int secondHighestCardCount = 0;

    for (const auto& pair: cardOccurrences) {
        int cardCount = pair.second;

        if (cardCount > highestCardCount) {
            secondHighestCardCount = highestCardCount;
            highestCardCount = cardCount;
        } else if (cardCount > secondHighestCardCount && cardCount < highestCardCount) {
            secondHighestCardCount = cardCount;
        }
    }

    if (std::unordered_set<char>(initialArrangement.begin(), initialArrangement.end()).size() == 1) {
        highestValueArrangement = initialArrangement;
        setHandType("Five of a kind");
    } else {

    }



}

void Hand::calculateHandValue() {

}

void Hand::setHandType(const string& handType) {


}

int Hand::getCardValue(const char &card) {
    std::map<char, int> cardValues = {
            {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
            {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 10},
            {'Q', 10}, {'K', 10}, {'A', 11}
    };
    return cardValues[card];
}

