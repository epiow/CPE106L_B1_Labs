#ifndef PILE_H
#define PILE_H

#include "Card.h"
#include <vector>

class Pile {
private:
    std::vector<Card> cards;

public:
    int getSize() const;
    void clear();
    void addCard(const Card& c);
    void addCards(const Pile& p);
    Card nextCard();
};

#endif // PILE_H
