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
    std::string nameP;
public:
    Player(){};//empty constructor
    Player(std::string s);
    string getPName(); // get the player name
    //int numCardsLeft=26;// Number of the players card left
    //card_* cardsLeft[26];// List of the players card left

    std::list<card_> cardsLeft;// List of the players card left

    int cards_won=0;
    int numOfWins=0;
    card_* cardsTie;//list of cards in case of tie
    int index_tie=0; // index to use in the dynamic array of cardsTie
    card_ get_card(); //get card from the player card list (when it is player turn)
    int stacksize(); //prints the amount of game_cards left. should be 21 but can be less if a draw was played
    int cardesTaken(); // prints the amount of game_cards this player has won.
/////////
};



#endif //INC_2TASK_PLAYER_HPP
