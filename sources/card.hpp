//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_CARD_HPP
#define INC_2TASK_CARD_HPP
# include <string>

using namespace std;

class card_{

public:
    enum Shape { CLUBS, DIAMONDS, HEARTS, SPADES };
    card_(){};//empty constructor
    card_(int value,Shape shape);

    int getCardValue(); // get the card value
    Shape getCardShape() const; // get the player shape

//std::string  shape;// The shape written on the card (Hearts, Clubs, Spades, Diamonds)
private:
    int value;// Number of the card (A,2,3,...,J,Q,K = 1,2,3,...,13)
    // enum to represent the shape of the card
    Shape shape;

};

#endif //INC_2TASK_CARD_HPP
