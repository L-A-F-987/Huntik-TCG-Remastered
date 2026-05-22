#ifndef Hand_H_
#define Hand_H_

#include "Deck.h"

class Hand{

    public:
    int GetHandSize();
    std::vector<Card*> ListCurrentCards();

    // Functions to modify hand
    void AddCard(Card* card);
    void RemoveCard(Card* card);



    private:
    // Functions to search hand
    bool CardInHand(Card* card);
    bool FindCardByIndex(std::string index);

    // Data structure storing cards
    std::vector<Card*> cards;


};




#endif