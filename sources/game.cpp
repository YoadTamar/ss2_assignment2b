#include <iostream>
#include <string>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player& other1, Player& other2): player1(other1), player2(other2)
    {
        this->player1 = other1;
        this->player2 = other2;
    }

    void Game::playTurn() {}

    void Game::printLastTurn() {}

    void Game::playAll() {}

    void Game::printWiner() {}

    void Game::printLog() {}

    void Game::printStats() {}
};
