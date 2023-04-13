#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "card.hpp"
using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;
            bool active;
            int taken;
            vector<Card> cards;

        public:
            Player(string);
            string getname();
            int cardesTaken();
            void setTaken(int);
            int stacksize();
            bool playing();
            void set_active(bool);
            void add_card(Card);
            void remove_card();
            Card show_card();
    };
}
