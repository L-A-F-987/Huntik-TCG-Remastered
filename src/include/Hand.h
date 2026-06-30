#ifndef Hand_H_
#define Hand_H_

#include "Card.h"
#include <vector>
#include <algorithm>

/**
 * @brief
 * Class which stores all the cards available to a player and stroed in their
 * hand. Is responsable for managing the pointers to the car d
 */
class Hand{

    public:
    /**
    * @brief Returns integer representing the current length of cards
    * @return Integer equal to the size of cards array
    */
    int GetHandSize();

    /**
    * @brief Returns a std::vector that is a copy of all the card pointers
    * stored in the cards array
    * @return Copy of the cards array
    */
    std::vector<Card*> ListCurrentCards();

    // Functions to modify hand

    /**
    * @brief Adds the specified card pointer to the hand vector
    * @param card Pointer to a card that is to be added to hand
    * @throw Throws an error in the even the new card is not found in hand after
    * attempting to add it
    */
    void AddCard(Card* card);

    /**
    * @brief Adds the specified card pointer to the hand vector
    * @param card Pointer to a card that is to be removed from hand
    * @throw Throws an error in the even the new card is not found in hand after
    * attempting to add it
    */
    void RemoveCard(Card* card);



    private:
    /**
    * @brief Searches hand for a specific card by pointer
    * @param card Pointer to a card that should be found
    * @return A boolian: true if the card is found and false if not
    */
    bool CardInHand(Card* card);

    /**
    * @brief Searches hand for a specific card by card ID
    * @param card Card ID of a card that should be found
    * @throw Thorws an error if the card cannot be found
    * @return A copy of the card pointer
    */
    Card* FindCardByHandIndex(int index);

    // Data structure storing cards
    std::vector<Card*> cards;

};




#endif