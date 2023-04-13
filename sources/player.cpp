#include "player.hpp"
#include "iostream"
using namespace std;
using namespace ariel;

Player::Player(){
    
}

Player::Player(string name)
{
    this->name = name;
}
int Player::stacksize(){return 0;}

int Player::cardesTaken(){return 0;}

