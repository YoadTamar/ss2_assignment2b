#pragma once 

#include <iostream>
#include <string>

namespace ariel {

    using namespace std;

    class Card {
    private:
        int value;
        string type;

    public:
        Card(int value, string type);

        int getValue();

        string getType();

        string to_string();

    };
}
