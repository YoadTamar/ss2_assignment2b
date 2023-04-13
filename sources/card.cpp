#include <iostream>
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {
    Card::Card(int value, string type) {
        this->value = value;
        this->type = type;
    }

    int card::getValue()
    {
        return this->value;
    }

    string card::type()
    {
        return this->type;
    }

    string Card::to_string()
    {
        string str = nullptr;

        switch(this->value)
        {
            case 1:
                str = "Ace of " + type + "\n";
                break;
            case 11:
                str = "Prince of " + type + "\n";
                break;
            case 12:
                str = "Queen of " + type + "\n";
                break;
            case 13:
                str = "King of " + type + "\n";
                break;
            default:
                str = this->_value + " of " + type + "\n";
                break;
        }
    }
}
