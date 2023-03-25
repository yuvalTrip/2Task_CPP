//
// Created by yuvaltrip on 3/23/23.
//
# include "player.hpp"
# include "game.hpp"
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

int Player::stacksize() //return the amount of game_cards left. should be 21 but can be less if a draw was played
{
    return numCardsLeft;
}

int Player::cardesTaken() // return the amount of game_cards this player has won.
//prints the amount of game_cards player won and put in his side of the game.
{
    return cards_won;
}

card_* Player::get_card()
// Get card from the player card list (when it is player turn)
{
        numCardsLeft--;// for example in the start this number is 26 (so we will take the last element in index 25)
        return (cardsLeft[numCardsLeft]);
}

