#include <string>
using namespace std;

namespace ariel{
    class Card
    {
        private:
            int value;
            string symbol;
        public:
            Card(int value, string symbol);
            int getValue();
    };
    
    typedef Card* CardPtr;
}