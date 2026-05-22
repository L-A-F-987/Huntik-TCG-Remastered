#include "Hand.h"

int Hand::GetHandSize(){
    return static_cast<int>(cards.size());
}

void Hand::AddCard(Card* card){
    cards.push_back(card);

    if(std::find(cards.begin(),cards.end(),card) == cards.end()){
        throw std::runtime_error(
            "Tried to add card to hand but failed"
        );
    }
}

void Hand::RemoveCard(Card* card){
    if (GetHandSize() == 0){
        throw std::runtime_error("Cannot Remove Card From Hand Size 0");
    }
    auto index = std::remove(cards.begin(), cards.end(), card);
    if (index == cards.end()){
        throw std::runtime_error("Cannot find card in hand");
    }
    cards.erase(index, cards.end());
}