//
// Created by yuvaltrip on 3/23/23.
//

#include "game.hpp"
#include "player.hpp"
#include "card.hpp"


Game::Game(Player& first, Player& second)
//constructor
{
    player1 = &first;
    player2 = &second;
    initial_game();
    divide_cards();
}

void Game::initial_game()
{
    //Game::game_status::NOT_STARTED_YET;
// create list of 52 cards according to their shape and value
    for (int num = 1; num <= 13; num++) {
        for (int shape = 0; shape < 4; shape++) {
            card_::Shape cardShape = static_cast<card_::Shape>(shape);
            card_ card(num, cardShape);
            game_cards.push_back(card);// Add Card to the game_cards list
        }
    }
}

void Game::divide_cards()
// divided the game_cards randomly and equally between 2 players
{
    // Randomize the order of the game_cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<card_> game_cards_vec(game_cards.begin(), game_cards.end());
    std::shuffle(game_cards_vec.begin(), game_cards_vec.end(), g);
    std::list<card_> game_cards(game_cards_vec.begin(), game_cards_vec.end());
    // Divide the game cards between 2 players
    for (int i=0;i<26;i++)
    {
        player1->push_card(game_cards.back()); // Insert the last card from game_cards list to the player1.cardsLeft
        game_cards.pop_back();// Removes the last element from game_cards
        player2->push_card(game_cards.back()); // Insert the last card from game_cards list to the player2.cardsLeft
        game_cards.pop_back();// Removes the last element from game_cards
    }
}
void Game::playTurn()
{
    if (player1==player2){throw std::runtime_error("This is the same player!");}
    turns_counter++;// For prints
    if (player1->get_cardsLeft_size()>0)//numCardsLeft>0)
    {
        last_turn_string="";
        card_ card_p1 = player1->get_card();// player 1 put down card
        card_ card_p2 = player2->get_card();// player 2 put down card
        // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
        int num_of_tie=1; // number of card in case of several tie moves
        // if there is a tie
        while (card_p1.getCardValue() == card_p2.getCardValue() && player1->get_cardsLeft_size()>0)//numCardsLeft>0)
        {
            draw_counter++;// increase number of draws (for printStats function)
            // for example: // Alice played 6 of Hearts Bob played 6 of Spades. Draw.
                            //Alice played 10 of Clubs Bob played 10 of Diamonds. draw.
            last_turn_string=last_turn_string+player1->getPName()
                    +" played "+std::to_string(card_p1.getCardValue())
                    +" of "+card_p1.getCardShape()
                    +" "+player2->getPName()
                    +" played "+card_p2.printCardValue()
                    +" of "+card_p2.getCardShape()+
                    ". drow.";
            // Take one flip card
            card_ card_first_p1 = player1->get_card();// player 1 put down card
            card_ card_first_p2 = player2->get_card();// player 2 put down card
            num_of_tie++;
            // Take one open card
            if(player1->get_cardsLeft_size()>0)// If there are still left cards
            {
                card_p1 = player1->get_card();// player 1 put down card
                card_p2 = player2->get_card();// player 2 put down card
                num_of_tie++;
            }
        }
        last_turn_string=last_turn_string
                +player1->getPName()+
                " played "+std::to_string(card_p1.getCardValue())
                +" of "+card_p1.getCardShape()
                +" "+player2->getPName()
                +" played "+card_p2.printCardValue()
                +" of "+card_p2.getCardShape()+".";

        // If this is the last card
        if (card_p1.getCardValue() == card_p2.getCardValue())
        {
            draw_counter++;// increase number of draws (for printStats function)
            // each player take his card
            player1->increase_cards_won(num_of_tie);
            player2->increase_cards_won(num_of_tie);
            last_turn_string=last_turn_string+ " drow.";
        }
        // if player 1 is won
        else if (card_p1.getCardValue() > card_p2.getCardValue()) {
            player1->increase_cards_won(2*num_of_tie);//won all cards of him and the other
            player1->increase_num_of_wins();// update for stat
            //cout <<"player1.cards_won:"<<player1->cards_won<<endl;
            // To build the string of the last turn:
            // For example: Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
            last_turn_string=last_turn_string+" "+player1->getPName()+" wins.";
        } else //if (card_p1.getCardValue() < card_p2.getCardValue())
            // if player 2 is won
        {
            player2->increase_cards_won(2*num_of_tie);//won all cards of him and the other
            player2->increase_num_of_wins();// update for stat
            //cout <<"player2.cards_won:"<<player2->cards_won<<endl;

            // To build the string of the last turn:
            // For example: Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
            last_turn_string=last_turn_string+" "+player2->getPName()+" wins.";

        }

        log_print=log_print+last_turn_string+ "\n"; // Add the last turn to the long string for the print Log
    }
    else
    {
        throw std::runtime_error("Game is over!");
    }

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
    while (player1->get_cardsLeft_size()>0)//numCardsLeft>0)
    {
        playTurn();
    }

}

void Game::printWiner()
// prints the name of the winning player
{
    if (player1->get_how_many_cards_won()>player2->get_how_many_cards_won())
    {// Player 1 won
        std::cout << player1->getPName() << " won"<< endl;;
    }
    else if(player2->get_how_many_cards_won()>player1->get_how_many_cards_won())
    {// Player 2 won
        std::cout << player2->getPName() << " won"<< endl;;
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
    std::cout <<player1->getPName()+" : win rate- "+std::to_string(win_rate(*player1))+"% cards won:"+ std::to_string(player1->cardesTaken())+" draw rate- "+std::to_string(draw_rate())+"% number of draws:"+std::to_string(draw_counter)<<endl;
    std::cout <<player2->getPName()<<" : win rate- "+std::to_string(win_rate(*player2))+"% cards won:"+std::to_string(player2->cardesTaken())+" draw rate- "+std::to_string(draw_rate())+ "% number of draws:"+std::to_string(draw_counter)<< endl;

}// for each player prints basic statistics: win rate, game_cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

int Game::draw_rate()
// Draw rate will be compute as the precentage of draws from all turns.
{

    double d_rate=(100*draw_counter)/turns_counter;
    return d_rate;

}

int Game::win_rate(Player& player)
// Win rate will be compute as the precentage of wins from all turns.
{
    double w_rate=(100*player.get_num_of_wins())/turns_counter;
    return w_rate;
}





