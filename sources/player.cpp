//
// Created by yuvaltrip on 3/23/23.
//
# include "player.hpp"
# include <string>


Player::Player(std::string name)
// constructor
{
    this->nameP=name;
}


string Player::getPName()
// get the player name
{
    return nameP;
}

//int Player::SideCards_player()
//{
//    return 1;
//}

int Player::stacksize() //return the amount of cards left. should be 21 but can be less if a draw was played
{
    return 1;
}

int Player::cardesTaken() // return the amount of cards this player has won.
//prints the amount of cards player won and put in his side of the game.
{
    return 1;
}

