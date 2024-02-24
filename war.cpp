#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
class Card{
    private:
        int rank;
        int suit;
    public:
        Card(){
            rank = 0;
            suit = 0;
        }

        Card(int r, int s){
            rank = r;
            suit = s;
        }

        int getRank(){
            return rank;
        }

        int getSuit(){
            return suit;
        }

        int compareTo(Card& c){
            int thisRank = getRank();
            int otherRank = c.getRank();
            if(thisRank == 1) thisRank = 14;
            if(otherRank == 1) otherRank = 14;
            return thisRank - otherRank;
        }

        bool equals(Card c){
            Card other = c;
            return other.rank == c.rank && other.suit == c.suit;
        }
        string toString(){
            string val;
            vector<string> suitList {"", "Clubs", "Diamonds", "Hearts", "Spades"};
            switch(rank){
                case 1:{
                    val = "Ace";
                    break;
                }
                case 11:{
                    val = "Jack";
                    break;
                }
                case 12:{
                    val = "Queen";
                    break;
                }
                case 13:{
                    val = "King";
                    break;
                }
                default:{
                    val = to_string(rank);
                    break;
                }
            }
            string s = val + " of " + suitList[suit];
            for(int k = s.length() + 1; k <= 17; k++) s = s + " ";
            return s;
    }
};

class CardDeck{
    Card *deck;
    int numCards;

    public:
    CardDeck(){
        deck = new Card[52];
        fill();
    }
    void shuffle(){
        for(int next = 0; next != numCards - 1; next++){
            int r = myRandom(next, numCards - 1);
            Card temp = deck[next];
            deck[next] = deck[r];
            deck[r] = temp;
        }
    }

    Card deal(){
        numCards--;
        return deck[numCards];
    }
    int getSize(){
        return numCards;
    }
    void fill(){
        int index = 0;
        for(int r = 1; r <= 13; r++){
            for(int s = 1; s <= 4; s++){
                deck[index] = Card(r,s);
                index++;
            }
        }
        numCards = 52;
    }
    static int myRandom(int low, int high){
        return (int)((high + 1 - low)* rand() + low);
    }
    friend ostream operator<<(ostream& os, const Card& c);
};
class Pile{
    Card pile[52];
    int front;
    int end;
    public:
    Pile(){
        front = 0;
        end = 0;
    }
    int getSize(){
        return end - front;
    }
    void clear(){
        front = 0;
        end = 0;
    }
    void addCard(Card c){
        pile[end] = c;
        end++;
    }
    void addCards(Pile p){
        while(p.getSize() > 0) addCard(p.nextCard());
    }
    Card nextCard(){
        Card c = pile[front];
        front++;
        return c;
    }
};

class Player{
    public:
    string name;
    Pile playPile;
    Pile wonPile;
    public:
    Player(string n){
        name = n;
    }
    Card playCard(){
        if(playPile.getSize() == 0){
            useWonPile();
        }
        if(playPile.getSize() > 0) return playPile.nextCard();
    }
    string getName(){
        return name;
    }

    void collectCard(Card c){
        wonPile.addCard(c);
    }

    void collectCards(Pile p){
        wonPile.addCards(p);
    }

    void useWonPile(){
        playPile.clear();
        playPile.addCards(wonPile);
        wonPile.clear();
    }

    int numCards(){
        return playPile.getSize() + wonPile.getSize();
    }
};

class Game{
    Player p1;
    Player p2;
    void play(){
        CardDeck cd;
        cd.shuffle();
        while(cd.getSize() >= 2){
           p1.collectCard(cd.deal());
           p2.collectCard(cd.deal());    
        }
        p1.useWonPile();
        p2.useWonPile();
        Pile down;
        for(int t = 1; t <= 100; t++){
            if(!enoughCards(1)) break;
            Card c1 = p1.playCard();
            Card c2 = p2.playCard();

            cout << endl << "Turn " << t << ": " << endl;
            cout << p1.getName() << ": " << c1.toString() << " ";
            cout << p2.getName() << ": " << c2.toString() << " ";
            if(c1.compareTo(c2) > 0){
                p1.collectCard(c1);
                p1.collectCard(c2);
            }
            else if(c1.compareTo(c2) < 0){
                p2.collectCard(c1);
                p2.collectCard(c2);
            }
            else{
                down.clear();
                down.addCard(c1);
                down.addCard(c2);
                bool done = false;
                do{
                    int num = c1.getRank();
                    if(!enoughCards(num)) break;
                    cout << endl << "War! Players put down ";
                    cout << num << " card(s)." << endl;
                    
                    for(int m = 1; m <= num; m++){
                        c1 = p1.playCard();
                        c2 = p2.playCard();
                        down.addCard(c1);
                        down.addCard(c2);
                    }
                    cout << p1.getName() << ": " << c1.toString() << " ";
                    cout << p2.getName() << ": " << c2.toString() << " ";

                    if(c1.compareTo(c2) > 0){
                        p1.collectCards(down);
                        done = true;
                    }
                    if(c2.compareTo(c1) > 0){
                        p2.collectCards(down);
                        done = true;
                    }
                } while(!done);

                cout << p1.numCards() << " to " << p2.numCards();
            }
        }
    }

    bool enoughCards(int n){
        if(p1.numCards() < n || p2.numCards() < n) return false;
        return true;
    }

    Player getWinner(){
        if(p1.numCards() > p2.numCards()) return p1;
        else if(p2.numCards() > p1.numCards()) return p2;
    }
};
