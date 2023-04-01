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
    //cout <<"cards_won:"<<cards_won<<endl;

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

void Player::increase_num_of_wins()// Function increase num of wins by 1 (instead of writing p1.numOfWins++)-so I can make it private
{
    numOfWins++;
}

int Player::get_num_of_wins()
// Function return how many turn were wins for this player (because it is private)
{
    return numOfWins;
}



void Player::push_card(card_ push_card) // Function divide the 52 cards in the start equually between 2 players.
{
        cardsLeft.push_back(push_card); // Insert the last card from game_cards list to the player1.cardsLeft

}

int Player::get_cardsLeft_size()//return size of list (because we defined cardsLeft as private)
{
    return cardsLeft.size();
}

void Player::increase_cards_won(int num_) // Increases the cards_won of player by num_ (because cards_won is private)
{
    cards_won+=num_;
}

int Player::get_how_many_cards_won()// return how many cards player won (because I defined it as private)
{
    return cards_won;
}



