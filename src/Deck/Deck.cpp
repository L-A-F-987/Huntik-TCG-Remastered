#include "Deck.h"


Deck::Deck(std::deque<Card> starting_cards, std::string provided_name){

    name = provided_name;

    // fill the deck with cards and shuffle
    cards = starting_cards;
    Shuffle();
}

void Deck::Shuffle(){
    std::shuffle(cards.begin(), cards.end(), seed);
}


std::string Deck::GetDeckName(){
    if (name != "none"){
        return name;
    }
     throw std::invalid_argument("Name has not been defined");

}