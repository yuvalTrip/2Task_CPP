//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_GAME_HPP
#define INC_2TASK_GAME_HPP


#include "iostream"
namespace ariel{}
using namespace  ariel;
#include <string>
#include "player.hpp"
using namespace std;



class Game{
private:
    Player player1;
    Player player2;

public:
    Game(){}; //empty constructor
    Game(Player p, Player t);
    void initial_game(); // divided the cards randomly and equally between 2 players
    void playTurn();
    void playAll(); //plays the game until the end
    void printWiner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )


    void printLastTurn();
    // print the last turn stats. For example:
    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.



};

#endif //INC_2TASK_GAME_HPP
