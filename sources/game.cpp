#include <game.hpp>
#include <player.hpp>
#include <card.hpp>
#include <stdlib.h>
#include <string>
#include <stack>
#include <cstdlib> 

using namespace std;
using namespace ariel;

int cards[52];
int available = 0;

int getRandomCard(){
    if(available == 0) {
        available = 52;
        for(int i = 0; i < 52; i++){
            cards[i] = i;
        }     
    }

    int index = rand() % available;
    int value = cards[index];

    int temp = cards[available - 1];
    cards[available - 1] = cards[index];
    cards[index] = temp;
    available--;

    return value;
}

string getSymbol(int value){
    if(value <= 13) return "diamond";
    if(value <= 26) return "spades";
    if(value <= 39) return "hearts";
    return "clubs";
}

Game::Game(Player P1, Player P2) {
    p1 = &P1;
    p2 = &P2;
    turns = "";
    lasturn = "";

    P1.clearDeck();
    P2.clearDeck();


    for(int i = 0; i < 52; i++){
        //TODO : SORT FILES BETWEEN PLAYERS
        int card1 = getRandomCard();
        int card2 = getRandomCard();
        P1.addCard(new Card(card1, getSymbol(card1 + 1)));
        P2.addCard(new Card(card2, getSymbol(card2 + 1)));
    }
}

void Game::playTurn(){
    stack<CardPtr> cards1;
    stack<CardPtr> cards2;
    CardPtr c1 = p1->getTopCard();
    CardPtr c2 = p2->getTopCard();  
    printf("address of c2 = %p\n", c2);
    printf("address of c1 = %p\n\n", c1);
    if(c1 != NULL) cards1.push(c1);
    if(c2 != NULL) cards2.push(c2);

    if(c1 != NULL && c2 != NULL){
        //printf("%d %d\n", c1->getValue(),c2->getValue());
    }    
}

void Game::printLastTurn(){
    printf("%s\n", lasturn.c_str());
}

void Game::playAll(){
    while(p1->stacksize() > 0 && p2->stacksize() > 0){
        playTurn();
    }
}

void Game::printWiner(){
    if(p1->stacksize() == 0){
        printf("the winner is %s!\n", p1->getName().c_str());
    }else if (p2->stacksize() == 0){
        printf("the winner is %s!\n", p2->getName().c_str());
    }else{
        printf("no winner yet, the game is ongoing.\n");
    }
}

void Game::printLog(){
    printf("%s", turns.c_str());
}

void Game::printStats(){
    //TODO : MAKE UP SOME STATS
}