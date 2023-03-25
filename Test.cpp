//
// Created by yuvaltrip on 3/23/23.
//
#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

TEST_CASE("Game initialization")
{
    Player p1("Alice");
    Player p2("Bob");
    //Game game(p1, p2);
    CHECK_NOTHROW(Game game(p1, p2));
}
TEST_CASE("Test about the start of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
/* START OF THE GAME*/

// Make sure that p1 and p2's card stacks have the expected sizes
    CHECK(p1.stacksize() == 26);//TRUE
    CHECK(p2.stacksize() == 26);//TRUE

// Make sure that p1 and p2 have taken the expected amount of cards
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 0);

// Make sure there are in the start of the game still 52 cards
    CHECK(p1.cardesTaken() + p2.cardesTaken() + p1.stacksize() + p2.stacksize() == 52);

    CHECK_NOTHROW(game.printStats());// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    CHECK_NOTHROW(game.printLog());// prints all the turns played one line per turn (same format as game.printLastTurn())
}
TEST_CASE("Test about the middle of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

/* MIDDELE OF THE GAME*/

    for (int i = 0; i < 5; i++) {
        //game.playTurn();
        CHECK_NOTHROW(game.playTurn());
    }
// Make sure that p1 and p2's card stacks have the expected sizes
    CHECK(p1.stacksize() == 21);//TRUE
    CHECK(p2.stacksize() == 21);//TRUE

// Make sure that p1 and p2 have taken the expected amount of cards
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 10);

// Make sure there are in the middle of the game still 52 cards
    CHECK(p1.cardesTaken() + p2.cardesTaken() + p1.stacksize() + p2.stacksize() == 52);

    CHECK_NOTHROW(game.printStats());// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    CHECK_NOTHROW(game.printLog());// prints all the turns played one line per turn (same format as game.printLastTurn())
}
TEST_CASE("Test about the end of the game")
{
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

/* MIDDELE OF THE GAME*/

    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
/* END OF THE GAME*/

// Now we will play till the end of the game
//game.playAll();
CHECK_NOTHROW(game.playAll());

// Check all checks as before
CHECK(p1.stacksize()==0);//TRUE
CHECK(p2.stacksize()==0);//TRUE

// Make sure that p1 and p2 have taken the expected amount of cards
CHECK(p1.cardesTaken()+ p2.cardesTaken() == 52);

// Make sure there are in the end of the game still 52 cards
CHECK(p1.cardesTaken()+ p2.cardesTaken() + p1.stacksize() + p2.stacksize() == 52);

//Check the function below are not falling
CHECK_NOTHROW(game.printWiner());// prints the name of the winning player
CHECK_NOTHROW(game.printStats());// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
CHECK_NOTHROW(game.printLog());// prints all the turns played one line per turn (same format as game.printLastTurn())
CHECK_NOTHROW(game.printLastTurn());

}
