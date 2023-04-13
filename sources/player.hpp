#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    class Player
    {
        private:
            string name;

        public:
            Player(string name);
            Player();
            int cardesTaken();
            int stacksize();
    };
}
