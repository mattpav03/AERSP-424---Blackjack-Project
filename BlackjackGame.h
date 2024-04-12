#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "CardGame.h"
#include "Deck.h"
#include "Player.h"
#include <mutex>

class BlackjackGame : public CardGame {
private:
    Deck deck;
    Player player;
    Player dealer;
    std::mutex m; // Mutex for thread safety

public:
    void play() override;
    void dealInitialCards() override;
    void displayHands(bool showDealerCard) override;
    void displayCard(const Card &card) override;
    bool playerBusted() override;
    void handlePlayerTurn() override;
    void handleDealerTurn() override;
    void displayResult() override;
};

#endif // BLACKJACKGAME_H
