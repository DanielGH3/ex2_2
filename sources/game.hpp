#include "player.hpp"

#ifndef GAME_
#define GAME_
namespace ariel{
    class Game{
        private:
            Player* p1;
            Player* p2;
            string turns;
            string lasturn;
            void addToLastTurn(CardPtr c1, CardPtr c2);
        public:
            Game(Player& p1, Player& p2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();

            void playAgain();
    };
}
#endif