#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
private:
    Player* player1;
    Player* player2;
    Player* tie;

public:
    Game(const std::string& player1Name, const std::string& player2Name);
    ~Game();
    void play();
    bool enoughCards(int n) const;
    Player* getWinner() const;
};

#endif // GAME_H
