#include "Game.h"
#include <iostream>
#include <fstream>
#ifdef _WIN32
#include <conio.h>
#else
#include <iostream>
#include <cstdlib>
#endif

using namespace std;

// Function to wait for keypress before ending the program
void waitForKeypress() {
    cout << "Press any key to continue...";
#ifdef _WIN32
    _getch();
#else
    system("read -n1 -r -p \"Press any key to continue...\" key");
#endif
    cout << endl;
}

int main() {
    // file handling
    ifstream playersFile("players.txt");
    string p1Name, p2Name;

    if (playersFile.is_open()) {
        getline(playersFile, p1Name);
        getline(playersFile, p2Name);
        playersFile.close();

        // initialization of game
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

    cout << endl << "Press any key to continue...";
    waitForKeypress(); //wait for keypress before ending

    return 0;
}
