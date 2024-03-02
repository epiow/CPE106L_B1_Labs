#include "Card.h"
#include <vector>

Card::Card() : rank(0), suit(0) {}

Card::Card(int r, int s) : rank(r), suit(s) {}

int Card::getRank() const { return rank; }

int Card::getSuit() const { return suit; }

int Card::compareTo(const Card& c) const {
    int thisRank = getRank();
    int otherRank = c.getRank();
    if (thisRank == 1) thisRank = 14;
    if (otherRank == 1) otherRank = 14;
    return thisRank - otherRank;
}

bool Card::equals(const Card& c) const {
    return rank == c.getRank() && suit == c.getSuit();
}

std::string Card::toString() const {
    std::string val;
    std::vector<std::string> suitList = {"", "Clubs", "Diamonds", "Hearts", "Spades"};

    switch (rank) {
        case 1: val = "Ace"; break;
        case 11: val = "Jack"; break;
        case 12: val = "Queen"; break;
        case 13: val = "King"; break;
        default: val = std::to_string(rank); break;
    }
    return val + " of " + suitList[suit];
}
