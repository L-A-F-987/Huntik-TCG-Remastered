#include "DropZone.h"

int DropZone::GetDropZoneSize(){
    return static_cast<int>(cards.size());
}

std::vector<Card*> DropZone::ListCurrentCards(){
    return cards;
}

void DropZone::AddCard(Card* card){
    cards.push_back(card);
    if(CardInDropZone(card) == false){
        throw std::runtime_error(
            "Tried to add card to hand but failed"
        );
    }
}

void DropZone::RemoveCard(Card* card){
    if (GetDropZoneSize() == 0){
        throw std::runtime_error("Cannot Remove Card From DropZone Size 0");
    }
    auto index = std::remove(cards.begin(), cards.end(), card);
    if (index == cards.end()){
        throw std::runtime_error("Cannot find card in hand");
    }
    cards.erase(index, cards.end());

    if(CardInDropZone(card) == true){
        throw std::runtime_error(
            "Tried to remove card but failed"
        );
    }
}

bool DropZone::CardInDropZone(Card* card){
    /*
    Verify that the card's pointer is stored in memory
    */
    if (std::find(cards.begin(),cards.end(),card) != cards.end()){
        return true;
    };
    return false;
}
