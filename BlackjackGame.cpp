#include "BlackjackGame.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

void BlackjackGame::play() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        system(CLEAR_SCREEN);
        player.clearHand();
        dealer.clearHand();
        dealInitialCards();
        displayHands(true);

        // Using threads for player turn and dealer turn
        std::thread playerThread(&BlackjackGame::handlePlayerTurn, this);
        std::thread dealerThread(&BlackjackGame::handleDealerTurn, this);

        playerThread.join(); // Wait for player turn to finish
        dealerThread.join(); // Wait for dealer turn to finish

        displayHands(false);
        displayResult();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }
}

void BlackjackGame::dealInitialCards() {
    player.addToHand(deck.drawCard());
    dealer.addToHand(deck.drawCard());
    player.addToHand(deck.drawCard());
    dealer.addToHand(deck.drawCard());
}

void BlackjackGame::displayHands(bool showDealerCard) {
    std::cout << "Player's hand: ";
    for (size_t i = 0; i < player.handSize(); ++i) {
        displayCard(player[i]);
    }
    std::cout << " (" << player.getHandValue() << ")\n";
    std::cout << "Dealer's hand: ";
    if (showDealerCard) {
        displayCard(dealer[0]);
        std::cout << " ";
    } else {
        for (size_t i = 0; i < dealer.handSize(); ++i) {
            displayCard(dealer[i]);
        }
        std::cout << " (" << dealer.getHandValue() << ")\n";
    }
}

void BlackjackGame::displayCard(const Card &card) {
    switch (card.rank) {
        case ACE:
            std::cout << "Ace";
            break;
        case TWO:
            std::cout << "2";
            break;
        case THREE:
            std::cout << "3";
            break;
        case FOUR:
            std::cout << "4";
            break;
        case FIVE:
            std::cout << "5";
            break;
        case SIX:
            std::cout << "6";
            break;
        case SEVEN:
            std::cout << "7";
            break;
        case EIGHT:
            std::cout << "8";
            break;
        case NINE:
            std::cout << "9";
            break;
        case TEN:
            std::cout << "10";
            break;
        case JACK:
            std::cout << "Jack";
            break;
        case QUEEN:
            std::cout << "Queen";
            break;
        case KING:
            std::cout << "King";
            break;
    }
    switch (card.suit) {
        case CLUBS:
            std::cout << " Clubs ";
            break;
        case DIAMONDS:
            std::cout << " Diamonds ";
            break;
        case HEARTS:
            std::cout << " Hearts ";
            break;
        case SPADES:
            std::cout << " Spades ";
            break;
    }
}

bool BlackjackGame::playerBusted() {
    return player.getHandValue() > 21;
}

void BlackjackGame::handlePlayerTurn() {
    char choice;
    for (size_t i = 0; i < player.handSize() - 1; ++i) {
        if (player[i].rank == player[i + 1].rank) {
            std::cout << "Split or Stand? (p/s): ";
            std::cin >> choice;
            if (choice == 'p' || choice == 'P') {
                player.addToHand(deck.drawCard());
                player.addToHand(deck.drawCard());
                displayHands(true);
                handlePlayerTurn();
            }
        }
    }
    if (!playerBusted()) {
        std::cout << "Hit or Stand? (h/s): ";
        std::cin >> choice;
        while (choice == 'h' || choice == 'H') {
            player.addToHand(deck.drawCard());
            displayHands(true);
            if (playerBusted()) {
                std::cout << "Busted! You lose.\n";
                break;
            }
            std::cout << "Hit or Stand? (h/s): ";
            std::cin >> choice;
        }
    }
}

void BlackjackGame::handleDealerTurn() {
    std::lock_guard<std::mutex> lock(m); // Locking to ensure safe access to dealer's hand
    while (dealer.getHandValue() < 17) {
        dealer.addToHand(deck.drawCard());
    }
}

void BlackjackGame::displayResult() {
    int playerValue = player.getHandValue();
    int dealerValue = dealer.getHandValue();
    if (playerBusted()) {
        std::cout << "Player busts! Dealer wins.\n";
    } else if (dealerValue > 21 || playerValue > dealerValue) {
        std::cout << "Player wins!\n";
    } else if (dealerValue > playerValue) {
        std::cout << "Dealer wins.\n";
    } else {
        std::cout << "It's a tie!\n";
    }
}
