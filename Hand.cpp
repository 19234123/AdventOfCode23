#include "Hand.h"
#include <algorithm>


Hand::Hand(const string &initialArrangement, int bidAmount) {
    this->handString = initialArrangement;
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

    for (const auto& pair: cardOccurrences) {
        int cardCount = pair.second;

        if (cardCount >= highestCardCount) {
            secondHighestCardCount = highestCardCount;
            highestCardCount = cardCount;
        } else if (cardCount > secondHighestCardCount && cardCount < highestCardCount) {
            secondHighestCardCount = cardCount;
        }
    }

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
}

int Hand::getCardRank(const char &card) {
    std::map<char, int> cardValues = {
            {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6},
            {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11},
            {'Q', 12}, {'K', 13}, {'A', 14}
    };
    return cardValues[card];
}

Hand *Hand::getWeakestHand(const vector<Hand*> &handList) {
    Hand* weakestHand = nullptr;
    for (const auto& hand: handList) {
        if (weakestHand) {
            string handString = hand->handString;
            string weakestString = weakestHand->handString;
            if (handString == "77772" || handString == "44454" || weakestString == "77772" || weakestString == "44454"){
                string z;
            }
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