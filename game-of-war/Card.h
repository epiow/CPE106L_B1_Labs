#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    int rank;
    int suit;

public:
    Card();
    Card(int r, int s);

    int getRank() const;
    int getSuit() const;
    int compareTo(const Card& c) const;
    bool equals(const Card& c) const;
    std::string toString() const;
};

#endif // CARD_H
