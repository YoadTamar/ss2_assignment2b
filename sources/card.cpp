#include <iostream>
#include <string>
using namespace std;

#include "card.hpp"

namespace ariel {
    Card::Card(int value, char type) {
        this->value = value;
        this->type = type;
    }
}
