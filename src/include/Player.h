#ifndef Player_H_
#define Player_H_

# include "Deck.h"
# include "Hand.h"


class Player{

    public:

    // void functions
    void DrawCard();
    void AddCardToDeck(Card* card);
    void ShuffleDeck();


    // return functions
    Card* DiscardCard(Card* card);
    Card* PlayCard(Card* card);
    Card* SearchDeckCardName(std::string name);

    private:
    Deck deck;
    Hand hand;

};


#endif


