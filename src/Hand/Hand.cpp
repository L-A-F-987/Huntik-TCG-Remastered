#include "Hand.h"

int Hand::GetHandSize(){
    return static_cast<int>(cards.size());
}

void Hand::AddCard(Card* card){
    cards.push_back(card);
    if(CardInHand(card) == false){
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

    if(CardInHand(card) == true){
        throw std::runtime_error(
            "Tried to remove card but failed"
        );
    }
}

std::vector<Card*> Hand::ListCurrentCards(){
    return cards;
}

bool Hand::CardInHand(Card* card){
    /*
    Verify that the card's pointer is stored in memory
    */
    if (std::find(cards.begin(),cards.end(),card) != cards.end()){
        return true;
    };
    return false;
}

Card* Hand::FindCardByHandIndex(int index){
    if (index < 0 || index >= static_cast<int>(GetHandSize())){
        throw std::runtime_error(
            "Cannot get card from index out of bounds"
        );
    }
    return cards[static_cast<size_t>(index)];
}
