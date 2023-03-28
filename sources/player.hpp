#include <string>
namespace ariel{
    class Player{
        public:
            Player(string name);
            int stacksize();
            int cardesTaken();

            void clearDeck();
            void addCard(CardPtr card);
            CardPtr getTopCard();
            string getName();
    };
}