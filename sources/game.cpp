#include <iostream>
#include <string>
#include <stdexcept>
#include <random>
#include <ctime>
#include "game.hpp"
#include "player.hpp"
#include "card.hpp"

using namespace std;

namespace ariel
{
    Game::Game(Player& other1, Player& other2): player1(other1), player2(other2)
    {
        if(other1.playing() || other2.playing())
            throw invalid_argument("one of the players in other game");
        
        this->player1 = other1;
        this->player2 = other2;

        this->player1.set_active(true);
        this->player2.set_active(true);

        int i = 0;
        for (i = 1; i < 14; i++){
            this->game_cards.push_back(Card(i, "Diamonds"));
        }
        for (i = 1; i < 14; i++){
            this->game_cards.push_back(Card(i, "Spades"));
        }
        for (i = 1; i < 14; i++){
            this->game_cards.push_back(Card(i, "Hearts"));
        }
        for (i = 1; i < 14; i++){
            this->game_cards.push_back(Card(i, "Clubs"));
        }

            std::random_device random_device;
            std::default_random_engine default_rng(random_device());
            shuffle(this->game_cards.begin(), this->game_cards.end(), default_rng);
    
        for(i = 0; i<26; i++)
        {
            this->player1.add_card(this->game_cards.back());
            this->game_cards.pop_back();
            this->player2.add_card(this->game_cards.back());
            this->game_cards.pop_back();
        }

        this->turns = 0;
        this->win_p1 = 0;
        this->win_p2 = 0;
        this->draw = 0;
        this->game_log = "";
        this->last_turn_log = "";

    }

    void Game::playTurn() 
    {
        if(&player1 == &player2)
            throw invalid_argument("the playres are the same player!");
        
        if(this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
            // throw invalid_argument("logic error");
            exit(0);
        
        this->last_turn_log = "";
        turns++; 
        int cards_to_take = 2;

        Card player1_card = this->player1.show_card();
        Card player2_card = this->player2.show_card();
        int c1 = -1;
        c1 = player1_card.getValue();
        int c2 = -1;
        c2 = player2_card.getValue();
        this->player1.remove_card();
        this->player2.remove_card();

        this->last_turn_log = this->player1.getname() + " played " + player1_card.to_string() + " " + this->player2.getname() + " played " + player2_card.to_string() + ". ";

        while(c1 == c2)
        {
            this->draw++;
            this->last_turn_log += "Draw.";

            if (this->player1.stacksize() <= 1 || this->player2.stacksize() <= 1)
                {
                    this->player1.setTaken(cards_to_take/2);
                    this->player2.setTaken(cards_to_take/2);
                    break;
                }

            this->player1.remove_card();
            this->player2.remove_card();

            c1 = this->player1.show_card().getValue();
            c2 = this->player2.show_card().getValue();
            this->player1.remove_card();
            this->player2.remove_card();

            cards_to_take += 4;

            this->last_turn_log += this->player1.getname() + " played " + player1_card.to_string() + " " + this->player2.getname() + " played " + player2_card.to_string() + ". ";

        }
        if(c1 == 1)
        {
            if(c2 == 2)
            {
                this->last_turn_log += this->player2.getname() + " won the round!" + "\n\n";
                this->player2.setTaken(cards_to_take);
                this->win_p2++; 
            }
            else
            {
                this->last_turn_log += this->player1.getname() + " won the round!" + "\n\n";
                this->player1.setTaken(cards_to_take);
                this->win_p1++;
            }
        }
        else if(c2 == 1)
        {
            if(c1 == 2)
            {
                this->last_turn_log += this->player1.getname() + " won the round!" + "\n\n";
                this->player1.setTaken(cards_to_take);
                this->win_p1++;
            }
            else
            {
                this->last_turn_log += this->player2.getname() + " won the round!" + "\n\n";
                this->player2.setTaken(cards_to_take);
                this->win_p2++; 
            }
        }
        else
        {
            if(c1 > c2)
            {
                this->last_turn_log += this->player1.getname() + " won the round!" + "\n\n";
                this->player1.setTaken(cards_to_take);
                this->win_p1++;
            } 
            else if(c2 > c1)
            {
                this->last_turn_log += this->player2.getname() + " won the round!" + "\n\n";
                this->player2.setTaken(cards_to_take);
                this->win_p2++;
            } 
            else
            {
                this->last_turn_log += "Draw!\n";
            }
        }

        if (this->player1.stacksize() == 0 || this->player2.stacksize() == 0)
            {
                this->player1.set_active(false);
                this->player2.set_active(false);
            }

        this->game_log += this->last_turn_log;      
    }

    void Game::printLastTurn() 
    {
        std::cout << this->last_turn_log << endl;
    }

    void Game::printLog() 
    {
        std::cout << this->game_log << endl;
    }

    void Game::playAll() 
    {
        while(!this->player1.stacksize() || this->player2.stacksize())
            playTurn();
    }

    void Game::printWiner() 
    {
        if (!this->player1.stacksize() || this->player2.stacksize())
            return;

        if (player1.cardesTaken() == player2.cardesTaken())
            cout << "Draw!" << endl;
        else if(player1.cardesTaken() > player2.cardesTaken())
            cout << "The winner is " << player1.getname() << "!" << endl;
        else
            cout << "The winner is " << player2.getname() << "!" << endl;
    }

    void Game::printStats() 
    {
        std::cout << this->player1.getname() << " stats: \n win rate: " << (this->win_p1 *100) / this->turns << " %% . cards won: " << this->player1.cardesTaken() << endl;
        std::cout << this->player2.getname() << " stats: \n win rate: " << (this->win_p2 * 100) / this->turns) << " %% . cards won: " << this->player2.cardesTaken() << endl;
        std::cout << "Draw rate: " << (this->draw * 100) / this->turns  << " percent  amount of draws: " << this->draw << endl;
    }
};
