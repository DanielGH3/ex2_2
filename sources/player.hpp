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
            Player(string name);
            int stacksize();
            int cardesTaken();

            void clearDeck();
            void addCard(CardPtr card);
            void takeCard(CardPtr card);
            CardPtr getTopCard();
            string getName();
    };
}
#endif