#ifndef CARDGAME_H
#define CARDGAME_H

#include <iostream>
#include <vector>

enum Rank {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum Suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};

class Card {
public:
    Rank rank;
    Suit suit;
};

class CardGame {
public:
    virtual void play() = 0;
    virtual void dealInitialCards() = 0;
    virtual void displayHands(bool showDealerCard) = 0;
    virtual void displayCard(const Card &card) = 0;
    virtual bool playerBusted() = 0;
    virtual void handlePlayerTurn() = 0;
    virtual void handleDealerTurn() = 0;
    virtual void displayResult() = 0;
    virtual ~CardGame() {} // virtual destructor for base class
};

#endif // CARDGAME_H

