//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_PLAYER_HPP
#define INC_2TASK_PLAYER_HPP


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <stdio.h>

using namespace std;
#include "iostream"
#include "stdio.h"


class Player{

private:
    std::string nameP;

public:
    Player(){};//empty constructor
    Player(std::string s);

    std::string getPName(); // get the player name

    int SideCards_player(); //prints the amount of cards player won and put in his side of the game.
    int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played
    void cardesTaken(); // prints the amount of cards this player has won.

};

#endif


#endif //INC_2TASK_PLAYER_HPP
