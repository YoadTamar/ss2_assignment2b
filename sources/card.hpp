#pragma once 

#include <iostream>
#include <string>

namespace ariel {

    using namespace std;

    class Card {
    private:
        int value;
        char type;

    public:
        Card(int value, char type);

        int getValue();

        char getType();

    };
}
