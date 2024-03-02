#include "Deck.h"
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck() {
    for (int r = 1; r <= 13; r++) {
        for (int s = 1; s <= 4; s++) {
            cards.emplace_back(r, s);
        }
    }
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::mt19937(std::time(0)));
}

Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

int Deck::getSize() const { return cards.size(); }
