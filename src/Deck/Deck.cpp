#include "Deck.h"


Deck::Deck(Card* starting_cards, std::string provided_name){

    name = provided_name;

    // fill the deck with cards and shuffle
    Deck::FillDeck(starting_cards);
    std::shuffle(deck.begin(), deck.end(), seed);
}

void Deck::FillDeck(Card* starting_cards){
    // add each of the cards to the deck from the deck recipe
    for(int i = 0; i<sizeof(starting_cards) / sizeof(starting_cards[0]); i++){
        deck.push_back(starting_cards[i]);
    }

    #ifdef ENABLE_ASSERTS
        assert(
            sizeof(starting_cards) / sizeof(starting_cards[0]) ==
            starting_cards.size()
        );
    #endif
}