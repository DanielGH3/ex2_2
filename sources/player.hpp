#include <string>
#include <card.hpp>
#include <stack>

#ifndef PLAYER_
#define PLAYER_
namespace ariel{
    class Player{
        private:
            string name;
            stack<CardPtr> cards;
            stack<CardPtr> takenCards; 
        public:
            int wins;
            int losses; 
            int ties;
            int normal;

            Player(string name);
            ~Player();
            int stacksize();
            int cardesTaken();

            void clearDeck();
            void addCard(CardPtr card);
            void takeCard(CardPtr card);
            CardPtr getTopCard();
            string getName();

            double getWinrate();
            double getDrawrate();
    };
}
#endif