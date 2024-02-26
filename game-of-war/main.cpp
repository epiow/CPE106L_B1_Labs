#include "war.cpp"
using namespace std;
int main() {
  
    //file handling
    ifstream playersFile("players.txt"); 
    string p1Name, p2Name;

    if (playersFile.is_open()) {

        getline(playersFile, p1Name);
        getline(playersFile, p2Name);
        playersFile.close();

        //initialization of game
        Game g(p1Name, p2Name);
        g.play();
        Player* winner = g.getWinner();
        cout << endl;
        cout << "Winner: " << winner->getName() << endl;
    } else {
        cerr << "Cannot open File" << endl;
    }

    return 0;
}
