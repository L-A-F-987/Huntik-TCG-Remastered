#ifndef Board_H_
#define Board_H_

#include "Card.h"
#include <array>
#include <sstream>
#include <vector>

struct Row{
    std::vector<Card*> cards = {};

    // Check if the cards in the List have a given playerID.
    // This is used in place of a boolian since lookup time is short for the
    // the expected vector size
    bool hasPlayerCard(std::string PlayerID){
        for (Card* card: cards){
            if (card -> GetAssociatedPlayerID() == PlayerID){
                return true;
            }
        }
        return false;
    }
};


class Board{

    public:

    // Lookup Functions
    std::vector<Card*> ListCardsInRow(int row_number);
    std::vector<Card*> GetCardsInRowByPlayerID(
        int row_number, std::string playerId
    );

    // Modify Rows
    void AddCardToRow(int row_number, Card* card);
    void RemoveCardFromRow(int row_number, Card* card);
    void MoveCardAcrossRows(int row_of_origin, int row_moved_to, Card* card);



    private:
    std::array<Row, 5> rows = {};

    void ValidRowNumber_(int row_number);
};

#endif