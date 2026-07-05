#ifndef DropZone_H_
#define DropZone_H_

#include "Card.h"
#include <vector>
#include <algorithm>

/**
 * @brief
 * Class which stores all the cards available to a player and stroed in their
 * DropZone. Is responsable for managing the pointers to the card
 */
class DropZone{

    public:
    /**
    * @brief Returns integer representing the current length of cards
    * @return Integer equal to the size of cards array
    */
    int GetDropZoneSize();

    /**
    * @brief Returns a std::vector that is a copy of all the card pointers
    * stored in the cards array
    * @return Copy of the cards array
    */
    std::vector<Card*> ListCurrentCards();

    // Functions to modify DropZone

    /**
    * @brief Adds the specified card pointer to the DropZone vector
    * @param card Pointer to a card that is to be added to DropZone
    * @throw Throws an error in the even the new card is not found in DropZone
    * after attempting to add it
    */
    void AddCard(Card* card);

    /**
    * @brief Adds the specified card pointer to the DropZone vector
    * @param card Pointer to a card that is to be removed from DropZone
    * @throw Throws an error in the even the new card is not found in DropZone after
    * attempting to add it
    */
    void RemoveCard(Card* card);



    private:
    /**
    * @brief Searches DropZone for a specific card by pointer
    * @param card Pointer to a card that should be found
    * @return A boolian: true if the card is found and false if not
    */
    bool CardInDropZone(Card* card);

    // Data structure storing cards
    std::vector<Card*> cards;

};




#endif