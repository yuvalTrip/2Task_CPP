//
// Created by yuvaltrip on 3/23/23.
//

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"


Game::Game(Player first, Player second)
//constructor
{
    player1 = first;
    player2 = second;

}

void Game::initial_game()
{
    Game::game_status::NOT_STARTED_YET;
// create list of 52 cards according to their shape and value
    for (int num = 1; num <= 13; num++) {
        for (int shape = 0; shape < 4; shape++) {
            card_::Shape cardShape = static_cast<card_::Shape>(shape);
            card_ card(num, cardShape);
            // Add Card to the game_cards list
            game_cards[size_game_card++] = &card;
        }
    }
}

void Game::divide_cards()
// divided the game_cards randomly and equally between 2 players
{
    // Randomize the order of the game_cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(game_cards, game_cards + CARD_CAPACITY, g);
    // Divide the game cards between 2 players
    for (int i=0;i<26;i++)
    {
        player1.cardsLeft[i] = game_cards[i];
    }
    for(int i=26; i<52;i++)
    {
        player2.cardsLeft[i] = game_cards[i];
    }
}
void Game::playTurn()
{
    if (player1.numCardsLeft>0)
    {
        last_turn_string="";
        card_ card_p1 = *player1.get_card();// player 1 put down card
        card_ card_p2 = *player2.get_card();// player 2 put down card
        // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.

        int num_of_tie=1; // number of card in case of several tie moves
        // if there is a tie
        while (card_p1.getCardValue() == card_p2.getCardValue() && player1.numCardsLeft>0)
        {
            // for example: // Alice played 6 of Hearts Bob played 6 of Spades. Draw.
                            //Alice played 10 of Clubs Bob played 10 of Diamonds. draw.
            last_turn_string=last_turn_string+player1.getPName()+" played "+card_p1.getCardValue()+" of "+card_p1.getCardShape()+" "+
            player1.getPName()+" played "+card_p2.getCardValue()+" of "+card_p2.getCardShape()+". drow";
            // Take one flip card
            card_ card_first_p1 = *player1.get_card();// player 1 put down card
            card_ card_first_p2 = *player2.get_card();// player 2 put down card
            num_of_tie++;
            // Take one open card
            if (player1.numCardsLeft>0)
            {
                card_p1 = *player1.get_card();// player 1 put down card
                card_p2 = *player2.get_card();// player 2 put down card
                num_of_tie++;
            }
        }
        last_turn_string=last_turn_string+player1.getPName()+" played "+card_p1.getCardValue()+" of "+card_p1.getCardShape()+" "+
        player1.getPName()+" played "+card_p2.getCardValue()+" of "+card_p2.getCardShape()+".";

        // If this is the last card
        if (card_p1.getCardValue() == card_p2.getCardValue())
        {
            // each player take his card
            player1.cards_won+=num_of_tie;
            player2.cards_won+=num_of_tie;
            last_turn_string=last_turn_string+ " drow.";
        }
        // if player 1 is won
        else if (card_p1.getCardValue() > card_p2.getCardValue()) {
            player1.cards_won+=2*num_of_tie;//won all cards of him and the other
            player1.numOfWins++;// update for stat
            // To build the string of the last turn:
            // For example: Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
            last_turn_string=last_turn_string+" "+player1.getPName()+" wins.";
        } else //if (card_p1.getCardValue() < card_p2.getCardValue())
            // if player 2 is won
        {
            player2.cards_won+=2*num_of_tie;//won all cards of him and the other
            player2.numOfWins++;// update for stat
            // To build the string of the last turn:
            // For example: Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
            last_turn_string=last_turn_string+" "+player2.getPName()+" wins.";

        }

        log_print=log_print+last_turn_string+ "\n"; // Add the last turn to the long string for the print Log
    }




//    if (player1.numCardsLeft>0)
//    //player 1 and player 2 have the same number of cards , so if it will be bigger than 0 we will do
//        //as follow:
//    {
//        if (Game::game_status==P1LOOSE || Game::game_status==P1WON || Game::game_status==NOT_STARTED_YET)
//        {
//            card_ card_p1 = *player1.get_card();// player 1 put down card
//            card_ card_p2 = *player2.get_card();// player 2 put down card
//            // if player 1 is won
//            if (card_p1.getCardValue() > card_p2.getCardValue()) {
//                player1.cards_won+=2;//won both cards
//                player1.numOfWins++;// update for stat
//                game_status::P1WON;
//            } else if (card_p1.getCardValue() < card_p2.getCardValue())
//                // if player 2 is won
//            {
//                player2.cards_won+=2;//won both cards
//                player2.numOfWins++;// update for stat
//                game_status::P1LOOSE;
//            }
//                // if there is a tie
//            else {
//                game_status::TIE;
//                // Add 2 card to the cardsTie list of both players
//                player1.cardsTie[player1.index_tie]=card_p1;
//                player2.cardsTie[player2.index_tie]=card_p1;
//                player1.cardsTie[player1.index_tie++]=card_p2;
//                player2.cardsTie[player2.index_tie++]=card_p2;
//
//            }
//        }
//        else// If the stat is tie
//        {
//            //we will get one more card for each player
//            //and send it to cardsTie
//            card_ card_temp1= *player1.get_card();// player 1 put down card
//            player1.cardsTie[player1.index_tie++]=card_temp1;
//            card_ card_temp2 = *player2.get_card();// player 2 put down card
//            player2.cardsTie[player2.index_tie++]=card_temp2;
//            //we will get one more card for both players and check which is the winner
//            // This is the last card
//            card_ card_last1= *player1.get_card();// player 1 put down the last card
//            //player1.cardsTie[player1.index_tie++]=card_last1;
//            card_ card_last2= *player2.get_card();// player 2 put down the last card
//            //player2.cardsTie[player2.index_tie++]=card_last2;
//            // Now we will check the values
//            if (card_last1.getCardValue() > card_last2.getCardValue()) {
//                player1.cards_won+=2;//won both cards
//                player1.numOfWins++;// update for stat
//                game_status::P1WON;
//            } else if (card_last1.getCardValue() < card_last2.getCardValue())
//                // if player 2 is won
//            {
//                player2.cards_won+=2;//won both cards
//                player2.numOfWins++;// update for stat
//                game_status::P1LOOSE;
//            }
//                // if there is a tie
//            else {
//                game_status::TIE;
//                // Add 2 card to the cardsTie list of both players
//                player1.cardsTie[player1.index_tie]=card_last1;
//                player2.cardsTie[player2.index_tie]=card_last1;
//                player1.cardsTie[player1.index_tie++]=card_last2;
//                player2.cardsTie[player2.index_tie++]=card_last2;
//
//            }
//
//
//        }
//
//
//    }

}
void Game::printLastTurn()
// print the last turn stats. For example:
// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
{
    cout << last_turn_string << endl;
}

void Game::playAll()
//players the game until the end
{
    while (player1.numCardsLeft>0))
    {
        playTurn();
    }

}

void Game::printWiner()
// prints the name of the winning player
{
    if (player1.cards_won>player2.cards_won)
    {// Player 1 won
        std::cout << player1.getPName() << " won"<< endl;;
    }
    else if(player2.cards_won>player1.cards_won)
    {// Player 2 won
        std::cout << player2.getPName() << " won"<< endl;;
    }
    else
    {// Tie
        std::cout << " It is a tie"<< endl;;
    }

}

void Game::printLog()// prints all the turns played one line per turn (same format as game.printLastTurn())
{
    std::cout << log_print << endl;// Print the string we concat during "PlayTurn" function

}

void Game::printStats()
{

}// for each player prints basic statistics: win rate, game_cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )






