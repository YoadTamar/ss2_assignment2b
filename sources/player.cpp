#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;

Player::Player(string name)
{
    if (name == "")
        throw invalid_argument("player name can't be empty")
    this->name = name;
    this->taken = 0;
    this->active = false;
}
int Player::stacksize(){return this->cards.size();}

int Player::cardesTaken(){return this->taken;}

string Player::getname(){return this->name;}

void Player::setTaken(int num){this->taken+= num;}

bool Player::is_active(){return this->active;}

void Player::set_active(bool change){this->active = change;}

void Player::add_card(Card card)
{
    this->cards->push_back(card);
}

void Player::remove_card()
{
    this->cards->pop_back();
}

Card Player::show_card()
{
    this->cards->back();
}

