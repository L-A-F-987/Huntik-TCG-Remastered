#ifndef Deck_H_
#define Deck_H_

#include "Card.h"
#include <random>
#include <deque>
#include <algorithm>
#include <optional>

#define TOP_DECK 0
#define BOTTOM_DECK -1

/**
 * @brief Deck Class which stores and manipulates the card pointers found in a 
 * player's deck
 */
class Deck{

    public:
        /**
         * @brief Deck Class Constructor
         * @param[in] starting_cards a std::deque storing all of the card*
         * that should be added to the initial
         * @param[in] provided_name std::string representing the name of the deck
         * @param[in] shuffle boolian value specifying if the deck should be
         * shuffled on initialisation. Default to true.
         */
        Deck(std::deque<Card*> starting_cards,
            std::string provided_name = "none",
            bool shuffle = true
        );

        // getters

        /**
         * @brief Function to get the number of card* in the deck
         * @return An integer equal to the number of card* currently
         * stored in deck
         */
        int GetDeckSize();

        /**
         * @brief Function to get the associated deck name
         * @return std::string equal to stored deck name
         */
        std::string GetDeckName();

        // functions for modiying deck

        /**
         * @brief Draw Card function that is used to
         * @return card* The top card of the deck if cards is not empty, else
         * std::nullopt
         */
        std::optional<Card*> DrawCard();

        /**
         * @brief Function to add a given card* to the cards deque of deck
         * @param[in] card Card* to be added
         * @param[in] location int index to add a card, default = Bottom Deck
         */
        void AddToDeck(Card* card,
            int location = BOTTOM_DECK
        );

        /**
         * @brief Function shuffle/randomise the cards stored in deck
         */
        void Shuffle();

    private:

        // private variables
        std::random_device seed;
        std::mt19937 generator;
        std::string name;
        std::deque<Card*> cards;

};


#endif