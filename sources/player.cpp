//
// Created by yuvaltrip on 3/23/23.
//
# include "player.hpp"
# include <string>


Player::Player(std::string name)
// constructor
{
    nameP=name;
}

int Player::SideCards_player()
//prints the amount of cards player won and put in his side of the game.
{
    return 1;
}

int Player::stacksize() //prints the amount of cards left. should be 21 but can be less if a draw was played
{
    return 1;
}

void Player::cardesTaken() // prints the amount of cards this player has won.
{

}

