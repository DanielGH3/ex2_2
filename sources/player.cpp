#include <player.hpp>
#include <string>
#include <stack>

using namespace std;
using namespace ariel;

Player::Player(string name){
    this->name = name;
}

int Player::stacksize(){
    return cards.size();
}

int Player::cardesTaken(){
    return takenCards.size();
}


void Player::clearDeck(){
    while(!cards.empty()){
        cards.pop();
    }
}

void Player::addCard(CardPtr card){
    cards.push(card);
}

void Player::takeCard(CardPtr card){
    takenCards.push(card);
}

CardPtr Player::getTopCard(){
    if(cards.empty()) return NULL;
    CardPtr temp = cards.top();
    cards.pop();
    return temp;
}

string Player::getName(){
    return name;
}