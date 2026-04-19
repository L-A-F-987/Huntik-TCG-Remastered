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


std::optional<Card> Deck::DrawCard(){

    // return none if there are no card to draw
    if (cards.empty()){
        return std::nullopt;
    }

    // take top card of the deck and pop
    Card drawn = cards.front();
    cards.pop_front();
    return drawn;
}


int Deck::GetDeckSize(){
    return static_cast<int>(cards.size());
}

