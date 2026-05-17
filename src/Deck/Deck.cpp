#include "Deck.h"


Deck::Deck(std::deque<Card*> starting_cards, std::string provided_name, bool shuffle):
generator(seed()),
name(provided_name),
cards(starting_cards)
{
    // Shuffle Deck after Populating
    if (shuffle){
        Shuffle();
    }
}


std::string Deck::GetDeckName(){
    if (name != "none"){
        return name;
    }
     throw std::invalid_argument("Name has not been defined");

}


int Deck::GetDeckSize(){
    return static_cast<int>(cards.size());
}


std::optional<Card*> Deck::DrawCard(){

    // return none if there is no card to draw
    if (cards.empty()){
        return std::nullopt;
    }

    // take top card of the deck and pop
    Card* drawn = cards.front();
    cards.pop_front();
    return drawn;
}


void Deck::AddToDeck(Card* card, int location){

    // Put Card to the base of the deck if -1 provided
    if(location == BOTTOM_DECK){
        cards.push_back(card);
        return;
    }
    if(location == TOP_DECK){
        cards.push_front(card);
        return;
    };
    if(location < BOTTOM_DECK){
        throw std::invalid_argument(
            std::string("Cannot at a negative index ") +  std::to_string(location)
        );
    };
    if(location >= GetDeckSize()){
       throw std::invalid_argument(
            std::string("Cannot Insert at: ") +  std::to_string(location) +
            std::string(" When Deck Length is: ") + std::to_string(GetDeckSize())
        );
    };
    cards.insert(cards.begin() + location, card);
    return;

};

void Deck::Shuffle(){
    std::shuffle(cards.begin(), cards.end(), generator);
}
