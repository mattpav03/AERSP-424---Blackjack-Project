#ifndef PLAYER_H
#define PLAYER_H

#include "CardGame.h"

class Player {
protected:
    std::vector<Card> hand;

public:
    void addToHand(Card card);
    void clearHand();
    int getHandValue() const;
    size_t handSize() const;
    Card& operator[](size_t index);
};

#endif // PLAYER_H
