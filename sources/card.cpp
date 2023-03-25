//
// Created by yuvaltrip on 3/23/23.
//

#include "card.hpp"
#include <string>


card_::card_(int value_,Shape shape_)
// constructor
{
    this->value=value_;// Number of the card (A,2,3,...,J,Q,K)
    this->shape=shape_; // The shape written on the card (Hearts, Clubs, Spades, Diamonds)
};

int card_::getCardValue()
// return card value
{
    return value;
}

card_::Shape card_::getCardShape() const
// return player shape
{
    return shape;
}