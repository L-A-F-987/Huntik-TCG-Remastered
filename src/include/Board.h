#ifndef Board_H_
#define Board_H_

#include "Card.h"
#include <array>
#include <sstream>
#include <vector>



class Board{

    public:
    std::vector<Card*> ListCardsInRow(int row_number);

    // Modify Rows
    void AddCardToRow(int row_number, Card* card);
    void RemoveCardFromRow(int row_number, Card* card);

    private:
    std::array<std::vector<Card*>,5> rows = {};

    void ValidRowNumber_(int row_number);
};

#endif