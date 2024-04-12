#ifndef DECK_H
#define DECK_H

#include "CardGame.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card drawCard();
};

#endif // DECK_H
