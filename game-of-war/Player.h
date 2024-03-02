#ifndef PLAYER_H
#define PLAYER_H

#include "Pile.h"
#include <string>

class Player {
private:
    std::string name;
    Pile playPile;
    Pile wonPile;

public:
    Player(const std::string& n);
    std::string getName() const;
    Card playCard();
    void collectCard(const Card& c);
    void collectCards(const Pile& p);
    void useWonPile();
    int numCards() const;
};

#endif // PLAYER_H
