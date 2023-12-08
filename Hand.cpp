#include "Hand.h"

Hand::Hand(const string &handString, int bidAmount) {
    this->handString = handString;
    this->bidAmount = bidAmount;

    initialiseCardsAndOccurrences();
    calculateHandType();
}

void Hand::initialiseCardsAndOccurrences() {
    for (const auto& card: handString){
        cardOccurrences[card]++;
    }
}

void Hand::calculateHandType() {
    int highestCardCount = 0;
    int secondHighestCardCount = 0;
    int numberOfJokers = 0;

    for (const auto& pair: cardOccurrences) {
        int cardCount = pair.second;

        if (pair.first == 'J') {
            numberOfJokers = cardCount;
        } else if (cardCount >= highestCardCount) {
            secondHighestCardCount = highestCardCount;
            highestCardCount = cardCount;
        } else if (cardCount > secondHighestCardCount && cardCount < highestCardCount) {
            secondHighestCardCount = cardCount;
        }
    }

    highestCardCount += numberOfJokers;
    handType = cardCountToHandType(highestCardCount, secondHighestCardCount);
}


string Hand::cardCountToHandType(int highestCardCount, int secondHighestCardCount) {
    string handType;

    if (highestCardCount == 5) {
        handType = "Five of a kind";
    } else if (highestCardCount == 4) {
        handType = "Four of a kind";
    } else if (highestCardCount == 3) {
        if (secondHighestCardCount == 2){
            handType = "Full house";
        } else {
            handType = "Three of a kind";
        }
    } else if (highestCardCount == 2) {
        if (secondHighestCardCount == 2) {
            handType = "Two pair";
        } else {
            handType = "One pair";
        }
    } else {
        handType = "High card";
    }

    return handType;
}

int Hand::getCardRank(const char &card) {
    std::map<char, int> cardValues = {
            {'J', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
            {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'Q', 11},
            {'K', 12}, {'A', 13}
    };
    return cardValues[card];
}

Hand *Hand::getWeakestHand(const vector<Hand*> &handList) {
    Hand* weakestHand = nullptr;
    for (const auto& hand: handList) {
        if (weakestHand) {
            string handString = hand->handString;
            string weakestString = weakestHand->handString;
            for (int i = 0; i < handString.size(); i++) {
                int handCardValue = getCardRank(handString[i]);
                int weakestCardValue = getCardRank(weakestString[i]);

                if (handCardValue == weakestCardValue) {
                    continue;
                }

                if (handCardValue < weakestCardValue) {
                    weakestHand = hand;
                    break;
                } else {
                    break;
                }
            }
        } else {
            weakestHand = hand;
        }
    }

    return weakestHand;
}