#include <iostream>
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {
    Card::Card(int value, string type) {
        this->value = value;
        this->type = type;
    }

    int Card::getValue()
    {
        return this->value;
    }

    string Card::getType()
    {
        return this->type;
    }

    string Card::to_string()
    {
        string str;

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
                str = std::to_string(this->value) + " of " + type + "\n";
                break;
        }

        return str;
    }
}
