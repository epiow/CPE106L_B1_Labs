#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // File handling
    ifstream playersFile("players.txt");
    string p1Name, p2Name;

    if (playersFile.is_open()) {
        getline(playersFile, p1Name);
        getline(playersFile, p2Name);
        playersFile.close();

        // Initialization of game
        Game g(p1Name, p2Name);
        g.play();
        Player* winner = g.getWinner();
        cout << endl;
        cout << "Winner: " << winner->getName() << endl;
    } else {
        cerr << "Cannot open File" << endl;
    }

    cout << endl << "Follow me on Instagram -> @abads_ok" << endl;
    cout << "Me too @episangilannn" << endl;
    return 0;
}
