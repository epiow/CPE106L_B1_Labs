#include "war.cpp"
int main(){
    Game g;
    g.play();
    Player* winner = g.getWinner();
    cout << endl << "Winner = " << winner->getName() << endl; 
}