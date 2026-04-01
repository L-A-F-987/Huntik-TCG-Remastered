#ifndef Deck_H_
#define Deck_H_

#include "Card.h"
#include <random>
#include <thread>
#include <deque>
#include <algorithm>

class Deck{

    public:
        // constructor
        Deck(Card* cards_location, std::string provided_name = "none");

        // getters
        int GetDeckSize();

        // public variables
        std::deque<Card> deck;
        std::string name;
    private:
        // setters
        void Deck::FillDeck(Card* starting_cards);

        // private variables
        std::thread thr_deck_management;
        std::random_device seed;

};


#endif