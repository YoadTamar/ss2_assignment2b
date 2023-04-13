#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    class Game
    {
        private:
            Player& player1;
            Player& player2;
            int turns;
            int win_p1;
            int win_p2;
            int draw;
            string game_log;
            string last_turn_log;
            vector<Card> game_cards;


        public:
            Game(Player& other1, Player& other2);

            void playTurn();

            void printLastTurn();

            void playAll();

            void printWiner();

            void printLog();

            void printStats();

    };
}
