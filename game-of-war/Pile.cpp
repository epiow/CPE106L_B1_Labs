#include "Pile.h"

int Pile::getSize() const { return cards.size(); }

void Pile::clear() { cards.clear(); }

void Pile::addCard(const Card& c) { cards.push_back(c); }

void Pile::addCards(const Pile& p) { cards.insert(cards.end(), p.cards.begin(), p.cards.end()); }

Card Pile::nextCard() {
    Card c = cards.front();
    cards.erase(cards.begin());
    return c;
}
