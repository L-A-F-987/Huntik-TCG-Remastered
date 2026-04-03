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
        Deck(std::deque<Card> starting_cards, std::string provided_name = "none");

        // getters
        int GetDeckSize();
        std::string GetDeckName();

        // functions for modiying deck
        Card DrawCard();
        void Shuffle();

        // public variables
        std::deque<Card> cards;
        std::string name;

    private:
        // setters

        // private variables
        std::thread thr_deck_management;
        std::random_device seed;

};


#endif