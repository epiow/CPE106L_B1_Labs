#include "Game.h"
#include "Deck.h"
#include <iostream>
#include <algorithm>

Game::Game(const std::string& player1Name, const std::string& player2Name) {
    player1 = new Player(player1Name);
    player2 = new Player(player2Name);
    tie = new Player("It's a tie!");
}

Game::~Game() {
    delete player1;
    delete player2;
    delete tie;
}

void Game::play() {
    Deck deck;
    deck.shuffle();

    while (deck.getSize() >= 2) {
        player1->collectCard(deck.dealCard());
        player2->collectCard(deck.dealCard());
    }

    player1->useWonPile();
    player2->useWonPile();

    Pile down;

    for (int t = 1; t <= 100; t++) {
        if (!enoughCards(1)) break;

        Card c1 = player1->playCard();
        Card c2 = player2->playCard();

        std::cout << std::endl << "Turn " << t << ": " << std::endl;
        std::cout << player1->getName() << ": " << c1.toString() << " ";
        std::cout << player2->getName() << ": " << c2.toString() << " ";

        if (c1.compareTo(c2) > 0) {
            player1->collectCard(c1);
            player1->collectCard(c2);
        } else if (c1.compareTo(c2) < 0) {
            player2->collectCard(c1);
            player2->collectCard(c2);
        } else {
            // War logic
        }
    }
}

bool Game::enoughCards(int n) const {
    return player1->numCards() >= n && player2->numCards() >= n;
}

Player* Game::getWinner() const {
    if (player1->numCards() > player2->numCards()) return player1;
    else if (player2->numCards() > player1->numCards()) return player2;
    return tie;
}
