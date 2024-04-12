#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

Deck::Deck() {
    for (int suit = CLUBS; suit <= SPADES; ++suit) {
        for (int rank = ACE; rank <= KING; ++rank) {
            cards.push_back({static_cast<Rank>(rank), static_cast<Suit>(suit)});
        }
    }
    shuffle();
}

void Deck::shuffle() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::random_device()()));
}

Card Deck::drawCard() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}
