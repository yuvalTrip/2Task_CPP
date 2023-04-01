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
    //return numCardsLeft;
    return cardsLeft.size();

}

int Player::cardesTaken() // return the amount of game_cards this player has won.
//prints the amount of game_cards player won and put in his side of the game.
{
    cout <<"cards_won:"<<cards_won<<endl;

    return cards_won;
}

card_ Player::get_card()
// Get card from the player card list (when it is player turn)
{
    //numCardsLeft--;// for example in the start this number is 26 (so we will take the last element in index 25)
        //return (cardsLeft.pop_back());
        //return (cardsLeft[numCardsLeft]);
    card_ last_card = cardsLeft.back();// Get a reference to the last element in the list and store it in the last_card variable

    cardsLeft.pop_back();// Removes the last element from cardsLeft

    return last_card;// Returns a pointer to the removed element.
}

