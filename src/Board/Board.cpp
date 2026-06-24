#include "Board.h"


void Board::ValidRowNumber_(int row_number){
    if (row_number < 0 || row_number >= static_cast<int>(rows.size())){
        throw std::invalid_argument("Row Index Out of Range");
    }
}

std::vector<Card*> Board::ListCardsInRow(int row_number){
    ValidRowNumber_(row_number);
    return rows[static_cast<std::size_t>(row_number)].cards;
}

std::vector<Card*> Board::GetCardsInRowByPlayerID(
    int row_number, std::string playerId
    ){
    std::vector<Card*> cards = ListCardsInRow(row_number);
    std::vector<Card*> cards_matching_playerId  = {};

    for (Card* card: cards){
        if (card -> GetAssociatedPlayerID() == playerId){
            cards_matching_playerId.push_back(card);
        }
    }

    return cards_matching_playerId;
}

void Board::AddCardToRow(int row_number, Card* card){
    ValidRowNumber_(row_number);
    rows[static_cast<std::size_t>(row_number)].cards.push_back(card);
}

void Board::RemoveCardFromRow(int row_number, Card* card){
    ValidRowNumber_(row_number);

    auto search_result = std::find(
    rows[static_cast<std::size_t>(row_number)].cards.begin(),
    rows[static_cast<std::size_t>(row_number)].cards.end(),
    card
);

    if (search_result == rows[static_cast<std::size_t>(row_number)].cards.end()){
        std::ostringstream error_msg;
        error_msg   << "Cannot Remove Card which is not stored in Row"
                    << std::to_string(row_number);
        throw std::runtime_error("Cannot Remove Card which is not stored in Row");
    };

    rows[static_cast<std::size_t>(row_number)].cards.erase(search_result);

}
