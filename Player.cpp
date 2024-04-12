#include "Player.h"

void Player::addToHand(Card card) {
    hand.push_back(card);
}

void Player::clearHand() {
    hand.clear();
}

int Player::getHandValue() const {
    int value = 0;
    int numAces = 0;
    for (const auto &card : hand) {
        if (card.rank >= TWO && card.rank <= TEN) {
            value += static_cast<int>(card.rank);
        } else if (card.rank >= JACK && card.rank <= KING) {
            value += 10;
        } else if (card.rank == ACE) {
            ++numAces;
            value += 11;
        }
    }
    while (value > 21 && numAces > 0) {
        value -= 10;
        --numAces;
    }
    return value;
}

size_t Player::handSize() const {
    return hand.size();
}

Card& Player::operator[](size_t index) {
    return hand[index];
}
