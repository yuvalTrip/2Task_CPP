//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_GAME_HPP
#define INC_2TASK_GAME_HPP
#define CARD_CAPACITY 52

#include "iostream"
#include <random>
#include <algorithm>
namespace ariel{}
using namespace  ariel;
#include <string>
#include "player.hpp"
#include "card.hpp"

using namespace std;



class Game{
private:
    Player player1;
    Player player2;
    //card_* game_cards;//cardlist

public:
    Game(){}; //empty constructor
    Game(Player p, Player t);
    enum game_status { P1WON, P1LOOSE, TIE, NOT_STARTED_YET };// The status in specific turn
    void initial_game(); // create list of 52 cards according to their shape and value
    void divide_cards();// divided the game_cards randomly and equally between 2 players
    void playTurn();
    void playAll(); //plays the game until the end
    void printWiner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats();// for each player prints basic statistics: win rate, game_cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    void printLastTurn();
    // print the last turn stats. For example:
    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
    int size_game_card=0;//the index of card in the start when we put game_cards in game_cards last (in initialization game)
    card_* game_cards[CARD_CAPACITY];//all the cards in the game

};

#endif //INC_2TASK_GAME_HPP
