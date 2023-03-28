#include <game.hpp>
#include <player.hpp>
#include <card.hpp>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
using namespace ariel;

class Game{
    private:
    Player* p1;
    Player* p2;
    string turns;
    string lasturn;

    public:
    Game(Player P1, Player P2) {
        p1 = &P1;
        p2 = &P2;
        turns = "";
        lasturn = "";

        P1.clearDeck();
        P2.clearDeck();

        for(int i = 0; i < 26; i++){
            //TODO : SORT FILES BETWEEN PLAYERS
            P1.addCard(new Card(0, ""));
            P2.addCard(new Card(0, ""));
        }
    }

    void playTurn(){
        stack<CardPtr> cards;
        CardPtr c1 = p1->getTopCard();
        CardPtr c2 = p2->getTopCard();
        cards.push(c1);
        cards.push(c2);

        while(c1->getValue() == c2->getValue()){
            cards.push(p1->getTopCard());
            cards.push(p2->getTopCard());
            c1 = p1->getTopCard();
            c2 = p1->getTopCard();
            cards.push(c1);
            cards.push(c2);
        }
        
        while(!cards.empty()){
            if(c1->getValue() > c2->getValue()){
                p1->addCard(cards.top());
            }else{
                p2->addCard(cards.top());
            }
            cards.pop();
        }
    }

    void printLastTurn(){
        printf("%s\n", lasturn);
    }

    void playAll(){
        while (p1->stacksize() >= 0 && p2->stacksize() >= 0){
            playTurn();
        }
    }

    void printWiner(){
        if(p1->stacksize() == 0){
            printf("the winner is %s!\n", p1->getName());
        }else if (p2->stacksize() == 0){
            printf("the winner is %s!\n", p2->getName());
        }else{
            printf("no winner yet, the game is ongoing.\n");
        }
    }

    void printLog(){
        printf("%s", turns);
    }

    void printStats(){
        //TODO : MAKE UP SOME STATS
    }
};