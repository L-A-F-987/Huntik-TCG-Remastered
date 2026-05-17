#ifndef Deck_H_
#define Deck_H_

#include "Card.h"
#include <random>
#include <deque>
#include <algorithm>
#include <optional>

#define TOP_DECK 0
#define BOTTOM_DECK -1

class Deck{

    public:
        // constructor
        Deck(std::deque<Card*> starting_cards,
            std::string provided_name = "none",
            bool shuffle = true
        );

        // getters
        int GetDeckSize();
        std::string GetDeckName();

        // functions for modiying deck
        std::optional<Card*> DrawCard();
        void AddToDeck(Card* card,
            int location = BOTTOM_DECK
        );
        void Shuffle();

    private:

        // private variables
        std::random_device seed;
        std::mt19937 generator;
        std::string name;
        std::deque<Card*> cards;

};


#endif