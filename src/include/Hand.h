#ifndef Hand_H_
#define Hand_H_

#include "Deck.h"

class Hand{

    public:
    int GetHandSize();
    std::deque<Card*> ListCurrentCards();

    // Functions to modify hand
    void AddCard(Card* card);
    void RemoveCard(Card* card);



    private:
    std::vector<Card*> cards;


};




#endif