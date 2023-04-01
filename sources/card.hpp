//
// Created by yuvaltrip on 3/23/23.
//

#ifndef INC_2TASK_CARD_HPP
#define INC_2TASK_CARD_HPP
# include <string>

using namespace std;

class card_{

public:
    enum Shape { CLUBS, DIAMONDS, HEARTS, SPADES };// The shape written on the card (Hearts, Clubs, Spades, Diamonds)
    card_(){};//empty constructor
    card_(int value_,Shape shape_);
    int getCardValue(); // get the card value (as numbers 1,2,..,13)
    std::string printCardValue(); // get the card value (as strings: Ace,King,Queen,Jack.)
    std::string getCardShape() const; // get the card shape

private:
    int value;// Number of the card (A,2,3,...,J,Q,K = 1,2,3,...,13)
    // enum to represent the shape of the card
    Shape shape;

};

#endif //INC_2TASK_CARD_HPP

//
//#include <list>
//class Card {
//public:
//    int value;
//    std::string suit;
//};
//int main() {
//    Card card1 = {1, "hearts"};
//    Card card2 = {2, "diamonds"};
//    deck.push_back(card1);
//    deck.push_back(card2);
//    return 0;
//}