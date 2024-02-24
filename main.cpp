#include "war.cpp"
int main(){
    Game g;
    Player* winner = g.getWinner();
    cout << endl << "Winner = " << winner->getName() << endl; 
}