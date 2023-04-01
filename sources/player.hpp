//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_PLAYER_HPP
#define INC_2TASK_PLAYER_HPP


#include <string>
#include <stdio.h>
#include <list>
#include "iostream"
#include "card.hpp"

using namespace std;


class Player{

private:
    std::string nameP; //Player name
    std::list<card_> cardsLeft;// List of the players card left
    int cards_won=0;
    int numOfWins=0;
    int index_tie=0; // index to use in the dynamic array of cardsTie

public:
    Player();//empty constructor
    Player(std::string s);
    string getPName(); // get the player name
    card_ get_card(); //get card from the player card list (when it is player turn)
    int stacksize(); //prints the amount of game_cards left. should be 21 but can be less if a draw was played
    int cardesTaken(); // prints the amount of game_cards this player has won.
    void increase_num_of_wins();// Function increase numOfWins by 1. (because numOfWins is private)
    int get_num_of_wins(); //Function return how many turn were wins for this player (because it is private)
    void push_card(card_ push_card); // Function divide the 52 cards in the start equually between 2 players.
    int get_cardsLeft_size();//return size of cardsLeft list (because we defined cardsLeft as private)
    void increase_cards_won(int num_) ; // Increases the cards_won of player by num_ (because cards_won is private)
    int get_how_many_cards_won(); // return how many cards player won (because I defined it as private)
};



#endif //INC_2TASK_PLAYER_HPP
