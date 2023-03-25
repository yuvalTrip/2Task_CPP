//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_PLAYER_HPP
#define INC_2TASK_PLAYER_HPP


#include <string>
#include <stdio.h>
#include "iostream"

using namespace std;


class Player{

private:
    std::string nameP;

public:
    Player(){};//empty constructor
    Player(std::string s);

    string getPName(); // get the player name

    int stacksize(); //prints the amount of cards left. should be 21 but can be less if a draw was played
    int cardesTaken(); // prints the amount of cards this player has won.

};



#endif //INC_2TASK_PLAYER_HPP
