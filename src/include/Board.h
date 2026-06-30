#ifndef Board_H_
#define Board_H_

#include "Card.h"
#include <algorithm>
#include <array>
#include <sstream>
#include <vector>

/**
 * @brief Row struct
 *
 * Stores all the cards associated with a row and contains the hasPlayerCard
 * Function
 */
struct Row{
    std::vector<Card*> cards = {};

    /**
    * @brief Check if the cards in the List have a given playerID.
    * This is used in place of a boolian since lookup time is short for the
    * the expected vector size
    * @return A boolian value true if the playerID has a card in the row false
    * if not
    */
    bool hasPlayerCard(std::string PlayerID){
        for (Card* card: cards){
            if (card -> GetAssociatedPlayerID() == PlayerID){
                return true;
            }
        }
        return false;
    }
};

/**
 * @brief Stores a series of Row structs and contains functions to modify and
 * search these rows
 */
class Board{

    public:

    // Lookup Functions

    /**
    * @brief Function to get a list of all the card pointers stored in a given
    * row
    * @param[in] row_number The row number specified to run the function on
    * @return A std::vector which is a copy of all the current card pointers
    * stored in the row
    */
    std::vector<Card*> ListCardsInRow(int row_number);

    /**
    * @brief Function to get a list of all the card pointers stored in a given
    * row that have a specific player ID
    * @param[in] row_number The row number specified to run the function on
    * @param[in] PlayerID Player ID specifed to look for matching cards under
    * @return A std::vector which is a copy of all the current card pointers
    * stored in the row with the given player ID
    */
    std::vector<Card*> GetCardsInRowByPlayerID(
        int row_number, std::string playerId
    );

    // Modify Rows

    /**
    * @brief Adds the provided card pointer to the specified row
    * @param[in] row_number Target row index
    * @param[in] card Card pointer to be added
    */
    void AddCardToRow(int row_number, Card* card);

    /**
    * @brief Removes the provided card pointer to the specified row
    * @param[in] row_number Target row index
    * @param[in] card Card pointer to be added
    * @throw Throws an std::runtime error if a matching card pointer cannot be
    * found
    */
    void RemoveCardFromRow(int row_number, Card* card);

    /**
    * @brief Removes the provided card pointer to the specified row
    * @param[in] row_of_origin Initial Row expected to have the card pointer
    * @param[in] row_moved_to Target Row to move the card to
    * @param[in] card Card pointer to be moved
    */
    void MoveCardAcrossRows(int row_of_origin, int row_moved_to, Card* card);



    private:
    std::array<Row, 5> rows = {};

    /**
    * @brief Checks if a given row index is out of range
    * @throw Throws std::invalid argument if the row number is out of range
    */
    void ValidRowNumber_(int row_number);
};

#endif