#include "Player.h"

Player::Player(const std::string& n) : name(n) {}

std::string Player::getName() const { return name; }

Card Player::playCard() {
    if (playPile.getSize() == 0) {
        useWonPile();
    }
    if (playPile.getSize() > 0) return playPile.nextCard();
    return Card(0, 0); // dummy card if playPile is empty
}

void Player::collectCard(const Card& c) { wonPile.addCard(c); }

void Player::collectCards(const Pile& p) { wonPile.addCards(p); }

void Player::useWonPile() {
    playPile.clear();
    playPile.addCards(wonPile);
    wonPile.clear();
}

int Player::numCards() const { return playPile.getSize() + wonPile.getSize(); }
