//
// Created by yuvaltrip on 3/23/23.
//

#include "card.hpp"
#include <string>


card_::card_(int value_,Shape shape_)
// constructor
{
    this->value=value_;// Number of the card (A,2,3,...,J,Q,K)
    this->shape =shape_; // The shape written on the card (Hearts, Clubs, Spades, Diamonds)
};

int card_::getCardValue()
// return card value -for copmarison between cards value (function use values as numbers 1..13)
{
    return value;
}

string card_::printCardValue()
// return card value -for prints- we need that: 1= Ace, 11=Jack ,12=Queen 13=King (because during the game we used the values as numbers)
{
    switch (value) {
        case 1:
            return "Ace";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return"King";
            break;
        default:
            return std::to_string(value);
            break;
    }
}

std::string card_::getCardShape() const
// return player shape
{
    switch (shape) {
        case card_::CLUBS:
            return "Clubs";
        break;
        case card_::DIAMONDS:
            return "Diamonds";
        break;
        case card_::HEARTS:
            return "Hearts";
        break;
        case card_::SPADES:
            return"Spades";
        break;
        default:
            return "Unknown";
        break;
    }

}

